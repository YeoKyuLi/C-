// 7_�����Լ��ǿ���4

#include <iostream>
using namespace std;

class Base
{
public :
	virtual void foo(int i = 10) { cout << " Base : " << i << endl; }
};

class Derived : public Base
{
public:
	virtual void foo(int i = 20) { cout << " Derived : " << i << endl; }
};

int main()
{
	Base* p = new Derived;
	p->foo(); // ��� ������ ���ÿ� - �����Լ��� ���� ��ü�� ���󰣴�. �ݴ�� Base�� ������?�� ����.
			// Derived : 10

	// p -> vtptr[0](defalut---10) �� ������ �˴ϴ�.
	// ����Ʈ �Ķ���� : �����Ϸ��� ������ �ð��� ä���ְ� �˴ϴ�.
	// �����Լ� :  ����ð��� �Լ��� �����ϰ� �˴ϴ�.

	// �ǵ����̸� �����Լ������� ����Ʈ �Ķ���͸� ������� ���ÿ�.
	// ����ߴٸ� �����Լ� "������"�ÿ� ����Ʈ���� �������� ���ÿ�.
}