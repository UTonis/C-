#include <iostream>
#include <string>
using namespace std;
class Book;
bool operator == (Book c, int x);
bool operator == (Book c, string t);
bool operator == (Book c, Book z);

class Book{
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0){
		this->title = title; this->price = price; this->pages = pages;
	}
	void show(){
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	friend bool operator == (Book c, int x){
		if (c.price == x) return true;
		else return false;
	}
	friend bool operator == (Book c, string t){
		if (c.title == t) return true;
		else return false;
	}
	friend bool operator == (Book c, Book z){
		if (c.title == z.title && c.price == z.price && c.pages == z.pages) return true;
		else return false;
	}
};

int main(){
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if (a == 30000) cout << "정가 30000원" << endl;
	if (a == "명품 C++") cout << "명품 C++입니다." << endl;
	if (a == b) cout << "두 책이 같은 책입니다." << endl;
}