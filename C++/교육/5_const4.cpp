//5_const4

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
class Point
{
	int x, y;

public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// ��ü�� ���¸� ���ڿ��� ��ȯ�ϴ� �Լ� - ����� �뵵

	char* toString() //const
	{
		static char s[16];
		sprintf(s, "%d, %d", x, y);
		return s;
	}

};
int main()
{
	const Point p(1, 1);

	// ��ü p�� ���¸� ����� ����ʹ�. / JAVA�� __ �Լ�

	cout << p.toString() << endl;

}