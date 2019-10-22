//4_static
#include <iostream>

using namespace std;
//static member data : 

// �������� : ��� ��ü�� �����Ѵ�.
//			������, �߸��� ����� ���� �� ����.
//int cnt = 0;

// static ��� ������
// 1. ��ü�� ��� �޸𸮿� ���δ�.
// 2. ��ü�� ���� ������ ��� ��ü�� �����Ѵ�.
// 3. �ᱹ ���������ڸ� ����� �� �ִ� ���� ������ �ǹ�.


class Car
{
private :
	static int cnt; // ��� ��ü�� �����ϴ� ��� data

public:
	Car()	{ ++cnt; }
	~Car()	{ --cnt; }

	int getCount()
	{
		return cnt;
	}
};
// C++ ������ static ��� data�� �ݵ�� �ܺ� ������ �ʿ��ϴ�.
int Car::cnt = 0;
int main()
{
	Car c1, c2;

	cout << c1.getCount() << endl;
	//cout << cnt << endl;

	//cnt = 10; // ����ڰ� �Ǽ�..
}