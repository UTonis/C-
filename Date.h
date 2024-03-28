#ifndef Date_H
#define Date_H

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

#endif