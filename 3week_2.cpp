#include <iostream>
#include <string>
using namespace std;

class Date{
public:
	int Year1, Month1, Day1;
	int Year2, Month2, Day2;
	Date(string s);
	Date(int d1, int d2, int d3);
	int show();
	int getYear();
	int getMonth();
	int getDay();
};

Date::Date(string s){ // 1945�� 8�� 15��
	size_t pos = s.find('/');
	Year1 = stoi(s.substr(0, pos));
	s = s.substr(pos + 1);
	pos = s.find('/');
	Month1 = stoi(s.substr(0, pos));
	Day1 = stoi(s.substr(pos + 1));
}

Date::Date(int d1, int d2, int d3){ //2014�� 3�� 20��
	Year2 = d1;
	Month2 = d2;
	Day2 = d3;
}

int Date::show(){
	cout << Year1 << "��" << Month1 << "��" << Day1 << "��" << endl;
	return 0;
}

int Date::getYear(){
	return Year2;
}

int Date::getMonth(){
	return Month2;
}

int Date::getDay(){
	return Day2;
}

int main(){
	Date birth(2014, 3, 20); //2014�� 3�� 20��
	Date independenceDay("1945/8/15");
	independenceDay.show();

	cout << birth.getYear() << "," << birth.getMonth() << "," << birth.getDay() << endl;

	return 0;
}