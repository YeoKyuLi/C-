//stack8.cpp

#include <iostream>

using namespace std;
//8단계, 선언파일과 구현파일로 분리.
//사용자 입장에서는 클래스의 선언 파일만 있으면 사용가능.
#include "Stack.h"

int main()
{
	Stack s1(100);

	s1.push(20);
	s1.push(160);

	cout << s1.pop() << endl;
}

//클래스 하나당 "헤더, 소스"로 제공되는 경우가 많다.