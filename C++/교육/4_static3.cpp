//4_static3
#include <iostream>

using namespace std;

class Car
{
private:
	static int cnt; // ��� ��ü�� �����ϴ� ��� data

public:
	Car() { ++cnt; }
	~Car() { --cnt; }

	// static ��� �Լ� : ��ü���� ȣ�� ������ �Լ�.
	static int getCount() { return cnt; }
};
// C++ ������ static ��� data�� �ݵ�� �ܺ� ������ �ʿ��ϴ�.
int Car::cnt = 0;
int main()
{
	Car c;
	// C++
	int n1 = Car::getCount();	 // Ŭ�����̸�::static ����Լ�()
	int n2 = c.getCount();		// ��ü.static����Լ�()

	// java
	int n3 = Car.getCount(); // Ŭ�����̸�.static����Լ�()
	int n4 = c.getCount(); // ��ü.static����Լ�()�� error
	//int n5 = c.static�� �ƴ� ����Լ�();


}