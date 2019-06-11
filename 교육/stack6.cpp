//stack6.cpp

#include <iostream>

using namespace std;
//6�ܰ�, �ڷᱸ���� ���� - �����޸� �Ҵ��� ����� ����. 
//			����ڰ� ���� ũ�� ����
//			�Ҹ��ڸ� �����ؼ� ��ü�� ����� �ڿ� ����.

class Stack	//���� ������ ������ ����Ʈ�� private
{
	int* buff;
	int idx;

public:
	//��� �Լ�.
	Stack(int sz = 10) 
	{
		idx = 0;
		buff = new int[sz];
	}
	
	
	//�Ҹ��� : ��ü�� �ı��ɶ� ȣ��ȴ�.
	//		���ڸ� ���� �� ����. Ŭ���� �̸� �տ� ~�� ���ε�.
	~Stack() { delete[] buff; }


	void push(int a) { buff[(idx)++] = a; }
	int pop() { return buff[--(idx)]; }
};


int main()
{
	Stack s1(100);


	s1.push(20);
	s1.push(160);

	cout << s1.pop() << endl;

}