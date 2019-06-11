
#include <iostream>
using namespace std;
void inc1(int n) { ++n; }
void inc2(int* p) { ++(*p); }
void inc3(int& r) { ++r; }
//inc2 / inc3의 차이점이 헷갈림. 메모리의 주소를 접근하느냐
// 메모리의 주소를 가르키는 참조를 가지고 있음.

int main()
{
	int a = 10;
	//inc1(a); // 증가 안함 - call by value 값만 전달
	//inc2(&a); // 증가 함 - call by pointer(call by reference )값을 가지고 있는 주소 전달.
			 //C++에서는 call by pointer

	inc3(a); //int& r = 변수만 
			//int& r = n; //참조 타입 변수 - 기존 메모리에 대한 추가적인 이름 부여
			// call by reference

	cout << a << endl;//11이 나오게 하고 싶다.

	int n2 = 0;
	scanf("%d", &n2 );	//&n : pointer base
	cin >> n2 ;			//n : reference base


}