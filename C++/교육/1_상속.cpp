//1_���

#include <iostream>
using namespace std;

// ����� ���� : Ŭ���� ����� ������ Ư¡�� ��Ƽ� ��� Ŭ������ ���� �� �ִ�.
//				"��� ������ ���̰� �ִ�."
// Base class, Super class, parent

class Animal
{
	int age;
public:
	void Cry() {}
};

// Derived class, Sub Class, Child class
class Dog : public Animal	// class Dog extends Animal
{
	int color;
public:
};

int main()
{
	Dog d;
	cout << sizeof(d) << endl;	// 8
}