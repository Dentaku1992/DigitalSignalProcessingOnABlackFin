

#include "L2_SRAM.h"


// semaphores in shared memory

volatile bool semaphore_frames_received = false;	// signals to core B that output stream can be started
													// makes sure that output stream is on valid frames

volatile bool semaphoreResetVideo = false;          // signals to core B to reset video DMA
