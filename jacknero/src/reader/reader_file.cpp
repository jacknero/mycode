#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/************************************/
/* Picture type */
/************************************/
#define COLOR_PIC 0
#define MONO_PIC 	1

/**************************************/
/* Pixel tyep */
/**************************************/
#define BIN_PIC		0
#define UBYTE_PIC	1 //unsigned char
#define USHORT_PIC	2 //unsigned short
#define UINT_PIC	3 //unsigned int
#define FLOAT_PIC	4 //float
#define DOUBLE_PIC	5 //double
#define SBYTE_PIC	6 //signed char
#define SSHORT_PIC	7 //signed short
#define SINT_PIC    8 //signed int

#define PIC_LENGTH	4

int main()
{
	FILE* pFile;
	short x_len;
	short y_len;
	short pixel_type;
	short pic_type;
	unsigned char buf[PIC_LENGTH];
	unsigned char buf1[2];
	unsigned char buf2[1];
	unsigned char buf3[2];
	 char buf4;
	char endian;

	pFile = fopen("lung0001.pic", "rb");
 	fread(buf, PIC_LENGTH, 1,pFile); 
	x_len = (short)atoi((const char*)buf);
	printf("%4d\n",x_len);

	fread(buf, PIC_LENGTH, 1,pFile); 
	y_len = (short)atoi((const char*)buf);
	printf("%x\n",y_len);

	fread(buf, 2, 1,pFile);
	memcpy(buf1,buf,2);
	pixel_type = (short)atoi((const char*)buf1);
	printf("%2d",pixel_type);


	fread(buf, 1, 1,pFile);
	memcpy(buf2,buf,1);
	pic_type = (short)atoi((const char*)buf2);
	printf("%2d\n",pic_type);
	fclose(pFile);

	fread(buf, 2, 1,pFile);
	printf("%X",(int)(unsigned char)buf);
	memcpy(buf3,buf,1);
	

	fclose(pFile);

	return 0;
}