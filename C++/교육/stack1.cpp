//stack1.cpp

#include <iostream>

using namespace std;
//스택을 만들어 봅시다.
//1단계. 전역변수 배열과 함수 사용
//단점 : 스택이 2개 필요하다면 어떻게 할까요 ?


int buff[10];
int idx = 0;
void push(int a) { buff[idx++] = a; }
int pop() { return buff[--idx]; }
int main()
{
	push(20);
	push(10);

	cout << pop() << endl; //10
}