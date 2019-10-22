// 3_�����Լ�

#include <iostream>
using namespace std;

class Animal
{
	int age;
public:
	virtual void Cry() { cout << "Aniaml City" << endl; }	// 1
};

class Dog : public Animal
{
public:
	// �Լ� �������̵�(override) : ��� Ŭ������ �Լ��� �Ļ� Ŭ������ �ٽ� ����� ��.
	virtual void Cry() { cout << "Dog City" << endl; }	// 2
};

int main()
{
	Animal a; a.Cry();	// 1
	Dog d; d.Cry();		// 2
	Animal* p = &d;		// �ڽ��� �ּҸ� ��� �ּҿ� ��´�.
	// if(����� �Է�)  p = �ٸ� ����.
	p->Cry();			// 1, C++, C# : Aniaml Cry
						//				��, �����Լ� ��� Dog Cry
						// java, Objective-C, swift : Dog Cry
}