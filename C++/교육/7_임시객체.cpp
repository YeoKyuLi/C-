// 7_�ӽð�ü - ���� ������ 2�� ����		
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

// call by value : ���纻���� ���� �޴´�. ���� ������ ȣ��.
//void foo(Point p){}
Point goo()
{
	Point p;		// 2. ������
	return p;		// 3. ���Ͽ� �ӽð�ü����(p�� �����ؼ� �����.) / ���� �����ڸ� ���� ����� ����.
}					// 4. p�� �Ҹ���
int main()
{
	Point pt;		// 1. ������
	pt = goo();		// 5. ���Ͽ� �ӽð�ü �ı� - �Ҹ��� ( ; ������ �ı� )

	cout << "A" << endl; // 6. A
						 //foo(pt);

}					// 7. pt�� �Ҹ���.

