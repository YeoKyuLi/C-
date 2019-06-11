//stack6.cpp

#include <iostream>

using namespace std;
//6단계, 자료구조의 변경 - 동적메모리 할당을 사용한 버퍼. 
//			사용자가 버퍼 크기 지정
//			소멸자를 도입해서 객체가 사용한 자원 해지.

class Stack	//접근 지정자 생략시 디폴트가 private
{
	int* buff;
	int idx;

public:
	//멤버 함수.
	Stack(int sz = 10) 
	{
		idx = 0;
		buff = new int[sz];
	}
	
	
	//소멸자 : 객체가 파괴될때 호출된다.
	//		인자를 가질 수 없다. 클래스 이름 앞에 ~을 붙인디ㅏ.
	~Stack() { delete[] buff; }


	void push(int a) { buff[(idx)++] = a; }
	int pop() { return buff[--(idx)]; }
};


int main()
{
	Stack s1(100);


	s1.push(20);
	s1.push(160);

	cout << s1.pop() << endl;

}