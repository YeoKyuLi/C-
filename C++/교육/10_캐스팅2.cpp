// 10_ĳ����2

#include <iostream>
using namespace std;

int main()
{

	//const int c = 10;	// ������ �ð� ���. ,, ��ũ�� ó�� ��ȯ...

	int n = 10;
	const int c = n;	// ������ �� �� �ʱⰪ�� �𸣰�, ����ð����� �ٲܼ��� ����.
						// ����ð� ���,

	//int* p = &c;	// complie time error, ����޸𸮴� ������ ����Ű�� �����Ϳ� ���� �� ����.

	int* p = (int*)&c;	// ok... wow

	*p = 20;

	cout << c << endl;		// 10
	cout << *p << endl;		// 20

}