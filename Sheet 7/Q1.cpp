#include<iostream>
using namespace std;
class Data{
	double A[20],B[20];
public:
	int n;
	friend istream& operator >>(istream& in,Data &d){
		cout<<"Enter number of elements:"<<endl;
		in>>d.n;
		cout<<"Enter A elements : "<<endl;
		for(int i=0;i<d.n;i++)
			in>>d.A[i];
		return in;
	}
	void set()
	{
		double sum=0;
	  for(int i=0;i<n;i++)
	  {
		  sum=0;
	    for(int j=0;j<=i;j++)
		  sum+=pow(A[j],2);
	   B[i]=sum;
	  }
	}
	friend ostream& operator <<(ostream& out,Data &d){
		for(int i=0;i<d.n;i++)
		out<<d.A[i]<<" "<<endl;
		return out;
		cout<<endl;
	}
	Data operator *=(Data x){
		for(int i=0;i<x.n;i++)
			A[i]*=x.A[i];
		return *this;
	}
	Data operator *(Data x){
		Data z;
		for(int i=0;i<x.n;i++)
		z.B[i]=B[i]*x.B[i];
		return z;
	}
	friend Data operator *(Data x,double c){
		Data z;
		for(int i=0;i<x.n;i++){
		z.B[i]=x.B[i]*c;
		z.A[i]=x.A[i]*c;
		}
		return z;
	}
		//--x(prefix) is similar
	Data operator ++(){//++x(prefix)
		for(int i=0;i<n;i++) B[i]+=1;
		return *this;
	}
	//x--(postfix) is similar
	Data operator ++(int){ //x++(postfix)
		Data t=*this;
		for(int i=0;i<n;i++) B[i]+=1;
		return t;
	}
	bool operator > (Data d){
		for(int i=0;i<n;i++)
			if(A[i]<d.A[i]) return false;
		return true;
	}
	bool operator < (Data d){
		for(int i=0;i<n;i++)
			if(B[i]>d.B[i]) return false;
		return true;
	}
	double operator [](int i){
		return B[i];
	}
	friend void CompareMin(Data d1,Data d2);
	friend void CompareMax(Data d1,Data d2);
};
  void CompareMin(Data d1,Data d2)
{
 if(d1>d2)
	 cout<<d1<<endl;
 else
	 cout<<d2<<endl;
}
   void CompareMax(Data d1,Data d2)
{
 if(d1<d2)
	 for(int i=0;i<d1.n;i++)
	 cout<<d1[i]<<endl;
 else
	 for(int i=0;i<d2.n;i++)
	 cout<<d2[i]<<endl;
}
void main()
{
	Data d1,d2;
	cin>>d1;
	cin>>d2;
	
	
//	d1*=d2;

	cout<<"\nComaprison of Max for A elements"<<endl;
    CompareMin(d1,d2);

    d1.set();
	d2.set();
	cout<<"\nElements of B for d1"<<endl;
	for(int i=0;i<d1.n;i++)
	 cout<<d1[i]<<endl;

	cout<<"\nElements of B for d2"<<endl;
	for(int i=0;i<d2.n;i++)
	 cout<<d2[i]<<endl;
	cout<<"\nComaprison of Min for B elements"<<endl;
    CompareMax(d1,d2);

  system("pause");

}