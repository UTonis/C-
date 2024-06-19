#include <iostream>
#include <string>
using namespace std;
class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() { }
	void paint() {
		draw();
	}
	Shape* add(Shape* p) {
		this->next = p;
		return p;
	}
	Shape* getNext() { return next; }
};
class Circle :public Shape {
protected:
	void draw() {
		cout << "Circle" << endl;
	}
};
class Rect :public Shape {
protected:
	void draw() {
		cout << "Rect" << endl;
	}
};
class Line :public Shape {
protected:
	void draw() {
		cout << "Line" << endl;
	}
};
class GraphicEditor {
	Shape *pStart = NULL;
	Shape *pLast;
	int num;
public:
	void run() {
		cout << "그래픽 에디터입니다." << endl;

		while (true)
		{
			cout << endl << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> "; cin >> num;
			if (num == 1) {
				cout << "선:1, 원:2, 사각형:3 >> "; cin >> num;
				Insert(num);
			}
			else if (num == 2) {
				cout << "삭제하고자 하는 도형의 인덱스 >> "; cin >> num;
				Shape* p1;
				p1 = pStart;
				for (int i = 0; i < num + 1; i++) {
					p1 = p1->getNext();
				}
				Shape* p2;
				p2 = pStart;
				for (int i = 0; i < num; i++) {
					p2 = p2->getNext();
					if (i == num - 2) {
						p2->add(p1);
					}
				}
			}
			else if (num == 3) {
				int i = 0;
				Shape* p = pStart;
				while (p != NULL) {
					cout << i << ": "; 
					p->paint();
					p = p->getNext();
					i++;
				}
			}
			else if (num == 4) {
				break;
			}
			else {
				cout << "1~4를 입력해주세요." << endl;
			}
		}
	}
	void Insert(int num) {
		if (pStart == NULL) {
			if (num == 1) {
				pStart = new Line();
				pLast = pStart;
			}
			else if (num == 2) {
				pStart = new Circle();
				pLast = pStart;
			}
			else if (num == 3) {
				pStart = new Rect();
				pLast = pStart;
			}
		}
		else {
			if (num == 1) {
				Shape* p;
				p = new Line();
				pLast->add(p);
				pLast = p;
			}
			else if (num == 2) {
				Shape* p;
				p = new Circle();
				pLast->add(p);
				pLast = p;
			}
			else if (num == 3) {
				Shape* p;
				p = new Rect();
				pLast->add(p);
				pLast = p;
			}
			else {
				cout << "!ERROR!" << endl;
			}
		}
	}
};
int main() {
	GraphicEditor g;
	g.run();
}