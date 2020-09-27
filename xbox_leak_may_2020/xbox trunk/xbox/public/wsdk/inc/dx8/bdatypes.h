//+---------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1999-2000
//
//  File: bdatypes.h
//
//  Typedefs and enums needed by both the wdm drivers and the
//  user mode com interfaces
//
//----------------------------------------------------------------------------

#ifndef _BDATYPES_

#define _BDATYPES_      1

/* Utility Macros */

#define MIN_DIMENSION   1
#define NATURAL     4
#define CACHE_LINE  128
#define PAGE        4096
#define ALIGN( pointer, size) (((ULONG)(pointer) + (ULONG)(size) - 1) & ~((ULONG)(size) - 1))
#define BDA_STRING_CONST(x)   {sizeof(L##x)-2, sizeof(L##x), L##x}


#ifdef __midl
#define V1_ENUM [v1_enum]
#else
#define V1_ENUM
#endif

//===========================================================================
//
//  BDA Topology Structures
//
//===========================================================================

typedef struct _BDA_TEMPLATE_CONNECTION
{
    ULONG   FromNodeType;
    ULONG   FromNodePinType;
    ULONG   ToNodeType;
    ULONG   ToNodePinType;
}BDA_TEMPLATE_CONNECTION, *PBDA_TEMPLATE_CONNECTION;


typedef struct _BDA_TEMPLATE_PIN_JOINT
{
    ULONG   uliTemplateConnection;
    ULONG   ulcInstancesMax;
}BDA_TEMPLATE_PIN_JOINT, *PBDA_TEMPLATE_PIN_JOINT;



//===========================================================================
//
//  BDA Events
//
//===========================================================================

//  In-band Event IDs
//
typedef enum {
    BDA_EVENT_SIGNAL_LOSS = 0,
    BDA_EVENT_SIGNAL_LOCK,
    BDA_EVENT_DATA_START,
    BDA_EVENT_DATA_STOP,
    BDA_EVENT_CHANNEL_ACQUIRED,
    BDA_EVENT_CHANNEL_LOST,
    BDA_EVENT_CHANNEL_SOURCE_CHANGED,
    BDA_EVENT_CHANNEL_ACTIVATED,
    BDA_EVENT_CHANNEL_DEACTIVATED,
    BDA_EVENT_SUBCHANNEL_ACQUIRED,
    BDA_EVENT_SUBCHANNEL_LOST,
    BDA_EVENT_SUBCHANNEL_SOURCE_CHANGED,
    BDA_EVENT_SUBCHANNEL_ACTIVATED,
    BDA_EVENT_SUBCHANNEL_DEACTIVATED,
    BDA_EVENT_ACCESS_GRANTED,
    BDA_EVENT_ACCESS_DENIED,
    BDA_EVENT_OFFER_EXTENDED,
    BDA_EVENT_PURCHASE_COMPLETED,
    BDA_EVENT_SMART_CARD_INSERTED,
    BDA_EVENT_SMART_CARD_REMOVED
} BDA_EVENT_ID, *PBDA_EVENT_ID;



//===========================================================================
//
//  KSSTREAM_HEADER extensions for BDA
//
//===========================================================================

typedef struct tagKS_BDA_FRAME_INFO {
    ULONG                   ExtendedHeaderSize; // Size of this extended header
    DWORD                   dwFrameFlags;  //
    ULONG                   ulEvent; //
    ULONG                   ulChannelNumber; //
    ULONG                   ulSubchannelNumber; //
    ULONG                   ulReason; //
} KS_BDA_FRAME_INFO, *PKS_BDA_FRAME_INFO;


//------------------------------------------------------------
//
//  BDA Network Ethernet Filter Property Set
//
// {71985F43-1CA1-11d3-9CC8-00C04F7971E0}
//
typedef struct _BDA_ETHERNET_ADDRESS {
    BYTE    rgbAddress[6];
} BDA_ETHERNET_ADDRESS, *PBDA_ETHERNET_ADDRESS;

typedef struct _BDA_ETHERNET_ADDRESS_LIST {
    ULONG               ulcAddresses;
    BDA_ETHERNET_ADDRESS    rgAddressl[MIN_DIMENSION];
} BDA_ETHERNET_ADDRESS_LIST, * PBDA_ETHERNET_ADDRESS_LIST;

