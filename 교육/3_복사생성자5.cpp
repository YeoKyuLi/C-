//3_복사생성자5
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

// 얕은 복사의 해결책 2. 참조계수(Reference counting) - 가장 중요한 기술
// copy on write
// 단 이경우, p1 객체가 이름을 변경할때는
// p2하고 공유하는 메모리에 변경하면 안되고... 자원을 분리해야한다.
// COW(Copy on Write)라고 불리는 개념 ---- 모든 언어에 있는 개념.

class People
{
	char* name;
	int age;
	int* ref; // 자원의 참조계수는 반드시 동적할당한 메모리에 관리되어야 함.
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

	// 깊은 복사(Deep copy)로 구현한 복사 생성자 - 
	People(const People& p) : name(p.name), age(p.age), ref(p.ref) //모든 멤법 얕은 복사.
	{
		++(*ref);
	}
};

int main()
{
	People p1("Kim", 20);

	People p2 = p1;

}