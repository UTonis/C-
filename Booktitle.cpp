#include <iostream>
#include <string>
using namespace std;

class Book{
	string str;
	int price;
	char *publishedDate;
public:
	Book(){};
	Book(char *title, int price, char *pDate){ str = title; this->price = price; publishedDate = pDate; };

	void set(char* title, int price, char* pDate){ str = title; this->price = price; publishedDate = pDate; };

	void show(){ cout << "책 이름:" << str << " 책 가격:" << price << " 출판일:" << publishedDate << endl; };

	int replaceBookTitle(Book *books, int nbks, char *oldtitle, char *newtitle);

	string getName() { string a = this->str; return a; }

	void setName(string a) { str = a; }
};

int replaceBookTitle(Book *books, int nbks, char *oldtitle, char *newtitle){
	for (int i = 0; i < nbks; i++){
		if (books[i].getName() == oldtitle){
			books[i].setName(newtitle);
			return i;
			break;
		}
		else{
			if (i == nbks - 1){
				return -1;
			}
		}
	}
}

int main(){
	Book bookShelf[3] = {
		Book("C#프로그래밍", 20000, "0901216"), 
		Book("c++", 25000, "09022018"),
		Book()
	};
	bookShelf[2].set("Java programming", 28000, "12052017");

	bookShelf[0].show();
	bookShelf[1].show();

	int n = replaceBookTitle(bookShelf, 3, "c++", "C++");

	if (n < 0){
		cout << "책이름이 없습니다." << endl; 
	}
	else{
		cout << n;
		bookShelf[n].show();
	}
}