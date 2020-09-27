// NT client IOCTLs

// NV graphics device driver string
#define NVRM_NAME_STRING L"\\Device\\nvgfx"
#define NVRM_LINK_STRING L"\\DosDevices\\nvgfx"

// device type and base control code
#define FILE_DEVICE_NVRM 	0x00008000
#define NVRM_IOCTL_INDEX 	0x00000800
#define NV_IOCTL_CODE(f)		  	\
	CTL_CODE(                   	\
		FILE_DEVICE_NVRM+(f),   	\
		NVRM_IOCTL_INDEX,     		\
		METHOD_BUFFERED,        	\
		FILE_ANY_ACCESS         	\
	)

// control codes
#define NV1_IOCTL_GET_DEVICE_OS_NAME		NV_IOCTL_CODE(0x0001)
//#define NV1_IOCTL_FREE  					NV_IOCTL_CODE(NV1_FREE)
#define NV1_IOCTL_ALLOC_CONTEXT_DMA  		NV_IOCTL_CODE(0x0002)
#define NV1_IOCTL_FREE_CONTEXT_DMA  		NV_IOCTL_CODE(0x0003)
#define NV3_IOCTL_ALLOC_CHANNEL_PIO  		NV_IOCTL_CODE(0x0008)
#define NV3_IOCTL_FREE_CHANNEL_PIO  		NV_IOCTL_CODE(0x0009)
#define NV3_IOCTL_ALLOC_CHANNEL_DMA  		NV_IOCTL_CODE(0x0007)
//#define NV3_IOCTL_ALLOC_CHANNEL_DMA  		NV_IOCTL_CODE(NV3_ALLOC_CHANNEL_DMA)
#define NV3_IOCTL_FREE_CHANNEL_DMA  		NV_IOCTL_CODE(0x000B)
#define NV3_IOCTL_DMA_FLOW_CONTROL  		NV_IOCTL_CODE(0x00FF)
//#define NV3_IOCTL_DMA_FLOW_CONTROL  		NV_IOCTL_CODE(NV3_DMA_FLOW_CONTROL)
#define NV1_IOCTL_ALLOC_MEMORY  			NV_IOCTL_CODE(0x000E)
#define NV1_IOCTL_FREE_MEMORY  				NV_IOCTL_CODE(0x000F)
