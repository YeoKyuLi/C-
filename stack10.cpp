//stack10.cpp

#include <iostream>

using namespace std;
//10�ܰ�, C++ ǥ�� ���� ���
#include <stack>

int main()
{
	stack<int> s1; // ���� �޸� �Ҵ��� �ƴ϶� list ���� ���..
	stack<double> s2;

	s1.push(20);
	s1.push(160);

	//����!! pop()�� ���Ÿ�, top()�� ���ϸ�.
	cout << s1.top() << endl;
	s1.pop();
	cout << s1.top() << endl;

}