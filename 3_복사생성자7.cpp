// 3_���������7


#include <stack>
#include <iostream>
#include <complex>
#include <mutex>

using namespace std;

// ��ü�� ���� ���
// ���� ����, ���� ����, ���� ���, ���� ����, ������ ����(move)
// ���� ���� �׳� ��°�� �����ϴ°�
// ���� ���� �޸𸮸� ����?�� �ϴ°� pointer
int main()
{
	mutex m1;
	//mutex m2 = m1; // ���� ����
	m1.lock;


	stack<int> s1;
	s1.push(10);
	s1.push(20);

	stack<int> s2 = s1; // � ����ϱ��? --> ���� ���簡 ����.

	complex<int> c1(1, 1);
	complex<int> c2 = c1; // ���� ����.
}