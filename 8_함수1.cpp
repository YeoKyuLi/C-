//8_�Լ�1.cpp
//c�� �ٸ� c++�Լ��� Ư¡, 1.����Ʈ �Ķ����
//���� 1. ������ ���ں��� ���ʴ�θ� ��������.
//���� 2. �Լ��� ����� �������� �и��ÿ��� ���𿡸� ����Ʈ������..

#include <iostream>
//void foo(int a = 0, int b, int c = 0) //���� 1. error

void foo(int a, int b = 0, int c = 0); //���� 2.

int main()
{
	foo(1, 2, 3);
	foo(1, 2);
	foo(1);

}

void foo(int a, int b /* = 0 */ , int c /* = 0 */)
{

}