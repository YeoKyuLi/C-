// 7_임시객체2
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
	~Point()
	{
		cout << " 소멸자 " << endl;
	}
};

Point p; // 전역변수.. 종료시까지 파괴되지 않는다.

//Point foo()		// 값 리턴 : 임시객채로 리턴한다.
Point& foo()		// 참조 리턴 : 리턴용 임시객체를 만들지 말라는 의도.
{					// 주의! 지역변수는 절대로 참조를 리턴하면 안된다. 참조 리턴은 전역변수만 가능, 지역 변수늠 안됨.
					// 지역변수는 함수가 끝남과 동시에 소멸자가 불리기 때문에
					// 참조를 할 대상이 없다.
	return p;
}
int main()
{
	Point pt;
	pt = foo();

}