typedef enum {
    BDA_PROMISCUOUS_MULTICAST = 0,
    BDA_FILTERED_MULTICAST,
    BDA_NO_MULTICAST
} BDA_MULTICAST_MODE, *PBDA_MULTICAST_MODE;


//------------------------------------------------------------
//
//  BDA Network IPv4 Filter Property Set
//
// {71985F44-1CA1-11d3-9CC8-00C04F7971E0}
//
typedef struct _BDA_IPv4_ADDRESS {
    BYTE    rgbAddress[4];
} BDA_IPv4_ADDRESS, *PBDA_IPv4_ADDRESS;

typedef struct _BDA_IPv4_ADDRESS_LIST {
    ULONG               ulcAddresses;
    BDA_IPv4_ADDRESS    rgAddressl[MIN_DIMENSION];
} BDA_IPv4_ADDRESS_LIST, * PBDA_IPv4_ADDRESS_LIST;


//------------------------------------------------------------
//
//  BDA Network IPv4 Filter Property Set
//
// {E1785A74-2A23-4fb3-9245-A8F88017EF33}
//
typedef struct _BDA_IPv6_ADDRESS {
    BYTE    rgbAddress[6];
} BDA_IPv6_ADDRESS, *PBDA_IPv6_ADDRESS;

typedef struct _BDA_IPv6_ADDRESS_LIST {
    ULONG               ulcAddresses;
    BDA_IPv6_ADDRESS    rgAddressl[MIN_DIMENSION];
} BDA_IPv6_ADDRESS_LIST, * PBDA_IPv6_ADDRESS_LIST;


//------------------------------------------------------------
//
//
//  BDA Signal Property Set
//
//  {D2F1644B-B409-11d2-BC69-00A0C9EE9E16}
//
typedef enum {
    BDA_SIGNAL_UNAVAILABLE = 0,
    BDA_SIGNAL_INACTIVE,
    BDA_SIGNAL_ACTIVE
} BDA_SIGNAL_STATE, * PBDA_SIGNAL_STATE;


//------------------------------------------------------------
//
//
//  BDA Change Sync Method Set
//
// {FD0A5AF3-B41D-11d2-9C95-00C04F7971E0}
//
typedef enum
{
    BDA_CHANGES_COMPLETE = 0,
    BDA_CHANGES_PENDING

} BDA_CHANGE_STATE, * PBDA_CHANGE_STATE;


//------------------------------------------------------------
//
//
//  BDA Device Configuration Method Set
//
// {71985F45-1CA1-11d3-9CC8-00C04F7971E0}
//


//------------------------------------------------------------
//
//
//  BDA Topology Property Set
//
// {A14EE835-0A23-11d3-9CC7-00C04F7971E0}
//


//------------------------------------------------------------
//
//
//  BDA Void Transform Property Set
//
// {71985F46-1CA1-11d3-9CC8-00C04F7971E0}
//


//------------------------------------------------------------
//
//
//  BDA Null Transform Property Set
//
// {DDF15B0D-BD25-11d2-9CA0-00C04F7971E0}
//


//------------------------------------------------------------
//
//
//  BDA Frequency Filter Property Set
//
// {71985F47-1CA1-11d3-9CC8-00C04F7971E0}
//


//------------------------------------------------------------
//
//
//  BDA Autodemodulate Property Set
//
// {DDF15B12-BD25-11d2-9CA0-00C04F7971E0}
//


//------------------------------------------------------------
//
//
//  BDA EcmMap Property Set
//
// {FA14A8B3-6068-48ef-96DD-53010B985A7D}
//
typedef enum
{
    ECM_MAP_STATE_GOOD_FLOW = 0,
    ECM_MAP_STATE_NO_CONTENT,
    ECM_MAP_STATE_NO_ECM,
    ECM_MAP_STATE_BAD_MAP
} BDA_ECM_MAP_STATE, *PBDA_ECM_MAP_STATE;

typedef struct _BDA_ECM_MAP
{
    ULONG               ulContentPID;
    ULONG               ulEcmPID;
	ULONG               ulProgramNum;
	ULONG               ulStreamType;
    BDA_ECM_MAP_STATE   mapState;
} BDA_ECM_MAP, *PBDA_ECM_MAP;

typedef struct _BDA_ES_DESCRIPTOR
{
    ULONG               ulContentPID;
    ULONG				ulTag;
	ULONG				ulCASystemID;
    ULONG				ulcbPrivateData;
    ULONG				argbPrivateData[MIN_DIMENSION];
} BDA_ES_DESCRIPTOR, *PBDA_ES_DESCRIPTOR;

