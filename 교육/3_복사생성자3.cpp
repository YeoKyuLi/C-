//3_복사생성자3

#include <iostream>
#include <string.h>

using namespace std;

// 클래스 안에 포인터 멤버가 있고, 동적 메모리 할당하고 있다면
// 디폴트 복사 생성자는 얕은 복사(Shllow Copy) 현상이 있다.

// 사용자는 반드시 복사 생성자를 직접(다시) 만들어야 합니다.

// 생성자는 메모리 순서에 따라서 생성하고 a -> b -> c
// 소멸자는 반대로 참조되는 것 먼저 생성한다. c -> b -> a
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

	People p2 = p1; // 이 순간 run-time error

}