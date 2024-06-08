#include <iostream>
using namespace std;
class Circle;
Circle operator + (int x, Circle a);

class Circle{
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " ÀÎ ¿ø" << endl; }
	int getRadius(){
		return radius;
	}
	void setRadius(int n){
		radius = n;
	}
	friend Circle operator + (int x, Circle a){
		Circle tmp = a;
		tmp.radius += x;
		return tmp;
	}
};

int main(){
	Circle a(5), b(4);
	b = 1 + a;
	a.show();
	b.show();
}