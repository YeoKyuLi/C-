//3_���������6
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// �ٽ�, 
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
	// �����Ϸ����� ���� �����ڸ� ������ ����� ���þ�
	// �̱��� ���� ������ ���Ͽ��� �θ� ����ϴ� ���...
	People(const People&) = delete; // �Լ� ����
};

void foo(People p) {}

int main()
{
	People p1("Kim", 20);

	foo(p1); // error. ��, foo�� ���ڸ� call by value ���
			// const People& �� ����ϸ� �ȴ�.
	//People p2 = p1; // complie-time error

}