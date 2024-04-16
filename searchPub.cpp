#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Book{
	string title;
	int price;
	string pub;
public:
	Book(){};
	Book(const char* title, int price){ this->title = (char *)title; this->price = price; };
	void set(string *title, int price, string *pub){ this->title = *title; this->price = price; this->pub = *pub; };
	void show() { cout << title << ' ' << price << "��" << endl; };
	void ShowPubList(Book *p, int size);
};

void Book::ShowPubList(Book *p, int size){
	
	cout << "���ǻ纰 �з��� ������ �����ϴ�." << endl;
	for (int i = 0; i < size; i++){
		string str = "";
		bool b = true; //��ó���� True
		int count = 0;
		for (int y = 0; y < size; y++){
			if (p[i].pub == p[y].pub)
				count++;
		}

		for (int k = 0; k < i; k++){
			if (p[k].pub == p[i].pub)
				b = false;
		}
		if (b == true)
			cout << p[i].pub << " " << count << "�� ";

		for (int j = 0; j < size; j++){
			if (b == true && p[i].pub == p[j].pub)
				cout << p[j].title  << " ";
		}
		cout << str << endl;
	}
}

int main() {
	string title;
	string pub;
	int size;
	int price;

	cout << "å �Ǽ�? ";
	cin >> size;
	Book *p = new Book[size];
	
	cout << size << "�� å�� ����� ����, ���ǻ���� �Է����ּ���" << endl;
	for (int i = 0; i < size; i++){
		cout << "å " << i + 1 << ">>";
		cin >> title >> price >> pub;
		p[i].set(&title, price, &pub);
	}

	p->ShowPubList(p, size);
}
