// 8_����Ҹ���

#include <iostream>
using namespace std;

// ��� : C++���� Ŭ���� ���鶧 ��� Ŭ������ ���Ǵ� ��� Ŭ������
//			�Ҹ��ڸ� �����Լ��� ������ �Ѵ�.

//			���� ���� ��� ��� Ŭ����(Animal, Base, IValidator, Shape)�� �Ҹ��ڸ� �������� �ؾ��մϴ�.

class Base
{
public:
	virtual ~Base() {}		// ���� �Ҹ���
};

class Derived : public Base
{

public:
	Derived() { cout << "�ڿ� �Ҵ� " << endl; }
	virtual ~Derived() { cout << "�ڿ� ���� " << endl; }
};

int main()
{
	Base* p = new Derived; // �޸� �Ҵ�  +  Derived ������ ȣ��,
	delete p; // ���� �߻�.	�޸� ���� + Derived �Ҹ��� ȣ�� But, p�� Base Ÿ���̹Ƿ� Base�� �Ҹ��ڸ� ȣ��
				// 
}