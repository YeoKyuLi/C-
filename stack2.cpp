//stack2.cpp

#include <iostream>

using namespace std;
//2�ܰ� , ����ü�� stack Ÿ���� �����Ѵ�.

struct Stack
{
	int buff[10];
	int idx;
}; //����ü �ʱ�ȭ �ȵ�.

void init(Stack* s) { s->idx = 0; }
void push(Stack* s, int a) { s->buff[(s->idx)++] = a; }
int pop(Stack* s) { return s->buff[--(s->idx)]; }
int main()
{
	Stack s1, s2; //2���� ����.
	init(&s1);
	push(&s1, 20);
	push(&s1, 10);

	cout << pop(&s1) << endl; //10
}