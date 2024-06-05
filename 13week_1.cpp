#include <iostream>
#include <string>
using namespace std;
class Converter{
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(){ ratio = 0; }
	Converter(double ratio){ this->ratio = ratio; }
	void run(){
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요>>";
		cin >> src;
		cout << "변환 결과 : " << convert(src) << getDestString() << endl;
	}
};
class WonToDallar : public Converter{
	int won;
	double convert(double src){
		return src / won;
	}
	string getSourceString(){
		return "원";
	}
	string getDestString(){
		return "달러";
	}
public:
	WonToDallar(int money){
		won = money;
	}
};
int main(){
	WonToDallar wd(1010);
	wd.run();
}