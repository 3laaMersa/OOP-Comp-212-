#include<iostream>
#include<math.h>
using namespace std;
class Base{
public:
 int A[30];
	int a,b,n;
public:

	void read()
	{
		cout<<"Enter variable a: ";
		cin>>a;
		cout<<"Enter variable b: ";
		cin>>b;
	cout<<"Enter the size of the array: ";
		cin>>n;
		for(int i=0;i<n;i++){
				cout<<"Enter ["<<i+1<<"]: ";
				cin>>A[i];
		}
	}

	 int fact(int num)
	{
		int f=1;
		 if(num <= 1)
           f=1;
   else
	   for(int i=1;i<=num;i++)
		   f=f*i;
      return f;
	}
	 virtual int MaxFact(){
	 int max=A[0];
	  for(int i=0;i<n;i++)
	  {
	    if(A[i]>max)
			max=A[i];
	  }
	  return fact(max);
	 }
 void display() {
        cout << "Factorial: " << MaxFact() << endl;
    }
	
};
class Drive1:public virtual Base{
protected:
	int B[30];
public: 
   void set()
   { 
	   int sum=0;
	   for(int i=0;i<n;i++){
		  sum=0;
		   for(int j=1;j<A[i];j++){
		   if(A[i]%a==0 && A[i]!=0)
		     sum+=pow(j,2.0);
		   else
		     sum+=pow(j,3.0);
		  }
		   B[i]=sum;
		 }
   }
   int MaxFact(){
	  int max=B[0];
	  for(int i=0;i<n;i++)
	  {
	    if(B[i]>max)
			max=B[i];
	  }
	  return fact(max);
   }
};
class Drive2:public virtual Base{
protected:
	int C[30];
public: 
   void set()
   { 
	   int sum=0;
	   for(int i=0;i<n;i++){
		  sum=0;
		   for(int j=1;j<A[i];j++){
		   if(A[i]%b==0 && A[i]!=0)
		     sum+=pow(j,2.0);
		   else
		     sum+=pow(j,3.0);
		  }
		   C[i]=sum;
		 }
   }
  int MaxFact(){
	  int max=C[0];
	  for(int i=0;i<n;i++)
	  {
	    if(C[i]>max)
			max=C[i];
	  }
	  return fact(max);
   }
};
class Drive:public Drive1,public Drive2{
	int D[3];
public:
	void set()
	{
		Drive1::set();
		Drive2::set();
	   D[0]=A[0],D[1]=B[0],D[2]=C[0];
		for(int i=1;i<n;i++)
		{
		  if(D[0]<A[i])
			  D[0]=A[i];
		  
		  if(D[1]<B[i])
			  D[1]=B[i];
		  
		  if(D[2]<C[i])
			  D[2]=C[i];
		}
			
   }
int MaxFact(){
	  return fact(D[0]+D[1]+D[2]);
}
}; 
void main()
{

	Drive1 d1;
	Drive2 d2;
	Drive d;
	Base *b1,*b2,b3,*b4;

	d.read();
	d.set();

    b1 = &d1;
    b2 = &d2;
    b4 = &d;

  cout << "Factorial for Drive1: ";
    b1->display();

    cout << "Factorial for Drive2: ";
    b2->display();

    cout << "Factorial for Drive: ";
    b4->display();
	
	system("pause");
}