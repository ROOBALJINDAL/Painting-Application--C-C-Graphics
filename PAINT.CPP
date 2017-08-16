
//            		INTRO AND GUIDELINES (hints)
/*           *********************RJ PAINT*******************
	     'k' stores the value of background color and
	     'l' stores the value of selected color of shapes
	     hit 'esc' to exit

	     drawing area --> rectangle(0,93,542,442);
	     ch=changeshape(x1,y1);
	     ************************************************

*/

#include<stdlib.h>
#include<conio.h>
#include<PROCESS.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<alloc.h>

void color();
int changecolor(int,int);
union REGS in,out,i,o;

// FUNCTIONS

getmouseposi(int *x,int *y,int *button)
{
	in.x.ax=3;
	int86(51,&in,&out);
	*x=out.x.cx;
	*y=out.x.dx;
	*button=out.x.bx;
	return 0;
}

int callmouse()
{
	in.x.ax=1;
	int86(51,&in,&out);
	return 1;
}

void setposi(int &xpos,int &ypos)
{
	in.x.ax=4;
	in.x.cx=xpos;
	in.x.dx=ypos;
	int86(51,&in,&out);
}


void restrictmouseptr( int x1, int y1, int x2, int y2)
{
	i.x.ax = 7;
	i.x.cx = x1;
	i.x.dx = x2;
	int86(0x33,&i,&o);
	i.x.ax = 8;
	i.x.cx = y1;
	i.x.dx = y2;
	int86(0x33,&i,&o);
}


int mousehide()
{
	in.x.ax=2;
	int86(51,&in,&out);
	return 1;
}


void shape()
{
	int i,j;
	setfillstyle(1,8);
	bar3d(0,0,getmaxx(),getmaxy(),0,0);

	for(i=550;i<=630;i++)
	for(j=60;j<=80;j++)
	putpixel(i,j,5);
	outtextxy(575,70,"BRUSH");

	for(i=550;i<=630;i++)
	for(j=100;j<=120;j++)
	putpixel(i,j,2);
	outtextxy(575,110,"CIRCLE");

	for(i=550;i<=630;i++)
	for(j=140;j<=160;j++)
	putpixel(i,j,3);
	outtextxy(575,150,"LINE");


	for(i=550;i<=630;i++)
	for(j=180;j<=200;j++)
	putpixel(i,j,4);
	outtextxy(575,190,"ELLIPSE");

	for(i=550;i<=630;i++)
	for(j=220;j<=240;j++)
	putpixel(i,j,9);
	outtextxy(575,230,"PATTERN");

	for(i=550;i<=630;i++)
	for(j=260;j<=280;j++)
	putpixel(i,j,10);
	outtextxy(575,270,"REC");


	for(i=550;i<=630;i++)
	for(j=300;j<=320;j++)
	putpixel(i,j,1);
	outtextxy(575,310,"PENCIL");

	for(i=550;i<=630;i++)
	for(j=340;j<=360;j++)
	putpixel(i,j,19);
	outtextxy(575,350,"3D BAR");

	for(i=550;i<=630;i++)
	for(j=380;j<=400;j++)
	putpixel(i,j,13);
	outtextxy(575,390,"CLEAR");

	for(i=550;i<=630;i++)
	for(j=420;j<=440;j++)
	putpixel(i,j,69);
	setcolor(15);
	outtextxy(575,430,"CLR Bk");

	for(i=550;i<=630;i++)
	for(j=460;j<=480;j++)
	putpixel(i,j,79);
	setcolor(0);
	outtextxy(573,468,"ERASER");
}
char changeshape(int x1,int y1)
{

	if((x1>550)&&(x1<630)&&(y1>60)&&(y1<80))
	return 'y';
	if((x1>550)&&(x1<630)&&(y1>100)&&(y1<120))
	return 'c';
	if((x1>550)&&(x1<630)&&(y1>140)&&(y1<160))
	return 'l';
	if((x1>550)&&(x1<630)&&(y1>180)&&(y1<200))
	return 'e';
	if((x1>550)&&(x1<630)&&(y1>220)&&(y1<240))
	return 'p';
	if((x1>550)&&(x1<630)&&(y1>260)&&(y1<280))
	return 'r';
	if((x1>550)&&(x1<630)&&(y1>300)&&(y1<320))
	return 'h';
	if((x1>550)&&(x1<630)&&(y1>380)&&(y1<400))
	return 'x';
	if((x1>550)&&(x1<630)&&(y1>340)&&(y1<360))
	return 'b';
	if((x1>550)&&(x1<630)&&(y1>420)&&(y1<440))
	return 'o';
	if((x1>550)&&(x1<630)&&(y1>460)&&(y1<480))
	return 'm';

	else return 'i';
}

