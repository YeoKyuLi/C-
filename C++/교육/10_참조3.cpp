
#include <iostream>

struct Data
{
	int x;
	char buf[1024];
};

//void foo(Data a) // Call by value :: 원본을 수정하지 않겠다는 의도 값 ? 포인터 ? 참조 ??
				//하지만 ,,, 변수가 하나 더 생기므로 메모리 낭비

void foo(const Data& a) // ruffhs : call by value보다 const &가 좋다.
{
}

int main()
{
	Data d;
	d.x = 10;
	foo(d); // 약속 :: foo 함수에서는 d의 내용을 변경하지 말아야 한다.

}

//함수 인자 만들기
// 1. 원본 변수를 수정할 때 : 포인터 또는 참조 모두 가능.
// 2. 원본 변수를 수정하지 않을 때 : call by value 보다는 const &
// 다음 중 좋은 코드는 ?
void foo(int a) {} //1
void foo(const int& a) {} //2
// --> int의 경우 overhead가 작아서, call by value를 많이 이용하고 struct들은 const 타입 이용
//1 번의 경우 컴파일 과정 시 최적화가 용이하다. --> 정확히 어떤 말이인지 노 이해.

