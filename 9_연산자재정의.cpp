//9_������������

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
	// ���� �� ���� ���� ���� �ڵ�� ?
	Point p3 = Add(p1, p2);	//
	Point p4 = p1.Add(p2);	// p1.Add ����Լ�
	Point p5 = p1 + p2;		//������ ������ ����
	
							
	//������ ������ ���� : ����� ���� Ÿ�ӿ� ���ؼ��� + ���� �����ڸ�
	//						����� �� �ְ� �ϴ� ����
	//						"small talk"�� �� ���� ���ʷ� ����.

}