// 11_스마트포인터
// 

#include <iostream>
using namespace std;

class Car
{
	int color;
public :
	void Go()	{ cout << "Car Go" << endl; }
	~Car() { cout << "~Car() " << endl; }
};
// 핵심 코드
// 스마트 포인터, 개념 : 객체가 다른 타입의 포인터 역할을 하는 것,
// 장점 : 진짜 포인터가 아닌 개체이다.
//			생성/복사/대입/소멸의 과정을 제어할 수 있게 된다.
//			ex) 소멸자에게 객체를 자동 삭제하는 기능 부여..................
// 원리 : -> 와 * 연산자를 재정의 해서 포인터 처럼 보이게 한다.
class Ptr
{
	Car* obj;
public :
	Ptr(Car* p = 0) : obj(p) {}
	~Ptr() { delete obj; } // 자원 삭제
	Car* operator->() { return obj; }
	Car& operator*() { return *obj; } // 값, 참조
};
int main()
{
	Ptr p = new Car;	// Ptr p(new Car) 로 생각
	p->Go();			// p +a ==> p.operator+(a)
						// p-> : p.operator->() 를 찾게 된다.
						// ( p.operator->() ) Go()의 모양이 되는데,
						// ( p.operator->() )-> Go()로 해석해준다.

	(*p).Go();			// 이 표현도 되야한다.
						// p.operator*()
	// 포인터는 함수가 끝나도 메모리에서 제거되거나 어떠한 반응도 없다.
}
