//5_const5

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// �ٽ�, ���� ����� : �ܺο��� ������ ��� ����� �Լ��� �Ǿ� ������,
//						������ ���������δ� ����� ���� �����ؾ� �ϴ� ���.
class Point
{
	int x, y;
	char cache[16];
	bool cache_valid;

public:
	Point(int a = 0, int b = 0) : x(a), y(b), cache_valid(false) {}

	// ��ü�� ���¸� ���ڿ��� ��ȯ�ϴ� �Լ� - ����� �뵵

	char* toString()// const
	{
		if (cache_valid == false)
		{
			sprintf(cache, "%d, %d", x, y);
			cache_valid = true;
		}
		return cache;
	}

};
int main()
{
	Point p(1, 1);

	// ��ü p�� ���¸� ����� ����ʹ�. / JAVA�� __ �Լ�

	cout << p.toString() << endl;
	cout << p.toString() << endl;

}