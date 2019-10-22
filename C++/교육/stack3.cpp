//stack3.cpp

#include <iostream>

using namespace std;
//3�ܰ� ,Ÿ�� ����� "���¸� ��Ÿ���� �����Ϳ� ���¸� �����ϴ� �Լ�"
//			�� ��� Ÿ���� �����. ==> "ĸ��ȭ(encapsulation" ����
//			C++ ������ ����ü�� �Լ��� ���� �� �ִ�.
struct Stack
{
	//��� ������
	int buff[10];
	int idx;

	//��� �Լ�.
	void init() {idx = 0; }
	void push( int a) {buff[(idx)++] = a; }
	int pop() { return buff[--(idx)]; }
}; //����ü �ʱ�ȭ �ȵ�.


int main()
{
	Stack s1, s2; //2���� ����.
	s1.init(); // init(&s1); --> �����Ϸ��� �ش� �������� ������ ����.
	s1.push(20);// push(&s1, 20);
	s1.push(160);// push(&s1, 10);

	cout << s1.pop() << endl; //10

	//C++�� ������ �ᱹ ������ ����.
	//s1.init() ==> init(&s1)		�� �����Ͻ� ����˴ϴ�.
}