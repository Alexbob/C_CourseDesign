#include "head\\common.h"
#include "head\\house.h"
#include "head\\inital.h"
#include "head\\hanzi.h"
#include "head\\mouse.h"
#include "head\\menu.h"
#include "head\\hanzi.h"
#include "head\\design.h"
#include "head\\bmp.h"
#include "head\\furni.h"
#include "head\\help.h"
#include "head\\finish.h"
#include "head\\decorate.h"

int DesignHouse(int colr)
{
	MyInitgraph();
	int chos;
	int flag;
	Mouse m;

	Menu furniture;
	Menu decorate;
	Menu complete;
	Menu quit;

	char *fur[]={"床","柜子","冰箱","沙发","桌子","椅子"};
	char *dec[]={"窗帘","电视","时钟","台灯"};

	Furni bed[5];
	Furni wardrobe[5];
	Furni fridge[5];
	Furni sofa[5];
	Furni desk[5];
	Furni chair[5];

	int bed_cnt=0;
	int wardrobe_cnt=0;
	int fridge_cnt=0;
	int sofa_cnt=0;
	int desk_cnt=0;
	int chair_cnt=0;

	Furni curtain;
	Furni tv;
	Furni colock;
	Furni light;

	int cnt;

	DrawHouse();
	ChangeColor(colr);

	DisChinese("第二步：请选择你喜欢的家居物品",10,12,1,1,8,0);
	DisChinese("家具",320,12,1,1,8,0);
	DisChinese("装饰品",400,12,1,1,8,0);
	DisChinese("完成",500,12,1,1,8,0);
	DisChinese("退出",580,12,1,1,8,0);



	furniture.x1=310;
	furniture.y1=7;
	furniture.x2=370;
	furniture.y2=32;

	decorate.x1=390;
	decorate.y1=7;
	decorate.x2=460;
	decorate.y2=32;

	complete.x1=490;
	complete.y1=7;
	complete.x2=550;
	complete.y2=32;

	quit.x1=570;
	quit.y1=7;
	quit.x2=630;
	quit.y2=32;

	DrawBtn(&furniture);
	DrawBtn(&decorate);
	DrawBtn(&complete);
	DrawBtn(&quit);

	Message("");

    do
	{
	    m=ReadMouse();
	}
	while (m.b==1);

	while(1)
	{
	    ShowMouse();
		m=ReadMouse();

		if(m.b==1)
		{
			if(MouseOnBtn(&furniture))
			{
				PressBtn(&furniture);
				Message("请选择你喜欢的家具");
				chos=PullMenuDown(fur,6,&furniture);
				Message("请在地板空白处单击，即可出现所选家具");
                switch (chos)
                {

                    case  0:
                        InitBed(&bed[bed_cnt]);
                        HandleFurni(&bed[bed_cnt]);
                        bed_cnt++;
                        break;

                    case  1:
                        InitWardrode(&wardrobe[wardrobe_cnt]);
                        HandleFurni(&wardrobe[wardrobe_cnt]);
                        wardrobe_cnt++;
                        break;

                    case  2:
                        InitFridge(&fridge[fridge_cnt]);
                        HandleFurni(&fridge[fridge_cnt]);
                        fridge_cnt++;
                        break;

                    case  3:
                        InitSofa(&sofa[sofa_cnt]);
                        HandleFurni(&sofa[sofa_cnt]);
                        sofa_cnt++;
                        break;


                    case  4:
                        InitDesk(&desk[desk_cnt]);
                        HandleFurni(&desk[desk_cnt]);
                        desk_cnt++;
                        break;

                    case  5:
                        InitChair(&chair[chair_cnt]);
                        HandleFurni(&chair[chair_cnt]);
                        chair_cnt++;
                        break;
                }
			}

			if(MouseOnBtn(&decorate))
			{
				PressBtn(&decorate);
                Message("请选择你喜欢的装饰品");
				chos=PullMenuDown(dec,4,&decorate);
                Message("请在墙壁上单击，即可出现所选装饰品");
                switch (chos)
                {
                    case  0:
                        InitCurtain(&curtain);
                        HandleDecorate(&curtain);
                        break;
                    case  1:
                        InitTv(&tv);
                        HandleDecorate(&tv);
                        break;
                    case  2:
                        InitColock(&colock);
                        HandleDecorate(&colock);
                        break;
                    case  3:
                        InitLight(&light);
                        HandleDecorate(&light);
                        break;
                }
			}

			if(MouseOnBtn(&complete))
			{
                PressBtn(&complete);
                flag=PopUp();
                if(flag == 0)
                {
                    HideMouse();
                    Finish();
                    break;
                }
                if(flag == 1)
                {
                    break;
                }
                if(flag==-1)
                {
                    DrawBtn(&complete);
                    continue;
                }
			}

			if(MouseOnBtn(&quit))
			{
				PressBtn(&quit);
				HideMouse();
				cleardevice();
				closegraph();
				Finish();
				flag=0;
				break;
			}
		}
        ShowMouse();
        IsFurni(desk,desk_cnt);
        IsFurni(sofa,sofa_cnt);
        IsFurni(wardrobe,wardrobe_cnt);
        IsFurni(chair,chair_cnt);
        IsFurni(fridge,fridge_cnt);
        IsFurni(bed,bed_cnt);

        DesignDecorate(&curtain,colr);
        DesignDecorate(&tv,colr);
        DesignDecorate(&colock,colr);
        DesignDecorate(&light,colr);
	}
	return flag;
}


void HandleFurni(Furni *p)
{

    static int flag=0;
    Mouse m;
    while(1)
    {
        ShowMouse();
        m=ReadMouse();
        if( (m.b==1) && ( MouseOnFloor() ))
        {
            p->x=m.x;
            p->y=m.y;
            ShowFurni(p);
            break;
        }
    }
    if(flag==0)
    {
        Message("按住鼠标左键可随意拖动家具，单击右键或按下回格键即可删除该家具");
        flag=1;
        return ;
    }
    if(flag==1)
    {
        Message("按住空格键可旋转家具，方向键进行微调");
        flag=0;
        return ;
    }


}


void HandleDecorate(Furni *p)
{
    Mouse m=ReadMouse();
    while(m.b==1)
    {
        m=ReadMouse();
    }
    while(1)
    {
        ShowMouse();
        m=ReadMouse();
        if( (m.b==1) && ( MouseOnWall() ))
        {
            p->x=m.x;
            p->y=m.y;
            ShowFurni(p);
            break;
        }
    }
    Message("单击鼠标右键可删除该装饰品");
}

void IsFurni(Furni *p,int n)
{
    int cnt;
    for(cnt=0;cnt<n;cnt++)
    {
        if(p[cnt].exist==1)
        {
            DesignFurni(&p[cnt]);
        }
    }
}

int MouseOnFloor()
{
    Mouse m;
    int x,y;
    int flag=0;
    m=ReadMouse();
    x=m.x;
    y=m.y;
    if((x> 0)&&(x < 639)&&(y < 450)&&(15*y+8*x-4653>0)&&(8*x-17*y+153<0))
    {
        flag=1;
    }
    return flag;

}

int MouseOnWall()
{
    Mouse m;
    int x,y;
    int flag=0;
    m=ReadMouse();
    x=m.x;
    y=m.y;
    if((x> 0)&&(x < 639)&&(y > 40))
    {
        flag=1;
    }
    return flag;
}
