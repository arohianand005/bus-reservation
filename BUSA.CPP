#include <string.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream.h>
#include<conio.h>

#include "BusR.cpp"


int k=0,bt,memo=1;
union REGS i,o;
long double num=0,accum,m;

void normalbutton(int x1,int x2,int y1,int y2)
{
setcolor(15);
rectangle(x1-2,y1-2,x2+1,y2+1);
rectangle(x1-1,y1-1,x2+2,y2+2);
setcolor(7);
rectangle(x1,y1,x2+2,y2+2);
rectangle(x1,y1,x2+1,y2+1);

setfillstyle(SOLID_FILL,3);
bar(x1,y1,x2,y2);
setcolor(1);
}
void notBookedSeat(int x1,int x2,int y1,int y2,int c)
{
setcolor(10);
rectangle(x1-2,y1-2,x2+1,y2+1);
rectangle(x1-1,y1-1,x2+2,y2+2);
setcolor(7);
rectangle(x1,y1,x2+2,y2+2);
rectangle(x1,y1,x2+1,y2+1);

setfillstyle(SOLID_FILL,12);
bar(x1,y1,x2,y2);
setcolor(1);
char c1[10];
sprintf(c1,"%d",c);
outtextxy((int)(x1+x2)/2,(int)(y1+y2)/2,c1);
}
void bookedSeat(int x1,int x2,int y1,int y2,int c)
{
setcolor(12);
rectangle(x1-2,y1-2,x2+1,y2+1);
rectangle(x1-1,y1-1,x2+2,y2+2);
setcolor(7);
rectangle(x1,y1,x2+2,y2+2);
rectangle(x1,y1,x2+1,y2+1);

setfillstyle(SOLID_FILL,13);
bar(x1,y1,x2,y2);
setcolor(1);

char c1[10];
sprintf(c1,"%d",c);
outtextxy((x1+x2)/2,(y1+y2)/2,c1);
}
/* initmouse */
initmouse()
{
 i.x.ax=0;
 int86 (0x33,&i,&o);
 return(o.x.ax);
}
hidemouseptr()
{
	 i.x.ax=2;
	 int86(0x33,&i,&o);
	 return 0;

}

/* displays mouse pointer */
showmouseptr()
{
 i.x.ax=1;
 int86(0x33,&i,&o);
 return 0;
}

/*gets mouse coordinates and button status*/

getmousepos(int *button,int *x,int *y)
{
 i.x.ax=3;
 int86(0x33,&i,&o);
 *button=o.x.bx;
 *x=o.x.cx;
 *y=o.x.dx;
 return 0;
}
/* Move mouse ptr to x,y */
movemouseptr(int *x,int *y)
{
 i.x.ax=4;
 int86(0x33,&i,&o);
 o.x.cx=*x;
 o.x.dx=*y;
 return 0;
}


void intro()
{
     system("color 04");
     system("cls");
}


class BusAvailability : public BusReservation
{
public:
  void show_bus();
  void is_bus_available();
  void position(int);
}bus[10];



void BusAvailability ::show_bus()
{
  int n;
  char number[5];
  cout<<"Enter bus number: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;

  }
  while(n<=p)
  {
	cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"Bus no: "<<bus[n].busn
	<<endl<<"Driver: "<<bus[n].driver<<endl<<"Arrival time: "
	<<bus[n].arrival<<endl<<"Departure time: "<<bus[n].depart
	<<endl<<"From: "<<bus[n].from<<endl<<"To: "<<
	bus[n].to<<endl;
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	bus[0].position(n);
	int a=1;
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	for (int i=0; i<8; i++)
	{
	for(int j=0;j<4;j++)
	{
	a++;
	if(strcmp(bus[n].seat[i][j],"Empty")!=0)
	cout<<endl<<"The seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
	}
	}
	break;

 }
	if(n>p)
	cout<<"Incorrect bus no: ";
	getch();
}

