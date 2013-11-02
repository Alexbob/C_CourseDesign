#include "head\\common.h"
#include "head\\inital.h"



void MyInitgraph()
{
	int gdrive=VGA;
	int gmode=VGAHI;
	int errorcode;

	char path[MAXPATH];
	getcwd(path, MAXPATH);
	strcat(path,"\\BGI");

	initgraph(&gdrive,&gmode,path);

	errorcode=graphresult();
	if (errorcode != grOk)
	{
	  printf("Graphic error:%s\n",grapherrormsg(errorcode));
	  printf("Press any key to halt...");
	  getch();
	  exit(1);
	}

	cleardevice();
}
