/*
Write a program contains two classes Ser1, Ser2. Class Ser1 has data members:
SX[30] (float) , x[30] (float), n (number of elements), a function to read data
members and to set the elements of SX such that each SXi

is equal to the *******************************
for i=0,.., n-1, a function to return max element in SX, and a function
to display data members. Class Ser2 has data members: SY[30](float), y[30]
(float), m (number of elements), a function to read data members and to set the
elements of SY such that each SYi

is equal to ********************************

for i=0,..,m-1, a function
to return the max element in SY, and a function to display data members. These
classes contain a friend function to compares between max elements for two
given objects of two classes, and display the max object, and a friend function to
return the following average ***************************************

where SX and SY are data
members for the given two objects. In main function define two objects of two
classes, and apply all functions on them.
*/

#include<iostream>
#include<cmath>
#include<math.h>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;
class ser2;
class ser1
{
    float sx[30] ,x[30] ;
    int n;
    public:
    void read()
    {
        cout<<"eneter the number of element ";
        cin>>n;
        for(int i=0 ;i<n ; i++)
        {
            cin>>x[i];
        }
        for(int i=0 ;i<n ; i++)
        {
            sx[i]=0;
            for(int j=0 ; j<i ;j++)
            {
                sx[i]+=(i+j)/(pow(x[j],2)+1);
            }
        }
    }
    float maximum()
    {
        float max=sx[0];
        for(int i=1 ; i<n ; i++)
        {
            if(sx[i]>max)
            {
                max=sx[i];
            }
        }
        return max;
    }
    void display()
    {
        cout << "x: ";
        for(int i = 0; i < n; i++) {
            cout << x[i] << " ";
        }
        cout << endl << "sx: ";
        for(int i = 0; i < n; i++) {
            cout << sx[i] << " ";
        }
        cout << endl;
    }
    friend bool compare(ser1 x , ser2 y);
    friend float avareage(ser1 x , ser2 y);
};
class ser2
{
    float sy[30] , y[30];
    int m;
    public:
    void read()
    {
        cout<<"eneter the number of element ";
        cin>>m;
        for(int i=0 ;i<m ; i++)
        {
            cin>>y[i];
        }
        for(int i=0 ;i<m ; i++)
        {
            sy[i]=0;
            for(int j=0 ; j<i ;j++)
            {
                sy[i]+=(i+j)/(pow(y[j],2)+1);
            }
        }
    }
    float maximum()
    {
        float max=sy[0];
        for(int i=1 ; i<m ; i++)
        {
            if(sy[i]>max)
            {
                max=sy[i];
            }
        }
        return max;
    }
    void display()
    {
        cout << "y: ";
        for(int i = 0; i < m; i++) {
            cout << y[i] << " ";
        }
        cout << endl << "sy: ";
        for(int i = 0; i < m; i++) {
            cout << sy[i] << " ";
        }
        cout << endl;
    }
    friend bool compare(ser1 x , ser2 y);
    friend float avareage(ser1 x , ser2 y);
};
bool compare(ser1 x, ser2 y) 
{
    if(x.maximum() > y.maximum()) {
        cout << "The max element of ser1 is greater." << endl;
        cout<<x.maximum();
        return true;
    } else {
        cout << "The max element of ser2 is greater." << endl;
        cout<<y.maximum();
        return false;
    }
}
float avareage(ser1 x , ser2 y)
{
    float avg=0;
    avg=((x.sx[0]+x.sx[x.n-1])+(y.sy[0]+y.sy[y.m-1]))/4.0;
    return avg;
}
int main() {
    ser1 x1, x2;
    ser2 y1, y2;

    cout << "Enter data for ser1 x1:" << endl;
    x1.read();
    cout << "Enter data for ser1 x2:" << endl;
    x2.read();
    cout << "Enter data for ser2 y1:" << endl;
    y1.read();
    cout << "Enter data for ser2 y2:" << endl;
    y2.read();

    cout << "Comparing maximum elements of ser1 x1 and ser2 y1:" << endl;
    compare(x1, y1);

    cout << "Comparing maximum elements of ser1 x2 and ser2 y2:" << endl;
    compare(x2, y2);

    cout << "Average of sx[0], sx[n-1], sy[0], sy[m-1] for x1 and y1: " << avareage(x1, y1) << endl;
    cout << "Average of sx[0], sx[n-1], sy[0], sy[m-1] for x2 and y2: " << avareage(x2, y2) << endl;

    x1.display();
    x2.display();
    y1.display();
    y2.display();

    return 0;
}