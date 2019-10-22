//10_참조1

#include <iostream>

using namespace std;

int main()
{
	int n = 3; //스택에 메모리 할당
	int* p = &n; //

	int& r = n; //참조 타입 변수 - 기존 메모리에 대한 추가적인 이름 부여

	r = 20;
	cout << n << endl; //20
	cout << &n << endl;
	cout << &r << endl; //위와 동일한 주소

	int& r2; //error. 참조변수는 반드시 초기값이 필요하다.

	//null pointer는 있지만 null 참조는 없다.
	//null pointer가 존재함으로 pointer는 조사해서 사용해야한다.
	int* p1 = 0;


}