//1_���3
#include <iostream>
using namespace std;

// ��ӿ����� ������ / �Ҹ���
// �����ڴ� �޸𸮿� ���� ������� ȣ���. / Base -> Derived
// �Ҹ��ڴ� �ݴ�� �޸� �Ʒ� �κк��� ȣ���. / Derived -> Base
// 1. ��� Ŭ���� ������, �Ļ� Ŭ���� ������ ������ ȣ��ȴ�.
// 2. ��� Ŭ������ �����ڴ� ����Ʈ �����ڰ� �⺻������ ���ȴ�.
//		Base()		{ cout << "Base() " << endl; } ���� ��� ����,
//		Derived(int a) : Base(a)	{ cout << "Derived(int)" << endl; } --> ����ϴ� ���
//		Base(int a)�� ȣ���.
//		��� Ŭ������ ���ڰ� �ִ� �����ڸ� ȣ���Ϸ��� �Ļ� Ŭ���� �ʱ�ȭ ����Ʈ����
//		��� Ŭ���� �����ڸ� ����� ȣ��.
// 3. ��Ȯ�� ���� : �Ļ� Ŭ������ �������� �ʱ�ȭ ����Ʈ����
//					��� Ŭ������ �����ڸ� ȣ���ϴ� �ڵ带 �����Ϸ��� �����ϴ°�.
class Base
{
public:
	Base()		{ cout << "Base() " << endl; }
	Base(int a)	{ cout << "Base(int)" << endl; }
	~Base()		{ cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
	Derived()		{ cout << "Derived() " << endl; }
	Derived(int a) : Base(a)	{ cout << "Derived(int)" << endl; }
	~Derived()		{ cout << "~Derived()" << endl; }

	/*
	// complier's view
	Derived() : Base() { cout << "Derived() " << endl; }
	Derived(int a) : Base() { cout << "Derived(int)" << endl; }
	~Derived() { cout << "~Derived()" << endl; ~Base(); }
	*/
};

int main()
{
	Derived d(5);
}