#include<iostream>
using namespace std;
class Mark{
	double M[10][10];
	
public:
	int n;
	friend istream& operator >>(istream &in,Mark &x){
		cout<<"\nEnter the size of the matrix: ";
		in>>x.n;
		for(int i=0;i<x.n;i++){
			for(int j=0;j<x.n-1;j++){
				cout<<"enter ["<<i+1<<","<<j+1<<"]: ";in>>x.M[i][j];
			}
		}
		return in;
	}
	friend ostream& operator <<(ostream &out,Mark x){	
		for(int i=0;i<x.n;i++){
			out<<endl;
			for(int j=0;j<x.n-1;j++)
				out<<x.M[i][j]<<" ";
			
		
		}
		out<<endl;
		return out;
	}
	void set()
	{
		double sum=0;
	 for(int i=0;i<=n-1;i++){
		 for(int j=0;j<=n-2;j++)
		 sum+=M[i][j];
			 M[i][n-1]=sum;
		     
		 }
	}
	int operator [](int i){
		return M[i][n-1];
	}
	Mark operator += (Mark x){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				M[i][j]+=x.M[i][j];
			}
		}
		return *this;
	}
	friend Mark operator + (Mark x,Mark y){
		Mark z;
		 z.n=x.n;
		for(int i=0;i<x.n;i++) {
			for(int j=0;j<x.n;j++){
				z.M[i][j] = 0;
				z.M[i][j]=x.M[i][j]+y.M[i][j];}
		}
		return z;
	}
	
	

	bool operator > (Mark x){
		for(int i=0;i<n;i++){
				if(M[i][n-1] < x.M[i][n-1])
					return false;
			
		}
		return true;
	}
	bool operator < (Mark x){
		for(int i=0;i<n;i++){
			for(int j=0;j<n-1;j++){
				if(M[i][j]>x.M[i][j])
					return false;
			}
		}
		return true;
	}
	Mark operator -- (){ //--M(prefix)
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				M[i][j]--;
			}
		}
		return *this;
	}
	Mark operator -- (int){ //M--(postfix)
		Mark z=*this;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				M[i][j]--;
			}
		}
		return z;
	}
	friend void CompareMin(Mark M1,Mark M2);
	friend void CompareMax(Mark M1,Mark M2);

};
void CompareMin(Mark d1,Mark d2)
{
 if(d1<d2)
	 cout<<d1<<endl;
 else
	 cout<<d2<<endl;
}
   void CompareMax(Mark d1,Mark d2)
{
 for(int i=0;i<d1.n;i++)
 {
   if(d1.M[i][d1.n-1] > d2.M[i][d2.n-1])
	   cout<<d1[i]<<endl;
      else
       cout<<d2[i]<<endl;
 
 }
   }
void main()
{
	Mark x,y,z;
	cin>>x;
	x.set();

	cout<<"\nMatrix X elements except last column ";
	cout<<x;

	cout<<"\nLast column for matrix X is "<<endl;
	for(int i=0;i<x.n;i++)
	cout<<x[i]<<endl;

	cin>>y;
	y.set(); 
	
	cout<<"\nMatrix Y elements except last column ";
	cout<<y;

	cout<<"\nLast column for matrix Y is "<<endl;
	for(int i=0;i<y.n;i++)
	cout<<y[i]<<endl;

	x+=y;
	cout<<"\nMatrix X elements after summation";
	cout<<x;
	cout<<"\nLast column for matrix X after summation "<<endl;
	for(int i=0;i<x.n;i++)
	cout<<x[i]<<endl;
	z=x+y;

	cout<<"\nZ elements after summation of X and Y";
	cout<<z;

	cout<<"\nLast column for matrix Z is "<<endl;
	for(int i=0;i<x.n;i++)
	cout<<z[i]<<endl;

	cout<<"\nMAx object"<<endl;
	CompareMax(x,y);
	cout<<"\nMin object"<<endl;
	CompareMin(x,y);
	system("pause");
}