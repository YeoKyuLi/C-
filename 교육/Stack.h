//Stack.h

class Stack	//접근 지정자 생략시 디폴트가 private
{
	int* buff;
	int idx;

public:
	//클래서 선언에는 함수 선언만,, 함수 구현은 외부에
	Stack(int sz = 10);
	~Stack();
	void push(int a);
	int pop();
};