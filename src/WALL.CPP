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


	char * colr[]={"ǳ��","���","����","����","����","����","�����","��ɫ"};



	changebk.x1=310;
	changebk.y1=7;
	changebk.x2=420;
	changebk.y2=32;

	nextstep.x1=540;
	nextstep.y1=7;
	nextstep.x2=630;
	nextstep.y2=32;

	DrawHouse();


	DisChinese("��һ������ѡ����ϲ����ǽ����ɫ",10,12,1,1,8,BLACK);
	DisChinese("ǽ����ɫ",330,12,1,1,8,BLACK);
	DisChinese("��һ��",560,12,1,1,8,BLACK);


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
