#include <iostream>
#include <string>
using namespace std;
class Circle{
	int radius;
public:
	Circle(int radius = 0){
		this->radius = radius;
	}
	int getRadius(){ return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea(){ return 3.14*radius*radius; }
};
class NamedCircle : public Circle{
	string CircleName;
public:
	void set(int radius, string CircleName){
		setRadius(radius);
		this->CircleName = CircleName;
	}
	string getName(){
		return CircleName;
	}
};
int main(){
	int r;
	string name;
	NamedCircle pizza[5];
	cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
	for (int i = 0; i < 5; i++){
		cout << i + 1 << ">> ";
		cin >> r >> name;
		pizza[i].set(r, name);
	}
	int max = pizza[0].getArea();
	name = pizza[0].getName();
	for (int i = 1; i < 5; i++){
		if (max < pizza[i].getArea()){
			max = pizza[i].getArea();
			name = pizza[i].getName();
		}
			
	}
	cout << "���� ������ ū ���ڴ� " << name << "�Դϴ�." << endl;
}