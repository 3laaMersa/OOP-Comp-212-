#include<iostream>
#include<string>
using namespace std;
struct course{
	string C_name;
	float Degree;
	int Credit;
};
class Level
{
protected:
	course L[5];
public:
	void read()
	{
		for(int i=0;i<5;i++)
		{
			cout<<"Enter Course " << i + 1 << " details:\n";
		    cout<<"course name :";
			cin>>L[i].C_name;
		    cout<<"course degree :";
			cin>>L[i].Degree;
		    cout<<"course credit houres : ";
			cin>>L[i].Credit;
		}
	}

	void Display()
	{
		cout<<"\t\t course name \t\t course degree \t\t credit houres "<<endl;
		for(int i=0;i<5;i++)
			cout<<"\t\t "<<L[i].C_name<<"   \t\t\t "<<L[i].Degree<<"   \t\t\t "<<L[i].Credit<<endl;
	}

};

class Student : public Level
{
	string name;
	char GPA;
	float totald;
	int totalc;
	int id;
public:
	void read()
	{
		cout<<"enter student id : ";
		cin>>id;
		cout<<"enter student name : ";
		cin>>name;
		Level::read();
		totald=0;
		totalc=0;
		for(int i=0;i<5;i++)
		{
			totald+=L[i].Degree;
			totalc+=L[i].Credit;
		}

		float average_degree = totald / 5;
        if (average_degree >= 90) {
            GPA = 'A';
        } else if (average_degree >= 85) {
            GPA = 'B';
        } else if (average_degree >= 80) {
            GPA = 'B';
        } else if (average_degree >= 75) {
            GPA = 'C+';
        } else if (average_degree >= 70) {
            GPA = 'C';
        } else if (average_degree >= 65) {
            GPA = 'D';
        } else {
            GPA = 'F';
        }
    
		
	}

	void Display()
	{
		cout<<"student name : "<<name<<" , id : "<<id<<" , total degree : "<<totald<<" , total credit houers : "<<totalc<<" , GPA : "<<GPA<<endl;
		Level::Display();
	}

};

void main()
{
	Student s;
	s.read();
	s.Display();
	system("pause");
}