#ifndef _BMP_H_
#define _BMP_H_

#include "head\\furni.h"

typedef struct tagBITMAPFILEHEADER
{
    unsigned int bfType;
    unsigned long bfSize;
    unsigned int bfReserved1;
    unsigned int bfReserved2;
    unsigned long bfOffBits;
}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
    unsigned long biSize;
    long biWidth;
    long biHeight;
    unsigned int biPanes;
    unsigned int biBitCount;
    unsigned long biCompression;
    unsigned long biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
}BITMAPINFOHEADER;

typedef struct tagRGBQUAD
{
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
}RGBQUAD;


void ShowFurni(Furni *pfur);

#endif