void color()
{    int i,j;


     for(i=10;i<40;i++)
     for(j=60;j<90;j++)
     putpixel(i,j,12);

     for(i=50;i<80;i++)
     for(j=60;j<90;j++)
     putpixel(i,j,1);

     for(i=90;i<120;i++)
     for(j=60;j<90;j++)
     putpixel(i,j,2);

     for(i=130;i<160;i++)
     for(j=60;j<90;j++)
     putpixel(i,j,3);

     for(i=170;i<200;i++)
     for(j=60;j<90;j++)
     putpixel(i,j,4);

     for(i=210;i<240;i++)
     for(j=60;j<90;j++)
     putpixel(i,j,5);

     for(i=250;i<280;i++)
     for(j=60;j<90;j++)
     putpixel(i,j,6);

     for(i=290;i<320;i++)
     for(j=60;j<90;j++)
     putpixel(i,j,7);

     for(i=330;i<360;i++)
     for(j=60;j<90;j++)
     putpixel(i,j,15);


     for(i=370;i<400;i++)
     for(j=60;j<90;j++)
     putpixel(i,j,9);


     for(i=410;i<440;i++)
     for(j=60;j<90;j++)
     putpixel(i,j,10);

     for(i=450;i<480;i++)
     for(j=60;j<90;j++)
     putpixel(i,j,0);

     for(i=490;i<520;i++)
     for(j=60;j<90;j++)
     putpixel(i,j,YELLOW);

}

int changecolor(int x1,int y1)
{
     int i,j;

     if((x1>10)&&(x1<40)&&(y1>60)&&(y1<90))
     return 12;
     else if((x1>50)&&(x1<80)&&(y1>60)&&(y1<90))
     return 1;
     else if((x1>90)&&(x1<120)&&(y1>60)&&(y1<90))
     return 2;
     else if((x1>130)&&(x1<160)&&(y1>60)&&(y1<90))
     return 3;
     else if((x1>170)&&(x1<200)&&(y1>60)&&(y1<90))
     return 4;
     else if((x1>210)&&(x1<240)&&(y1>60)&&(y1<90))
     return 5;
     else if((x1>250)&&(x1<280)&&(y1>60)&&(y1<90))
     return 6;
     else if((x1>290)&&(x1<320)&&(y1>60)&&(y1<90))
     return 7;
     else if((x1>330)&&(x1<360)&&(y1>60)&&(y1<90))
     return 15;
     else if((x1>370)&&(x1<400)&&(y1>60)&&(y1<90))
     return 9;
     else if((x1>410)&&(x1<440)&&(y1>60)&&(y1<90))
     return 10;
     else if((x1>450)&&(x1<480)&&(y1>60)&&(y1<90))
     return 0;
     else if((x1>490)&&(x1<520)&&(y1>60)&&(y1<90))
     return 14;

     else return 2;
}

// EXIT ANIMATION

void exite()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"");
	setviewport(0,0,getmaxx(),getmaxy(),1);
	setcolor(0);
	setfillstyle(1,0);
	bar3d(2,2,540,440,0,0);
	int i,j;
	for(i=0;i<=140;i+=10)
	{
	setcolor(i);
	setfillstyle(CLOSE_DOT_FILL,i);
	fillellipse(150+i,110+i,15,15);
	delay(25);
	setcolor(i);
	setfillstyle(CLOSE_DOT_FILL,i+3);
	fillellipse(450-i,110+i,15,15);
	delay(25);

	setcolor(i+7);
	setfillstyle(CLOSE_DOT_FILL,i+6);
	fillellipse(150+i,390-i,15,15);
	delay(25);
	setcolor(i+7);
	setfillstyle(CLOSE_DOT_FILL,i+10);
	fillellipse(450-i,390-i,15,15);
	delay(25);

	setcolor(0);
	setfillstyle(1,0);
	fillellipse(150+i,110+i,15,15);
	setcolor(0);
	setfillstyle(1,0);
	fillellipse(450-i,110+i,15,15);

	setcolor(0);
	setfillstyle(1,0);
	fillellipse(150+i,390-i,15,15);
	setcolor(0);
	setfillstyle(1,0);
	fillellipse(450-i,390-i,15,15);
	}

