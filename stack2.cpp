//stack2.cpp

#include <iostream>

using namespace std;
//2단계 , 구조체로 stack 타입을 설계한다.

struct Stack
{
	int buff[10];
	int idx;
}; //구조체 초기화 안됨.

void init(Stack* s) { s->idx = 0; }
void push(Stack* s, int a) { s->buff[(s->idx)++] = a; }
int pop(Stack* s) { return s->buff[--(s->idx)]; }
int main()
{
	Stack s1, s2; //2개의 스택.
	init(&s1);
	push(&s1, 20);
	push(&s1, 10);

	cout << pop(&s1) << endl; //10
}