typedef struct _BDA_PROGRAM_DESCRIPTOR
{
    ULONG               ulProgramNum;
    ULONG				ulTag;
	ULONG				ulCASystemID;
    ULONG				ulcbPrivateData;
    ULONG				argbPrivateData[MIN_DIMENSION];
} BDA_PROGRAM_DESCRIPTOR, *PBDA_PROGRAM_DESCRIPTOR;


//=============================================================
//
//
//  BDA Tuning Model enumerations
//
//
//=============================================================

// system type for particular DVB Tuning Space instance
typedef enum DVBSystemType {
    DVB_Cable,
    DVB_Terrestrial,
    DVB_Satellite,
} DVBSystemType;

//------------------------------------------------------------
//
//  BDA Channel Tune Request

V1_ENUM enum {
    BDA_UNDEFINED_CHANNEL = -1,
};


//------------------------------------------------------------
//
//  BDA Component(substream)
//

typedef V1_ENUM enum ComponentCategory
{
    CategoryNotSet = -1,
    CategoryOther = 0,
    CategoryVideo,
    CategoryAudio,
    CategoryText,
    CategoryData,
} ComponentCategory;

// Component Status
typedef enum ComponentStatus
{
    StatusActive,
    StatusInactive,
    StatusUnavailable,
} ComponentStatus;


//------------------------------------------------------------
//
//  BDA MPEG2 Component Type
//
// from the MPEG2 specification
typedef V1_ENUM enum MPEG2StreamType {
    BDA_UNITIALIZED_MPEG2STREAMTYPE = -1,
    Reserved1 = 0x0,
    ISO_IEC_11172_2_VIDEO   = Reserved1 + 1,
    ISO_IEC_13818_2_VIDEO   = ISO_IEC_11172_2_VIDEO + 1,
    ISO_IEC_11172_3_AUDIO   = ISO_IEC_13818_2_VIDEO + 1,
    ISO_IEC_13818_3_AUDIO   = ISO_IEC_11172_3_AUDIO + 1,
    ISO_IEC_13818_1_PRIVATE_SECTION = ISO_IEC_13818_3_AUDIO + 1,
    ISO_IEC_13818_1_PES     = ISO_IEC_13818_1_PRIVATE_SECTION + 1,
    ISO_IEC_13522_MHEG      = ISO_IEC_13818_1_PES + 1,
    ANNEX_A_DSM_CC          = ISO_IEC_13522_MHEG + 1,
    ITU_T_REC_H_222_1       = ANNEX_A_DSM_CC + 1,
    ISO_IEC_13818_6_TYPE_A  = ITU_T_REC_H_222_1 + 1,
    ISO_IEC_13818_6_TYPE_B  = ISO_IEC_13818_6_TYPE_A + 1,
    ISO_IEC_13818_6_TYPE_C  = ISO_IEC_13818_6_TYPE_B + 1,
    ISO_IEC_13818_6_TYPE_D  = ISO_IEC_13818_6_TYPE_C + 1,
    ISO_IEC_13818_1_AUXILIARY = ISO_IEC_13818_6_TYPE_D + 1,
    ISO_IEC_13818_1_RESERVED = ISO_IEC_13818_1_AUXILIARY + 1,
    USER_PRIVATE            = ISO_IEC_13818_1_RESERVED + 1
} MPEG2StreamType;


//------------------------------------------------------------
//
//  BDA ATSC Component Type
//
//
// ATSC made AC3 Audio a descriptor instead of
// defining a user private stream type.
typedef enum ATSCComponentTypeFlags {
    // bit flags for various component type properties
    ATSCCT_AC3 = 0x00000001,
} ATSCComponentTypeFlags;


//------------------------------------------------------------
//
//  BDA Locators
//


typedef V1_ENUM enum BinaryConvolutionCodeRate {
    BDA_BCC_RATE_NOT_SET = -1,
    BDA_BCC_RATE_NOT_DEFINED = 0,
    BDA_BCC_RATE_1_2 = 1,   // 1/2
    BDA_BCC_RATE_2_3,   // 2/3
    BDA_BCC_RATE_3_4,   // 3/4
    BDA_BCC_RATE_3_5,
    BDA_BCC_RATE_4_5,
    BDA_BCC_RATE_5_6,   // 5/6
    BDA_BCC_RATE_5_11,
    BDA_BCC_RATE_7_8,   // 7/8
    BDA_BCC_RATE_MAX,
} BinaryConvolutionCodeRate;

