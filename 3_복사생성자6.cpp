//3_복사생성자6
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// 핵심, 
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
	// 컴파일러에게 복사 생성자를 만들지 말라는 지시어
	// 싱글톤 등의 디자인 패턴에서 널리 사용하는 기법...
	People(const People&) = delete; // 함수 삭제
};

void foo(People p) {}

int main()
{
	People p1("Kim", 20);

	foo(p1); // error. 단, foo의 인자를 call by value 대신
			// const People& 로 사용하면 된다.
	//People p2 = p1; // complie-time error

}