//9_�����޸� �Ҵ�
#include <iostream>
using namespace std;

int main()
{
	int n = 10;
	//cin >> n;
	//�Է¹��� ũ�� ��ŭ �޸𸮸� �Ҵ��ϰ� �ʹ�.
	//C89 : �迭�� ũ��� ����� ����
	//C99 : �迭�� ũ��� ������ ����. gcc ����, vc�� ��������.
	//C11�� �ִ�.
	//int jumsu[n];

	//c ��Ÿ���� ���� �޸� �Ҵ�
	//C : void* ==> �ٸ� Ÿ��* �Ͻ��� ��ȯ ���
	//C++ �Ͻ��� ��ȯ �ȵ�.
	int* jumsu = (int*)malloc(sizeof(int)*n);
	free(jumsu);

	//C++
	int* p = new int;
	delete p;

	int* p2 = new int[n]; //������ �Ҵ�
	delete[] p2; // ����!!! �ݵ�� �迭 ���� delete ���
	delete p2; //������ ����(Undefined) �߻� �̶�� ǥ��.
}