//FORMING FACE
	setfillstyle(SOLID_FILL,YELLOW);
	for(i=0;i<=220;++i)
	fillellipse(320,250,25+i,25+i);

	for(i=0;i<40;i++)
	{
	setfillstyle(SOLID_FILL,i);
	fillellipse(210,150,40,40);
	setfillstyle(SOLID_FILL+i,i+2);
	fillellipse(430,150,40,40);
	delay(100);
	}

// lips
	setcolor(YELLOW);
       //	setfillstyle(4,YELLOW);
       //	pieslice(320,250,220,330,140);

// black eyes
	//setfillstyle(SOLID_FILL,YELLOW);
   //	pieslice(320,250,220,330,70);

	setfillstyle(SOLID_FILL,BLACK);
	fillellipse(210,150,40,40);
	setfillstyle(SOLID_FILL,BLACK);
	fillellipse(430,150,40,40);
	delay(100);

	setfillstyle(4,BLACK);
	pieslice(320,250,210,330,140);

	setfillstyle(SOLID_FILL,YELLOW);
	pieslice(320,250,200,340,90);
	setcolor(2);
	outtextxy(240,250," THANKS FOR VISITING...!!");
	delay(1000);
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	pieslice(430,150,0,180,40);
	delay(1000);
	setcolor(0);
	setfillstyle(SOLID_FILL,BLACK);
	pieslice(430,150,0,180,40);
	delay(1000);
	exit(1);

}

//PASSWORD

int password()
{
	clrscr();
	char x,b[7];
	int q,j,i=0;

	b[0]='r';
	b[1]='o';
	b[2]='o';
	b[3]='b';
	b[4]='a';
	b[5]='l';
	b[6]='\0';

	char a[20];
	gotoxy(35,10);
	textcolor(BLUE);
	cprintf("\nPASSWORD: ");
	while(x!=13)
	{
	x=getch();
	a[i]=x;
	gotoxy(45+i,11);
	textcolor(GREEN);
	cprintf("*");
	i++;
	}

	int y;
	y=i;
	i=0;
	while(a[i]==b[i])
	{
	i++;
	}
	//checking

	if((i==6)&&(y==7))
	{
	clrscr();
	gotoxy(30,11);
	textcolor(GREEN+BLINK);
	cprintf("\nPASSWORD ACCEPTED");
	delay(1000);

	textcolor(BLACK);
	return 1;
	}
	else
	{
	clrscr();
	gotoxy(30,12);
	textcolor(RED+128);
	cprintf("\nINCORRECT PASSWORD");
	delay(1000);
	textcolor(BLACK);
	return 0;
	}
	textcolor(BLACK);
}

