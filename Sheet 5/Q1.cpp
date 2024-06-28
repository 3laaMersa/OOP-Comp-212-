#include<iostream>
#include<string>
using namespace std;
class GCD{
	float X[20],Y[20];
public:
	int n,G[20];
public:
float gcd(float x,float y)
{
   if(y==0)
      return x;
   else
      return gcd(y,fmod(x,y));
}
void read()
{
	cout<<"Enter number of elements"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
	  cout<<"Num 1: ";
	  cin>>X[i];
	  cout<<endl;
	  cout<<"Num 2: ";
	  cin>>Y[i];
	  cout<<endl;
	  G[i]=gcd(X[i],Y[i]);
	}
}
void display(){
	for(int i=0;i<n;i++){
	cout<<"GCD("<<X[i]<<","<<Y[i]<<") = "<<G[i]<<endl;
	cout<<"***************************************"<<endl;
	}
}
friend float avg( GCD obj);
friend GCD maxAverage(GCD obj1, GCD obj2);
};
float avg(GCD obj) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < obj.n; i++) {
        if (obj.G[i] > 2) {
            sum += obj.G[i];
            count++;
        }
    }
    if (count == 0)
        return 0;
    return float(sum) / count;
}

GCD maxAverage(GCD obj1, GCD obj2) {
    float avg1 = avg(obj1);
    float avg2 = avg(obj2);

    if (avg1 > avg2)
        return obj1;
    else
        return obj2;
}


void main()
{
	
	system("pause");
}