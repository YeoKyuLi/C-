// 3_복사생성자
#include <iostream>>

using namespace std;

class Point
{
public :
	int x, y;
public:
	Point()				: x(0), y(0) {} // 1
	Point(int a, int b) : x(a), y(b) {} // 2

	// 복사 생성자 : 자신의 타입의 객체로 초기화 될 때 사용
	//					사용자가 만들지 않으면 컴파일러가 만들어 준다.
	// 기본 모양 :  Point(const Point& p){}
	//					기본 구현은 모든 멤버를 복사해 준다.
	
	Point(const Point& p) : x(p.y), y(p.x)
	{

	}
};

int main()
{
	// 모든 객체는 생성할때 반드시 생성자를 호출해야 한다.
	Point p1;			// 1
	Point p2(1, 2);		// 2
	Point p3(p2);		// Point( Point ) 모양의 생성자가 필요하다.

	cout << "p2 == " << p2.x << "  " << p2.y << endl;

	cout << "p3 == " << p3.x << "  " << p3.y << endl;
}