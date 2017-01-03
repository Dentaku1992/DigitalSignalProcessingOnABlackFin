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