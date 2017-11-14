//2_소멸자

#include <iostream>

using namespace std;

class People
{
	//char name[5]; // 배열 : 이름에 갯수에 제한을 가지게 된다.
	char* name;
	int age;
public :
	People(const char* n, int a) :  age(a)
	{
		// 이름의 문자열 갯수 만큼을 메모리 할당한다.
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	// 소멸자 필요성 : 동적 메모리할당 과 같이 자원을 생성하는 경우
	//					해지하기 위해서 필요하다.
	//					자원해지가 필요없다면 만들지 않아도 된다.
	//					프로그램이 끊거나 전원이 나가면 메모리는 free 되지만,
	//					끝나지 않는 프로그램을 개발하는 경우 delete 해줘야 함.
	~People()
	{
		delete[] name;
	}
};

int main()
{
	People p("Kim", 20);


}