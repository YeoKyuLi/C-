

#include <iostream>
#include <algorithm> //swap() 함수 템블릿이 존재한다.

using namespace std;

void Swap(int* a, int* b) //C
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*
void Swap1(int& a, int& b) //C++ 
{
	int temp = a;
	a = b;
	b = temp;
}*/

namespace Util
{
	template<typename T> inline void Swap1(T& a, T& b) //C++ 
	{
		T temp = a;
		a = b;
		b = temp;
	}
}
int main()
{
	int a = 10, b = 20;

	//아래 함수를 만들어 보세요. 리턴타입은 void로/
	//Swap(&a, &b);
	//Util::Swap1(a, b);

	std::swap(a, b); 

	cout << b << endl; // 10
	cout << a << endl; // 20
}