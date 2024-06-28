#include<iostream>
using namespace std;
class EQ{
private : 
	float a,b,c;
public:
	EQ(float a1=2,float b2=3, float c3=4):a(a1),b(b2),c(c3){}
	void Quadratic(){
		float discriminant = pow(b,2) - (4 * a *c);
		float r1,r2;
	if(discriminant > 0)
	  	{
	  	    r1 = (-b + sqrt(discriminant) / (2 * a));
	  	    r2 = (-b - sqrt(discriminant) / (2 * a));
	  	    cout<<"Root1 = " << r1 << "\t\t Root2 = " << r2<<endl;
	  	}
	  	else if(discriminant == 0)
	  	{
	  	    r1 = r2 = -b / (2 * a);
	  	     cout<<"Root1 = " << r1 << "\t\t Root2 = " << r2<<endl;
	  	}
	  	else 
	  	{
	  	  r1 = r2 = -b / (2 * a);
	  	  float imaginary = sqrt(-discriminant) / (2 * a);
	  	  cout<<"Root1 = " <<r1 << " + " << imaginary << " \t\t Root2 = " << r2 <<" - " <<imaginary<<endl;
	  	}
	}
};
void main()
{

	EQ t(2,3,4);
	t.Quadratic();

	EQ t2(5,6,7);
	t2.Quadratic();

	EQ t3(8,9,10);
	t3.Quadratic();
 system("pause");
}