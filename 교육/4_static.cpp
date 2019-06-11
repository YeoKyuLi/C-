//4_static
#include <iostream>

using namespace std;
//static member data : 

// 전역변수 : 모든 객체가 공유한다.
//			하지만, 잘못된 사용을 막을 수 없다.
//int cnt = 0;

// static 멤버 데이터
// 1. 객체가 없어도 메모리에 놓인다.
// 2. 객체를 열개 생성시 모든 객체가 공유한다.
// 3. 결국 접근지정자를 사용할 수 있는 전역 변수의 의미.


class Car
{
private :
	static int cnt; // 모든 객체가 공유하는 멤버 data

public:
	Car()	{ ++cnt; }
	~Car()	{ --cnt; }

	int getCount()
	{
		return cnt;
	}
};
// C++ 에서는 static 멤버 data는 반드시 외부 선언이 필요하다.
int Car::cnt = 0;
int main()
{
	Car c1, c2;

	cout << c1.getCount() << endl;
	//cout << cnt << endl;

	//cnt = 10; // 사용자가 실수..
}