// 10_캐스팅2

#include <iostream>
using namespace std;

int main()
{

	//const int c = 10;	// 컴파일 시간 상수. ,, 매크로 처럼 변환...

	int n = 10;
	const int c = n;	// 컴파일 할 때 초기값을 모르고, 실행시간동안 바꿀수가 없다.
						// 실행시간 상수,

	//int* p = &c;	// complie time error, 상수메모리는 비상수를 가리키는 포인터에 담을 수 없다.

	int* p = (int*)&c;	// ok... wow

	*p = 20;

	cout << c << endl;		// 10
	cout << *p << endl;		// 20

}