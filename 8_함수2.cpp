//�Լ�2.cpp - C++�Լ��� Ư¡2. �����ε�
//������ Ÿ���̳� ������ �ٸ��� �����̸��� �Լ��� 2���̻� ����� �ִ�.
int square(int a)
{
	return a*a;
}
double square(double a)
{
	return a*a;
}
int main()
{
	square(3);
	square(3.3);
}
// ���� ����
void f1(int a){}
void f1(int a, int b) {} //ok

//���� 1. ����Ʈ �� ����
void f2(int a) {}
void f2(int a, int b=0) {} //error overload (X)
f2(10);

//���� 2.����Ÿ�Ը� �ٸ���� �����ε� �� �� ����.
void f3(int a) {}
int f3(int a) {}
f3(10);
