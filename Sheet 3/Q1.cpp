#include<iostream>
#include<math.h>
using namespace std;
class Data{
private:
	float X[30];
	int h,n;
	char T[30];
public:
	void read(){
	  cout<<"Enter a constant number"<<endl;
	  cin>>h;
	   cout<<"Enter number of elements to test if divisibale by the constant number"<<endl;
	   cin>>n;
	   cout<<"Enter array elements"<<endl;
	   for(int i=0;i<n;i++)
	   {
	     cout<<"X["<<(i+1)<<"]: ";
		 cin>>X[i];
		 if(fmod(X[i],h)==0)
			 T[i]='Y';
		 else
			 T[i]='N';
	   }
 	
	}
   int CountX()
   {
	   int count=0;
     for(int i=0;i<n;i++){
		 if(T[i]=='N')
			 count++;
	 }
	 return count;
   }
   float AverageX(){
     int sum=0;
     for(int i=0;i<n;i++){
		 if(T[i]=='Y')
			 sum+=X[i];
	 }
	 float avg=sum/(n-CountX());
	 return avg;
   }
   void display(){
	   cout<<"X values \t     T values"<<endl;
    for(int i=0;i<n;i++)
		cout<<X[i]<<" \t\t\t "<<T[i]<<endl;
   }
   void compare(Data d1){
	   if(AverageX()>d1.AverageX())
		   cout<<"MAx average = "<<AverageX()<<endl;
	   else
		   cout<<"MAx average = "<<d1.AverageX()<<endl;
   
   }
};
void main()
{
	
Data d1,d2;

    d1.read(); d2.read();
    d1.compare(d2);
    d1.display();
	d2.display();
  system("pause");
}