// 6_this

#include <iostream>
using namespace std;


class Point
{
	int x, y;

public :
	void set(int x, int y) // void set(Point* const this, int x , int y)
	{
		// this = 0;
		cout << this << endl; // ��ü�� �ּҰ� ���´�.
		this -> x = x;
		this -> y = y;
	}

	// this�� �����ϴ� �Լ�
	Point* goo() { return this; }    // �ּ� ����
	//Point foo() { return *this; } // �ڽ��� ���纻 ����
	Point& foo() { return *this; } // ���纻�� �ƴ� ��¥ �ڽ��� ����.
};

int main()
{
	Point p1, p2;
	p1.set(10, 20); // set(&p1, 10, 20)
	p2.set(30, 40);	// set(&p2, 30, 40)

	p1.goo()->goo(); //�ּ� ����
	p1.foo().foo().foo();// �� ���� cout << "A" << "B" << "C" << endl; --> this return.
}