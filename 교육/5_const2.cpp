//5_const2
#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;

public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}
	void set(int a, int b) { x = a, y = b; }

	void print() //const // ��� ��� �Լ�
	{
		//x = 10; //error. ��� ����Լ� �ȿ����� ����� ���� ������ �� ����.
		cout << x << "," << y << endl;
	}
};
int main()
{
	const Point p(1, 1); // const int c = 10;

	p.x = 10;			// error. p�� ��� ��ü�̴�.
	p.set(10, 20);		// error. 
	p.print();			// void print(); �� �����ؼ��� complier�� ���� �ٲٴ����� �� �� ����.
						// �ǰ� �Ϸ��� print() �� �Լ��Լ��� �ؾ� �Ѵ�.
						// "�����ü"�� "�������Լ�"�� ȣ�� �� �� �ִ�.

}