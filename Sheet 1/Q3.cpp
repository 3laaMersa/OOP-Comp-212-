#include<iostream>
using namespace std;
void read(int arr[],int n)
	{
		
	 cout<<"Enter array values"<<endl;
	 for(int i=0;i<n;i++)
	 {
	   cin>>arr[i];
	 }
	}
int checkprime(int num)
{
 for(int j=2;j<num;j++)
 {
 if(num%j==0)
 return 0;
else
return 1;
 }
}
int Average(int arr[])
{
	int prod=1,c=0;
	 for (int i = 0; i < 5; i++)
    {
        if(checkprime(arr[i])==1){
		c++;
        prod *= arr[i];
		}
    }
	 return prod/c;
}
int Average(int arr[],char ch)
{
	int prod=1,c=0;
	if(ch =='E' || ch=='e'){
	 for (int i = 0; i < 5; i++)    
	{	 if(arr[i]%2==0){
		   c++;
		   prod *= arr[i];
	 }
	}
	 return prod/c;
	}
	else if(ch =='O' || ch=='o')
	{
	  for (int i = 0; i < 10; i++)    
	{	 if(arr[i]%3==0){
		    c++;
		    prod *= arr[i];
	  }
		 
	}
	  return prod/c;
	}
	else
	{
	  return 0;
	}

}
void main()
{
	int arr[100],n;

	char c;
	
	cout<<"Enter number of array elements"<<endl;
	cin>>n;
	read(arr,n);

	cout<<Average(arr)<<endl;
	cout <<"\nEnter your char o for odd and e for even"<<endl;
	cin>>c;
	cout<<Average(arr,c)<<endl;


 system("pause");
}