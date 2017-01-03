void process()
{
	Y1 = (sFrame0[PIXEL] >> 8) & 0x00FF;
	Y2 = (sFrame0[PIXEL+1] >> 8) & 0x00FF;
	Cb = (sFrame0[PIXEL]) & 0x00FF;
	Cr = (sFrame0[PIXEL+1]) & 0x00FF;

	if(Y1 >= 130 && Y1 <= 180 && Cb > 150 && Cr > 50)
	{
		sFrame0[PIXEL] = 0xEB28;	
		sFrame0[PIXEL+1] = 0xEB98;
	}

	if(Y2 >= 130 && Y2 <= 180 && Cb > 150 && Cr > 50)
	{
		sFrame0[PIXEL] = 0xEB28;	
		sFrame0[PIXEL+1] = 0xEB98;		
	}
}