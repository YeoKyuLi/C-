//9_연산자재정의2

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// 멤버로 구현한 + 함수
	Point operator+(const Point& p)
	{
		Point temp(x + p.x, y + p.y);
		return temp;
	}

	//friend Point operator+(const Point& p1, const Point& p2); // 방법 1.
};
/*
Point operator+(const Point& p1, const Point& p2)
{
	Point temp(p1.x + p2.x, p1.y + p2.y);
	return temp;
}
*/
int main()
{
	int n = 3 + 4;

	Point p1(1, 1);
	Point p2(2, 2);

	Point p5 = p1 + p2;		
							// 1. p1.operator+(p2)를 찾고, 
							// 2. operator+( p1, p2) 를 찾게 된다.
	
	// ++a : 객체의 상태를 변경하는 연산자는 멤버 함수가 좋다.
	//			값을 바꾸는 경우는 멤버 함수가 더 좋다.
	// a+b : 객체의 상태를 변경하지 않는 경우는 일반 함수도 나쁘지 않다.

	// (), -> , =, *(곱셈말고 dereference) 는 반드시 멤버 함수만 가능하다.

}