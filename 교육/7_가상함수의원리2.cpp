// 7_�����Լ��ǿ���2

#include <iostream>
using namespace std;

// ���� ������(complier's view) ==> �Լ������� AnimalArray[2] = { &Animal::foo, &Animal::goo };
class Animal
{
	// (complier's view) �迭 ������* vtptr;
	int age;

public :
	//(complier's view) Animal() : vtptr(AniamlArray) {}
	virtual void foo() {}
	virtual void goo() {}
};


//---------------------------------------------------------------------------------------------
// ���� ������(complier's view) ==> �Լ������� DogArray[2] = { &Animal::foo, &Dog::goo };

class Dog : public Animal
{
	// �迭������ * vtptr;
	int color;

public :
	// Dog() : vtptr(DogArray) {}
	virtual void goo() {}
};

int main()
{
	Animal a;
	Dog d;
	Animal* p = &d;
	p->foo();	// 1. p�� animal* ��� ����� �˰��ִ�.
				// 2. Animal ���� ���� foo�� �����Լ����� �ƴ��� ����
				// 3. ������ �ƴϸ� ������ Animal foo ȣ��
				// 4. �����̸� �� ��° �����Լ����� �����Ŀ�
				//		p ->vtptr[0]() ��� ���� �ڵ� ����
}