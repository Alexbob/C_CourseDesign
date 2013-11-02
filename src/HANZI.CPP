#include "head\\common.h"
#include "head\\hanzi.h"


void DisChinese(char *s,int x,int y,int col,int row,int width,int color)
{
	 FILE *fp;
	 char buffer[32];
	 register m,n,i,j,k;
	 unsigned char qh,wh;
	 unsigned long offset;



	 if ((fp=fopen("HANZIKU\\hzk16","rb"))==NULL)
	 {
	  printf("Can't open haz16,Please add it");
	  getch();
	  closegraph();
	  exit(0);
	 }


	while (*s)
	{

	 qh=*(s)-0xa0;
	 wh=*(s+1)-0xa0;
	 offset=(94*(qh-1)+(wh-1))*32L;

	 fseek(fp,offset,SEEK_SET);
	 fread(buffer,32,1,fp);

	 for(i=0;i<16;i++)
        for(n=0;n<row;n++)
            for(j=0;j<2;j++)
                for(k=0;k<8;k++)
                    for(m=0;m<col;m++)
                     if (((buffer[i*2+j]>>(7-k))&0x01)!=NULL)
                     {
                        putpixel(x+8*j*col+k*col+m,y+i*row+n,color);
                     }
                     s+=2;
                     x+=(8*1*col+col+width);
	 }
	 fclose(fp);
}

