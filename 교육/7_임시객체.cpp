// 7_임시객체 - 복사 생성자 2번 복사		
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

// call by value : 복사본으로 전달 받는다. 복사 생성자 호출.
//void foo(Point p){}
Point goo()
{
	Point p;		// 2. 생성자
	return p;		// 3. 리턴용 임시객체생성(p를 복사해서 만든다.) / 복사 생성자를 만들어서 결과값 리턴.
}					// 4. p의 소멸자
int main()
{
	Point pt;		// 1. 생성자
	pt = goo();		// 5. 리턴용 임시객체 파괴 - 소멸자 ( ; 만나면 파괴 )

	cout << "A" << endl; // 6. A
						 //foo(pt);

}					// 7. pt의 소멸자.

