//9_������������2

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// ����� ������ + �Լ�
	Point operator+(const Point& p)
	{
		Point temp(x + p.x, y + p.y);
		return temp;
	}

	//friend Point operator+(const Point& p1, const Point& p2); // ��� 1.
};
/*
Point operator+(const Point& p1, const Point& p2)
{
	Point temp(p1.x + p2.x, p1.y + p2.y);
	return temp;
}
*/
int main()
{
	int n = 3 + 4;

	Point p1(1, 1);
	Point p2(2, 2);

	Point p5 = p1 + p2;		
							// 1. p1.operator+(p2)�� ã��, 
							// 2. operator+( p1, p2) �� ã�� �ȴ�.
	
	// ++a : ��ü�� ���¸� �����ϴ� �����ڴ� ��� �Լ��� ����.
	//			���� �ٲٴ� ���� ��� �Լ��� �� ����.
	// a+b : ��ü�� ���¸� �������� �ʴ� ���� �Ϲ� �Լ��� ������ �ʴ�.

	// (), -> , =, *(�������� dereference) �� �ݵ�� ��� �Լ��� �����ϴ�.

}