#ifndef _MOUSE_H_
#define _MOUSE_H_

typedef struct
{
	int x;          // mouse x  coordinate
	int y;          //mouse y coordinate
	int b;          //mouse status
} Mouse;

void ShowMouse();
void HideMouse();
Mouse ReadMouse();
int  MouseIn(int x1,int y1,int x2,int y2);
void InitMouse();
void UpdateMouse(int show_flag);
                                                     /* 鼠标器初始化函数 */


#endif
