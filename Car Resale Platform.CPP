#include<dos.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>
class car_resale
{
private:
char model[50];
float price;
int use;
float dist;
long idno;
public:
void get();
void show();
long retno();
};
void car_resale::get()
{
cout<<"Enter car model: "; gets(model);
cout<<"Enter VIN number: "; cin>>idno;
cout<<"How much do you want to sell your vehicle for?"; cin>>price;
cout<<"How many years has the vehicle been in use?"; cin>>use;
cout<<"Approximate usage of vehicle? (in kilometers)"; cin>>dist;
}
void car_resale::show()
{
cout<<"\n\nCar model: "; puts(model);
cout<<"VIN number: "<<idno;
cout<<"\nPrice: "<<price;
cout<<"\nUsage: "<<use;
cout<<"\nDriven for(in kilometers): "<<dist;
}
long car_resale::retno()
{
return idno;
}
void main()
{
clrscr();
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"*******************************************************************************";
cout<<endl;
cout<<"                       WELCOME TO FPCS CAR SALES                       ";
cout<<endl<<"*******************************************************************************";
delay(5000);
clrscr();
ofstream f1; car_resale a; int n, ch; char ch1;
f1.open("car.dat", ios::out|ios::binary);
cout<<"\nHow many records do you wish to store? "; cin>>n;
for(int i=0; i<n; i++)
{
a.get();
f1.write((char*)&a,sizeof(a));
}
f1.close();
do
{
clrscr();
cout<<"\nCase 1: Append";
cout<<"\nCase 2: Modify";
cout<<"\nCase 3: Search";
cout<<"\nCase 4: Delete";
cout<<"\nCase 5: Display";
cout<<"\nCase 6: Exit";
cout<<"\nEnter your choice: "; cin>>ch;
switch(ch)
{
case 1:
f1.open("car.dat",ios::app|ios::binary);
a.get();
f1.write((char*)&a,sizeof(a));
f1.close();
break;
case 2:
ofstream f2;
f2.open("car.dat", ios::out|ios::ate|ios::binary);
int n1;
cout<<"\nEnter the record which has to be modified: "; cin>>n1;
int x=(n1-1)*sizeof(a);
f2.seekp(x,ios::beg);
a.get();
f2.write((char*)&a,sizeof(a));
f2.close();
break;
case 3:
ifstream f3; int flag=0;
f3.open("car.dat",ios::in|ios::binary);
f3.seekg(0,ios::beg);
long id;
cout<<"\nEnter VIN number: "; cin>>id;
while(f3.read((char*)&a,sizeof(a)))
{
if(a.retno()==id)
{
a.show();
flag=1;
}}
if(flag==0)
cout<<"\nID number not found. SORRY!";
f3.close();
break;
case 4:
ofstream f41; ifstream f42; long c;
f42.open("car.dat",ios::in|ios::binary);
f41.open("newcar.dat",ios::out|ios::app|ios::binary);
f42.seekg(0,ios::beg);
cout<<"\nEnter vin number: "; cin>>c;
while(f42.read((char*)&a,sizeof(a)))
{
if(c!=a.retno())
f41.write((char*)&a,sizeof(a));
}
remove("car.dat"); rename("newcar.dat","car.dat");
f41.close(); f42.close();
break;
case 5:
ifstream f5;
f5.open("car.dat",ios::in|ios::binary);
f5.seekg(0,ios::beg);
while(f5.read((char*)&a,sizeof(a)))
a.show();
f5.close();
break;
case 6:
clrscr();
cout<<"_*_*_*_*_*_*_*_*_**_*_*_*_*_*_*_*_*_*_*_*_*_*_*_**_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
cout<<"                               ************************************;
cout<<"\n                          *      Thank you for using FPCS!!            *           ";
cout<<"                               ************************************;
cout<<"_*_*_*_*_*_*_*_*_**_*_*_*_*_*_*_*_*_*_*_*_*_*_*_**_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
delay(5000);
exit(0);
}
cout<<"\nDo you wish to continue? "; cin>>ch1;
}
while(ch1=='Y'||ch1=='y');
getch();
}




