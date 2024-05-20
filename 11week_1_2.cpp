#include <iostream>
#include <string>
using namespace std;
class Book;
Book& operator+=(Book &c, int x);
Book& operator-=(Book &c,int x);

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
	void plusPrice(int price){
		this->price += price;
	}
	void minusPrices(int price){
		this->price -= price;
	}
	friend Book& operator += (Book &c, int x){
		c.plusPrice(x);
		return c;
	}
	friend Book& operator -= (Book &c, int x){
		c.minusPrices(x);
		return c;
	}
};

int main(){
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;  //a.+=(500)
	b -= 500;
	a.show();
	b.show();
}