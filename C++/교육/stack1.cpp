//stack1.cpp

#include <iostream>

using namespace std;
//������ ����� ���ô�.
//1�ܰ�. �������� �迭�� �Լ� ���
//���� : ������ 2�� �ʿ��ϴٸ� ��� �ұ�� ?


int buff[10];
int idx = 0;
void push(int a) { buff[idx++] = a; }
int pop() { return buff[--idx]; }
int main()
{
	push(20);
	push(10);

	cout << pop() << endl; //10
}