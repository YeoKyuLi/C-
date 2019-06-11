//12_연산자재정의기타

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point* operator&() { return 0; }
};

int main()
{
	// . * ->* # : 은 재정이 안됨.
	// * ->* # : 은 재정이 안됨. C++11
	Point p;
	cout << &p << endl;	// ?? 왜 주소가 나올까?
						// p -> 포인터 또는 객체
						// &p : p.operator&()
	p.// 멤버 함수 호출 ( p.operator() ) // p.foo() ==> (p.operator.()).foo()

}