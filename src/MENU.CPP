#include "head\\common.h"
#include "head\\menu.h"
#include "head\\mouse.h"
#include "head\\hanzi.h"


void DrawBtn(Menu *pm)
{
	HideMouse();


	setcolor(WHITE);
	line(pm->x1,pm->y1,pm->x2,pm->y1);
	line(pm->x1,pm->y1,pm->x1,pm->y2);

	setcolor(BLACK);
	line(pm->x2,pm->y1,pm->x2,pm->y2);
	line(pm->x1,pm->y2,pm->x2,pm->y2);
}




void PressBtn(Menu *pm)
{
	HideMouse();
	setcolor(BLACK);


	line(pm->x1,pm->y1,pm->x2,pm->y1);
	line(pm->x1,pm->y1,pm->x1,pm->y2);


	setcolor(WHITE);
	line(pm->x2,pm->y1,pm->x2,pm->y2);
	line(pm->x1,pm->y2,pm->x2,pm->y2);
}



int MouseOnBtn(Menu *pm)
{
	int flag=0;
	Mouse m;
	m=ReadMouse();


	if ( (pm->x1 < m.x) && (m.x < pm->x2) && (m.y > pm->y1) && (m.y < pm->y2))
	{
		flag=1;
	}
	return flag;
}



void DrawWin(int sx,int sy,int ex,int ey,int c)
{
   HideMouse();
   setfillstyle(SOLID_FILL,c);
   bar(sx,sy,ex,ey);
   setcolor(WHITE);
   line(sx,sy,sx,ey);
   line(sx,sy,ex,sy);
   setcolor(BLACK);
   line(ex,sy,ex,ey);
   line(sx,ey,ex,ey);

}



void DrawBar(int sx,int sy,int ex,int ey,int c)
{
  int i;
  setwritemode(XOR_PUT);
  setcolor(c);


  for(i=sy;i<=ey;i++)
  {
        line(sx,i,ex,i);
  }

  setwritemode(COPY_PUT);
}



int PullMenuDown(char *txt[],int n,Menu *pm)
{
	Mouse m;
	int selection;
	int i;
	int j;
	void *buffer;

	HideMouse();
	i=n*20;


	buffer=malloc(imagesize(pm->x1+1,pm->y2+2,pm->x2+1,pm->y2+i+5));


	if(buffer==NULL)
	{
		closegraph();
		restorecrtmode();
		printf("Not Enough Memory !\n try to reduce the area used.\n");
		exit(1);
	}


	getimage(pm->x1+1,pm->y2+2,pm->x2+1,pm->y2+i+5,buffer);

	DrawWin(pm->x1+1,pm->y2+2,pm->x2+1,pm->y2+i+5,WHITE);


	for(j=0;j<n;j++)
	{
		DisChinese(txt[j],pm->x1+14,pm->y2+8+j*20,1,1,14,DARKGRAY);
	}


	do
	{
	    m=ReadMouse();
	}
	while (m.b==1);

	while(1)
	{
	    ShowMouse();
		m=ReadMouse();
		if (m.b==1)
		{
			break;
		}
		for (j=0;j<n;j++)
		{
			if ( MouseIn(pm->x1+4,pm->y2+6+j*20,pm->x2,pm->y2+22+j*20) )
			{
			    ShowMouse();
				DrawBar(pm->x1+3,pm->y2+6+j*20,pm->x2,pm->y2+22+j*20,5);
				while( MouseIn(pm->x1+4,pm->y2+6+j*20,pm->x1+97,pm->y2+22+j*20) )
				{
					m=ReadMouse();
					if(m.b==1)
					{
						selection=j;
						break;
					}
				}
				DrawBar(pm->x1+3,pm->y2+6+j*20,pm->x2,pm->y2+22+j*20,5);
			}
		}
	}

	HideMouse();
	putimage(pm->x1+1,pm->y2+2,buffer,COPY_PUT);
	DrawBtn(pm);
	free (buffer);
	return selection;
}

