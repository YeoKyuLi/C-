//4_static2
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
	static int getCount(){return cnt;}
};
// C++ 에서는 static 멤버 data는 반드시 외부 선언이 필요하다.
int Car::cnt = 0;
int main()
{

	// "클래스이름::정적멤버" 로 접근 가능
	// 자바 : 클래스이름.정적멤버
	//cout << Car::cnt << endl; // 하지만, private 이므로 error

	cout << Car::getCount() << endl;

	Car c1, c2;

	cout << c1.getCount() << endl;
}