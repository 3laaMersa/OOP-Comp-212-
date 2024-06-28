#include<iostream>
#include<string>
using namespace std;
class Student{
private:
	string name;
	int age,id;
	static int count;
public:
	Student(string n, int a) {
		name =n;
		age=a;
        id = count + 3333; 
        count++; 
    }
	void read(){
	cout<<"Enter student name"<<endl;
	cin>>name;

	cout<<"Enter student age"<<endl;
	cin>>age;

	cout<<"Enter student id"<<endl;
	cin>>id;
	}
	void display()
	{
	cout<<"Student name is "<<name<<endl;
	cout<<"Student age is "<<age<<endl;
	cout<<"Student id is "<<id<<endl;
	}
	static void displayCount() {
        cout << "Number of students: " << count << endl;
    }
};
int Student::count = 0;
void main()
{
	Student s1("Alaa", 22);
    Student s2("Esraa", 23);
	 Student s3("Mahmoud", 24);


    s1.display();
    cout<<"--------------------------------"<<endl;
   
	s2.display();
    cout<<"--------------------------------"<<endl;

    s3.display();
    cout<<"--------------------------------"<<endl;

    Student::displayCount();
 system("pause");
}