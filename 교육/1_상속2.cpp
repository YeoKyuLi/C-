//1_���2

#include <iostream>
using namespace std;

// 

class Animal
{
	// �ڹ��� ��� ���信�� �ϳ��� ������ �� �ִ�.
private:
	int age;	// �ڽ��� ��� �Լ�, friend �Լ��� ���� ����.

protected :
	int data;	// �ڽ��� ����Լ�, friend �Լ�, 
				// �Ļ� Ŭ������ ��� �Լ�, friend �Լ����� ���ٰ���.
public:
	int data2;	// ��� �Լ��� ���� ����.
	void Cry() {}
};

class Dog : public Animal	
{
	int color;
public:
	void foo()
	{
		age = 10;	//error
	}
};

int main()
{


}