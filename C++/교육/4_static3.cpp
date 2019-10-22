//4_static3
#include <iostream>

using namespace std;

class Car
{
private:
	static int cnt; // 모든 객체가 공유하는 멤버 data

public:
	Car() { ++cnt; }
	~Car() { --cnt; }

	// static 멤버 함수 : 객체없이 호출 가능한 함수.
	static int getCount() { return cnt; }
};
// C++ 에서는 static 멤버 data는 반드시 외부 선언이 필요하다.
int Car::cnt = 0;
int main()
{
	Car c;
	// C++
	int n1 = Car::getCount();	 // 클래스이름::static 멤버함수()
	int n2 = c.getCount();		// 객체.static멤버함수()

	// java
	int n3 = Car.getCount(); // 클래스이름.static멤버함수()
	int n4 = c.getCount(); // 객체.static멤버함수()는 error
	//int n5 = c.static이 아닌 멤버함수();


}