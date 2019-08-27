https://github.com/codenuri/CPPINTERMEDIATE/tree/master/304_PERFECT_FORWARDING
=============perfect forwarding 개념=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void goo(int& a) { cout << "goo" << endl; a = 30; }
void foo(int  a) { cout << "foo" << endl; }

// 완벽한 전달 : 래퍼함수가 인자를 받아서 원본 함수에게 완벽하게
//				전달하는 개념
// perfect forwarding.
template<typename F, typename A> 
void chronometry(F f, const A& arg)
{
	f(arg);
}

int main()
{
	int n = 0;
	//goo(n);
	//foo(5);
	chronometry(&goo, n); // goo(n)
	chronometry(&foo, 5); // foo(5) 실행시 수행시간.

	cout << n << endl; // 30

}

=============sperfect forwarding 구현=============

핵심 1. 함수 인자를 받을 때 reference를 사용해야 한다.
핵심 2. lvalue, ravlue reference 버전 모두 제공해야한다.
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void goo(int& a) { cout << "goo" << endl; a = 30; }
void foo(int  a) { cout << "foo" << endl; }

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	int n = 0;

	chronometry(&goo, n);
	chronometry(&foo, 5);

	cout << n << endl; 

}

핵심 3. rvalue reference 버전의 함수에서는 인자를 원본 함수에 전달할 때 rvalue로 캐스팅해서 전달한다.
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void goo(int& a) { cout << "goo" << endl; a = 30; }
void foo(int  a) { cout << "foo" << endl; }
void hoo(int&& a) { cout << "hoo" << endl; }

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	// int&& arg = 10
	//f(arg);
	// 해결책 : lvalue인 arg를 rvalue로 다시 캐스팅한다
	f(static_cast<int&&>(arg));
}

int main()
{
	//hoo(10); // ok..
	chronometry(&hoo, 10); // error
	
	int&& arg = 10; // 10 은 rvalue,
					// arg는 lvalue 이다.

	
	int n = 0;

	chronometry(&goo, n);
	chronometry(&foo, 5);

	cout << n << endl;

}

=============forwarding reference=============
함수 인자로 T&&를 사용하는 경우 (forwarding reference)

1. lvalue와 rvalue를 모두 전달 받을 수 있다.
2. 인자로 lvalue 전달시 -> T : int&, T&&:int & && -> int&
3. 인자로 rvalue 전달시 -> T : int, T&& : int&&

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void goo(int& a) { cout << "goo" << endl; a = 30; }
void foo(int  a) { cout << "foo" << endl; }
void hoo(int&& a) { cout << "hoo" << endl; }


/*
template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/
// int&  : 정수형 lvalue
// int&& : 정수형 rvalue
// T&    : 모든 타입 lvalue
// T&    : 모든 타입 lvalue와 rvalue를 받을수 있다.
// forwarding reference
template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 0;

	chronometry(&goo, n);
	chronometry(&hoo, 10);

	chronometry(&foo, 5);
	cout << n << endl;
}

완벽한 전달을 사용하는 함수를 만든 방법
1. 함수 인자로 forwarding reference를 사용한다.
2. 함수 인자를 원본 함수에 보낼 때 std::forward<T>(arg)로 묶어서 전달한다.

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void foo(int  a)  { cout << "foo" << endl; }
void goo(int& a)  { cout << "goo" << endl; a = 30; }
void hoo(int&& a) { cout << "hoo" << endl; }

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	//f(static_cast<T&&>(arg));

	f(std::forward<T>(arg)); // forward()가 결국
							// 내부적으로 위의 캐스팅
							// 수행.
}

int main()
{
	int n = 0;

	chronometry(&foo, 5);
	chronometry(&goo, n);
	chronometry(&hoo, 10);

	cout << n << endl;
}


=============chronometry=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

int x = 10;
int& foo(int  a) { return x; }

// error
/*
template<typename F, typename T>
decltype( f(std::forward<T>(arg)) ) chronometry(F f, T&& arg)
{
	return f( std::forward<T>(arg) ); 
}
*/
// ok.
/*
template<typename F, typename T>
auto chronometry(F f, T&& arg) -> decltype(f(std::forward<T>(arg)))
{
	return f(std::forward<T>(arg));
}
*/
/*
// 컴파일 ok.. 원본 함수가 참조를 리턴하면 버그..
template<typename F, typename T>
auto chronometry(F f, T&& arg) 
{
	return f(std::forward<T>(arg));
}
*/

// 컴파일 ok.. 원본 함수가 참조를 리턴해도 ok..
template<typename F, typename T>
decltype(auto) chronometry(F f, T&& arg)
{
	return f(std::forward<T>(arg));
}

int main()
{
	int& ret = chronometry(&foo, 10);
	ret = 20;
	cout << x << endl;
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate..7
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void foo(int a, int& b, double d) { b = 30; }
void goo() {}

template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{
	return f(std::forward<Types>(args)... );
}


int main()
{
	int x = 10;

	chronometry(&foo, 1, x, 3.4); // ...을 넣어서 여러 인자를 받을수 있음.
	chronometry(&goo);

	cout << x << endl; // 30
}

