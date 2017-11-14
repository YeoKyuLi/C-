#include <iostream>
#include <vector>
using namespace std;

// "동일 이름"의 상수 멤버 함수와 비상수 멤버 함수를 만들 수 있다.

class Test
{
public:
	void foo()		 { cout << "foo" << endl; }				// 1
	void foo() const { cout << "foo const " << endl; }		// 2
};

int main()
{
	Test t1;
	t1.foo();		// 1, 1이 없다면 2번 호출

	const Test t2;
	t2.foo();		// 2, 2가 없으면 error

	//------------------------------------------------------------------------------
	vector<int> v(10, 3);	// vector 배열과 유사 클래스
							// 10개를 3으로 초기화
	v[0] = 10;				// v.operator[](0) = 10; / OK

//	const vector<int> v1(10, 3);
//	v1[0] = 10;	//v1.operator[](0) = 10; / ERROR
}