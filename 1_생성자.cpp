//1_생성자

#include <iostream>
using namespace std;

//객제지향 : 프로그램에서 필요한 타입을 먼저 설계한 후 프로그램을 만들자.
class Point
{
	int x;
	int y;

public:
	// 생성자 : 클래스 이름과 동일, 리턴타입이 없다. 객체생성시 자동호출
	// 함수 오버로딩 가능 - 2개 이상 만들 수 있다는 의미.
	// 사용자가 한개도 만들지 않으면 컴파일러가 인자가 없는 생성자를
	// 만들어 준다. - 디폴트 생성자.

	//Point()				{ x = 0; y = 0; }	//1
	//Point(int a, int b) { x = a; y = b; }	//2
	Point() = default; // 컴파일러에게 디폴트 생성자를 만들어 달라는 의미.
	//Point(){}

	// Point() = default; / Point(){} 두가지의 차이는 명백하다.

};

int main()
{
	Point p1;
	//Point p2(1, 1);

	//C++11 부터는 아래 처럼도 사용가능.
	//Point p3 = { 1,1 };
	//Point p4{ 1,1 }; //이 표현이 많이 사용된다.
}