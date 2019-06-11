//1_생성자3

#include <iostream>
using namespace std;

// 핵심 : const 멤버나 디폴트 생성자가 없는 타입을 멤버로 가질 때
//			반드시 초기화 리스트를 사용해야 한다.
class Point
{
	int x;
	int y;
	const int c; // c는 상수 이므로 반드시 초기화 되어야 한다.
				// 반드시 초기화 리스트를 사용해야 한다.

public:
	Point(int a, int b) : x(a), y(b), c(10)
	{
		//c = 10; //error 초기화가 아닌 대입이다.
		//초기화 리스트를 사용해야 한다.
	}
};

class Rect
{
	Point p1;
	Point p2;

public:
	Rect() : p1(0,0), p2(1,1)
	{
		//p1(0,0); 대입하는 곳, 
	}
};

int main()
{
	Rect r;

	//Point p(1, 1); //1,1로 초기화 됨.

}