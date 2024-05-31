#include <iostream>
#include <string>
using namespace std;
class Point{
	int x, y;
public:
	Point(){}
	Point(int x, int y){ this->x = x; this->y = y; }
	int getX(){ return x; }
	int getY(){ return y; }
protected:
	void move(int x, int y){ this->x = x; this->y = y; }
};
class ColorPoint : public Point{
	string Color;
public:
	ColorPoint(int x, int y, string Color){
		move(x, y);
		this->Color = Color;
	}
	void setPoint(int x, int y){
		move(x, y);
	}
	void setColor(string Color){
		this->Color = Color;
	}
	void show(){
		cout << Color << "������ (" << getX() << ", " << getY() << ")�� ��ġ�� ���Դϴ�." << endl;
	}
};

int main(){
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}