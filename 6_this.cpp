// 6_this

#include <iostream>
using namespace std;


class Point
{
	int x, y;

public :
	void set(int x, int y) // void set(Point* const this, int x , int y)
	{
		// this = 0;
		cout << this << endl; // 객체의 주소가 나온다.
		this -> x = x;
		this -> y = y;
	}

	// this를 리턴하는 함수
	Point* goo() { return this; }    // 주소 리턴
	//Point foo() { return *this; } // 자신의 복사본 리턴
	Point& foo() { return *this; } // 복사본이 아닌 진짜 자신을 리턴.
};

int main()
{
	Point p1, p2;
	p1.set(10, 20); // set(&p1, 10, 20)
	p2.set(30, 40);	// set(&p2, 30, 40)

	p1.goo()->goo(); //주소 리턴
	p1.foo().foo().foo();// 값 리턴 cout << "A" << "B" << "C" << endl; --> this return.
}