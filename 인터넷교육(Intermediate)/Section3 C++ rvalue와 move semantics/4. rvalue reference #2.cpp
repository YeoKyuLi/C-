https://github.com/codenuri/CPPINTERMEDIATE/tree/master/302_RVALUE_REFERENCE
=============reference collapse=============

*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

using LREF = int&;	// typedef int&  LREF;
using RREF = int&&; // typedef int&& RREF;

template<typename T> void foo(T& a) {}

int main()
{
	int n = 10;

	foo<int&>(n ); // foo( int& & a) => foo(int& a)

	LREF r1 = n;
	RREF r2 = 10;

	LREF&  r3 = n; // int& & r3 = ?
	RREF&  r4 = n; // int&& & => int&
	LREF&& r5 = n; // int& && => int&
	RREF&& r6 = 10; // int&& && => int&&

	int& && r7; //컴파일 에러.. typedef or template을 쓰는 경우 reference collapse 발생

}

=============forwarding reference=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/


void f1(int&  a) {} // lvalue 만 인자로 전달 가능. f1(n) : ok.     f1(10) : error
void f2(int&& a) {} // rvalue 만 인자로 전달 가능. f2(n) : error.  f2(10) : ok

// 모든 타입의 lvalue 만 전달 가능.
template<typename T> void f3(T& a) {} // T : int&   T& : int& &


int main()
{
	int n = 10;

	// T의 타입을 사용자가 지정할 경우
	f3<int>(n );	// f3( int & a)  => lvalue 전달 가능.
	f3<int&>(n );	// f3( int& & a) => f3( int& a) => lvalue 전달 가능.
	f3<int&&>(n );	// f3( int&& & a)=> f3( int& a) => lvalue 전달 가능.

	// 사용자가 T 타입을 지정하지 않은 경우
	f3(10); // error
	f3(n);  // T : int.  ok.
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/


// T&& : lvalue 와 rvalue를 모두 전달 가능. (forwarding reference)
//	    lvalue 전달하면 T는 lvalue reference 로 결정
//      rvalue 전달하면 T는 값 타입으로 결정..

template<typename T> void f4(T&& a) {}

int main()
{
	int n = 10;

	// 사용자가 T의 타입을 명시적으로 전달할때
	f4<int>(10 );	// f4(int&& a)   => rvalue 를 전달
	f4<int&>(n );	// f4(int& && a) => f4(int& a) => lvalue 를 전달
	f4<int&&>(10 ); // f4(int&& && a)=> f4(int&& a) => rvalue 전달 

	// T의 타입을 명시적으로 전달하지 않을때
	f4(n);	// ok. 컴파일러가 T를 int& 로 결정.
	f4(10);	// ok. 컴파일러가 T를 int  로 결정. f4(T&& ) => f4(int && ) 
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/


void f1(int&  a) {} 
void f2(int&& a) {} 
template<typename T> void f3(T&  a) {} 
template<typename T> void f4(T&& a) {}

// int&  : int 형의 lvalue 전달 가능.
// int&& : int 형의 rvalue 전달 가능.
// T&    : 모든 타입의 lvalue 전달 가능.(함수 생성)

// T&&   : 모든 타입의 lvalue 와 rvalue 모두 전달 가능.(함수 생성)
//		   "universal reference"  => "forwarding reference"
//			lvalue 를 전달하면 foo(n)  => T : int&    T&& : int& && => int&
//          rvalue 를 전달하면 foo(10) => T : int     T&& : int&&    


forwarding reference
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/


template<typename T> void foo(T&& a) {} // forwarding reference

template<typename T> class Test
{
public:
	void goo(T&& a) {} // forwarding reference 아님..

	template<typename U> void hoo(U&& a) {} // forwarding reference 맞음.
};

int main()
{
	int n = 10;
	
	foo(n);	// ok
	foo(10);// ok

	Test<int> t1; // T가 int로 결정.  void goo(int&& a)
	t1.goo(n);	// error
	t1.goo(10); // ok

	Test<int&> t2; // T int& => void goo( int& && a) => void goo(int& )
	t2.goo(n); // ok
	t2.goo(10); // error

