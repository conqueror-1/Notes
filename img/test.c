#include "stdio.h"
#include "stdlib.h"

int main(void)
{
	FILE *streamIn;
	streamIn = fopen ("./time.bmp","r");

	unsigned char header[54];
	unsigned char colorTable[1024];

	int i;	

	for (i = 0; i < 54; i++)
		header[i] = getc(streamIn);
	
	int width = *(int*)&header[18];
	int height = *(int*)&header[22];
	int bitDepth = *(int*)&header[28];

	if (bitDepth <= 8)
		fread (colorTable,sizeof(unsigned char),1024, streamIn);

	unsigned char buf[height*width];

	fread(buf,sizeof(unsigned char),(height*width),streamIn);

	FILE *fo = fopen("./new.bmp","wb");

	fwrite(header,sizeof(unsigned char), 54, fo);

	if (bitDepth <= 8)
		fwrite(colorTable,sizeof(unsigned char),1024,fo);

	fwrite(buf,sizeof(unsigned int),(height*width),fo);

	fclose(fo);
	fclose(streamIn);

	return 0;
}
