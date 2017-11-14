//stack10.cpp

#include <iostream>

using namespace std;
//10단계, C++ 표준 스택 사용
#include <stack>

int main()
{
	stack<int> s1; // 동적 메모리 할당이 아니라 list 등의 방법..
	stack<double> s2;

	s1.push(20);
	s1.push(160);

	//주의!! pop()은 제거만, top()은 리턴만.
	cout << s1.top() << endl;
	s1.pop();
	cout << s1.top() << endl;

}