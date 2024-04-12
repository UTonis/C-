#include <iostream>
using namespace std;

class Storage{
private:
	int nData; //������ ũ��
	int *strg;
public:
	Storage(Storage& Storage);
	Storage(int nData);
	void showList();
	void addDatas(int extra);
	void subStrg(Storage &S);
};

Storage::Storage(Storage& s){
	this->nData = s.nData;
	this->strg = s.strg;

}

Storage::Storage(int nData){
	this->nData = nData;
	this->strg = new int [nData];
	int getNum;

	cout << "�ڷ� " << nData << " �Է� :" << endl;
	for (int i = 0; i < nData; i++){
		cin >> getNum;
		for (int y = i; y > -1; y--){
			if (getNum == this->strg[y]){
				cout << getNum << "�ߺ�" << endl;
				i--;
				break;
			}
			else{
				if (y == 0)
				this->strg[i] = getNum;
			}
		}
	}

	cout << "�Է¿Ϸ� : ";
	for (int i = 0; i < nData; i++){
		cout << this->strg[i] << " ";
	}
	cout << endl;
}

void Storage::showList(){
	cout << this->nData << ":";
	for (int i = 0; i < this->nData; i++){
		cout << strg[i] << " ";
	}
	cout << endl << endl;;
}

void Storage::addDatas(int extra){
	this->nData = this->nData + extra;
	int getNum;

	cout << "�ڷ� " << extra << " �߰��Է� :";
	for (int i = 0; i < this->nData - extra; i++){
		cout << this->strg[i] << " ";
	}
	cout << endl;
	for (int i = this->nData - extra; i < this->nData; i++){
		cin >> getNum;
		for (int y = i; y > -1; y--){
			if (getNum == this->strg[y]){
				cout << getNum << "�ߺ�" << endl;
				i--;
				break;
			}
			else{
				if (y == 0)
					this->strg[i] = getNum;
			}
		}
	}

	cout << "�Է¿Ϸ� : ";
	for (int i = 0; i < nData; i++){
		cout << this->strg[i] << " ";
	}
	cout << endl;
}

void Storage::subStrg(Storage &S){
	int count = 0;

	for (int i = 0; i < this->nData; i++){
		for (int y = 0; y < S.nData; y++){
			if (strg[i] == strg[y]){
				strg[i] = NULL;
			}
		}
	}

	for (int i = 0; i < this->nData; i++){
		if (strg[i] == NULL){
			for (int y = i; y < this->nData; y++){
				strg[y] = strg[y + 1];
			}
			count++;
			i--;
		}
	}

	this->nData = this->nData - count;
}

int main(void){
	Storage s1(4);
	s1.showList();

	Storage s2(s1);
	s2.showList();
	s2.addDatas(3);
	s2.showList();

	Storage s3(3);
	s3.showList();
	s2.subStrg(s3);
	s2.showList();
}