void BusAvailability ::position(int l){
  int s=0;
  setcolor(9);
  rectangle(50,310,80,340);
  setfillstyle(SOLID_FILL,13);
  bar(50,310,80,340);
setcolor(1);

  outtextxy(90,320,"Booked");
  setcolor(14);
  rectangle(50,360,80,390);
setfillstyle(SOLID_FILL,12);
  bar(50,360,80,390);
setcolor(1);

  outtextxy(90,370,"Not Booked");

  rectangle(180,175,400,470);
  int x1=180,y1=180,count=0;
  for (int i =0; i<7;i++)
  {
      s+=4;
	if(strcmp(bus[l].seat[i][0], "Empty")==0){
	  notBookedSeat(x1+20,x1+50,y1+10,y1+40,count+1);
	}
	else
	{
		bookedSeat(x1+20,x1+50,y1+10,y1+40,count+1);
	}
	if(strcmp(bus[l].seat[i][1], "Empty")==0){
	  notBookedSeat(x1+65,x1+95,y1+10,y1+40,count+2);
	}
	else
	{
		bookedSeat(x1+65,x1+95,y1+10,y1+40,count+2);
	}
	if(strcmp(bus[l].seat[i][2], "Empty")==0){
	  notBookedSeat(x1+125,x1+155,y1+10,y1+40,count+3);
	}
	else
	{
		bookedSeat(x1+125,x1+155,y1+10,y1+40,count+3);
	}
	if(strcmp(bus[l].seat[i][3], "Empty")==0){
	  notBookedSeat(x1+170,x1+200,y1+10,y1+40,count+4);
	}
	else
	{
		bookedSeat(x1+170,x1+200,y1+10,y1+40,count+4);
	}
	count+=4 ;
	y1+=40;
  }
   // cout<<endl<<endl<<"There are "<<p<<" seats empty in Bus Number: "<<bus[l].busn;
}



void BusAvailability ::is_bus_available()
{
  for(int n=0;n<p;n++)
  {
	  if(bus[n].busn[0]!='\0') {
		cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
	cout<<"Bus number: "<<bus[n].busn<<endl<<"Driver: "<<bus[n].driver
	<<endl<<"Arrival time: "<<bus[n].arrival<<endl<<"Departure Time: "
	<<bus[n].depart<<endl<<"From: "<<bus[n].from<<endl<<"To: "
	<<bus[n].to;
	cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
	  }
  }
getch();
}

void main()
{
int gd=DETECT,gm,x1,y1,x2,y2,x,y,button;
initgraph(&gd,&gm,"..\\bgi");

if(initmouse()==0){
closegraph();
restorecrtmode();
cout<<"Mouse driver not loaded";
exit(1);
}

for(int n=0;n<p;n++)
{
  bus[n].busn[0] = '\0';
}

showmouseptr();
movemouseptr(&x,&y);

while(1){
int flag=0;
setbkcolor(11);
setcolor(1);
settextstyle(0,0,2);

outtextxy(140,30,"Bus Reservation System");

settextstyle(0,0,1);
normalbutton(80,200,80,200);
outtextxy(110,135,"Add Bus");
normalbutton(250,370,80,200);
outtextxy(266,135,"Reservation");
normalbutton(420,540,80,200);
outtextxy(450,135,"Show Bus");
normalbutton(165,285,250,370);
outtextxy(210,292,"Buses");
outtextxy(200,313,"Available");
normalbutton(335,455,250,370);
outtextxy(373,305,"Exit");
setcolor(1);
while(flag==0){
getmousepos(&button,&x,&y);
if((x<200&&x>80)&&(y<200&&y>80)){
	if((button & 1)==1){
	bt=1;
	delay(500);
	flag=1;
		cleardevice();
		bus[p].add_bus(bus);
		cleardevice();
		clrscr();

	}
}
else if((x<370&&x>250)&&(y<200&&y>80)){
	if((button & 1)==1){
		bt=2;
		delay(500);
		flag=1;
		cleardevice();
		bus[p].reserve_bus(p, bus);
		cleardevice();
		clrscr();

	}

       }
	else if((x<540&&x>420)&&(y<200&&y>80)){
		if((button & 1)==1){
		bt=3;
		delay(500);
		flag=1;
		cleardevice();
		bus[0].show_bus();
		cleardevice();
			clrscr();
		}
	}
	else if((x<285&&x>165)&&(y<370&&y>250)){
		if((button & 1)==1){
			bt=4;
			delay(500);
			flag=1;
			cleardevice();
			bus[0].is_bus_available();
			cleardevice();
			clrscr();
		}
	}
	else if((x<455&&x>335)&&(y<370&&y>250)){
		if((button & 1)==1){
			closegraph();
			exit(0);
		}
	}
	}

}
}
