#include "head\\common.h"
#include "head\\key.h"
#include "head\\mouse.h"


void CheckKeyboard(Furni *p)
{
    int key;


    if (bioskey(1))
    {
        key=bioskey(0);
        switch (key)
        {
            case SPACE:
                OverTurn(p);
                break;

            case BACKSPACE:
                DelFurni(p);
                break;

            case UP:
                MoveFurni(p,0,-INCRE);
                break;

            case DOWN:
                MoveFurni(p,0,INCRE);
                break;

            case LEFT:
                MoveFurni(p,-INCRE,0);
                break;

            case RIGHT:
                MoveFurni(p,INCRE,0);
                break;


            default:
                break;
        }
    }
}

void OverTurn(Furni *p)
{
    int x;
    int y;
    int w;
    int l;
    int i,j;
    int px,py;

    x=p->x+1;
    y=p->y+1;
    w=p->wid-1;
    l=p->len-1;


    int **temp;
    temp = (int**)malloc(sizeof(int*)*w);
    for (i=0; i<w; i++)
    {
            temp[i] = (int*)malloc(sizeof(int)*l);
    }

    HideMouse();

    for(i=0,px=x;i<w;i++,px++)
    {
           for(j=0,py=y;j<l;j++,py++)
           {
                temp[i][j]=getpixel(px,py);
           }
    }


    HideMouse();
    setfillstyle(SOLID_FILL,WHITE);
	bar(p->x,p->y,p->x+p->wid,p->y+p->len);


    for(i=w-1,px=x;i>=0;i--,px++)
    {
           for(j=0,py=y;j<l;j++,py++)
           {
                putpixel(px,py,temp[i][j]);
           }
    }


    for (i=0; i<w; i++)
    {
           free(temp[i]);
    }
    free(p);

    ShowMouse();

}
