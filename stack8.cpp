//stack8.cpp

#include <iostream>

using namespace std;
//8�ܰ�, �������ϰ� �������Ϸ� �и�.
//����� ���忡���� Ŭ������ ���� ���ϸ� ������ ��밡��.
#include "Stack.h"

int main()
{
	Stack s1(100);

	s1.push(20);
	s1.push(160);

	cout << s1.pop() << endl;
}

//Ŭ���� �ϳ��� "���, �ҽ�"�� �����Ǵ� ��찡 ����.