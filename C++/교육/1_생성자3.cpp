//1_������3

#include <iostream>
using namespace std;

// �ٽ� : const ����� ����Ʈ �����ڰ� ���� Ÿ���� ����� ���� ��
//			�ݵ�� �ʱ�ȭ ����Ʈ�� ����ؾ� �Ѵ�.
class Point
{
	int x;
	int y;
	const int c; // c�� ��� �̹Ƿ� �ݵ�� �ʱ�ȭ �Ǿ�� �Ѵ�.
				// �ݵ�� �ʱ�ȭ ����Ʈ�� ����ؾ� �Ѵ�.

public:
	Point(int a, int b) : x(a), y(b), c(10)
	{
		//c = 10; //error �ʱ�ȭ�� �ƴ� �����̴�.
		//�ʱ�ȭ ����Ʈ�� ����ؾ� �Ѵ�.
	}
};

class Rect
{
	Point p1;
	Point p2;

public:
	Rect() : p1(0,0), p2(1,1)
	{
		//p1(0,0); �����ϴ� ��, 
	}
};

int main()
{
	Rect r;

	//Point p(1, 1); //1,1�� �ʱ�ȭ ��.

}