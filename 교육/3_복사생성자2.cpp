// 3_복사생성자2
#include <iostream>>

using namespace std;

class Point
{
public:
	int x, y;
public:
	Point() : x(0), y(0) { cout << "생성자1" << endl; } // 1
	Point(int a, int b) : x(a), y(b) { cout << "생성자2" << endl; }
	Point(const Point& p) : x(p.x), y(p.y)
	{
		cout << "복사 생성자" << endl;
	}
};


// call by value : 메모리 복제본 생성 - 메모리 오버헤드 발생
//					복사 생성자/소멸자 호출 - 성능 오버헤드
//void foo(Point p) // Point p = p3
void foo(const Point& p) // call by value 대신 const 참조가 좋다.
{
}

int main()
{
	// 모든 객체는 생성할때 반드시 생성자를 호출해야 한다.
	Point p1;			// 생성자 1
	Point p2(1, 2);		// 생성자 2
	Point p3(p2);		// 복사 생성자
	Point p4 = p3;		// Point p4(p3); 즉, 복사 생성자
	foo(p3);			

//	int a = 0;
//	int a(0);
}
