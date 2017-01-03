#define AVLENGTH1 240
#define AVLENGTH2 240
#define AVSTART1 19
#define AVSTART2 281

#define LINEOFFSET 276/2		// 4 EAV + 268 HB + 4 SAV
#define LINELENGTH 1716/2		// ITU-R BT656 line is 1716 bytes

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
		case 3:
			video_frame = sFrame3;
			break;
	}

	for(int avField = 0; avField<2; avField++)
	{
		for(int i=((avField==0)?AVSTART1:AVSTART2); i<((avField==0)?AVSTART1:AVSTART2)+((avField==0)?AVLENGTH1:AVLENGTH2); i++)
		{
			for(int j=LINEOFFSET; j<LINELENGTH; j+=2)
			{
				char[][] rgb = YUVtoRGB(video_frame[i*LINELENGTH+j], video_frame[i*LINELENGTH+j+1]);
				if(IsSmurfBlue(rgb[0])
					rgb[0] = ReplaceBlueWithYellow(rgb[0]);
				if(IsSmurfBlue(rgb[1])
					rgb[1] = ReplaceBlueWithYellow(rgb[1]);
				short[] yuv = RGBtoYUV(rgb);
				video_frame[i*LINELENGTH+j] = yuv[0];
				video_frame[i*LINELENGTH+j+1] = yuv[1];
			}
		}
	}
}

bool IsSmurfBlue(char[] rgb)
{
	if( rgb[0] > 60 && rgb[0] < 80 )
		if( rgb[1] > 160 && rgb[1] < 180 )
			if( rgb[2] > 240 )
				return true;

	return false;
}

char[] ReplaceBlueWithYellow(char[] rgb)
{
	rgb[0] = 255;
	rgb[1] = 255;
	rgb[2] = 0;

	return rgb;
}


char[][] YUVtoRGB(short CbY, short CrY)
{
	//First RGB by using Y from CbY
	char R1 = 1.164*( (CbY&0x00FF) - 16)
			+ 1.596*( ((CrY>>8)&0x00FF) - 128);
	char G1 = 1.164*( (CbY&0x00FF) - 16)
			- 0.813*( ((CrY>>8)&0x00FF) - 128)
			- 0.391*( ((CbY>>8)&0x00FF) - 128);
	char B1 = 1.164*( (CbY&0x00FF) - 16)
			+ 2.018*( ((CbY>>8)&0x00FF) - 128);
	
	//Second RGB by using Y from CrY
	char R2 = 1.164*( (CrY&0x00FF) - 16)
			+ 1.596*( ((CrY>>8)&0x00FF) - 128);
	char G2 = 1.164*( (CrY&0x00FF) - 16)
			- 0.813*( ((CrY>>8)&0x00FF) - 128)
			- 0.391*( ((CbY>>8)&0x00FF) - 128);
	char B2 = 1.164*( (CrY&0x00FF) - 16)
			+ 2.018*( ((CbY>>8)&0x00FF) - 128);

	return char[][] { {R1, G1, B1} , {R2, G2, B2} };
}

short[] RGBtoYUV(char[][] RGB)
{
	char Y1 = 16 + 0.257*RGB[0][0] + 0.504*RGB[0][1] + 0.098*RGB[0][2];
	char Cb = 128- 0.148*RGB[0][0] - 0.291*RGB[0][1] + 0.439*RGb[0][2];

	char Y2 = 16 + 0.257*RGB[1][0] + 0.504*RGB[1][1] + 0.098*RGB[1][2];
	char Cr = 128+ 0.439*RGB[1][0] - 0.368*RGB[1][1] - 0.071*RGb[1][2];

	short CbY = Cb;
	CbY = CbY << 8;
	CbY = CbY + Y1;

	short CrY = Cr;
	CrY = CrY << 8;
	CrY = CrY + Y1;

	return short[] {CbY, CrY};
}