int mainscreen()
{       int i,k;
	clrscr();
	gotoxy(55,23);
	textcolor(BLUE+128);
	cprintf("ProGraMmed bY: rJ");

	for(i=1;i<70;i++)
	{
	delay(30);
	gotoxy(30,10);
	textcolor(i+BLINK);
	cprintf("WELCOME TO RJ PAINT...!!");
	}

	textcolor(0);
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"");

	a:clrscr();

	int p,q,l=0,r,s,x,y,cl,b,j,d,x1,x2,y1,y2,button=0,fz;

	char ch,f;


	shape();
	// rectangles

	setcolor(GREEN);
	rectangle(1,1,getmaxx()-1,getmaxy());
	setcolor(BLUE);
	rectangle(0,0,getmaxx(),getmaxy());
	// darwing area

	setfillstyle(1,0);
	bar3d(2,95,540,440,0,0);

	setcolor(BLUE);
	rectangle(0,93,542,442);


	color();

     // TOOLBAR
     for(i=0;i<getmaxx()-22;i++)
     for(j=0;j<20;j++)
     putpixel(i,j,BLUE);
     for(i=getmaxx()-21;i<getmaxx();i++)
     for(j=0;j<20;j++)
     putpixel(i,j,RED);
     setcolor(15);

     outtextxy(getmaxx()-15,8,"X");
     setcolor(YELLOW);
     settextstyle(2,0,0);
     outtextxy(280,8,"RJ PAINT");

     setcolor(0);
     setviewport(2,96,540,438,1); //setview
     char esc;
     unsigned int size;
     void *pic;
  while(1)
  {
	if(kbhit())
	{
	 esc=getch();
	 if(esc==27)
	 exit(1);
	}


	callmouse();
	restrictmouseptr(0,0,getmaxx(),getmaxy());
	getmouseposi(&x1,&y1,&button);
	gotoxy(1,1);

	if((x1>550)&&(x1<630)&&(y1>60)&&(y1<500)&&(button==1))
	ch=changeshape(x1,y1);

	if((x1>20)&&(x1<550)&&(y1>20)&&(y1<90)&&(button==1))
	{
	l=changecolor(x1,y1);
	setcolor(changecolor(x1,y1));
	}

	//clr bk
	if((ch=='o')&&(button==1))
	{

	setfillstyle(1,l);
	bar3d(2,0,539,439-95,0,0);
	k=l;
	}

	//ERASER
	if(ch=='m')
	{

	callmouse();
	while(button==1)
	{

	mousehide();
	restrictmouseptr(2,95,488,388);
	setcolor(k);
	setfillstyle(1,k);
	bar3d(x1,y1-95,x1+50,y1+50-95,0,0);
	getmouseposi(&x1,&y1,&button);
	setcolor(k);
	setfillstyle(1,k+1);
	bar3d(x1,y1-95,x1+50,y1+50-95,0,0);
	setcolor(k);
	setfillstyle(1,k);
	bar3d(x1,y1-95,x1+50,y1+50-95,0,0);
	}
	}

	//exit
	if(button==1)
	if((x1>getmaxx()-21)&&(x1<getmaxx())&&(y1>0)&&(y1<20))
	{
	setfillstyle(1,0);
	bar3d(2,95,540,440,0,0);
	clearviewport();
	exite();
	}


       /*	//minimize down

	if(button==1)
	if((x1>getmaxx()-41)&&(x1<getmaxx()-21)&&(y1>0)&&(y1<20))
	{
	setposi(200,200);
	for(i=0;i<getmaxy()-22;i+=5)
	{
	setfillstyle(1,0);
	delay(10);
	bar3d(0,0,getmaxx(),i,0,0);
	}
	for(i=0;i<getmaxx()-22;i++)
	for(j=getmaxy()-21;j<getmaxy()-95;j++)
	putpixel(i,j,BLUE);
	for(i=getmaxx()-21;i<getmaxx();i++)
	for(j=getmaxy()-21;j<getmaxy()-95;j++)
	putpixel(i,j,RED);
	setcolor(15);

	for(i=getmaxx()-41;i<getmaxx()-21;i++)
	for(j=getmaxy()-21;j<getmaxy()-95;j++)
	putpixel(i,j,GREEN);
	setcolor(15);
	outtextxy(getmaxx()-37,getmaxy()-8-95,"--");

	outtextxy(getmaxx()-15,getmaxy()-8-95,"X");
	setcolor(YELLOW);
	settextstyle(2,0,0);
	outtextxy(280,getmaxy()-8-95,"RJ PAINT");
	fz=1;
	}              */
      /*
     // minimize up

	if((button==1))
	if((x1>getmaxx()-41)&&(x1<getmaxx()-21)&&(y1>getmaxy()-21)&&(y1<getmaxy()))
	{
	goto a;
	}
	 */

	f=ch;


	// brush

	if(f=='y')
	{
	if(button==1)
	{
	 while(button==1)
	{
	restrictmouseptr(0,95,540,440);
	getmouseposi(&x2,&y2,&button);
	setcolor(l);
	circle(x2,y2-97,5);
	circle(x2,y2-97,4);
	circle(x2,y2-97,3);
	circle(x2,y2-97,2);
	circle(x2,y2-97,1);
	}

	restrictmouseptr(0,95,540,440);
	}
	}
	/*
	//line
	if(f=='l')
	{
	if(button==1)
	{
	 restrictmouseptr(0,0,getmaxx(),getmaxy());
	 while(button==1)
	{
	restrictmouseptr(0,95,540,440);
	getmouseposi(&x2,&y2,&button);
	}
	line(x1,y1-95,x2,y2-95);
	}
	}         */


	// test line
	if(f=='l')
	{
	if(button==1)
	{
	 restrictmouseptr(0,0,getmaxx(),getmaxy());
	 while(button==1)
	{
	mousehide();
	restrictmouseptr(0,95,540,440);
	getmouseposi(&x2,&y2,&button);
	setcolor(l);
	line(x1,y1-95,x2,y2-95);
	setcolor(k);
	line(x1,y1-95,x2,y2-95);
	}
	setcolor(l);
	line(x1,y1-95,x2,y2-95);
	}
	}



	//circle

	if(f=='c')
	{
	if(button==1)
	{
	 while(button==1)
	{
	restrictmouseptr(0,95,540,440);
	getmouseposi(&x2,&y2,&button);
	}

	restrictmouseptr(0,95,540,440);
	circle(x1,y1-97,sqrt( (pow(x2-x1,2)) + (pow(y2-y1,2))) );
	}
	}

	// ellipse
	if(f=='e')
	{
	if(button==1)
	{
	 while(button==1)
	{
	restrictmouseptr(0,95,540,440);
	getmouseposi(&x2,&y2,&button);
	}
	ellipse(x1,y1-75,0,360,abs(x2-x1),abs(y2-y1));
	}
	}

	//pattern

	if(f=='p')
	{
	if(button==1)
	{
	 while(button==1)
	{
	restrictmouseptr(2,95,540,440);
	getmouseposi(&x2,&y2,&button);
	line(x1,y1-95,x2,y2-95);
	}
	}
	}



	//RECTANGLE

	if(f=='r')
	{
	if(button==1)
	{
	while(button==1)
	{
	restrictmouseptr(2,95,540,440);
	getmouseposi(&x2,&y2,&button);
	}
	rectangle(x1,y1-95,x2,y2-95);
	}
	}

	//PENCIL
	if(f=='h')
	{
	callmouse();
	restrictmouseptr(0,0,getmaxx(),getmaxy());
	if(button==1)
	{
	while(button==1)
	{
	mousehide();
	restrictmouseptr(2,95,540,440);
	x2=x1;
	y2=y1;
	getmouseposi(&x1,&y1,&button);
	line(x1,y1-95,x2,y2-95);
	}
	}
	}

	//3D BAR

	if(f=='b')
	{
	if(button==1)
	{
	while(button==1)
	{
	restrictmouseptr(2,95,540,440);
	getmouseposi(&x2,&y2,&button);
	}
	setfillstyle(1,l);
	bar3d(x1,y1-95,x2,y2-95,10,10);
	}
	}


	//CLEAR
	if(f=='x')
	{
	ch='q';
	mainscreen();
	}

  }
  closegraph();
  return 0;
}



void intro()
	{


	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"..\\bgi");


	int i,j;

	for(j=0; j<=2000; j++)
	{
	delay(1);
	putpixel(random(getmaxx()),random(getmaxy()),j);
	}


	for(i=1;i<=8;++i)
	{
	setcolor(i+3);
	settextstyle(1,0,i);
outtextxy(120,140,"RJ PAINT");
delay(100);

setcolor(0);
settextstyle(1,0,i-1);
outtextxy(120,140,"RJ PAINT");

}
setcolor(2);
settextstyle(1,0,4);
outtextxy(80,400,"PRESS ANY KEY TO CONTINUE....!");
getch();
	setcolor(0);
	cleardevice();
	closegraph();

}




//MAIN FXN

int main()
{
	intro();
	if(password()==1)
	{
	mainscreen();
	}
	return 0;
}