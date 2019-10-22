//3_���������5
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

// ���� ������ �ذ�å 2. �������(Reference counting) - ���� �߿��� ���
// copy on write
// �� �̰��, p1 ��ü�� �̸��� �����Ҷ���
// p2�ϰ� �����ϴ� �޸𸮿� �����ϸ� �ȵǰ�... �ڿ��� �и��ؾ��Ѵ�.
// COW(Copy on Write)��� �Ҹ��� ���� ---- ��� �� �ִ� ����.

class People
{
	char* name;
	int age;
	int* ref; // �ڿ��� ��������� �ݵ�� �����Ҵ��� �޸𸮿� �����Ǿ�� ��.
public:
	People(const char* n, int a) : age(a)
	{

		name = new char[strlen(n) + 1];
		strcpy(name, n);

		ref = new int;
		*ref = 1;
	}

	~People()
	{
		if(--(*ref) == 0)
		{
			delete[] name;
			delete ref;
		}

	}

	// ���� ����(Deep copy)�� ������ ���� ������ - 
	People(const People& p) : name(p.name), age(p.age), ref(p.ref) //��� ��� ���� ����.
	{
		++(*ref);
	}
};

int main()
{
	People p1("Kim", 20);

	People p2 = p1;

}