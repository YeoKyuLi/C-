//Stack.h

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