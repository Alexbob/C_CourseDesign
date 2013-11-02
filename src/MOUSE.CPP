#include "head\\common.h"
#include "head\\mouse.h"



void ShowMouse()
{
	UpdateMouse(1);
}



void HideMouse()
{
	UpdateMouse(0);
}



Mouse ReadMouse()
{
	Mouse m;
	union REGS regs;
	regs.x.ax=3;
	int86(0x33,&regs,&regs);
	m.b=regs.x.bx;
	m.x=regs.x.cx;
	m.y=regs.x.dx;
	return m;
}


void UpdateMouse(int show_flag)
{
	int i,j,px,py;
    static int old_x,old_y;
    static int savimage[16][16];
    static int flag=1;
    int x,y;
    int mose_pot[1][16]=
    {
        0x3fff,0x1fff,0x0fff,0x07ff,/*  arrow¼ýÍ· */
        0x03ff,0x01ff,0x00ff,0x007f,
        0x003f,0x00ff,0x01ff,0x10ff,
        0x30ff,0xf87f,0xf87f,0xfc3f,
    };


    Mouse m;
    m=ReadMouse();
    x=m.x;
    y=m.y;


    if(flag==1)
    {
          old_x=x;
          old_y=y;
          for(i=0,py=y;i<16;i++,py++)
           {
               for(j=0,px=x;j<16;j++,px++)
               {
                    savimage[i][j]=getpixel(px,py);
               }
           }
         flag=0;
    }


    if( show_flag==1 )
    {
        if(  (x!=old_x)||(y!=old_y)  )
        {
                for(i=0;i<16;i++)
                {
                    for(j=0;j<16;j++)
                        {
                              if( !((mose_pot[0][i]>>(15-j))&1==1) )
                              {
                                  putpixel(old_x+j,old_y+i,savimage[i][j]);
                              }
                        }
                }

              for(i=0,py=y;i<16;i++,py++)
               {
                   for(j=0,px=x;j<16;j++,px++)
                   {
                        savimage[i][j]=getpixel(px,py);
                   }
               }

              for(i=0;i<16;i++)
              {
                    for(j=0;j<16;j++)
                    {
                        if( !((mose_pot[0][i]>>(15-j))&1==1) )
                        {
                                putpixel(x+j,y+i,GREEN);
                        }
                    }
              }
        }
    }


    if( show_flag==0 )
    {
        for(i=0;i<16;i++)
        {
            for(j=0;j<16;j++)
                {
                    if( !((mose_pot[0][i]>>(15-j))&1==1) )
                        putpixel(x+j,y+i,savimage[i][j]);
                }
        }
       flag=1;
    }
    old_x=x;
    old_y=y;
}


void InitMouse( )
{
    union REGS regs;
    int retcode;
    regs.x.ax=0;
    int86(51,&regs,&regs);
    retcode=regs.x.ax;
    if(retcode==0)
    {
       printf("Mouse or Mouse Driver Absent,P1ease install!");
       delay(5000);
       exit(1);
    }
    regs.x.ax=7;
    regs.x.cx=1;
    regs.x.dx=639;
    int86(51,&regs,&regs);
    regs.x.ax=8;
    regs.x.cx=1;
    regs.x.dx=479;
    int86(51,&regs,&regs);
}



int  MouseIn(int x1,int y1,int x2,int y2)
{
	int mouse_flag=0;
	Mouse m;
	m=ReadMouse();
	if( (x1<m.x) && (m.x<x2) && (m.y>y1) && (m.y<y2) )
	{
		mouse_flag=1;
	}
	return mouse_flag;
}



