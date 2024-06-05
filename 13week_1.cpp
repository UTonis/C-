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
		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
		cout << getSourceString() << "�� �Է��ϼ���>>";
		cin >> src;
		cout << "��ȯ ��� : " << convert(src) << getDestString() << endl;
	}
};
class WonToDallar : public Converter{
	int won;
	double convert(double src){
		return src / won;
	}
	string getSourceString(){
		return "��";
	}
	string getDestString(){
		return "�޷�";
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