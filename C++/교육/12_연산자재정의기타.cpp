//12_�����������Ǳ�Ÿ

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point* operator&() { return 0; }
};

int main()
{
	// . * ->* # : �� ������ �ȵ�.
	// * ->* # : �� ������ �ȵ�. C++11
	Point p;
	cout << &p << endl;	// ?? �� �ּҰ� ���ñ�?
						// p -> ������ �Ǵ� ��ü
						// &p : p.operator&()
	p.// ��� �Լ� ȣ�� ( p.operator() ) // p.foo() ==> (p.operator.()).foo()

}