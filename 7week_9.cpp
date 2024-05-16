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
			cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
			cin >> name >> radius;
			p[i].setCircle(name, radius);
		}
	}
	~circleManager(){};
	void searchByName(){
		string name;
		cout << "검색하고자 하는 원의 이름 >> ";
		cin >> name;
		for (int i = 0; i < size; i++){
			if (name == p[i].getName()){
				cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
			}
		}
	}
	void searchByArea(){
		int Area = 0;
		cout << "최소 면적을 정수로 입력하세요.";
		cin >> Area;
		cout << Area << "보다 큰 원을 검색합니다." << endl;
		for (int i = 0; i < size; i++){
			if (p[i].getArea() >(double)100){
				cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ", ";
			}
		}
		cout << endl;
	}
};

int main(){
	string name;
	int radius;
	int size;
	cout << "원의 개수>>";
	cin >> size;
	circleManager *p = new circleManager(size);
	p->searchByName();
	p->searchByArea();

}