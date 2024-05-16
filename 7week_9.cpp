#include <iostream>
#include <string>
using namespace std;
class Circle{
	int radius;
	string name;
public:
	void setCircle(string name, int radius){ this->name = name, this->radius = radius; }
	double getArea() { return radius * radius * 3.14; }
	string getName() { return name; }
};

class circleManager{
	Circle *p;
	int size;
public:
	circleManager(){ };
	circleManager(int size) { 
		this->size = size;
		p = new Circle[size];
		for (int i = 0; i < size; i++){
			string name;
			int radius;
			cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
			cin >> name >> radius;
			p[i].setCircle(name, radius);
		}
	}
	~circleManager(){};
	void searchByName(){
		string name;
		cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
		cin >> name;
		for (int i = 0; i < size; i++){
			if (name == p[i].getName()){
				cout << p[i].getName() << "�� ������ " << p[i].getArea() << endl;
			}
		}
	}
	void searchByArea(){
		int Area = 0;
		cout << "�ּ� ������ ������ �Է��ϼ���.";
		cin >> Area;
		cout << Area << "���� ū ���� �˻��մϴ�." << endl;
		for (int i = 0; i < size; i++){
			if (p[i].getArea() >(double)100){
				cout << p[i].getName() << "�� ������ " << p[i].getArea() << ", ";
			}
		}
		cout << endl;
	}
};

int main(){
	string name;
	int radius;
	int size;
	cout << "���� ����>>";
	cin >> size;
	circleManager *p = new circleManager(size);
	p->searchByName();
	p->searchByArea();

}