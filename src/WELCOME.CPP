#include "head\\welcome.h"
#include "head\\common.h"
#include "head\\inital.h"
#include "head\\hanzi.h"
#include "head\\mouse.h"



void Welcome()
{
	Mouse m;


	setbkcolor(WHITE);
	setviewport(40, 40, 600, 440, 1);

	setfillstyle(SOLID_FILL, LIGHTCYAN);
	setcolor(YELLOW);
	rectangle(0, 0, 560, 400);
	floodfill(50, 50, 14);

    setviewport(40, 40, 580, 420, 1);
	rectangle(20, 20, 540, 380);
	setfillstyle(SOLID_FILL, LIGHTMAGENTA);
	floodfill(21, 300, YELLOW);


	setcolor(BLACK);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 8);
	outtextxy(110, 55, "Welcome");
	DisChinese("今天你是设计师",170,165,2,2,10,10);


	setcolor(BLUE);
	setfillstyle(SOLID_FILL, YELLOW);
	ellipse(450,335,0,360,60,20);
	floodfill(450, 335, BLUE);
	DisChinese("开始",430,328,1,1,20,DARKGRAY);


	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);

	arc(260,818,85,130,470);
	arc(270,820,85,130,470);
	arc(285,822,85,130,470);

	line(61,227,74,400);
	line(61,227,164,211);
	line(164,211,174,360);

	line(184,277,254,265);
	line(184,277,190,355);
	line(254,265,260,355);

	bar(85,245,108,270);
	bar(131,245,155,270);
	bar(85,300,108,330);
	bar(131,300,155,330);

	bar(199,287,215,302);
	bar(230,282,246,298);
	bar(199,320,215,335);
	bar(230,320,246,335);


	while (1)
	{
	    ShowMouse();
	    m=ReadMouse();
        if (m.b == 1)
        {
			if (MouseIn(430,305,500,395))
			{
			    HideMouse();
			    cleardevice();
			    closegraph();
				break;
			}
		}
	}
}
