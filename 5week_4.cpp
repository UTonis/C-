#include <iostream>
using namespace std;

class Sample{
	int *p;
	int size;
public:
	Sample(int n){ //������
		size = n; p = new int[n];  //n���� ���� �迭�� ���� ����
	}
	void read(); //���� �Ҵ���� ���� �迭 p�� ����ڷκ��� ������ �Է¹���
	void wirte(); //���� �迭�� ȭ�鿡 ���
	int big(); //���� �迭���� ���� ū �� ����
};

void Sample::read(){
	for (int i = 0; i < size; i++){
		cin >> p[i];
	}
}

void Sample::wirte(){
	for (int i = 0; i < size; i++){
		cout << p[i] << " ";
	}
	cout << endl;
}

int Sample::big(){
	int max = p[0];

	for (int i = 1; i < size; i++){
		if (max < p[i])
			max = p[i];
	}

	return max;
}

int main(){
	Sample s(10); // 10�� ���� �迭�� ���� sameple��ü ����
	s.read(); //Ű���忡�� ���� �迭 �б�
	s.wirte(); //���� �迭 ���
	cout << "���� ū ���� " << s.big() << endl; // ���� ū �� ���
}