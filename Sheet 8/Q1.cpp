#include<iostream>
#include<string>
using namespace std;
class Data_X{
public:
  double X[30];
  int y;
  int n;
public:
	friend istream& operator >>(istream &in,Data_X &d1){
		cout<<"Enter y "<<endl;
		in>>d1.y;
		cout<<"Enter number of elements"<<endl;
		in>>d1.n;
		cout<<"Enter elements "<<endl;
		for(int i=0;i<d1.n;i++)
			in>>d1.X[i];


	return in;
	}

	friend ostream& operator <<(ostream &out,Data_X d1){	
		cout<<"Value of y "<<endl;
		out<<d1.y;
		cout<<"Number of elements"<<endl;
		out<<d1.n;
		cout<<"Elements "<<endl;
		for(int i=0;i<d1.n;i++)
			out<<d1.X[i];

		return out;
	}
	
	double SumOfX(){
	double sum=0;
	for(int i=0;i<n;i++)
			sum+=X[i];
	return sum;
	}
};
class Data{
 double B[30];
 Data_X A[30];
 int n;
public :
	void read()
	{
	  
	 double s=0;
	  cout << "Enter number of elements: "<<endl;
        cin >> n;
       cout << "Enter data for each element of A "<<endl;
        for (int i = 0; i < n; i++) {
           cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
			s=0;
			for(int j=0;j<n;j++)
			{
				if(fmod(A[i].X[j],A[i].y)==0)
					s+=pow(A[i].X[j],2);
				else
					s+=pow(A[i].X[j],3);

			}
			B[i]=s;
        }

	}
	 friend double SumOfEachXinA(Data d) {
        double sum = 0;
        for (int i = 0; i < d.n; i++) {
            sum += d.A[i].SumOfX();
        }
        return sum;
    }

    friend double maxSum(Data d) {
		double max = d.A[0].SumOfX();
        for (int i = 1; i < d.n; i++) {
            if (max < d.A[i].SumOfX()) {
                max = d.A[i].SumOfX();
            }
        }
        return max;
    }
	friend void compareMaxSum(Data d1,Data d2) {
        if (maxSum(d1) > maxSum(d2)) {
           cout << "D1 is max"<<endl;
        } else if (maxSum(d1) < maxSum(d2)) {
                    cout << "D2 is max"<<endl;
        } else {
                    cout << "D1 is equal D2"<<endl;
        }
    }
};

void main()
{
	Data a;
	a.read();
	cout<<"Data summation of Xs = "<<SumOfEachXinA(a)<<endl;
	cout<<"Data Max sum = "<<maxSum(a)<<endl;

  system("pause");
}