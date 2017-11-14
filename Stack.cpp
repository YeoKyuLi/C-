#include "Stack.h" // 반드시 필요하다. Stack의 정체를 알려줘야 한다.
#include <iostream>
using namespace std;

//Stack.cpp
Stack::Stack(int sz/* = 10*/)
{
	idx = 0;
	buff = new int[sz];
}
Stack::~Stack()
{
	delete[] buff;
}
void Stack::push(int a)
{
	buff[(idx)++] = a;
}
int Stack::pop()
{
	return buff[--(idx)];
}

int main()
{
	Stack s1(100);


	s1.push(20);
	s1.push(0b0111);

	cout << s1.pop() << endl;

}