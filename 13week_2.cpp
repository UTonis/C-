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
class KmToMile : public Converter{
	double km;
	double convert(double src){
		return src/km;
	}
	string getSourceString(){
		return "Km";
	}
	string getDestString(){
		return "Mile";
	}
public:
	KmToMile(double km){
		this->km = km;
	}
};
int main(){
	KmToMile toMile(1.609344);
	toMile.run();
}