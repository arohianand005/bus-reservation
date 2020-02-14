#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <string.h>
#include <stdlib.h>
#include "Bus.cpp"

class BusReservation : public Bus
{
public:
  void show_bus();
  void reserve_bus(int p, BusReservation* bus);
};

 void BusReservation ::show_bus()
 {
	cout<<"No Bus Available."<<endl;
 }

void BusReservation::reserve_bus(int p, BusReservation* bus)
{
  int seat;
  char number[5];
  cout<<"Bus number: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }//for
  while(n<=p)
  {
    cout<<endl<<"Seat Number: ";
    cin>>seat;
    if(seat>24)
    {
      cout<<endl<<"There are only 32 seats available in this bus.";
    }//if
    else
    {
      if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
	cout<<"Enter passanger's name: ";
	cin>>bus[n].seat[seat/4][(seat%4)-1];
	break;
      }//if
    else
      cout<<"The seat no. is already reserved."<<endl;
     }//else
    }//while
    if(n>p)
    {
      cout<<"Enter correct bus no."<<endl;
	  cout<<"Press enter to main menu....";
    }//if
	else {
		   cout<<endl<<" Added Successfully....";
	}
	getch();
}//BusReservation::reserve_bus

