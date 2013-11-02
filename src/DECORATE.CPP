#include "head\\common.h"
#include "head\\mouse.h"
#include "head\\decorate.h"
#include "head\\bmp.h"
#include "head\\furni.h"


void DesignDecorate(Furni *p,int colr)
{
    Mouse m;
    m=ReadMouse();
    if(m.b==2)
    {
	if( ChooseDecorate(p) && (p->exist))
        {
            DelDecorate(p,colr);
        }

    }
}


int ChooseDecorate(Furni *p)
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

void  DelDecorate(Furni *p,int colr)
{
    HideMouse();
	setfillstyle(1,colr);
	bar(p->x,p->y,p->x+p->wid,p->y+p->len);
	ShowMouse();
	p->exist=0;

}



void InitCurtain(Furni *p)
{
    p->path="picture\\curtain.bmp";
    p->wid=70;
    p->len=120;
    p->exist=1;
}

void InitColock(Furni *p)
{
    p->path="picture\\colock.bmp";
    p->wid=50;
    p->len=70;
    p->exist=1;
}

void InitTv(Furni *p)
{
    p->path="picture\\tv.bmp";
    p->wid=60;
    p->len=70;
    p->exist=1;
}

void InitLight(Furni *p)
{
    p->path="picture\\light.bmp";
    p->wid=50;
    p->len=46;
    p->exist=1;
}
