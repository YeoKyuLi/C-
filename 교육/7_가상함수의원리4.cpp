// 7_가상함수의원리4

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
	p->foo(); // 결과 예측해 보시오 - 가상함수의 경우는 개체를 따라간다. 반대는 Base의 포인터?를 따라감.
			// Derived : 10

	// p -> vtptr[0](defalut---10) 로 컴파일 됩니다.
	// 디폴트 파라미터 : 컴파일러가 컴파일 시간에 채워주게 됩니다.
	// 가상함수 :  실행시간에 함수를 결정하게 됩니다.

	// 되도록이면 가상함수에서는 디폴트 파라미터를 사용하지 마시오.
	// 사용했다면 가상함수 "재정의"시에 디폴트값을 변경하지 마시오.
}