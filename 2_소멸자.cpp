//2_�Ҹ���

#include <iostream>

using namespace std;

class People
{
	//char name[5]; // �迭 : �̸��� ������ ������ ������ �ȴ�.
	char* name;
	int age;
public :
	People(const char* n, int a) :  age(a)
	{
		// �̸��� ���ڿ� ���� ��ŭ�� �޸� �Ҵ��Ѵ�.
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	// �Ҹ��� �ʿ伺 : ���� �޸��Ҵ� �� ���� �ڿ��� �����ϴ� ���
	//					�����ϱ� ���ؼ� �ʿ��ϴ�.
	//					�ڿ������� �ʿ���ٸ� ������ �ʾƵ� �ȴ�.
	//					���α׷��� ���ų� ������ ������ �޸𸮴� free ������,
	//					������ �ʴ� ���α׷��� �����ϴ� ��� delete ����� ��.
	~People()
	{
		delete[] name;
	}
};

int main()
{
	People p("Kim", 20);


}