// 8_가상소멸자

#include <iostream>
using namespace std;

// 결론 : C++에서 클래스 만들때 기반 클래스로 사용되는 모든 클래스는
//			소멸자를 가상함수로 만들어야 한다.

//			오늘 만든 모든 기반 클래스(Animal, Base, IValidator, Shape)의 소멸자를 가상으로 해야합니다.

class Base
{
public:
	virtual ~Base() {}		// 가상 소멸자
};

class Derived : public Base
{

public:
	Derived() { cout << "자원 할당 " << endl; }
	virtual ~Derived() { cout << "자원 해지 " << endl; }
};

int main()
{
	Base* p = new Derived; // 메모리 할당  +  Derived 생성자 호출,
	delete p; // 버그 발생.	메모리 해지 + Derived 소멸자 호출 But, p가 Base 타입이므로 Base의 소멸자만 호출
				// 
}