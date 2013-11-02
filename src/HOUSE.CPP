#include "head\\house.h"
#include "head\\mouse.h"
#include "head\\common.h"



void DrawHouse()
{
	setfillstyle(1,WHITE);
	bar(0,0,639,479);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(1,1,639,35);
	setcolor(BLACK);
	setlinestyle(0,0,3);
	line(300,150,0,310);
	line(300,150,639,310);
	setlinestyle(0,0,1);
	line(0,40,639,40);
	line(300,40,300,150);
}



void ChangeColor(int col)
{
	setfillstyle(1,col);
	floodfill(200,150,BLACK);
	floodfill(400,150,BLACK);
}
