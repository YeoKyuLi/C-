#include <iostream>
#include <vector>
using namespace std;

// "���� �̸�"�� ��� ��� �Լ��� ���� ��� �Լ��� ���� �� �ִ�.

class Test
{
public:
	void foo()		 { cout << "foo" << endl; }				// 1
	void foo() const { cout << "foo const " << endl; }		// 2
};

int main()
{
	Test t1;
	t1.foo();		// 1, 1�� ���ٸ� 2�� ȣ��

	const Test t2;
	t2.foo();		// 2, 2�� ������ error

	//------------------------------------------------------------------------------
	vector<int> v(10, 3);	// vector �迭�� ���� Ŭ����
							// 10���� 3���� �ʱ�ȭ
	v[0] = 10;				// v.operator[](0) = 10; / OK

//	const vector<int> v1(10, 3);
//	v1[0] = 10;	//v1.operator[](0) = 10; / ERROR
}