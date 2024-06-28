#include<iostream>
#include<math.h>
using namespace std;
struct Point{
float x,y,z;
};
class Point_3D{
private:	
	Point P[30];
	float N[30];
	int m;
public:
	float norm(Point p) {
        return sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
    }
	void read() {
        cout << "Enter the number of elements for P and N: ";
        cin >> m;
        for (int i = 0; i < m; i++) {
            cout << "Enter point[" << i << "]: ";
            cin >> P[i].x >> P[i].y >> P[i].z;
            N[i] = norm(P[i]);
        }
    }
	float DistanceFirstLast() {
        return sqrt(pow(P[0].x - P[m-1].x, 2) + pow(P[0].y - P[m-1].y, 2) + pow(P[0].z - P[m-1].z, 2));
    }
	float MaxNorm() {
        float max = N[0];
        for (int i = 1; i < m; i++) {
            if (N[i] > max) {
                max = N[i];
            }
        }
        return max;
    }
	Point_3D CompareNorm(Point_3D p1) {
        if (MaxNorm() > p1.MaxNorm()) 
            return *this;
         else 
            return p1;
    }
	float MinDistance(Point_3D p1) {
		 if (DistanceFirstLast() > p1.DistanceFirstLast()) 
            return DistanceFirstLast();
         else 
            return p1.DistanceFirstLast();
    }
	void display() {
        cout << "Point Coordinates\tNorm\n";
        for (int i = 0; i < m; ++i) {
            cout << P[i].x << ", " << P[i].y << ", " << P[i].z << "\t\t" << N[i] << endl;
        }
    }
};
void main()
{
	Point_3D P1, P2;

   
    P1.read();
    P2.read();

    P1.display();
    P2.display();

    cout << "Distance between first and last points for object 1: " << P1.DistanceFirstLast() << endl;
    cout << "Distance between first and last points for object 2: " << P2.DistanceFirstLast() << endl;

    cout << "Maximum norm for object 1: " << P1.MaxNorm() << endl;
    cout << "Maximum norm for object 2: " << P2.MaxNorm() << endl;

    Point_3D maxNorm = P1.CompareNorm(P2);
    cout << "Object with maximum norm:" << endl;
    maxNorm.display();

    cout << "Minimum distance between first and last points for both objects: " << P1.MinDistance(P2) << endl;


  system("pause");
}