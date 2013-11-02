#include "head\\common.h"
#include "head\\inital.h"
#include "head\\hanzi.h"
#include "head\\finish.h"
#include "head\\menu.h"
#include "head\\mouse.h"




void Finish()
{
    MyInitgraph();

    setbkcolor(GREEN);

	setcolor(YELLOW);

	line(20,40,540,40);
	line(540,40,540,380);
	line(540,380,560,380);
	line(560,380,620,440);
	line(620,440,100,440);
	line(100,440,100,100);
	line(100,100,80,100);
	line(80,100,20,40);

	setfillstyle(SOLID_FILL,LIGHTGREEN);
	floodfill(150,150,YELLOW);

	DisChinese("希望你能喜欢我们为你设计的程序",110,75,2,2,10,GREEN);
	DisChinese("谢谢使用！",200,180,4,4,25,YELLOW);


	setcolor(YELLOW);

	line(490,320,450,360);
	line(450,360,530,360);
	line(530,360,490,320);

	setfillstyle(1,GREEN);
	floodfill(490,330,YELLOW);


	line(460,360,460,420);
	line(460,420,520,420);
	line(520,420,520,360);

	setfillstyle(1,GREEN);
	floodfill(490,380,YELLOW);


	line(480,420,480,380);
	line(480,380,500,380);
	line(500,380,500,420);
	putpixel(485,400,YELLOW);

    DisChinese("制作人：熊博",120,370,2,2,18,YELLOW);
    DisChinese("严乐",260,407,2,2,18,YELLOW);

}




int PopUp()
{
    int choice;
    Mouse m;
    Menu content;
    Menu uncontent;
    Menu close;
    void *buffer[6];
    char i;
    HideMouse();


    for(i=0;i<6;i++)
    {
        buffer[i]=malloc( imagesize(150+i*60, 160, 150+(i+1)*60, 340) );
        if(buffer[i]==NULL)
        {
            closegraph();
            restorecrtmode();
            printf("Not Enough Memory !\n try to reduce the area used.\n");
            exit(1);
        }


        getimage(150+i*60, 160, 150+(i+1)*60, 340,buffer[i]);
    }


    setcolor(GREEN);
	rectangle(150,160,510,340);
	rectangle(161,180,499,329);
	setfillstyle(1,YELLOW);
	floodfill(210,165,GREEN);
	setfillstyle(1,LIGHTGRAY);
	floodfill(250,280,GREEN);
	DisChinese("你对你的设计满意吗？",182,200,1,1,8,BLACK);
	DisChinese("满意则进入下一界面，不满意可重新设计",182,230,1,1,8,BLACK);
	DisChinese("满意",250,280,1,1,12,BLACK);
	DisChinese("不满意",350,280,1,1,8,BLACK);

	setcolor(RED);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	outtextxy(493,158,"x");

    content.x1=235;
	content.y1=275;
	content.x2=305;
	content.y2=300;

	uncontent.x1=340;
	uncontent.y1=275;
	uncontent.x2=410;
	uncontent.y2=300;

	close.x1=489;
	close.y1=165;
	close.x2=505;
	close.y2=178;

	DrawBtn(&content);
	DrawBtn(&uncontent);
	DrawBtn(&close);
	ShowMouse();

	while(1)
	{
	    ShowMouse();
	    m=ReadMouse();
	    if(m.b==1)
	    {
                if(MouseOnBtn(&content))
                {
                    PressBtn(&content);
                    choice=0;
                    break;
                }
                if(MouseOnBtn(&uncontent))
                {
                    PressBtn(&uncontent);
                    choice=1;
                    break;
                }
                if(MouseOnBtn(&close))
                {
                    HideMouse();
                    for(i=0;i<6;i++)
                    {
                        putimage(150+i*60, 160, buffer[i], COPY_PUT);
                    }
                    choice=-1;
                    break;
                }
	    }
	}

	for(i=0;i<6;i++)
	{
	    free (buffer[i]);
	}

	return choice;

}

