//변수1.cpp
#include <iostream>
using namespace std;

int main() {
	int x[3] = { 1,2,3 };

	//int n = x[0];
	auto n = x[0]; // 우변의 타입을 조사해서 좌변을 결정해 달라. 
					//C++
	//auto n2; // ??error

	decltype(n) n3; // n과 동일 타입의 변수 n3
					//C++

	//초기화 방법
	int n3 = 10;
	int y[2] = { 1, 2 };
	//Point p(1,2); //C++ 클래스 초기화
	
	//모든 변수를 동일한 방법으로 초기화 C++11
	//일관된 초기화 - 모두 {}로 초기화 가능
	int n4 = { 10 };
	int z[2] = { 1,2 };

	int n5 = 3.4;//ok
	int n5 = { 3.4 };//error

	char c = { 300 }; // 255까지 가능 overflow

	int n7 = 0b1;//2진수 C++11
	int n8 = 1'000'000; // ' 표시 가능.


}