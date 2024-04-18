#include <iostream>
using namespace std;
class Circle{
	int radius;
public:
	Circle(){ radius = 1; }
	Circle(int a){ radius = a; }
	void swap(Circle c1, Circle c2);
	int getradius(){ return radius; };
};

void swap(Circle c1, Circle c2){
	Circle c3;
	c3 = c1;
	c1 = c2;
	c2 = c3;

	cout << c1.getradius() << " " << c2.getradius() << endl;
}

int main(){
	Circle c1(10);
	Circle c2(20);
	cout << c1.getradius() << " " << c2.getradius() << endl;

	swap(c1, c2);
	cout << c1.getradius() << " " << c2.getradius() << endl;
}