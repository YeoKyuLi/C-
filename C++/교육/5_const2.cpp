//5_const2
#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;

public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}
	void set(int a, int b) { x = a, y = b; }

	void print() //const // 상수 멤버 함수
	{
		//x = 10; //error. 상수 멤버함수 안에서는 멤버의 값을 수정할 수 없다.
		cout << x << "," << y << endl;
	}
};
int main()
{
	const Point p(1, 1); // const int c = 10;

	p.x = 10;			// error. p는 상수 객체이다.
	p.set(10, 20);		// error. 
	p.print();			// void print(); 만 참고해서는 complier가 값을 바꾸는지는 알 수 없다.
						// 되게 하려면 print() 를 함수함수로 해야 한다.
						// "상수객체"는 "상수멤버함수"만 호출 할 수 있다.

}