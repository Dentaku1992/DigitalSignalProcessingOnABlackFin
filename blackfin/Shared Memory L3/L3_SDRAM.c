#include "L3_SDRAM.h"

// Define the DMA buffers for each frame.
// Because of SDRAM performance, each frame must be in a different bank.
// The placement in different banks is obtained by creating seperate memory bank placements in the ldf file! 
//The NO_INIT pragma, avoids the memory initialization on a program load, reducing the executable loading time.

#pragma section("frame_buffer0",NO_INIT)
volatile short sFrame0[Frame_Size];
#pragma section("frame_buffer1",NO_INIT)
volatile short sFrame1[Frame_Size];
#pragma section("frame_buffer2",NO_INIT)
volatile short sFrame2[Frame_Size];
#pragma section("frame_buffer3",NO_INIT)
volatile short sFrame3[Frame_Size];
#pragma section("frame_buffer4",NO_INIT)
volatile short sFrame4[Frame_Size];
#pragma section("frame_buffer5",NO_INIT)
volatile short sFrame5[Frame_Size];
#pragma section("frame_buffer6",NO_INIT)
volatile short sFrame6[Frame_Size];
#pragma section("frame_buffer7",NO_INIT)
volatile short sFrame7[Frame_Size];
#pragma section("frame_buffer8",NO_INIT)
volatile short sFrame8[Frame_Size];
#pragma section("frame_buffer9",NO_INIT)
volatile short sFrame9[Frame_Size];
#pragma section("frame_buffer10",NO_INIT)
volatile short sFrame10[Frame_Size];
#pragma section("frame_buffer11",NO_INIT)
volatile short sFrame11[Frame_Size];
#pragma section("frame_buffer12",NO_INIT)
volatile short sFrame12[Frame_Size];
#pragma section("frame_buffer13",NO_INIT)
volatile short sFrame13[Frame_Size];
#pragma section("frame_buffer14",NO_INIT)
volatile short sFrame14[Frame_Size];
#pragma section("frame_buffer15",NO_INIT)
volatile short sFrame15[Frame_Size];
#pragma section("frame_buffer16",NO_INIT)
volatile short sFrame16[Frame_Size];
#pragma section("frame_buffer17",NO_INIT)
volatile short sFrame17[Frame_Size];
#pragma section("frame_buffer18",NO_INIT)
volatile short sFrame18[Frame_Size];
#pragma section("frame_buffer19",NO_INIT)
volatile short sFrame19[Frame_Size];
#pragma section("frame_buffer20",NO_INIT)
volatile short sFrame20[Frame_Size];
#pragma section("frame_buffer21",NO_INIT)
volatile short sFrame21[Frame_Size];
#pragma section("frame_buffer22",NO_INIT)
volatile short sFrame22[Frame_Size];
#pragma section("frame_buffer23",NO_INIT)
volatile short sFrame23[Frame_Size];
#pragma section("frame_buffer24",NO_INIT)
volatile short sFrame24[Frame_Size];
#pragma section("frame_buffer25",NO_INIT)
volatile short sFrame25[Frame_Size];
#pragma section("frame_buffer26",NO_INIT)
volatile short sFrame26[Frame_Size];
#pragma section("frame_buffer27",NO_INIT)
volatile short sFrame27[Frame_Size];
#pragma section("frame_buffer28",NO_INIT)
volatile short sFrame28[Frame_Size];
#pragma section("frame_buffer29",NO_INIT)
volatile short sFrame29[Frame_Size];
#pragma section("frame_buffer30",NO_INIT)
volatile short sFrame30[Frame_Size];
#pragma section("frame_buffer31",NO_INIT)
volatile short sFrame31[Frame_Size];
///TOT HIER
volatile bool semaphore_frames_received;		// signals to core B that output stream can be started
volatile bool semaphoreResetVideo;
volatile unsigned char frameNumberToSend;