https://github.com/codenuri/CPPINTERMEDIATE/tree/master/302_RVALUE_REFERENCE
=============lvalue와 rvalue=============
lvalue
    등호(=)의 왼쪽과 오른쪽에 모두 놓일 수 있다.
    이름(id)를 가진다.
    안일 문장을 벗어나서 사용될 수 있다.
    주소 연산자로 주소를 구할 수 있다.
    참조를 리턴하는 함수


rvalue
    등호(=)의 오른쪽에만 놓일 수 있다.
    이름(id)이 없다.
    단일 문장에서만 사용된다.
    주소 연산자로 주소를 구할 수 없다.
    값을 리턴하는 함수, 임시객체, 정수/실수형 리터럴(literal)
    rvalue가 모두 상수인 것은 아니다.
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int x = 10;
int  f1() { return x; }
int& f2() { return x; }

int main()
{
	int v1 = 10, v2 = 10;
	v1 = 20; // v1 : lvalue  20 : rvalue
	20 = v1; // error
	v2 = v1; //

	int* p1 = &v1; // ok
	int* p2 = &10; // error.

	f1() = 10; // error 값을 리턴을 하면 실제 그 값이 오는것이 아니라 복사된 임시 객체가 넘어옴으로, 임시객체는 왼쪽에 올 수 없다.
	f2() = 20; // ok.

	const int c = 10;
	c = 20; // c는 rvalue ? lvalue ?
			// c 는 수정 불가능한 lvalue

	// rvalue가 모두 상수인 것은 아니다.
	//Point().x = 10; // error
	//Point().set(10, 20); // ok

}

=============연산자와 lvalue=============
/*
*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/


int operator++(int& a, int)
{
	int temp = a;
	a = a + 1;
	return temp;
}
// 전위형 증가 연산자 - 참조리턴
int& operator++(int& a)
{
	a = a + 1;
	return a;
}

int main()
{
	int n = 0;
	n = 10;

	n++ = 20; // operator++(n, int) error.
	++n = 20; // operator++(n).   ok

	//++(++n);

	int a = 10, int b = 0;

	a + b = 20; // error.

	int x[3] = { 1,2,3 };
	x[0] = 5; // x.operator[](0) = 5;  lvalue
}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int main()
{
	int n = 0;
	int* p = &n;

	decltype(n) n1; // int

	decltype(p) d1; // int*

	decltype(*p) d2; // int ? int&  // *p = 20 lvalue
					 // int&.   error 참조인데 초기값이 없어서
                     // 표현식이 lvalue가 될 수 있으면 참조
                     // lvalue가 될 수 없으면 값

	int x[3] = { 1,2,3 };

	decltype(x[0]) d3; // int&. error  참조인데 초기값이 없어서
	auto a1 = x[0];    // int 오른쪽의 참조는 제거된다.

	decltype(++n) d4; // int&
	decltype(n++) d5; // int
}

=============rvalue reference=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int main()
{
	int n = 10;

	// 규칙 1. not const lvalue reference 는 lvalue 만 참조 가능
	int& r1 = n;	// ok
	int& r2 = 10;	// error 일반 참조로는 rvalue를 가르킬 수 없지만, 
    // 10은 값을 바꿀 수 없는 건데, int&로 하면 값을 바꾸겠다는 의미 아닌가..?

	// 규칙 2. const lvalue reference 는 lvalue 와 rvalue를 모두 참조 가능
	const int& r3 = n;	// ok
	const int& r4 = 10;	// ok  const 참조로는 rvalue를 가르킨다.

	//const Point& r = Point(1, 1);
	//r.x = 10;

	// 규칙 3. rvalue reference 는 rvalue 만 가리킬수 있다. C++11 문법.
	int&& r1 = n;	// error
	int&& r2 = 10;	// ok.
}


reference and function overroad



/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void foo(int& a)       { cout << "int&" << endl; }			// 1
void foo(const int& a) { cout << "const int&" << endl; }	// 2
void foo(int&& a)      { cout << "int&&" << endl; }			// 3

int main()
{
	int n = 10;

	foo(n);	// 1번, 1번이 없으면 2번
	foo(10);// 3번, 3번이 없으면 2번

	int& r1 = n;
	foo(r1);	// 1번, 없으면 2번

	int&& r2 = 10;	// 10은 rvalue, 10을 가리키는 이름있는 
					//				r2 참조변수는 lvalue 이다.
	foo(r2);		// 1번. 

	foo(static_cast<int&&>(r2));  // 3번.
}
