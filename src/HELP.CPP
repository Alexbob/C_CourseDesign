#include "head\\hanzi.h"
#include "head\\common.h"
#include "head\\help.h"



void Message(char *help)
{
    setfillstyle(1,YELLOW);
    bar(0,450,639,479);
    DisChinese("°ïÖú",12,458,1,1,12,RED);
    DisChinese(help,60,458,1,1,8,GREEN);

}
