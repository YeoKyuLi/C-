// 10_ĳ����3

#include <iostream>
using namespace std;

int main()
{
	//int* p1 = (int *)malloc(sizeof(10)); // C style


	//	static_cast : void* ==> �ٸ� Ÿ�� ���
	//					�̿ܿ��� �������� �ִ� Ÿ�Ը� ���...
	int* p1 = static_cast<int*>( malloc(sizeof(10)) ); // C++ style


	int n = 3;
	//double* p2 = static_cast<double*>(&n);	// complie time error
	double* p2 = reinterpret_cast<double*>(&n);	// ok..
												// ���� �ٸ� Ÿ���� ������ ĳ�����Ҷ� ���.

	const int c = 10;
	//int* p3 = static_cast<int*>(&c);	// error
	//int* p3 = reinterpret_cast<int*>(&c);	// error
											// ������� ������ �� ����..
	int* p3 = const_cast<int*>(&c);	// ok.. ���� Ÿ�԰�ü�� ����� ����.


	const double d2 = 3.4;

	int* p4 = reinterpret_cast<int*>( const_cast<double*>( &d2 ) );//C++ ĳ�������� �������� �ʰ� �غ�����.


}