//4_static4

class Car
{
	int speed;
	static int cnt;

public :
	void init() { speed = 0; }

	// static ��� �Լ������� static ����� ������ �� �ִ�.
	static void foo()
	{
		// ���� �� ������ ��� ������.
		speed = 10;	// 1. error
		cnt = 0;	// 2. ok
		init();		// 3. error
	}
};

int Car::cnt = 0;

int main()
{
	Car::foo();	// ��ü���� ȣ�Ⱑ��.

}