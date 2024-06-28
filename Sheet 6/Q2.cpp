#include<iostream>
using namespace std;
class Student{
	float SM[10][10];
	int n;
	
public:
	void read (){
		cout<<"\nEnter the size of the matrix: ";
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n-1;j++){
				cout<<"enter ["<<i+1<<","<<j+1<<"]: ";
				cin>>SM[i][j];
			}
		}
	}
	void set()
	{
		double sum=0;
	 for(int i=0;i<=n-1;i++){
		 sum=0;
		 for(int j=0;j<=n-2;j++){
		        sum+=SM[i][j];
			 }
			 SM[i][n-1]=sum;
		 }
	}
	void display(){	
		for(int i=0;i<n;i++){
			cout<<endl;
			for(int j=0;j<n;j++)
				cout<<SM[i][j]<<" ";

		}
	
	}
	
	int operator [](int i){
		return M[i][n-1];
	}
	Matrix operator -= (Matrix x){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				M[i][j]-=x.M[i][j];
			}
		}
		return *this;
	}
	friend Student operator + (Student x,float y){
		Student z;
		 z.n=x.n;
		for(int i=0;i<x.n;i++) {
			for(int j=0;j<x.n;j++){
				z.SM[i][j] = 0;
				z.SM[i][j]=x.SM[i][j]+y;}
		}
		return z;
	}
	
	Student operator*(float c)  {
        Student z;
        z.n = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
				z.SM[i][j] = 0;
                z.SM[i][j] = SM[i][j] * c;
            }
      
        }
        return z;
    }
	bool operator == (Student x){
		for(int i=0;i<n;i++){
				if(SM[i][n-1] != x.SM[i][n-1])
					return false;
			
		}
		return true;
	}
	bool operator >= (Student x){
		for(int i=0;i<n;i++){
				if(SM[i][n-1] < x.SM[i][n-1])
					return false;
			
		}
		return true;
	}
	

};

void main()
{
	


	system("pause");
}