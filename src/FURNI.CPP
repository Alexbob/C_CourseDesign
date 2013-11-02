#include "head\\common.h"
#include "head\\furni.h"
#include "head\\mouse.h"
#include "head\\key.h"

int ChooseFurni(Furni *p)
{
	Mouse m;
	char flag=0;
	m=ReadMouse();
	if((m.x > p->x)&&(m.x < p->x+p->wid)&&(m.y < p->y+p->len)&&(m.y > p->y))
	{
		flag=1;
	}
	return flag;
}

void OutFurni(Furni *p)
{
	Mouse m;
	setcolor(MAGENTA);
	setlinestyle(DOTTED_LINE,1,0);
	rectangle(p->x,p->y,p->x+p->wid,p->y+p->len);
	m=ReadMouse();
	while (ChooseFurni(p))
	{
	    CheckKeyboard(p);
	    ShowMouse();
		m=ReadMouse();
		if(m.b!=0)
		{
		    HideMouse();
			break;
		}
	}
	setlinestyle(0,1,0);
	setcolor(WHITE);
	rectangle(p->x,p->y,p->x+p->wid,p->y+p->len);
}


int FurniOnFlooor(Furni *p)
{
	int flag=0;
	int x1,y1,x2,y2;
	x1=p->x;
	y1=p->y;
	x2=p->x+p->wid;
	y2=p->y+p->len;
	if((x1> 0)&&(x2 < 639)&&(y2 < 450)&&(15*y1+8*x1-4653>0)&&(8*x2-17*y1+153<0))
	{
			flag=1;
	}
	return flag;

}


void MoveFurni(Furni *p,int dx,int dy)
{
	int size;
	void *buffer;
	HideMouse();

	size=imagesize(p->x,p->y,p->x+p->wid,p->y+p->len);	/*  指定图象占字节数*/
	if( (buffer=malloc(size))==NULL)					/*为指定图像分配内存*/
	{
			closegraph();
			printf("not enough memory ,Press any key to halt...");
			getch();
			exit(1);
	}
	getimage(p->x,p->y,p->x+p->wid,p->y+p->len,buffer);  /*  存图象 */

	setfillstyle(1,WHITE);
	bar(p->x,p->y,p->x+p->wid,p->y+p->len);
	p->x=p->x+dx;
	p->y=p->y+dy;

	if(FurniOnFlooor(p))
	{
		putimage(p->x,p->y,buffer,COPY_PUT);
	}
	else
	{
		p->x=p->x-dx;
		p->y=p->y-dy;
		putimage(p->x,p->y,buffer,COPY_PUT);
	}
	free(buffer);
}


void DragFurni(Furni *p)
{
	Mouse m;
	int oldx,oldy,newx,newy;
	m=ReadMouse();
	oldx=m.x;
	oldy=m.y;
	while(m.b==1)
	{
		m=ReadMouse();
		newx=m.x;
		newy=m.y;
		if( (newx!=oldx)||(newy!=oldy) )
		{
		    MoveFurni(p,newx-oldx,newy-oldy);
		}
		oldx=newx;
		oldy=newy;
	}

}

void DelFurni(Furni *p)
{
	HideMouse();
	setfillstyle(1,WHITE);
	bar(p->x,p->y,p->x+p->wid,p->y+p->len);
	ShowMouse();
	p->exist=0;

}

void DesignFurni(Furni *p)
{
    Mouse m;
    m=ReadMouse();
    if(m.b==1)
    {
        if( ChooseFurni(p) && (p->exist))
        {
            OutFurni(p);
            DragFurni(p);
        }
    }
    if(m.b==2)
    {
        if( ChooseFurni(p) && (p->exist))
        {
            DelFurni(p);
        }

    }
    else
    {
        if( ChooseFurni(p) && (p->exist))
        {
            OutFurni(p);
        }

    }
}


void InitDesk(Furni *p)
{
	p->path="picture\\desk.bmp";
	p->wid=80;
	p->len=78;
	p->exist=1;
}


void InitSofa(Furni *p)
{
    p->path="picture\\sofa.bmp";
    p->wid=100;
    p->len=92;
    p->exist=1;
}

void InitWardrode(Furni *p)
{
    p->path="picture\\wardrobe.bmp";
    p->wid=70;
    p->len=114;
    p->exist=1;
}

void InitChair(Furni *p)
{
    p->path="picture\\chair.bmp";
    p->wid=50;
    p->len=73;
    p->exist=1;
}


void InitFridge(Furni *p)
{
    p->path="picture\\fridge.bmp";
    p->wid=62;
    p->len=115;
    p->exist=1;
}


void InitBed(Furni *p)
{
    p->path="picture\\bed.bmp";
    p->wid=120;
    p->len=91;
    p->exist=1;
}
