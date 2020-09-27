/*

Copyright (c) 2000 Microsoft Corporation

Module Name:

    CopyFileEx.cpp

Abstract:

    

Author:

    Josh Poley (jpoley)

Environment:

    XBox

Revision History:
    04-21-2000  Created

Notes:

*/

#include "stdafx.h"
#include "commontest.h"
#include "mutests.h"

static BOOL cancel = FALSE;
static DWORD CALLBACK CopyFileProgressRoutine(LARGE_INTEGER TotalFileSize, LARGE_INTEGER TotalBytesTransferred, LARGE_INTEGER StreamSize, LARGE_INTEGER StreamBytesTransferred, DWORD dwStreamNumber, DWORD dwCallbackReason, HANDLE hSourceFile, HANDLE hDestinationFile, LPVOID lpData);
static DWORD CALLBACK CancelHalfway(LARGE_INTEGER TotalFileSize, LARGE_INTEGER TotalBytesTransferred, LARGE_INTEGER StreamSize, LARGE_INTEGER StreamBytesTransferred, DWORD dwStreamNumber, DWORD dwCallbackReason, HANDLE hSourceFile, HANDLE hDestinationFile, LPVOID lpData);
static DWORD CALLBACK CancelOnFirst(LARGE_INTEGER TotalFileSize, LARGE_INTEGER TotalBytesTransferred, LARGE_INTEGER StreamSize, LARGE_INTEGER StreamBytesTransferred, DWORD dwStreamNumber, DWORD dwCallbackReason, HANDLE hSourceFile, HANDLE hDestinationFile, LPVOID lpData);


struct CopyState
    {
    HANDLE hLog;
    __int64 totalBytesTransferred;
    int state;
    };

// states
#define TEST_CANCELRESUME   1
#define TEST_CANCELFLAG     2


