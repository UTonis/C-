#include <iostream>
#include <string>
using namespace std;
class Book;
bool operator ! (Book b);

class Book{
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0){
		this->title = title; this->price = price; this->pages = pages;
	}
	void show(){
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() { return title; }
	friend bool operator ! (Book b){
		if (b.price == 0) return true;
		else return false;
	}
};

int main(){
	Book book("�������", 0, 50);
	if (!book) cout << "��¥��" << endl;
}