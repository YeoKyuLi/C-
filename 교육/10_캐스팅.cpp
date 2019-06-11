// 10_캐스팅

#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int n = 5;

	double* p = &n;	// error, 서로 다른 타입의 주소를 담을 수 없다.

	double* p = (double*)&n;	// 명시적 캐스팅 사용...ok

	*p = 3.4; // 할당하지 않은 메모리, 또는 다른 변수의 메모리를 침범하게 된다.




}