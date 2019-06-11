//1_생성자2

#include <iostream>
using namespace std;

//객제지향 : 프로그램에서 필요한 타입을 먼저 설계한 후 프로그램을 만들자.
class Point
{
	int x;
	int y;

public:
	// 초기화 리스트(initialize list)
	// 생성자 () 뒤에 : 을 적고 멤버를 초기화하는 기술.
	// 
	Point(int a = 0, int b = 0) : x(a), y(b) // 초기화
	{ 
	// x의 defalut 생성자를 부르고 대입을 진행하다.
	//	x = a; // 초기화가 아니라 대입
	//	y = b; 
	}	
};

int main()
{
	Point p2(1, 1);

	int a = 10; // 초기화, a가 사용자 타입이면 생성자로 초기화
	int b;		// b가 int가 아니라 사용자 타입이면 생성자
	b = 10; // 대입, 대입 연산자가 불림.


	// 상수 변수는 대입은 안되고 초기화만 가능.
	const int c1 = 10; // ok 
	const int c2;	  // ?
	c2 = 10;		 // ?
}