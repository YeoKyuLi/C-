//9_연산자재정의

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
	int n = 3 + 4;

	Point p1(1, 1);
	Point p2(2, 2);
	// 다음 중 가장 보기 좋은 코드는 ?
	Point p3 = Add(p1, p2);	//
	Point p4 = p1.Add(p2);	// p1.Add 멤버함수
	Point p5 = p1 + p2;		//연산자 재정의 개념
	
							
	//연산자 재정의 개념 : 사용자 정의 타임에 대해서도 + 등의 연사자를
	//						사용할 수 있게 하는 개념
	//						"small talk"등 의 언어에서 최초로 등장.

}