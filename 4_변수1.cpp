//����1.cpp
#include <iostream>
using namespace std;

int main() {
	int x[3] = { 1,2,3 };

	//int n = x[0];
	auto n = x[0]; // �캯�� Ÿ���� �����ؼ� �º��� ������ �޶�. 
					//C++
	//auto n2; // ??error

	decltype(n) n3; // n�� ���� Ÿ���� ���� n3
					//C++

	//�ʱ�ȭ ���
	int n3 = 10;
	int y[2] = { 1, 2 };
	//Point p(1,2); //C++ Ŭ���� �ʱ�ȭ
	
	//��� ������ ������ ������� �ʱ�ȭ C++11
	//�ϰ��� �ʱ�ȭ - ��� {}�� �ʱ�ȭ ����
	int n4 = { 10 };
	int z[2] = { 1,2 };

	int n5 = 3.4;//ok
	int n5 = { 3.4 };//error

	char c = { 300 }; // 255���� ���� overflow

	int n7 = 0b1;//2���� C++11
	int n8 = 1'000'000; // ' ǥ�� ����.


}