//5_const5

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// 핵심, 논리적 상수성 : 외부에서 볼때는 상수 멤버가 함수가 되야 하지만,
//						실제로 내부적으로는 멤버의 값을 변경해야 하는 경우.
class Point
{
	int x, y;
	char cache[16];
	bool cache_valid;

public:
	Point(int a = 0, int b = 0) : x(a), y(b), cache_valid(false) {}

	// 객체의 상태를 문자열로 변환하는 함수 - 디버깅 용도

	char* toString()// const
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

	// 객체 p의 상태를 출력해 보고싶다. / JAVA의 __ 함수

	cout << p.toString() << endl;
	cout << p.toString() << endl;

}