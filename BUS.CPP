#include <conio.h>
#include <stdio.h>
#include<fstream.h>
#include <iostream.h>
#include <string.h>
#include <stdlib.h>

static int p = 0;
class Bus
{

public:
  char busn[5];
  char driver[10];
  char arrival[5];
  char depart[5];
  char from[10];
  char to[10];
  char seat[8][4][10];

public:
  void empty(int p, Bus* bus);
  void add_bus(Bus* bus);
};

void Bus::empty(int p, Bus* bus)
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}


void Bus::add_bus(Bus* bus)
{
  cout<<"\n\n\n\n\n\n\n\n";
  cout<<"\t\tEnter bus number: ";
  cin>>bus[p].busn;

  cout<<"\t\tEnter Driver's name: ";
  cin>>bus[p].driver;

  cout<<"\t\tArrival time: ";
  cin>>bus[p].arrival;

  cout<<"\t\tDeparture: ";
  cin>>bus[p].depart;

  cout<<"\t\tFrom: ";
  cin>>bus[p].from;

  cout<<"\t\tTo: ";
  cin>>bus[p].to;

   cout<<endl<<"\n\n\t\t   Added Successfully....";
   ofstream outfile;
   outfile.open("busDetails.dat",ios::app);
   outfile << bus[p].busn <<"\n   "<< bus[p].driver<<"   " << bus[p].arrival <<"   "<< bus[p].depart <<"   "<< bus[p].from<<"   " << bus[p].to;
   outfile.close();
  bus[p].empty(p, bus);
  p++;

  getch();
}

