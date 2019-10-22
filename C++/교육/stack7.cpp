//stack7.cpp

#include <iostream>

using namespace std;
//7�ܰ�, ��� �Լ��� ����� ������ �и�.

class Stack	//���� ������ ������ ����Ʈ�� private
{
	int* buff;
	int idx;

public:
	//Ŭ���� ���𿡴� �Լ� ����,, �Լ� ������ �ܺο�
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