#include <iostream>
using namespace std;
class Circle;
void operator ++(Circle &a);
Circle& operator ++(Circle &a, int x);

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
	friend void operator ++(Circle &a){
		a.radius++;
	}
	friend Circle& operator ++(Circle &a, int x){
		Circle tmp = a;
		a.radius++;
		return tmp;
	}
};

int main(){
	Circle a(5), b(4);
	++a;
	b = a++;
	a.show();
	b.show();
}