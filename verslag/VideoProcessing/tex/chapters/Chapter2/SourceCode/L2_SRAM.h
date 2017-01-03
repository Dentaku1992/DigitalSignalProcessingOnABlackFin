#ifndef  __L2_DEFINED
#define __L2_DEFINED

#include "..\system.h"


/********************************************************************************/
/***** Global variables	and types											*****/
/***** All global variables are defined in main.c							*****/
/********************************************************************************/

// semaphores
extern volatile bool semaphore_frames_received;		// signals to core B that output stream can be started

extern volatile bool semaphoreResetVideo;

#endif

