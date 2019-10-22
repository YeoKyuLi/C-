//stack4.cpp

#include <iostream>

using namespace std;
//4단계, 외부의 잘못된 사용으로 부터 객체가 불안해 지는 것을 막는다.
//		접근 지정자의 도입.
//		"정보 은닉(information hiding)"


struct Stack // 접근 지정자 생략시 디폴트가 public
//class Stack	//접근 지정자 생략시 디폴트가 private
{
	//private이 정의되어 있지 않으면 public이다. -- struct에서.
private :	//멤버 함수만 접근 가능, 외부에서는 접근 불가.
	//멤버 데이터
	int buff[10];
	int idx;

public:
	//멤버 함수.
	void init() { idx = 0; }
	void push(int a) { buff[(idx)++] = a; }
	int pop() { return buff[--(idx)]; }
}; 


int main()
{
	Stack s1;
	s1.init(); 

	//s1.idx = -10; //사용자가 잘 못 사용했다..



	s1.push(20);
	s1.push(160);

	cout << s1.pop() << endl; 

}