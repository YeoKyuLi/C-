//2_소멸자

#include <iostream>

using namespace std;


void foo(char* s)
{
	*s = 10;
}

int main()
{
	// C 문자열에 대해서
	// s1 과  s2의 차이점 ?

	char s1[] = "hello"; 

	// foo 는 인자로 문자열을 받고 있습니다.
	foo(s1); // 버퍼에 있는 문자열, ( 읽고 쓰기가 가능한 문자열 ) OK
	foo("hello"); // 상수 문자열		runtime error

	// 문자열 상수 만들기
	char* s2 = "hello";			// 쓰기를 시도하면 실행시간 에러
	const char* s2 = "hello";	// 쓰기를 시도하면 컴파일 에러


	*s1 = 'X'; // ok
	char* s2 = "hello";
	*s2 = 'X'; // runtime error ==>  상수 메모리는 read-only memory를 사용하기 때문에 에러.

	const char* s2 = "hello";
	*s2 = 'X'; // complie error
}
