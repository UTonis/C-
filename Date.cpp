#include <iostream>
#include <string>
using namespace std;

#include "Date.h";

Date::Date(string s){ // 1945년 8월 15일
	size_t pos = s.find('/');
	Year1 = stoi(s.substr(0, pos));
	s = s.substr(pos + 1);
	pos = s.find('/');
	Month1 = stoi(s.substr(0, pos));
	Day1 = stoi(s.substr(pos + 1));
}

Date::Date(int d1, int d2, int d3){ //2014년 3월 20일
	Year2 = d1;
	Month2 = d2;
	Day2 = d3;
}

int Date::show(){
	cout << Year1 << "년" << Month1 << "월" << Day1 << "일" << endl;
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