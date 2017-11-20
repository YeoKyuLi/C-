// 7_가상함수의원리3

#include <iostream>
using namespace std;

class Animal
{
	int age;

public:
	virtual void foo() {}
	virtual void goo() {}

	virtual ~Animal() {} // + 추가
};
class Dog : public Animal
{
	int color;

public:
	virtual void goo() {}
};

int main()
{
	Animal a;
	Dog d;

	cout << sizeof(a) << endl;	// 4 --> 8
	cout << sizeof(d) << endl;	// 8 --> 12 
	Animal* p = &d;
	p->foo();
}