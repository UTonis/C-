#include <iostream>
using namespace std;

#include "CoffeeMachine.h";

int main(){
	CoffeeMachine java(5, 10, 3);  // Ŀ�� 5, ���� 10, ���� 6 ���� �ʱ�ȭ
	java.drinkEspresso();  // Ŀ�� 1, �� 1 �Һ�
	java.show();  //���� Ŀ�Ǹӽ� ���� ���
	java.drinkAmericano();  // Ŀ��1 , �� 2 �Һ�
	java.show();
	java.drinkSugarCoffee(); // Ŀ�� 1, �� 2, ���� 1 �Һ�
	java.show();
	java.fill();  // Ŀ�� 10, �� 10, ���� 10���� ä���
	java.show();
}