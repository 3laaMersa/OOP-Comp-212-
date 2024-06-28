#include<iostream>
#include<math.h>
using namespace std;

int distance(int x1=2, int y1=3, int x2 = 4, int y2 = 5)
{
     return sqrt(pow((double)(x2 - x1), 2) +pow((double)(y2 - y1), 2) );
}
void swap(int &x1,int &y1,int &x2,int &y2)
{
	int temp;
	temp = x1;
    x1 = x2;
    x2 = temp;

    temp = y1;
    y1 = y2;
    y2 = temp;
}
void display(int x1, int y1, int x2 , int y2 )
{
  
	cout<<"Point 1 : "<<"("<<x1<<","<<y1<<") ";
	cout<<"Point 2 : "<<"("<<x2<<","<<y2<<")"<<endl;
}
void main()
{
	int x1,x2,y1,y2;
	cout<<"Enter Point 1 \n x1 :"<<endl;
	cin>>x1;
	cout<<"y1 : "<<endl;
	cin>>y1;
	cout<<"Enter Point 2 \n x2 :"<<endl;
	cin>>x2;
	cout<<"y2 : "<<endl;
	cin>>y2;

	cout<<"The distance between two points form 1 : "<<distance(x1,y1,x2,y2)<<endl;
	cout<<"The distance between two points form 2 : "<<distance()<<endl;
	cout<<"The distance between two points form 3 : "<<distance(x1,y1)<<endl;
	cout<<"The distance between two points form 4 : "<<distance(x1,y2,x2)<<endl;
	display(x1,y1,x2,y2);

    swap(x1,y1,x2,y2);
	cout<<"After swap the two points : "<<endl;
	display(x1,y1,x2,y2);


	

 system("pause");
}