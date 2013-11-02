#include "head\\common.h"
#include "head\\bmp.h"
#include "head\\mouse.h"
#include "head\\furni.h"



void ShowFurni(Furni *pfur)
{
    FILE *fp;

    long x;
    long y;

    long Height;
    long Width;

    long WBytes;
    long DataOffset;

    unsigned char SrcData,data;

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;



    int winLeft,winTop,winWidth,winHeight;
    winLeft=pfur->x;
    winTop=pfur->y;
    winWidth=pfur->wid;
    winHeight=pfur->len;


    if((fp=fopen(pfur->path,"rb"))==NULL)
    {
        closegraph();
        printf("%s cannot open\n",pfur->path);
        printf("Press any key to halt...");
        getch();
        exit(1);
    }

    HideMouse();

    fseek(fp,0L,SEEK_SET);


    fread(&bfh,sizeof(BITMAPFILEHEADER),1,fp);

    fread(&bih,sizeof(BITMAPINFOHEADER),1,fp);



    if(bfh.bfType!='M'*256+'B' || bih.biBitCount!=4)
    {
		closegraph();
        printf("%s is not a 16 color file\n",pfur->path);
        printf("Press any key to halt...");
        getch();
        exit(1);
    }


    WBytes=(bih.biWidth*bih.biBitCount+31)/8;
    WBytes=(WBytes/4)*4;

    Width=bih.biWidth<winWidth ? bih.biWidth : winWidth;
    Height=bih.biHeight<winHeight ?    bih.biHeight : winHeight;

    DataOffset=118;

    if(bih.biHeight > winHeight)
    {
        DataOffset+=(bih.biHeight-winHeight)*WBytes;
    }


    for(y=0; y<Height; y++)
    {
        fseek(fp, DataOffset+y*WBytes, SEEK_SET);


        for(x=0; x<Width; x+=2)
         {
            fread(&SrcData,1,1,fp);

            if( (data=SrcData/16) != WHITE)
            {
                putpixel(winLeft+x,winTop+Height-y-1,data);
            }
            if( (data=SrcData%16) != WHITE)
            {
                putpixel(winLeft+x+1,winTop+Height-y-1,data);
            }
        }
    }

    fclose(fp);
    ShowMouse();

}
