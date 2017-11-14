//3_���������4
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// ���� ������ �ذ�å 1. ���� ���� = �޸� ��ü�� �����ϴ� ���

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

	// ���� ����(Deep copy)�� ������ ���� ������ - 
	People(const People& p)
	{
		// ������ ����� �ƴ� ��� �׳� ����
		// age = p.age;

		// 1. �޸� �Ҵ�. 2. �޸� ����
		// ������ ����� �޸� �Ҵ� �� �޸� ��ü�� ����
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}
};

int main()
{
	People p1("Kim", 20);

	People p2 = p1; 

}