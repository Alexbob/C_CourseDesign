#ifndef _FURNI_H_
#define _FURNI_H_

typedef struct
{
	char *path;
	int x;
	int y;
	int wid;
	int len;
	char exist;
} Furni;


int ChooseFurni(Furni *p);
void OutFurni(Furni *p);
int FurniOnFlooor(Furni *p);
void MoveFurni(Furni *p,int dx,int dy);
void DragFurni(Furni *p);
void DelFurni(Furni *p);
void DesignFurni(Furni *p);
void IsFurni(Furni *p,int n);

void InitTable(Furni *p);
void InitSofa(Furni *p);
void InitDesk(Furni *p);
void InitWardrode(Furni *p);
void InitChair(Furni *p);
void InitFridge(Furni *p);
void InitBed(Furni *p);



#endif








