//5_const4

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
class Point
{
	int x, y;

public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// 객체의 상태를 문자열로 변환하는 함수 - 디버깅 용도

	char* toString() //const
	{
		static char s[16];
		sprintf(s, "%d, %d", x, y);
		return s;
	}

};
int main()
{
	const Point p(1, 1);

	// 객체 p의 상태를 출력해 보고싶다. / JAVA의 __ 함수

	cout << p.toString() << endl;

}