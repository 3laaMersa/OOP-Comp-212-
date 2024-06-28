#include<iostream>
using namespace std;
class Data{
private:
	float P[2][2];
public:
	Data() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                P[i][j] = 2;
            }
        }
    }

   
    Data(float arr[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                P[i][j] = arr[i][j];
            }
        }
    }

    Data(const Data& obj) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                P[i][j] = obj.P[i][j];
            }
        }
    }

    float sum()
	{
	 return sqrt(pow((P[0][0]-P[1][0]),2)+pow((P[0][1]-P[1][1]),2));
	}
    void display() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cout << "P["<<i<<"]["<<j<<"]: "<<P[i][j]<<"  ";
            }
         cout<<endl;
		}
	}
};
void main()
{
	float arr[2][2];
	for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
				cout<<"a["<<i<<"]["<<j<<"]:";
                cin >> arr[i][j];
            }
			cout<<endl;
		}
    Data d1; 
    cout << "Data 1:\n";
    d1.display();
    cout <<"Summation = "<<d1.sum()<<endl;
	cout<<"--------------------------------------------------------------------"<<endl;
    Data d2(arr); 
     cout << "Data 2:\n";
    d2.display();
    cout <<"Summation = "<<d2.sum()<<endl;
	cout<<"--------------------------------------------------------------------"<<endl;
    Data d3(d2); 
    cout << "Data 3:\n";
    d3.display();
    cout <<"Summation = "<<d3.sum()<<endl;


 system("pause");
}