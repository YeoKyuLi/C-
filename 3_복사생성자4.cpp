//3_복사생성자4
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// 얕은 복사의 해겨책 1. 깊은 복사 = 메모리 자체를 복사하는 기법

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

	// 깊은 복사(Deep copy)로 구현한 복사 생성자 - 
	People(const People& p)
	{
		// 포인터 멤버가 아닌 경우 그냥 복사
		// age = p.age;

		// 1. 메모리 할당. 2. 메모리 복사
		// 포인터 멤버는 메모리 할당 후 메모리 자체를 복사
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}
};

int main()
{
	People p1("Kim", 20);

	People p2 = p1; 

}