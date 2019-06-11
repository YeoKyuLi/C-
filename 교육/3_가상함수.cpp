// 3_가상함수

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
	// 함수 오버라이드(override) : 기반 클래스의 함수를 파생 클래스가 다시 만드는 것.
	virtual void Cry() { cout << "Dog City" << endl; }	// 2
};

int main()
{
	Animal a; a.Cry();	// 1
	Dog d; d.Cry();		// 2
	Animal* p = &d;		// 자신의 주소를 기반 주소에 담는다.
	// if(사용자 입력)  p = 다른 동물.
	p->Cry();			// 1, C++, C# : Aniaml Cry
						//				단, 가상함수 라면 Dog Cry
						// java, Objective-C, swift : Dog Cry
}