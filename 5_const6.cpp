//5_const6

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// 핵심, 논리적 상수성 1. 
class Point
{
	int x, y;
	// mutable : 상수 멤버 함수에서도 값을 변경할 수 있는 멤버 data
	mutable char cache[16];
	mutable bool cache_valid;

public:
	Point(int a = 0, int b = 0) : x(a), y(b), cache_valid(false) {}

	// 객체의 상태를 문자열로 변환하는 함수 - 디버깅 용도

	char* toString() const
	{
		if (cache_valid == false)
		{
			sprintf(cache, "%d, %d", x, y);
			cache_valid = true;
		}
		return cache;
	}

};
int main()
{
	Point p(1, 1);

	cout << p.toString() << endl;
	cout << p.toString() << endl;

}