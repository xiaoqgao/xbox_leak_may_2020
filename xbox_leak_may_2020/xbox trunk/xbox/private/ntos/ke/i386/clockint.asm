        title  "Interval Clock Interrupt"
;++
;
; Copyright (c) 1989  Microsoft Corporation
;
; Module Name:
;
;    clockint.asm
;
; Abstract:
;
;    This module implements the code necessary to field and process the
;    interval clock interrupt.
;
; Author:
;
;    Shie-Lin Tzong (shielint) 12-Jan-1990
;
; Environment:
;
;    Kernel mode only.
;
; Revision History:
;
;   bryanwi 20-Sep-90
;
;       Add KiSetProfileInterval, KiStartProfileInterrupt,
;       KiStopProfileInterrupt procedures.
;       KiProfileInterrupt ISR.
;       KiProfileList, KiProfileLock are delcared here.
;
;   shielint 10-Dec-90
;       Add performance counter support.
;       Move system clock to irq8, ie we now use RTC to generate system
;         clock.  Performance count and Profile use timer 1 counter 0.
;         The interval of the irq0 interrupt can be changed by
;         KiSetProfileInterval.  Performance counter does not care about the
;         interval of the interrupt as long as it knows the rollover count.
;       Note: Currently I implemented 1 performance counter for the whole
;       i386 NT.  It works on UP and SystemPro.
;
;--

.386p
        .xlist
KERNELONLY  equ     1
include ks386.inc
include callconv.inc                    ; calling convention macros
include i386\kimacro.inc
include i386\ix8259.inc
        .list

        EXTRNP  HalBeginClockInterrupt,2,,FASTCALL
        EXTRNP  HalEndSystemInterrupt,1,,FASTCALL
        EXTRNP  HalRequestSoftwareInterrupt,1,,FASTCALL
        extrn   _KiTimerTableListHead:DWORD
        extrn   _KiTimerExpireDpc:DWORD
        extrn   _KdDebuggerEnabled:BYTE
        EXTRNP  _DbgBreakPoint
        EXTRNP  _DbgBreakPointWithStatus,1
        extrn   _KiPCR:DWORD
        extrn   _KiIdleThread:DWORD
        extrn   _KeTickCount:DWORD
        extrn   _KeInterruptTime:DWORD
        extrn   _KeSystemTime:DWORD

if DBG
        extrn   _DbgPrint:near
        extrn   _KiDPCTimeout:DWORD
        extrn   _MsgDpcTimeout:BYTE
endif

ifdef DEVKIT
        EXTRNP  _KdPollBreakIn
        extrn   _KiDbgClockInt:DWORD
endif

        page ,132
        subttl  "Update System Time"

_TEXT   SEGMENT DWORD PUBLIC 'CODE'
        ASSUME  DS:FLAT, ES:FLAT, SS:NOTHING, FS:NOTHING, GS:NOTHING
;++
;
; VOID
; KeClockInterrupt(
;       VOID
;       )
;
; Routine Description:
;
;    This routine is entered as the result of an interrupt generated by CLOCK.
;    Its function is to update the system time and check to determine if a timer
;    has expired.
;
; Arguments:
;
;    None.
;
; Return Value:
;
;    None.
;
;--
cPublicProc _KeClockInterrupt     ,0

;
; Save machine state in trap frame.
;

        ENTER_INTERRUPT

;
; (esp) - base of trap frame
; (ebp) - base of trap frame
;

;
; Dismiss interrupt and raise irq level to CLOCK_LEVEL.
;

.errnz CLOCK_VECTOR - PRIMARY_VECTOR_BASE
        xor     ecx, ecx
        mov     edx, CLOCK_LEVEL
        push    ecx                     ; allocate space to save OldIrql
        fstCall HalBeginClockInterrupt

ifdef DEVKIT
;
; Call the debugger's clock interrupt routine if there is one.
;
        mov     esi,_KiDbgClockInt
        test    esi, esi
        jz      kust_nodbgr
        push    ebp
        call    esi
kust_nodbgr:
endif

;
; Update interrupt time.
;
; N.B. The interrupt time is updated in a very strict manner so that an
;      interlock does not have to be used in an MP system to read time.
;

        mov     edi,_KeInterruptTime+0  ; get low interrupt time
        mov     esi,_KeInterruptTime+4  ; get high interrupt time
        mov     ebx,_KeTickCount        ; get tick count
        add     edi,CLOCK_TIME_INCREMENT; add time increment
        adc     esi,0                   ; propagate carry
        mov     _KeInterruptTime+8,esi  ; store high 2 interrupt time
        mov     _KeInterruptTime+0,edi  ; store low interrupt time
        mov     _KeInterruptTime+4,esi  ; store high 1 interrupt time

;
; Update system time.
;
; N.B. The system time is updated in a very strict manner so that an
;      interlock does not have to be used in an MP system to read time.
;

        mov     ecx,_KeSystemTime+0     ; get low interrupt time
        mov     edx,_KeSystemTime+4     ; get high interrupt time
        add     ecx,CLOCK_TIME_INCREMENT; add time increment
        adc     edx,0                   ; propagate carry
        mov     _KeSystemTime+8,edx     ; store high 2 interrupt time
        mov     _KeSystemTime+0,ecx     ; store low interrupt time
        mov     _KeSystemTime+4,edx     ; store high 1 interrupt time

;
; Update tick count.
;

        mov     eax,ebx                 ; copy tick count
        mov     ecx,ebx                 ; copy tick count
        inc     ecx                     ; increment tick count
        mov     _KeTickCount,ecx        ; store low tick count

