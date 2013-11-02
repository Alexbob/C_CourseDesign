#include "head\\common.h"
#include "head\\welcome.h"
#include "head\\wall.h"
#include "head\\design.h"
#include "head\\inital.h"
#include "head\\mouse.h"



void main()
{
	int wall_color;
	int content_flag;
	content_flag=1;

	MyInitgraph();
	InitMouse();

	Welcome();

	while (content_flag)
	{
        wall_color = DesignWall();
        content_flag = DesignHouse(wall_color);
	}
	getch();
	closegraph();
}
