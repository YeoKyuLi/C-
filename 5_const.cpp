//5_const
#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;

public :
	Point(int a = 0, int b = 0) : x(a), y(b) {}
	void set(int a, int b) { x = a, y = b; }

	void print() const // ��� ��� �Լ�
	{
		//x = 10; //error. ��� ����Լ� �ȿ����� ����� ���� ������ �� ����.
		cout << x << "," << y << endl;
	}
};
int main()
{

}