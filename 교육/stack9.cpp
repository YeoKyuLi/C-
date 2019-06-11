//stack9.cpp

#include <iostream>

using namespace std;
//9단계, 다양한 타입을 저장 할 수 있게 - template 도입
//		다양한 타입의 stack 클래스를 자동 생성
//		template은 일반적으로 선언과 구현으로 분리하지 않습니다.
//		이유는 마지막날...

template<typename T>
class Stack	
{
	T* buff;
	int idx;

public:
	//멤버 함수.
	Stack(int sz = 10)
	{
		idx = 0;
		buff = new T[sz];
	}

	~Stack() { delete[] buff; }


	void push(const T& a) { buff[(idx)++] = a; }
	T pop() { return buff[--(idx)]; }
};


int main()
{
	Stack<int> s1(100);
	Stack<double> s2(10);

	s1.push(20);
	s1.push(160);

	cout << s1.pop() << endl;

}