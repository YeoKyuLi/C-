//stack5.cpp

#include <iostream>

using namespace std;
//5�ܰ�, ��ü�� �ʱ�ȭ�� �ڵ�����... �������� ����.

//struct Stack // ���� ������ ������ ����Ʈ�� public
class Stack	//���� ������ ������ ����Ʈ�� private
{
private:	//��� �Լ��� ���� ����, �ܺο����� ���� �Ұ�.
			//��� ������
	int buff[10];
	int idx;

public:
	//��� �Լ�.
	//������ : ����ü(Ŭ����) �̸��� �����ϰ� ��ü�� ����� �ڵ����� ȣ��ȴ�.
	//			���ϰ��� ���� ���� Ÿ���� ǥ������ �ʴ´�.
	Stack() { idx = 0; }
	void push(int a) { buff[(idx)++] = a; }
	int pop() { return buff[--(idx)]; }
};


int main()
{
	Stack s1;
	s1.init();


	s1.push(20);
	s1.push(160);

	cout << s1.pop() << endl;

}