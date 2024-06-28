#include<iostream>
using namespace std;
class Data{
	int D[10];
	double F[20];
	int n;
public:
	int fact(int f){
		if f==0
			f=1;
	return f*fact(f-1);
	}
	int combination (int a,int b){
	
	return fact(a)/(fact(b)*fact(a-b));
	}
	void read()
	{
	
		cout<<"Enter number of elements"<<endl;
		cin>>n;
		for(int i=0;i<n;i++){
		cout<<"Enter element "<<(i+1)<<endl;
		cin>>D[i];
		}
	}
		void set (){
		int sum=0;
		for(int i=0;i<n;i++){
		sum=0;
		for(int k=0;k<=i+1;k++)
		{
		  sum+=combination(i+1,k)*D[k];
		}
		F[i]=fact(sum);
		}
		}
		double sumF(){
			double sum=0;
		for(int i=0;i<n;i++)
			sum+=F[i];
		return sum;
		}
	void display(){
	  cout<<"D values \t     F values"<<endl;
    for(int i=0;i<n;i++)
		cout<<D[i]<<" \t\t\t "<<F[i]<<endl;
   }
	
	
	bool operator != (Data x){
		if(sumF() == x.sumF())
			return false;
		return true;
	}
	
	bool operator < (Data x){
		x.n=n;
		for(int i=0;i<n;i++){
				if(D[i]>=x.D[i])
					return false;

		}
		return true;
	}
	Data operator -(Data t){
		Data z;
		z.n=n;
		t.n=n;
		for(int i=0;i<t.n;i++){
			z.D[i]=D[i]-t.D[i];
		}
		z.set();
		return z;
	}
	friend Data operator *(Data t,double c){
		Data z;
		z.n=n;
		for(int i=0;i<t.n;i++){
		z.D[i]=t.D[i]*c;
		}
		z.set();
		return z;
	}

};

void main()
{
	Data d1, d2,d3,d4;
    d1.read();
    d1.set();
    cout << "SumF data 1: " << d1.sumF() << endl;
    cout<<"Data 1"<<endl;
    d1.display();


    d2.read();
    d2.set();
    cout << "SumF of data 2: " << d2.sumF() << endl;
    cout<<"Data 2"<<endl;
    d2.display();

 
    d3 = d1 - d2;
    cout << "Data 3" << endl;
    d3.display();


    int c = 3;
    d4 = d1 * c;
    cout << "Data 4 "<<endl;
    d4.display();


	system("pause");
}