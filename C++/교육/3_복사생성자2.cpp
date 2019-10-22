// 3_���������2
#include <iostream>>

using namespace std;

class Point
{
public:
	int x, y;
public:
	Point() : x(0), y(0) { cout << "������1" << endl; } // 1
	Point(int a, int b) : x(a), y(b) { cout << "������2" << endl; }
	Point(const Point& p) : x(p.x), y(p.y)
	{
		cout << "���� ������" << endl;
	}
};


// call by value : �޸� ������ ���� - �޸� ������� �߻�
//					���� ������/�Ҹ��� ȣ�� - ���� �������
//void foo(Point p) // Point p = p3
void foo(const Point& p) // call by value ��� const ������ ����.
{
}

int main()
{
	// ��� ��ü�� �����Ҷ� �ݵ�� �����ڸ� ȣ���ؾ� �Ѵ�.
	Point p1;			// ������ 1
	Point p2(1, 2);		// ������ 2
	Point p3(p2);		// ���� ������
	Point p4 = p3;		// Point p4(p3); ��, ���� ������
	foo(p3);			

//	int a = 0;
//	int a(0);
}
