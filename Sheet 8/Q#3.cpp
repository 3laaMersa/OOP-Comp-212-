#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
class Data1 {
protected:
	string s1;
	double d1[20];
	int a;
	int n;
public:
	void read1() {
		cout << "enter th string:";
		cin >> s1;
		cout << "enter size of array:";
		cin >> n;
		cout << "enter number of a:";
		cin >> a;
		for (int i = 0; i < n; i++) {
			cin >> d1[i];
			cout << "d1[" << i << "]" << endl;
		}
	}
	float sum1() {
		float st = 0;
		for (int i = 0; i < n; i++) {
			float s = 0;
			for (int j = 1; j < i + 1; j++) {
				if ((int)d1[i] % a)
					s += pow(d1[i], 2 * (j + 1));
				else
					s += pow(d1[i], (j + 1));
			}
			st += s;
		}
		return st;
	}
	void display1() {
		cout << "s1=" << s1 << endl;
		cout << "a=" << a << endl;
		for (int i = 0; i < n; i++)
			cout << "d1[" << i << "]=" << d1[i];
	}
};
class Data2 {
protected:
	string s2;
	double D2[20];
	int b;
	int m;
public:
	void read2() {
		cout << "enter th string:";
		cin >> s2;
		cout << "enter size of array:";
		cin >> m;
		cout << "enter number of b:";
		cin >> b;
		for (int i = 0; i < m; i++) {
			cin >> D2[i];
			cout << "d1[" << i << "]" << endl;
		}
	}
	float sum2() {
		float st = 0;
		for (int i = 0; i < m - 1; i++) {
			float s = 0;
			for (int j = 1; j < i + 1; j++) {
				if (D2[i] > b)
					s += pow(D2[i], 2 * (j + 1));
				else
					s += pow(D2[i], (j + 1));
			}
			st += s;
		}
		return st;
	}
	void display2() {
		cout << "s2=" << s2 << endl;
		cout << "b=" << b << endl;
		for (int i = 0; i < m; i++)
			cout << "D2[" << i << "]="<< D2[i]<<"\t";
	}
};
class Data :public Data1 , public Data2{
	string ND;
	int t_sum;
public:
	void read() {
		cout << "cout enter strin ND:";
		cin >> ND;
	}
	float total_sum(){
		return t_sum = sum1() + sum2();
	}
	void display() {
		cout << "ND IS::" << ND << endl;
	}
};
void main()
{
	Data d2;
	d2.read1();
	d2.read2();
	d2.read();
	cout << "_________________________" << endl;
	d2.sum1();
	d2.sum2();
	cout<<"total sum="<<d2.total_sum()<<endl;
	cout << "____________________________" << endl;
	d2.display1();
	d2.display2();
	d2.display();
}