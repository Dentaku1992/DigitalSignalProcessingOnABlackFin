#include "video.h"
#include "main.h"

static char videoReadyFlag;

short data; //temp 
short data2; // temp

int a = 0;
int b =LINES_PER_FRAME;
short color = 0xFF00;

void videoReady()
{
	videoReadyFlag = 1;
}