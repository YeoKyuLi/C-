//stack9.cpp

#include <iostream>

using namespace std;
//9�ܰ�, �پ��� Ÿ���� ���� �� �� �ְ� - template ����
//		�پ��� Ÿ���� stack Ŭ������ �ڵ� ����
//		template�� �Ϲ������� ����� �������� �и����� �ʽ��ϴ�.
//		������ ��������...

template<typename T>
class Stack	
{
	T* buff;
	int idx;

public:
	//��� �Լ�.
	Stack(int sz = 10)
	{
		idx = 0;
		buff = new T[sz];
	}

	~Stack() { delete[] buff; }


	void push(const T& a) { buff[(idx)++] = a; }
	T pop() { return buff[--(idx)]; }
};


int main()
{
	Stack<int> s1(100);
	Stack<double> s2(10);

	s1.push(20);
	s1.push(160);

	cout << s1.pop() << endl;

}