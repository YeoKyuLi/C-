// 10_ĳ����

#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int n = 5;

	double* p = &n;	// error, ���� �ٸ� Ÿ���� �ּҸ� ���� �� ����.

	double* p = (double*)&n;	// ����� ĳ���� ���...ok

	*p = 3.4; // �Ҵ����� ���� �޸�, �Ǵ� �ٸ� ������ �޸𸮸� ħ���ϰ� �ȴ�.




}