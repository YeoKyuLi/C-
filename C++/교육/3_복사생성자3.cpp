//3_���������3

#include <iostream>
#include <string.h>

using namespace std;

// Ŭ���� �ȿ� ������ ����� �ְ�, ���� �޸� �Ҵ��ϰ� �ִٸ�
// ����Ʈ ���� �����ڴ� ���� ����(Shllow Copy) ������ �ִ�.

// ����ڴ� �ݵ�� ���� �����ڸ� ����(�ٽ�) ������ �մϴ�.

// �����ڴ� �޸� ������ ���� �����ϰ� a -> b -> c
// �Ҹ��ڴ� �ݴ�� �����Ǵ� �� ���� �����Ѵ�. c -> b -> a
class People
{
	char* name;
	int age;

public:
	People(const char* n, int a) : age(a)
	{

		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	~People()
	{
		delete[] name;
	}
};

int main()
{
	People p1("Kim", 20);

	People p2 = p1; // �� ���� run-time error

}