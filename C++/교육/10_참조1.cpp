//10_����1

#include <iostream>

using namespace std;

int main()
{
	int n = 3; //���ÿ� �޸� �Ҵ�
	int* p = &n; //

	int& r = n; //���� Ÿ�� ���� - ���� �޸𸮿� ���� �߰����� �̸� �ο�

	r = 20;
	cout << n << endl; //20
	cout << &n << endl;
	cout << &r << endl; //���� ������ �ּ�

	int& r2; //error. ���������� �ݵ�� �ʱⰪ�� �ʿ��ϴ�.

	//null pointer�� ������ null ������ ����.
	//null pointer�� ���������� pointer�� �����ؼ� ����ؾ��Ѵ�.
	int* p1 = 0;


}