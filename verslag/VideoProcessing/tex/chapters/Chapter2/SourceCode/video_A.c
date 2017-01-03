#include "main.h"
#include "video.h";

#define MIN_Y  130
#define MAX_Y  180
#define MIN_CB 150
#define MIN_CR 50
#define MAX_CR 100

#define LINEOFFSET 276/2		// 4 EAV + 268 HB + 4 SAV
#define LINELENGTH 1716/2		// ITU-R BT656 line is 1716 bytes

#define AVLENGTH 240
#define AVSTART 19
#define AVSOFFSET 262

void process()
{
	volatile short * video_frame;

	switch(current_in_Frame)
	{
		case 0:
			video_frame = sFrame0;
			break;
		case 1:
			video_frame = sFrame1;
			break;
		case 2:
			video_frame = sFrame2;
			break;
			/*
			...
			*/
		case 31:
			video_frame = sFrame31;
			break;
	}

	unsigned char Y1, Y2, Cr, Cb;
	int i, j;

	for(i=AVSTART; i<AVSTART+AVLENGTH; i++)
	{
		for(j=LINEOFFSET; j<LINELENGTH; j+=2)
		{
			Y1 = (video_frame[i*LINELENGTH+j] >> 8) & 0x00FF;
			Y2 = (video_frame[i*LINELENGTH+j+1] >> 8) & 0x00FF;
			Cb = (video_frame[i*LINELENGTH+j]) & 0x00FF;
			Cr = (video_frame[i*LINELENGTH+j+1]) & 0x00FF;

			if(Cb > MIN_CB && Cr > MIN_CR && Cr < MAX_CR)
			{
				if(Y1 >= MIN_Y && Y1 <= MAX_Y)
				{
					video_frame[i*LINELENGTH+j] = 0xEB28;
					video_frame[i*LINELENGTH+j+1] = 0xEB98;
				}

				if(Y2 >= MIN_Y && Y2 <= MAX_Y)
				{
					video_frame[i*LINELENGTH+j] = 0xEB28;
					video_frame[i*LINELENGTH+j+1] = 0xEB98;
				}
			}
			
		    Y1 = (video_frame[(i+AVOFFSET)*LINELENGTH+j] >> 8) & 0x00FF;
			Y2 = (video_frame[(i+AVOFFSET)*LINELENGTH+j+1] >> 8) & 0x00FF;
			Cb = (video_frame[(i+AVOFFSET)*LINELENGTH+j]) & 0x00FF;
			Cr = (video_frame[(i+AVOFFSET)*LINELENGTH+j+1]) & 0x00FF;

			if(Cb > MIN_CB && Cr > MIN_CR)
			{
				if(Y1 >= MIN_Y && Y1 <= MAX_Y)
				{
					video_frame[(i+AVOFFSET)*LINELENGTH+j] = 0xEB28;
					video_frame[(i+AVOFFSET)*LINELENGTH+j+1] = 0xEB98;
				}

				if(Y2 >= MIN_Y && Y2 <= MAX_Y)
				{
					video_frame[(i+AVOFFSET)*LINELENGTH+j] = 0xEB28;
					video_frame[(i+AVOFFSET)*LINELENGTH+j+1] = 0xEB98;
				}
			}
		}
	}
}

