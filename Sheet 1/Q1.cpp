#include<iostream>
using namespace std;

void reverseNumber(int num)
{
  int rev = 0;
  while(num != 0) {
    rev = rev * 10 + num % 10;
    num /= 10;
  }

  cout<<"Reverse number is : "<< rev<<endl;
}

int countDigit(int num)
{
    int count = 0;
    while (num != 0)
    {
        num = num / 10;
        count ++;
    }
    return count;
}


void accept(int num1,int num2)
{
	int p=1;
	for(int i=1;i<=num2;i++)
	{
	p=num1*p;
	}
}

void main()
{
	int num1,num2;
	cout<<"Enter Two Integer numbers : "<<endl;
	cin>>num1>>num2;
    cout<<"Number 1 check"<<endl;
    reverseNumber(num1);
    cout<<"Number of Digits is : "<<countDigit(num1)<<endl;

     cout<<"Number 2 check"<<endl;
    reverseNumber(num2);
    cout<<"Number of Digits is : "<<countDigit(num2)<<endl;
    accept(num1,num2);

 system("pause");
}