typedef V1_ENUM enum FECMethod {
    BDA_FEC_METHOD_NOT_SET = -1,
    BDA_FEC_METHOD_NOT_DEFINED = 0,
    BDA_FEC_VITERBI = 1,          // FEC is a Viterbi Binary Convolution.
    BDA_FEC_RS_204_188,       // The FEC is Reed-Solomon 204/188 (outer FEC)
    BDA_FEC_MAX,
} FECMethod;

typedef V1_ENUM enum ModulationType {
    BDA_MOD_NOT_SET = -1,
    BDA_MOD_NOT_DEFINED = 0,
    BDA_MOD_16QAM = 1,
    BDA_MOD_32QAM,
    BDA_MOD_64QAM,
    BDA_MOD_80QAM,
    BDA_MOD_96QAM,
    BDA_MOD_112QAM,
    BDA_MOD_128QAM,
    BDA_MOD_160QAM,
    BDA_MOD_192QAM,
    BDA_MOD_224QAM,
    BDA_MOD_256QAM,
    BDA_MOD_320QAM,
    BDA_MOD_384QAM,
    BDA_MOD_448QAM,
    BDA_MOD_512QAM,
    BDA_MOD_640QAM,
    BDA_MOD_768QAM,
    BDA_MOD_896QAM,
    BDA_MOD_1024QAM,
    BDA_MOD_QPSK,
    BDA_MOD_BPSK,
    BDA_MOD_OQPSK,
    BDA_MOD_8VSB,
    BDA_MOD_16VSB,
    BDA_MOD_ANALOG_AMPLITUDE,  // std am
    BDA_MOD_ANALOG_FREQUENCY,  // std fm
    BDA_MOD_MAX,
} ModulationType;

typedef V1_ENUM enum SpectralInversion {
    BDA_SPECTRAL_INVERSION_NOT_SET = -1,
    BDA_SPECTRAL_INVERSION_NOT_DEFINED = 0,
    BDA_SPECTRAL_INVERSION_AUTOMATIC = 1,
    BDA_SPECTRAL_INVERSION_NORMAL,
    BDA_SPECTRAL_INVERSION_INVERTED,
    BDA_SPECTRAL_INVERSION_MAX
} SpectralInversion;

typedef V1_ENUM enum Polarisation {
    BDA_POLARISATION_NOT_SET = -1,
    BDA_POLARISATION_NOT_DEFINED = 0,
    BDA_POLARISATION_LINEAR_H = 1, // Linear horizontal polarisation
    BDA_POLARISATION_LINEAR_V, // Linear vertical polarisation
    BDA_POLARISATION_CIRCULAR_L, // Circular left polarisation
    BDA_POLARISATION_CIRCULAR_R, // Circular right polarisation
    BDA_POLARISATION_MAX,
} Polarisation;

typedef V1_ENUM enum GuardInterval {
    BDA_GUARD_NOT_SET = -1,
    BDA_GUARD_NOT_DEFINED = 0,
    BDA_GUARD_1_32 = 1, // Guard interval is 1/32
    BDA_GUARD_1_16, // Guard interval is 1/16
    BDA_GUARD_1_8, // Guard interval is 1/8
    BDA_GUARD_1_4, // Guard interval is 1/4
    BDA_GUARD_MAX,
} GuardInterval;

typedef V1_ENUM enum HierarchyAlpha {
    BDA_HALPHA_NOT_SET = -1,
    BDA_HALPHA_NOT_DEFINED = 0,
    BDA_HALPHA_1 = 1, // Hierarchy alpha is 1.
    BDA_HALPHA_2, // Hierarchy alpha is 2.
    BDA_HALPHA_4, // Hierarchy alpha is 4.
    BDA_HALPHA_MAX,
} HierarchyAlpha;

typedef V1_ENUM enum TransmissionMode {
    BDA_XMIT_MODE_NOT_SET = -1,
    BDA_XMIT_MODE_NOT_DEFINED = 0,
    BDA_XMIT_MODE_2K = 1, // Transmission uses 1705 carriers (use a 2K FFT)
    BDA_XMIT_MODE_8K, // Transmission uses 6817 carriers (use an 8K FFT)
    BDA_XMIT_MODE_MAX,
} TransmissionMode;

#endif // not defined _BDATYPES_

// end of file -- bdatypes.h