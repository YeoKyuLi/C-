//stack7.cpp

#include <iostream>

using namespace std;
//7단계, 멤버 함수의 선언과 구현의 분리.

class Stack	//접근 지정자 생략시 디폴트가 private
{
	int* buff;
	int idx;

public:
	//클래서 선언에는 함수 선언만,, 함수 구현은 외부에
	Stack(int sz = 10);
	~Stack();
	void push(int a);
	int pop();
};
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
	s1.push(160);

	cout << s1.pop() << endl;

}