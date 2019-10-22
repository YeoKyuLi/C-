https://github.com/codenuri/CPPINTERMEDIATE/tree/master/303_MOVE
=============std::move 만들기=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include "Test.h"		
using namespace std;

// T&  : lvalue 만 받을수 있다.
// T&& : lvalue 와 rvalue를 모두 받을수 있다. (forwarding reference)
// 인자로 lvalue 전달 : T => Test&  T&& : Test& && => Test&
//        rvalue 전달 : T => Test   T&& : Test &&  => Test&&
template<typename T> 
typename remove_reference<T>::type &&
xmove(T&& obj)
{
	// 목표 : rvalue로 캐스팅.
	//return static_cast<T&&>(obj);

	return static_cast<typename remove_reference<T>::type &&>(obj);
}

int main()
{
	Test t1;
	Test t2 = t1;		 // copy
	Test t3 = xmove(t1); // move
	Test t4 = xmove( Test() ); // move
}

=============move와 const object=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include "Test.h"
using namespace std;

// lvalue 전달하면  T : lvalue 참조.. => const Test&
template<typename T>
typename remove_reference<T>::type &&
xmove(T&& obj)  
{
	// const Test&&    => Test(Test&&)       : error
	//                 => Test(const Test& ) : 

	return static_cast<const Test&&>(obj);
	return static_cast<typename remove_reference<T>::type &&>(obj);
}


int main()
{
	const Test t1;
	Test t2 = xmove(t1); // move ? copy ? error
						// const Test

	//Test t2 = static_cast<Test&&>(t1); // error, 상수를 비상수로 캐스팅 할 수 없다.
}

=============move 생성자 만들기=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <string>
#include "Test.h"
using namespace std;

class Buffer
{
	size_t sz;
	int*   buf;
	string tag;
	Test   test;
public:
	Buffer(size_t s, string t) 
		: sz(s), tag(t), buf(new int[s] ) {}

	~Buffer() { delete[] buf; }

	// 깊은 복사
	Buffer(const Buffer& b) : sz(b.sz), tag(b.tag), test(b.test)
	{
		buf = new int[sz];
		memcpy(buf, b.buf, sizeof(int)*sz);
	}

	// move 생성자 : 모든 멤버를 move 로 옮기도록 작성한다.
	Buffer(Buffer&& b) noexcept
		: sz(move(b.sz)), tag(move(b.tag)), test(move(b.test))
	{
		buf = move(b.buf); // 객체 타입은 move로 옮기고 int 등은 move를 안써도 됨
		b.buf = 0; // 자원 포기.
	}
	
	// 대입연산자.
	// move 대입연산자.
};

int main()
{
	Buffer b1(1024, "SHARED");
	//Buffer b2 = b1; // copy

	Buffer b2 = move(b1); // copy
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <string>
#include "Test.h"
using namespace std;

class Buffer
{
	size_t sz;
//	int*   buf;
	string tag;
	Test   test;
public:
	Buffer(size_t s, string t)
		: sz(s), tag(t) {}
	

    // 복사와 move하는 것을 안만들어주면 compailer가 생성해줌.
    // 복사만 만들어주면, 컴파일러는 복사를 쓰도록 한다. 굳이 move를 만들어주지 않음


	// 사용자가 만들지 않으면 컴파일러가 아래 모양제공.
	// 얕은복사..
	Buffer(const Buffer& b) : sz(b.sz), tag(b.tag), test(b.test)
	{
	}
	
	/*
	// move 생성자 : 모든 멤버를 move 로 옮기도록 작성한다.
	Buffer(Buffer&& b) noexcept
		: sz(move(b.sz)), tag(move(b.tag)), test(move(b.test))
	{
	}
	*/
	// 대입연산자.
	// move 대입연산자.
};

int main()
{
	Buffer b1(1024, "SHARED");
	Buffer b2 = b1; // copy
	Buffer b3 = move(b1); // move
}

=============value categories=============
1. 지역변수는 참조로 리턴할 수 없다.
2. 함수 리턴 타입의 종륭 ㅔ따라서 리턴하는 방법
    value type, lvalue reference, rvalue reference


#include <iostream>
using namespace std;

void f1(int a){}
void f2(int& a){}
void f3(int&& a){}

int main()
{
    int n = 10;
    f1(n);
    f2(n);
    f3(static_cast<int&&>(n));//f3(move(n))
}

// 리턴 타입에 따른 리턴 방법

#include <iostream>
using namespace std;
int x = 0;
int     f4() { return x; }
int&    f5() { return x; }
int&&   f6() { return move(x); } // 지역변수일때 사용 못함.

int main()
{
    f1() = 10;  // error
    f2() = 20;  // ok
    f3() = 30;  // error
}


#include <iostream>
using namespace std;
struct Base
{
    virtual void foo() {cout << "B::foo" << endl};
}
struct Derived : public Base
{
    virtual void foo() {cout << "D::foo" << endl};
}
Derived d;
Base    f1() { return d; }
Base&   f2() { return d; }
Base&&  f3() { return move(d)}

int main()
{
    Base b1 = f1(); // 임새객체, move       rvalue
    Base b2 = f2(); // copy                lvalue
    Base b3 = f3(); // move                rvalue

    f1().foo(); // B::foo   non-다형적
    f2().foo(); // D::foo   다형적
    f3().foo(); // D::foo   다형적

    int n = 10;
    n = 20; // n : lvalue , 20: prvalue
    int n3 = move(n); // xvalue
}