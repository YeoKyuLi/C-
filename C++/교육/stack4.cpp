//stack4.cpp

#include <iostream>

using namespace std;
//4�ܰ�, �ܺ��� �߸��� ������� ���� ��ü�� �Ҿ��� ���� ���� ���´�.
//		���� �������� ����.
//		"���� ����(information hiding)"


struct Stack // ���� ������ ������ ����Ʈ�� public
//class Stack	//���� ������ ������ ����Ʈ�� private
{
	//private�� ���ǵǾ� ���� ������ public�̴�. -- struct����.
private :	//��� �Լ��� ���� ����, �ܺο����� ���� �Ұ�.
	//��� ������
	int buff[10];
	int idx;

public:
	//��� �Լ�.
	void init() { idx = 0; }
	void push(int a) { buff[(idx)++] = a; }
	int pop() { return buff[--(idx)]; }
}; 


int main()
{
	Stack s1;
	s1.init(); 

	//s1.idx = -10; //����ڰ� �� �� ����ߴ�..



	s1.push(20);
	s1.push(160);

	cout << s1.pop() << endl; 

}