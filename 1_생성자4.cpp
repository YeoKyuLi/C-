//1_������4

#include <iostream>
using namespace std;

// �ٽ� : �ʱ�ȭ ����Ʈ�� ��������� ����� ���� ������� �ʱ�ȭ �ȴ�.
//			�ڵ��� ������ �ǹ̰� ����.
class Point
{
	//�������������
public:
	int y;
	int x;


public:
	// �ʱ�ȭ�� �޸��� ������� �����Ѵ�.
	Point(int a = 0, int b = 0 ) : y(b), x(y) // defalut param ���� ����
	{

	}
};



int main()
{
	Point p; //1,1�� �ʱ�ȭ ��.

	cout << p.x << endl;	// ������ ��
	cout << p.y << endl;	// 0
}