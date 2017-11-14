//stack5.cpp

#include <iostream>

using namespace std;
//5단계, 객체의 초기화를 자동으로... 생성자의 도입.

//struct Stack // 접근 지정자 생략시 디폴트가 public
class Stack	//접근 지정자 생략시 디폴트가 private
{
private:	//멤버 함수만 접근 가능, 외부에서는 접근 불가.
			//멤버 데이터
	int buff[10];
	int idx;

public:
	//멤버 함수.
	//생성자 : 구조체(클래스) 이름과 동일하고 객체를 만들면 자동으로 호출된다.
	//			리턴값이 없고 리턴 타입을 표시하지 않는다.
	Stack() { idx = 0; }
	void push(int a) { buff[(idx)++] = a; }
	int pop() { return buff[--(idx)]; }
};


int main()
{
	Stack s1;
	s1.init();


	s1.push(20);
	s1.push(160);

	cout << s1.pop() << endl;

}