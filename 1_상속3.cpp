//1_상속3
#include <iostream>
using namespace std;

// 상속에서의 생성자 / 소멸자
// 생성자는 메모리에 놓인 순서대로 호출됨. / Base -> Derived
// 소멸자는 반대로 메모리 아래 부분부터 호출됨. / Derived -> Base
// 1. 기반 클래스 생성자, 파생 클래스 생성자 순으로 호출된다.
// 2. 기반 클래스의 생성자는 디폴트 생성자가 기본적으로 사용된다.
//		Base()		{ cout << "Base() " << endl; } 없는 경우 에러,
//		Derived(int a) : Base(a)	{ cout << "Derived(int)" << endl; } --> 사용하는 경우
//		Base(int a)가 호출됨.
//		기반 클래스의 인자가 있는 생성자를 호출하려면 파생 클래스 초기화 리스트에서
//		기반 클래스 생성자를 명시적 호출.
// 3. 정확한 원리 : 파생 클래스의 생성자의 초기화 리스트에서
//					기반 클래스의 생성자를 호출하는 코드를 컴파일러가 생성하는것.
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