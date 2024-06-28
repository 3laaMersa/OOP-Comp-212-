#include<iostream>
using namespace std;
class Data{
	protected:
    double D[30][30];
	int n;
public:
	void read()
	{
	cout<<"enter the size of the matrix: ";
		cin>>n;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n;j++){
				cout<<"Enter ["<<i+1<<","<<j+1<<"]: ";
				cin>>D[i][j];
			}
		}
	}
	

bool isprime(int n) {
  bool prime = true;

  if (n == 0 || n == 1) {
    prime = false;
  }

  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      prime = false;
      break;
    }
  }

  return prime;
}
	double MaxPrime(int m)
	{
		
	double max=-999999;
	  for(int i=0;i<n-1;i++){
		if(isprime(D[i][m])==true && max<D[i][m])
	       max=D[i][m];
	  }
	  return max;
	}
	void set()
	{
	 for(int i=0;i<n;i++){
		 D[n-1][i]=MaxPrime(i);
	 }
	}
	//average of last row 
	virtual float average()
	{
	 int sum=0;
	 float avg=0;
	 for(int i=0;i<n;i++)
		 sum+=D[n-1][i];
	 avg=sum/n;
	 return avg;
	}
	void DisplayAvg()
	{
	  cout<<"Average "<<average()<<endl;
	}
	void display()
{
cout<<"Matrix display"<<endl;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
cout<<" "<<D[i][j]<<" ";
cout<<endl;
}
}

};
class Data1 : public Data{
 double D1[30];
public:
	int fact(int num)
	{
		 if(num <= 1)
      return(1);
   else
      return(num * fact(num-1));
	}
	void set()
	{
	 for(int i=0;i<n;i++)
	 {
	  D1[i]=fact(D[n-1][i]);
	 }
	}
	float average()
	{
	float sum=0;
	for(int i=0;i<n;i++)
	 {
	  sum+=D1[i];
	 }
	 return sum/n;
	}
};


void main()
{

	Data1 b1;
	Data *b2,b3;
	b1.Data::read();
	b1.Data::set();
	b1.display();
	b3=b1;
	b3.DisplayAvg();
	b2=&b1;
	cout<<"second class "<<endl;
	b1.set();
	b2->average();
	b2->DisplayAvg();
	system("pause");
}