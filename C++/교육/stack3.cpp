//stack3.cpp

#include <iostream>

using namespace std;
//3단계 ,타입 설계시 "상태를 나타내는 데이터와 상태를 조작하는 함수"
//			를 묶어서 타입을 만든다. ==> "캡슐화(encapsulation" 개념
//			C++ 에서는 구조체에 함수를 넣을 수 있다.
struct Stack
{
	//멤버 데이터
	int buff[10];
	int idx;

	//멤버 함수.
	void init() {idx = 0; }
	void push( int a) {buff[(idx)++] = a; }
	int pop() { return buff[--(idx)]; }
}; //구조체 초기화 안됨.


int main()
{
	Stack s1, s2; //2개의 스택.
	s1.init(); // init(&s1); --> 컴파일러가 해당 문법으로 컴파일 해줌.
	s1.push(20);// push(&s1, 20);
	s1.push(160);// push(&s1, 10);

	cout << s1.pop() << endl; //10

	//C++의 원리는 결국 다음과 같다.
	//s1.init() ==> init(&s1)		로 컴파일시 변경됩니다.
}