//4_static2
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
	static int getCount(){return cnt;}
};
// C++ ������ static ��� data�� �ݵ�� �ܺ� ������ �ʿ��ϴ�.
int Car::cnt = 0;
int main()
{

	// "Ŭ�����̸�::�������" �� ���� ����
	// �ڹ� : Ŭ�����̸�.�������
	//cout << Car::cnt << endl; // ������, private �̹Ƿ� error

	cout << Car::getCount() << endl;

	Car c1, c2;

	cout << c1.getCount() << endl;
}