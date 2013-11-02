#ifndef _MENU_H_
#define _MENU_H_


typedef struct
{
      int x1;
      int y1;
      int x2;
      int y2;
} Menu;

void DrawBtn(Menu *pm);
void PressBtn(Menu *pm);
int MouseOnBtn(Menu *pm);
void DrawWin(int sx,int sy,int ex,int ey,int c);
void DrawBar(int sx,int sy,int ex,int ey,int c);
int PullMenuDown(char *txt[],int n,Menu *pm);

#endif





