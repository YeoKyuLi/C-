// 10_캐스팅3

#include <iostream>
using namespace std;

int main()
{
	//int* p1 = (int *)malloc(sizeof(10)); // C style


	//	static_cast : void* ==> 다른 타입 허용
	//					이외에는 연관성이 있는 타입만 허용...
	int* p1 = static_cast<int*>( malloc(sizeof(10)) ); // C++ style


	int n = 3;
	//double* p2 = static_cast<double*>(&n);	// complie time error
	double* p2 = reinterpret_cast<double*>(&n);	// ok..
												// 서로 다른 타입의 포인터 캐스팅할때 사용.

	const int c = 10;
	//int* p3 = static_cast<int*>(&c);	// error
	//int* p3 = reinterpret_cast<int*>(&c);	// error
											// 상수성을 제거할 수 없다..
	int* p3 = const_cast<int*>(&c);	// ok.. 동일 타입객체의 상수성 제거.


	const double d2 = 3.4;

	int* p4 = reinterpret_cast<int*>( const_cast<double*>( &d2 ) );//C++ 캐스팅으로 에러나지 않게 해보세요.


}