/*

Routine Description:

    Tests the CopyFileEx API

Arguments:

    HANDLE hLog - handle to an XLOG object
    DWORD ThreadID - unique id of the thread - used to keep tests from 
        corrupting the same file

Return Value:

    

*/
DWORD MUTests::CopyFileEx_Test(HANDLE hLog, DWORD ThreadID)
    {
    /*
    BOOL CopyFileEx(
      LPCTSTR lpExistingFileName,           // name of existing file
      LPCTSTR lpNewFileName,                // name of new file
      LPPROGRESS_ROUTINE lpProgressRoutine, // callback function
      LPVOID lpData,                        // callback parameter
      LPBOOL pbCancel,                      // cancel status
      DWORD dwCopyFlags                     // copy options
    );
    */
    xSetFunctionName(hLog, "CopyFileEx");

    char lpSmallFile[80]; sprintf(lpSmallFile, "%ws:\\FCPX01_%d.txt", BASE_DRIVE, ThreadID);
    char lpBigFile[80]; sprintf(lpBigFile, "%ws:\\FCPX02_%d.txt", BASE_DRIVE, ThreadID);
    char lpExtraBigFile[80]; sprintf(lpExtraBigFile, "%ws:\\FCPX03_%d.txt", BASE_DRIVE, ThreadID);
    char lpFakeFile[80]; sprintf(lpFakeFile, "%ws:\\FCPX04_%d.bla", BASE_DRIVE, ThreadID);
    char lpFakeFile2[80]; sprintf(lpFakeFile2, "%ws:\\FCPX05_%d.bla", BASE_DRIVE, ThreadID);
    char lpDevice[80]; sprintf(lpDevice, "%ws:\\FCPX06_%d.txt", BASE_DRIVE, ThreadID);
    char lpDir1[80]; sprintf(lpDir1, "%ws:\\FCPX_%d", BASE_DRIVE, ThreadID);
    char lpSubFile[80]; sprintf(lpSubFile, "%ws:\\FCPX_%d\\FCPX07_%d.txt", BASE_DRIVE, ThreadID, ThreadID);
    char lpFile1[80];
    char lpFile2[80];
    unsigned i;

    // initialize system state
    CreateDirectory(lpDir1, NULL);
    CreateFilledFile(lpSmallFile, KILOBYTE*3);
    CreateFilledFile(lpBigFile, MEGABYTE*2);        // tests rely on this being 2meg
    CreateFilledFile(lpSubFile, KILOBYTE*9);


    DWORD time = GetTickCount();




    //////////////////////////////////////////////////////////////////////////
    // Straight line successes
    //////////////////////////////////////////////////////////////////////////
    TESTCASE("small file")
        {
        sprintf(lpFile1, "%ws:\\FCPX08_%d.txt", BASE_DRIVE, ThreadID);

        if(CopyFileEx(lpSmallFile, lpFile1, CopyFileProgressRoutine, hLog, &cancel, 0) == TRUE)
            TESTPASS(hLog, "CopyFileEx (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "CopyFileEx (ec: %ld)", GetLastError());

        if(FileExists(lpFile1) == TRUE)
            TESTPASS(hLog, "(ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "File doesn't exist (ec: %ld)", GetLastError());
        } ENDTESTCASE_CLEAN({ DeleteFile(lpFile1); });
    TESTCASE("large file")
        {
        sprintf(lpFile1, "%ws:\\FCPX08_%d.txt", BASE_DRIVE, ThreadID);

        if(CopyFileEx(lpBigFile, lpFile1, CopyFileProgressRoutine, hLog, &cancel, 0) == TRUE)
            TESTPASS(hLog, "CopyFileEx (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "CopyFileEx (ec: %ld)", GetLastError());

        if(FileExists(lpFile1) == TRUE)
            TESTPASS(hLog, "(ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "File doesn't exist (ec: %ld)", GetLastError());
        } ENDTESTCASE_CLEAN({ DeleteFile(lpFile1); });
    TESTCASE("Exists & FAIL_IF_EXISTS")
        {
        if(CopyFileEx(lpBigFile, lpBigFile, CopyFileProgressRoutine, hLog, &cancel, COPY_FILE_FAIL_IF_EXISTS) == FALSE)
            TESTPASS(hLog, "CopyFileEx (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "CopyFileEx (ec: %ld)", GetLastError());
        } ENDTESTCASE_CLEAN({ DeleteFile(lpFile1); });
    /*
    TESTCASE("large file cancel+resume")
        {
        CopyState state = { hLog, 0, TEST_CANCELRESUME };
        sprintf(lpFile1, "%ws:\\FCPX08_%d.txt", BASE_DRIVE, ThreadID);

        if(CopyFileEx(lpBigFile, lpFile1, CancelHalfway, &state, &cancel, COPY_FILE_RESTARTABLE) == FALSE)
            TESTPASS(hLog, "CopyFileEx (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "CopyFileEx (ec: %ld)", GetLastError());

        if(CopyFileEx(lpBigFile, lpFile1, CancelOnFirst, &state, &cancel, COPY_FILE_RESTARTABLE) == FALSE)
            TESTPASS(hLog, "CopyFileEx (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "CopyFileEx (ec: %ld)", GetLastError());

        if(state.totalBytesTransferred >= 1*MEGABYTE)
            TESTPASS(hLog, "(ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "Copy didnt restart, copied bytes = %I64d (ec: %ld)", state.totalBytesTransferred, GetLastError());
        } ENDTESTCASE_CLEAN({ DeleteFile(lpFile1); });
        */
    TESTCASE("cancel flag")
        {
        CopyState state = { hLog, 0, TEST_CANCELFLAG };
        sprintf(lpFile1, "%ws:\\FCPX08_%d.txt", BASE_DRIVE, ThreadID);

        if(CopyFileEx(lpBigFile, lpFile1, CancelHalfway, &state, &cancel, 0) == FALSE)
            TESTPASS(hLog, "CopyFileEx (ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "CopyFileEx (ec: %ld)", GetLastError());

        if(state.totalBytesTransferred < 1*MEGABYTE)
            TESTPASS(hLog, "(ec: %ld)", GetLastError());
        else
            TESTFAIL(hLog, "Copy didnt stop, copied bytes = %I64d (ec: %ld)", state.totalBytesTransferred, GetLastError());
        } ENDTESTCASE_CLEAN({ DeleteFile(lpFile1); });




    //////////////////////////////////////////////////////////////////////////
    // Performance
    //////////////////////////////////////////////////////////////////////////
    TESTCASE("Performance")
        {
        xLog(hLog, XLL_INFO, "Test took %lu milliseconds to run", GetTickCount()-time);
        } ENDTESTCASE;


    //////////////////////////////////////////////////////////////////////////
    // Cleanup
    //////////////////////////////////////////////////////////////////////////
    DeleteFile(lpSubFile);
    RemoveDirectory(lpDir1);
    DeleteFile(lpBigFile);
    DeleteFile(lpSmallFile);
    DeleteFile(lpExtraBigFile);
    DeleteFile(lpDevice);

    return 0;
    }


/*

Routine Description:

    Callback function used with the CopyFileEx and MoveFileWithProgress functions
    See "CopyProgressRoutine" in MSDN

Arguments:

    LARGE_INTEGER TotalFileSize          - file size
    LARGE_INTEGER TotalBytesTransferred  - bytes transferred
    LARGE_INTEGER StreamSize             - bytes in stream
    LARGE_INTEGER StreamBytesTransferred - bytes transferred for stream
    DWORD dwStreamNumber                 - current stream
    DWORD dwCallbackReason               - callback reason
    HANDLE hSourceFile                   - handle to source file
    HANDLE hDestinationFile              - handle to destination file
    LPVOID lpData                        - user data, HANDLE to XLOG object

Return Value:

    PROGRESS_CONTINUE, PROGRESS_STOP, or PROGRESS_CANCEL

*/
static DWORD CALLBACK CopyFileProgressRoutine(LARGE_INTEGER TotalFileSize, LARGE_INTEGER TotalBytesTransferred, LARGE_INTEGER StreamSize, LARGE_INTEGER StreamBytesTransferred, DWORD dwStreamNumber, DWORD dwCallbackReason, HANDLE hSourceFile, HANDLE hDestinationFile, LPVOID lpData)
    {
    if(!lpData) return PROGRESS_CONTINUE;

    HANDLE hLog = (HANDLE)lpData;

    //xLog(hLog, XLL_INFO, "1: %I64d of %I64d", TotalBytesTransferred.QuadPart, TotalFileSize.QuadPart);

    if(TotalBytesTransferred.QuadPart > TotalFileSize.QuadPart)
        {
        xLog(hLog, XLL_FAIL, "Transfered more than filesize: %I64d of %I64d", TotalBytesTransferred.QuadPart, TotalFileSize.QuadPart);
        }

    if(TotalBytesTransferred.QuadPart >= TotalFileSize.QuadPart)
        {
        }

    return PROGRESS_CONTINUE;
    }

/*

Routine Description:

    Callback function used with the CopyFileEx and MoveFileWithProgress functions
    See "CopyProgressRoutine" in MSDN

Arguments:

    LARGE_INTEGER TotalFileSize          - file size
    LARGE_INTEGER TotalBytesTransferred  - bytes transferred
    LARGE_INTEGER StreamSize             - bytes in stream
    LARGE_INTEGER StreamBytesTransferred - bytes transferred for stream
    DWORD dwStreamNumber                 - current stream
    DWORD dwCallbackReason               - callback reason
    HANDLE hSourceFile                   - handle to source file
    HANDLE hDestinationFile              - handle to destination file
    LPVOID lpData                        - user data, CopyState

Return Value:

    PROGRESS_CONTINUE, PROGRESS_STOP, or PROGRESS_CANCEL

*/
static DWORD CALLBACK CancelHalfway(LARGE_INTEGER TotalFileSize, LARGE_INTEGER TotalBytesTransferred, LARGE_INTEGER StreamSize, LARGE_INTEGER StreamBytesTransferred, DWORD dwStreamNumber, DWORD dwCallbackReason, HANDLE hSourceFile, HANDLE hDestinationFile, LPVOID lpData)
    {
    if(!lpData) return PROGRESS_CONTINUE;

    CopyState *state = (CopyState*)lpData;
    HANDLE hLog = state->hLog;
    state->totalBytesTransferred = TotalBytesTransferred.QuadPart;

    //xLog(hLog, XLL_INFO, "2: %I64d of %I64d", TotalBytesTransferred.QuadPart, TotalFileSize.QuadPart);

    if(TotalBytesTransferred.QuadPart >= 1*MEGABYTE)
        {
        if(state->state == TEST_CANCELRESUME)
            {
            //return PROGRESS_STOP;
            return PROGRESS_CONTINUE;
            }
        else if(state->state == TEST_CANCELFLAG)
            {
            cancel = TRUE;
            return PROGRESS_CONTINUE;
            }
        else
            {
            return PROGRESS_CONTINUE;
            }
        }

    if(TotalBytesTransferred.QuadPart >= TotalFileSize.QuadPart)
        {
        }

    return PROGRESS_CONTINUE;
    }

/*

Routine Description:

    Callback function used with the CopyFileEx and MoveFileWithProgress functions
    See "CopyProgressRoutine" in MSDN

Arguments:

    LARGE_INTEGER TotalFileSize          - file size
    LARGE_INTEGER TotalBytesTransferred  - bytes transferred
    LARGE_INTEGER StreamSize             - bytes in stream
    LARGE_INTEGER StreamBytesTransferred - bytes transferred for stream
    DWORD dwStreamNumber                 - current stream
    DWORD dwCallbackReason               - callback reason
    HANDLE hSourceFile                   - handle to source file
    HANDLE hDestinationFile              - handle to destination file
    LPVOID lpData                        - user data, CopyState

Return Value:

    PROGRESS_CONTINUE, PROGRESS_STOP, or PROGRESS_CANCEL

*/
static DWORD CALLBACK CancelOnFirst(LARGE_INTEGER TotalFileSize, LARGE_INTEGER TotalBytesTransferred, LARGE_INTEGER StreamSize, LARGE_INTEGER StreamBytesTransferred, DWORD dwStreamNumber, DWORD dwCallbackReason, HANDLE hSourceFile, HANDLE hDestinationFile, LPVOID lpData)
    {
    if(!lpData) return PROGRESS_CONTINUE;

    CopyState *state = (CopyState*)lpData;
    HANDLE hLog = state->hLog;
    state->totalBytesTransferred = TotalBytesTransferred.QuadPart;

    if(dwCallbackReason == CALLBACK_CHUNK_FINISHED) return PROGRESS_CANCEL;
    else return PROGRESS_CONTINUE;
    }

