// 7_�ӽð�ü2
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
	~Point()
	{
		cout << " �Ҹ��� " << endl;
	}
};

Point p; // ��������.. ����ñ��� �ı����� �ʴ´�.

//Point foo()		// �� ���� : �ӽð�ä�� �����Ѵ�.
Point& foo()		// ���� ���� : ���Ͽ� �ӽð�ü�� ������ ����� �ǵ�.
{					// ����! ���������� ����� ������ �����ϸ� �ȵȴ�. ���� ������ ���������� ����, ���� ������ �ȵ�.
					// ���������� �Լ��� ������ ���ÿ� �Ҹ��ڰ� �Ҹ��� ������
					// ������ �� ����� ����.
	return p;
}
int main()
{
	Point pt;
	pt = foo();

}