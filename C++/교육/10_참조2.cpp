
#include <iostream>
using namespace std;
void inc1(int n) { ++n; }
void inc2(int* p) { ++(*p); }
void inc3(int& r) { ++r; }
//inc2 / inc3�� �������� �򰥸�. �޸��� �ּҸ� �����ϴ���
// �޸��� �ּҸ� ����Ű�� ������ ������ ����.

int main()
{
	int a = 10;
	//inc1(a); // ���� ���� - call by value ���� ����
	//inc2(&a); // ���� �� - call by pointer(call by reference )���� ������ �ִ� �ּ� ����.
			 //C++������ call by pointer

	inc3(a); //int& r = ������ 
			//int& r = n; //���� Ÿ�� ���� - ���� �޸𸮿� ���� �߰����� �̸� �ο�
			// call by reference

	cout << a << endl;//11�� ������ �ϰ� �ʹ�.

	int n2 = 0;
	scanf("%d", &n2 );	//&n : pointer base
	cin >> n2 ;			//n : reference base


}