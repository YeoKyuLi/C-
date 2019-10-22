
#include <iostream>

struct Data
{
	int x;
	char buf[1024];
};

//void foo(Data a) // Call by value :: ������ �������� �ʰڴٴ� �ǵ� �� ? ������ ? ���� ??
				//������ ,,, ������ �ϳ� �� ����Ƿ� �޸� ����

void foo(const Data& a) // ruffhs : call by value���� const &�� ����.
{
}

int main()
{
	Data d;
	d.x = 10;
	foo(d); // ��� :: foo �Լ������� d�� ������ �������� ���ƾ� �Ѵ�.

}

//�Լ� ���� �����
// 1. ���� ������ ������ �� : ������ �Ǵ� ���� ��� ����.
// 2. ���� ������ �������� ���� �� : call by value ���ٴ� const &
// ���� �� ���� �ڵ�� ?
void foo(int a) {} //1
void foo(const int& a) {} //2
// --> int�� ��� overhead�� �۾Ƽ�, call by value�� ���� �̿��ϰ� struct���� const Ÿ�� �̿�
//1 ���� ��� ������ ���� �� ����ȭ�� �����ϴ�. --> ��Ȯ�� � �������� �� ����.

