//9_동적메모리 할당
#include <iostream>
using namespace std;

int main()
{
	int n = 10;
	//cin >> n;
	//입력받은 크기 만큼 메모리를 할당하고 싶다.
	//C89 : 배열의 크기는 상수만 가능
	//C99 : 배열의 크기는 변수도 가능. gcc 가능, vc는 지원안함.
	//C11도 있다.
	//int jumsu[n];

	//c 스타일의 동적 메모리 할당
	//C : void* ==> 다른 타임* 암시적 변환 허용
	//C++ 암시적 변환 안됨.
	int* jumsu = (int*)malloc(sizeof(int)*n);
	free(jumsu);

	//C++
	int* p = new int;
	delete p;

	int* p2 = new int[n]; //여러개 할당
	delete[] p2; // 주의!!! 반드시 배열 버전 delete 사용
	delete p2; //미정의 동작(Undefined) 발생 이라고 표현.
}