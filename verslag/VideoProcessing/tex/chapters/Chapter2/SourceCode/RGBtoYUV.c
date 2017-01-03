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