;
; Check to determine if a timer has expired.
; (edi:esi) = KiInterruptTime
; (eax) = bucket
; (ebx) = KeTickCount.LowPart
;

kust10: and     eax,TIMER_TABLE_SIZE-1  ; isolate current hand value
        lea     ecx,_KiTimerTableListHead[eax*8] ; get listhead addrees
        mov     edx,[ecx]               ; get first entry address
        cmp     ecx,edx                 ; check if list is empry
        je      kustxx                  ; if equal, list is empty
        cmp     esi,[edx].TiDueTime.TmHighTime-TiTimerListEntry ; compare high
        jb      kustxx                  ; if below, timer has not expired
        ja      short kust15            ; if above, timer has expired
        cmp     edi,[edx].TiDueTime.TmLowTime-TiTimerListEntry ; compare low
        jb      kustxx                  ; if below, timer has not expired

kust15:
;
; Timer has expired, put timer expiration DPC in the current processor's DPC
; queue.
;
; (ebx) = KeTickCount.LowPart
;

        lea     eax,_KiTimerExpireDpc+DpDpcListEntry ; get list entry address
        cmp     byte ptr [eax]+(DpInserted-DpDpcListEntry), 0H ; check if inserted
        jnz     kustxx                  ; if nz, DPC already inserted

        cli

        mov     byte ptr [eax]+(DpInserted-DpDpcListEntry), 1 ; mark as inserted
        mov     [eax]+(DpSystemArgument1-DpDpcListEntry),ebx  ; pass tick count
        lea     ecx,PCR[PcPrcbData+PbDpcListHead] ; compute DPC listhead address
        mov     ebx,[ecx]+LsBlink       ; get address of last entry in list
        mov     [ecx]+LsBlink, eax      ; set new address of last entry
        mov     [ebx]+LsFlink, eax      ; set forward link in old last entry
        mov     [eax]+LsFlink, ecx      ; set forward link in new last entry
        mov     [eax]+LsBlink, ebx      ; set backward link in new last entry

        sti                             ; enable interrupt

; request dispatch interrupt

        mov     ecx, DISPATCH_LEVEL
        fstCall HalRequestSoftwareInterrupt

kustxx:
ifdef DEVKIT
        cmp     _KdDebuggerEnabled, 0
        jz      kust30
        stdCall _KdPollBreakIn
        test    al,al
        jz      kust30
        stdCall _DbgBreakPointWithStatus,<DBG_STATUS_CONTROL_C>
kust30:
endif

;
; inline KeUpdateRunTime to do the actual work
;

        inc     dword ptr PCR[PcPrcbData+PbInterruptCount]
        mov     ebx, PCR[PcPrcbData+PbCurrentThread] ; (ebx)->current thread

;
; Update the total time spent in kernel mode
;

        cmp     byte ptr [esp], DISPATCH_LEVEL
        jc      short Kutp4             ; OldIrql<2, then kernel
        ja      short Kutp3             ; OldIrql>2, then interrupt

        cmp     dword ptr PCR[PcPrcbData.PbDpcRoutineActive], 0
        jz      short Kutp4             ; Executing Dpc?, no then thread time

        inc     dword ptr PCR[PcPrcbData.PbDpcTime]
if DBG
;
; Check for dpcs which run for too long
;

        inc     dword ptr PCR[PcPrcbData.PbDebugDpcTime]
        mov     edx, _KiDPCTimeout
        cmp     dword ptr PCR[PcPrcbData.PbDebugDpcTime], edx
        jc      Kutp55                  ; Jump if not over limit

;
; Dpc time has exceeded the allowed quanta
;

        push    offset FLAT:_MsgDpcTimeout ; push message address
        call    _DbgPrint               ; print debug message
        add     esp, 1 * 4              ; remove arguments from stack

        cmp     _KdDebuggerEnabled, 0   ; check if debugger enabled
        je      short Kutp6             ; if eq, no debugger, continue
        stdCall _DbgBreakPoint          ; break into debugger

Kutp6:  mov     dword ptr PCR[PcPrcbData.PbDebugDpcTime], 0 ; Reset Time
endif
        jmp     Kutp55

ALIGN 4
Kutp3:
;
; Update the time spent at interrupt time for this processor
;

        inc     dword ptr PCR[PcPrcbData.PbInterruptTime]
        jmp     Kutp55

ALIGN 4
Kutp4:

;
; Update the time spent in kernel mode for the current thread.
;

        inc     dword ptr [ebx]+ThKernelTime

;
; Decrement current thread quantum and check to determine if a quantum end
; has occurred.
;

ALIGN 4
Kutp55: sub     dword ptr [ebx]+ThQuantum, CLOCK_QUANTUM_DECREMENT ; decrement quantum
        jg      Kutp75                      ; if > 0, time remaining on quantum

;
; Set quantum end flag and initiate a dispather interrupt on the current
; processor.
;

        cmp     ebx,offset FLAT:_KiIdleThread ; check if idle thread
        jz      Kutp75                      ; if z, then idle thread
        mov     PCR[PcPrcbData.PbQuantumEnd], esp ; set quantum end indicator
        mov     ecx, DISPATCH_LEVEL         ; request dispatch interrupt
        fstCall HalRequestSoftwareInterrupt ;
Kutp75:                                     ;

;
; Do interrupt exit processing
;

        INTERRUPT_EXIT

stdENDP _KeClockInterrupt

_TEXT   ends
        end
