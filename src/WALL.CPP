#include "head\\common.h"
#include "head\\wall.h"
#include "head\\inital.h"
#include "head\\hanzi.h"
#include "head\\mouse.h"
#include "head\\menu.h"
#include "head\\house.h"



int DesignWall()
{
	MyInitgraph();
	int choice;
	Menu changebk;
	Menu nextstep;
	Mouse m;


	char * colr[]={"Ç³»Ò","Éî»Ò","µ­À¶","µ­ÂÌ","µ­Çà","µ­ºì","µ­Ñóºì","»ÆÉ«"};



	changebk.x1=310;
	changebk.y1=7;
	changebk.x2=420;
	changebk.y2=32;

	nextstep.x1=540;
	nextstep.y1=7;
	nextstep.x2=630;
	nextstep.y2=32;

	DrawHouse();


	DisChinese("µÚÒ»²½£ºÇëÑ¡ÔñÄãÏ²»¶µÄÇ½±ÚÑÕÉ«",10,12,1,1,8,BLACK);
	DisChinese("Ç½±ÚÑÕÉ«",330,12,1,1,8,BLACK);
	DisChinese("ÏÂÒ»²½",560,12,1,1,8,BLACK);


	DrawBtn(&changebk);
	DrawBtn(&nextstep);


	while (1)
	{
	    ShowMouse();
		m=ReadMouse();
		if (m.b == 1)
		{

			if (MouseOnBtn(&changebk))
			{
				PressBtn(&changebk);
				choice=PullMenuDown(colr, 8, &changebk);
				ChangeColor(choice+7);
				continue;
			}


			if(MouseOnBtn(&nextstep))
			{
				PressBtn(&nextstep);
				HideMouse();
				cleardevice();
				closegraph();
				break;
			}
		}
	}

	return choice+7;

}
