#include "main.h"
#include "video.h"

#define MIN_Y  130
#define MAX_Y  180
#define MIN_CB 150
#define MIN_CR 50
#define LINEOFFSET 276/2		// 4 EAV + 268 HB + 4 SAV
#define LINELENGTH 1716/2		// ITU-R BT656 line is 1716 bytes
#define AVSTART 19
#define AVLENGTH 240
#define AVOFFSET 264

volatile short * video_frame;

short temp;
short temp2;

unsigned char Y1;
unsigned char Y2;
unsigned char Cr;
unsigned char Cb;

void process()
{
	switch(current_in_Frame)
	{
		case 0:
			video_frame = sFrame8;
			break;
		case 1:
			video_frame = sFrame8;
			break;
		case 2:
			video_frame = sFrame8;
			break;
		case 3:
			video_frame = sFrame8;
			break;
		case 4:
			video_frame = sFrame8;
			break;
		case 5:
			video_frame = sFrame8;
			break;
		case 6:
			video_frame = sFrame8;
			break;
		case 7:
			video_frame = sFrame8;
			break;
		case 8:
			video_frame = sFrame16;
			break;
		case 9:
			video_frame = sFrame16;
			break;
		case 10:
			video_frame = sFrame16;
			break;
		case 11:
			video_frame = sFrame16;
			break;
		case 12:
			video_frame = sFrame16;
			break;
		case 13:
			video_frame = sFrame16;
			break;
		case 14:
			video_frame = sFrame16;
			break;
		case 15:
			video_frame = sFrame16;
			break;
		case 16:
			video_frame = sFrame24;
			break;
		case 17:
			video_frame = sFrame24;
			break;
		case 18:
			video_frame = sFrame24;
			break;
		case 19:
			video_frame = sFrame24;
			break;
		case 20:
			video_frame = sFrame24;
			break;
		case 21:
			video_frame = sFrame24;
			break;
		case 22:
			video_frame = sFrame24;
			break;
		case 23:
			video_frame = sFrame24;
			break;
		case 24:
			video_frame = sFrame0;
			break;
		case 25:
			video_frame = sFrame0;
			break;
		case 26:
			video_frame = sFrame0;
			break;
		case 27:
			video_frame = sFrame0;
			break;
		case 28:
			video_frame = sFrame0;
			break;
		case 29:
			video_frame = sFrame0;
			break;
		case 30:
			video_frame = sFrame0;
			break;
		case 31:
			video_frame = sFrame0;
			break;
	}
	int i =0;
	int j = 0;
	for( i=AVSTART; i<AVSTART+AVLENGTH; i++)
	{
		for( j=LINEOFFSET; j<LINELENGTH; j+=2)
		{
			//AVF odd
			Y1 = (video_frame[i*LINELENGTH+j] >> 8) & 0x00FF;
			Y2 = (video_frame[i*LINELENGTH+j+1] >> 8) & 0x00FF;
			Cb = (video_frame[i*LINELENGTH+j]) & 0x00FF;
			Cr = (video_frame[i*LINELENGTH+j+1]) & 0x00FF;

			if(Cb > MIN_CB && Cr > MIN_CR)
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

			//AVF even
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

