#include "main.h"
#include "video.h";

#define V480
#define MIN_Y  130
#define MAX_Y  180
#define MIN_CB 150
#define MIN_CR 50
#define LINEOFFSET 276/2		// 4 EAV + 268 HB + 4 SAV
#define LINELENGTH 1716/2		// ITU-R BT656 line is 1716 bytes

volatile short * video_frame;

short temp;
short temp2;

unsigned char Y1;
unsigned char Y2;
unsigned char Cr;
unsigned char Cb;
unsigned char toggle = 0;

void process()
{
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
		case 3:
			video_frame = sFrame3;
			break;
		case 4:
			video_frame = sFrame4;
			break;
		case 5:
			video_frame = sFrame5;
			break;
		case 6:
			video_frame = sFrame6;
			break;
		case 7:
			video_frame = sFrame7;
			break;
		case 8:
			video_frame = sFrame8;
			break;
		case 9:
			video_frame = sFrame9;
			break;
		case 10:
			video_frame = sFrame10;
			break;
		case 11:
			video_frame = sFrame11;
			break;
		case 12:
			video_frame = sFrame12;
			break;
		case 13:
			video_frame = sFrame13;
			break;
		case 14:
			video_frame = sFrame14;
			break;
		case 15:
			video_frame = sFrame15;
			break;
		case 16:
			video_frame = sFrame16;
			break;
		case 17:
			video_frame = sFrame17;
			break;
		case 18:
			video_frame = sFrame18;
			break;
		case 19:
			video_frame = sFrame19;
			break;
		case 20:
			video_frame = sFrame20;
			break;
		case 21:
			video_frame = sFrame21;
			break;
		case 22:
			video_frame = sFrame22;
			break;
		case 23:
			video_frame = sFrame23;
			break;
		case 24:
			video_frame = sFrame24;
			break;
		case 25:
			video_frame = sFrame25;
			break;
		case 26:
			video_frame = sFrame26;
			break;
		case 27:
			video_frame = sFrame27;
			break;
		case 28:
			video_frame = sFrame28;
			break;
		case 29:
			video_frame = sFrame29;
			break;
		case 30:
			video_frame = sFrame30;
			break;
		case 31:
			video_frame = sFrame31;
			break;
	}

	/*
	VB  19  lines
	AV  240 lines
	VB  3   lines
	VB  20  lines
	AV  240 lines
	VB  3   lines
	   -----
	    525 lines (480 visible)
	OR

	VB  20  lines
	AV  244 lines
	VB  19  lines
	AV  242 lines
	   -----
	    525 lines (486 visible)
	*/

	#ifdef V480
		#define AVLENGTH1 240
		#define AVLENGTH2 240
		#define AVSTART1 19
		#define AVSTART2 281
	#else
		#define AVLENGTH1 244
		#define AVLENGTH2 242
		#define AVSTART1  20
		#define AVSTART2  282
	#endif

	int avField = 0;
	int i = 0;
	int j = 0;
	
	for(avField = 0; avField<2; avField++)
	{
		for(i=((avField==0)?AVSTART1:AVSTART2); i<((avField==0)?AVSTART1:AVSTART2)+((avField==0)?AVLENGTH1:AVLENGTH2); i++)
		{
			for(j=LINEOFFSET; j<LINELENGTH; j+=2)
			{
				
				//AV Field 1
				Y1 = (video_frame[i*LINELENGTH+j] >> 8) & 0x00FF;
				Y2 = (video_frame[i*LINELENGTH+j+1] >> 8) & 0x00FF;
				Cb = (video_frame[i*LINELENGTH+j]) & 0x00FF;
				Cr = (video_frame[i*LINELENGTH+j+1]) & 0x00FF;
				
			    if(Y1 >= MIN_Y && Y1 <= MAX_Y && Cb > MIN_CB && Cr > MIN_CR)
				{
					video_frame[i*LINELENGTH+j] = 0xEB28;	
					video_frame[i*LINELENGTH+j+1] = 0xEB98;
				}
				
				if(Y2 >= MIN_Y && Y2 <= MAX_Y && Cb > MIN_CB && Cr > MIN_CR)
				{
					video_frame[i*LINELENGTH+j] = 0xEB28;	
					video_frame[i*LINELENGTH+j+1] = 0xEB98;		
				}
				
				//AV Field 2
				Y1 = (video_frame[i*LINELENGTH+j+262*LINELENGTH] >> 8) & 0x00FF;
				Y2 = (video_frame[i*LINELENGTH+j+1+262*LINELENGTH] >> 8) & 0x00FF;
				Cb = (video_frame[i*LINELENGTH+j+262*LINELENGTH]) & 0x00FF;
				Cr = (video_frame[i*LINELENGTH+j+1+262*LINELENGTH]) & 0x00FF;
				
			    if(Y1 >= MIN_Y && Y1 <= MAX_Y && Cb > MIN_CB && Cr > MIN_CR)
				{
					video_frame[i*LINELENGTH+j+262*LINELENGTH] = 0xEB28;	
					video_frame[i*LINELENGTH+j+1+262*LINELENGTH] = 0xEB98;
				}
				
				if(Y2 >= MIN_Y && Y2 <= MAX_Y && Cb > MIN_CB && Cr > MIN_CR)
				{
					video_frame[i*LINELENGTH+j+262*LINELENGTH] = 0xEB28;	
					video_frame[i*LINELENGTH+j+1+262*LINELENGTH] = 0xEB98;	
				}	
			}
		}
	}
}

