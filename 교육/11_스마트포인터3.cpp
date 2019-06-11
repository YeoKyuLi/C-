// 11_스마트포인터3
// 

#include <iostream>
#include <memory> // C++11 표준 스마트포인터를 제공하는 헤더,
using namespace std;

class Car
{
	int color;
public:
	void Go() { cout << "Car Go" << endl; }
	~Car() { cout << "~Car() " << endl; }
};

int main()
{
//	shared_ptr<Car> p1 = new Car; // error, 반드시 () 초기화로 해댜합니다.
	shared_ptr<Car> p2(new Car); // ok

	shared_ptr<Car> p3 = p2;	// 참조계수가 2로 증가합니다.

	p3->Go();
}
