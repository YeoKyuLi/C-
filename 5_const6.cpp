//5_const6

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// �ٽ�, ���� ����� 1. 
class Point
{
	int x, y;
	// mutable : ��� ��� �Լ������� ���� ������ �� �ִ� ��� data
	mutable char cache[16];
	mutable bool cache_valid;

public:
	Point(int a = 0, int b = 0) : x(a), y(b), cache_valid(false) {}

	// ��ü�� ���¸� ���ڿ��� ��ȯ�ϴ� �Լ� - ����� �뵵

	char* toString() const
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

	cout << p.toString() << endl;
	cout << p.toString() << endl;

}