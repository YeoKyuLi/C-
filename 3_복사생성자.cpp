// 3_���������
#include <iostream>>

using namespace std;

class Point
{
public :
	int x, y;
public:
	Point()				: x(0), y(0) {} // 1
	Point(int a, int b) : x(a), y(b) {} // 2

	// ���� ������ : �ڽ��� Ÿ���� ��ü�� �ʱ�ȭ �� �� ���
	//					����ڰ� ������ ������ �����Ϸ��� ����� �ش�.
	// �⺻ ��� :  Point(const Point& p){}
	//					�⺻ ������ ��� ����� ������ �ش�.
	
	Point(const Point& p) : x(p.y), y(p.x)
	{

	}
};

int main()
{
	// ��� ��ü�� �����Ҷ� �ݵ�� �����ڸ� ȣ���ؾ� �Ѵ�.
	Point p1;			// 1
	Point p2(1, 2);		// 2
	Point p3(p2);		// Point( Point ) ����� �����ڰ� �ʿ��ϴ�.

	cout << "p2 == " << p2.x << "  " << p2.y << endl;

	cout << "p3 == " << p3.x << "  " << p3.y << endl;
}