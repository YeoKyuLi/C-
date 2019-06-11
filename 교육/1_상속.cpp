//1_상속

#include <iostream>
using namespace std;

// 상속의 장점 : 클래스 설계시 공통의 특징을 모아서 기반 클래스로 묶을 수 있다.
//				"모든 동물은 나이가 있다."
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