//8_함수1.cpp
//c와 다른 c++함수의 특징, 1.디폴트 파라미터
//주의 1. 마지막 인자부터 차례대로만 지정가능.
//주의 2. 함수를 선언과 구현으로 분리시에는 선언에만 디폴트값지정..

#include <iostream>
//void foo(int a = 0, int b, int c = 0) //주의 1. error

void foo(int a, int b = 0, int c = 0); //주의 2.

int main()
{
	foo(1, 2, 3);
	foo(1, 2);
	foo(1);

}

void foo(int a, int b /* = 0 */ , int c /* = 0 */)
{

}