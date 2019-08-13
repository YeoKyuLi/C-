https://github.com/codenuri/CPPINTERMEDIATE/tree/master/102_THISCALL
=============멤버함수의 호출원리=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this1.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// this1.cpp - 멤버함수의 호출원리
// 1. 멤버 함수는 1번째 인자로 객체의 주소(this) 가 추가된다.
// 2. static 멤버 함수는 인자로 객체의 주소(this) 가 추가되지 않는다.

class Point
{
	int x = 0, y = 0;
public:
	void set(int a, int b) // void set(Point* const this, int a, int b)
                            // this는 상수 포인터
	{
		x = a;	// this->x = a;
		y = b;	// this->y = b;
	}
	static void foo(int a) // void foo( int a)
	{
		x = a;				// this->x = a;   변경해야 하는데.. this 가 없다. error
	}
};
// cl this1.cpp /FAs  => this1.asm
// g++ this1.cpp -S   => this1.s
int main()
{
	Point::foo(10); // push 10
					// call Point::foo

	Point p1;
	Point p2;
    // 객체를 2개 만들면 메모리에 2개에 잡힘.

	// this call
	p1.set(10, 20);	// set(&p1, 10, 20)
					// push 20
					// push 10
					// lea  ecx, &p1    rcx, &p1 // 객체 주소는 레지스터로
					// call Point::set
}

=============멤버함수 포인터=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this2.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// this2.cpp - this 와 멤버 함수 포인터

// 핵심 1. 일반 함수 포인터에 멤버함수의 주소를 담을수 없다.
// 핵심 2. 일반 함수 포인터에 static 멤버함수의 주소를 담을수 있다.
// 핵심 3. 멤버 함수 포인터 모양과 사용법.  .*   (p->*f3)()

class Dialog
{
public:
	void Close() {} // 내부적으로 this 포함
    //static void Cloase(){} // 	void(*f2)() = &Dialog::Close; 가능
};

void foo() {}

int main()
{
	void(*f1)() = &foo;
    //return값이 void 파라미터가 없는 함수
	f1();

//	void(*f2)() = &Dialog::Close; // error. this 가 추가되는 함수.

	void(Dialog::*f3)() = &Dialog::Close; // ok.. 멤버 함수 포인터.

	//f3(); // error. 객체(this)가 없다.

	Dialog dlg;
	//dlg.f3(); // dlg.Close()의 의미.. 하지만..f3이라는 멤버를 찾게된다.- error

	//dlg.*f3(); // ".*" : pointer to member operator
				// error. 연산자 우선순위 문제..

	(dlg.*f3)(); // ok.. dlg.Close();
	
}


=============Thread class 만들기=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// this3.cpp - thiscall 활용 예제
#include <iostream>
#include <windows.h> // windows 용 함수들..
using namespace std;

DWORD __stdcall foo(void* p)
{
	return 0;
}

int main()
{
	CreateThread(0, 0, 
				foo,		// 스레드로 수행할 함수
				(void*)"A", // 스레드 함수로 보낼인자
				0, 0);
}

// 빌드 하는 법
// mingw : g++ this3.cpp

// VC    : cl this3.cpp /nologo /EHsc  

//		   주의! "VC++ 확장 문법 사용"을 사용해야 함.
//			/Za 옵션을 지정하면 컴파일 안됨.

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// this4.cpp - Thread 클래스 만들기
#include <iostream>
#include <windows.h>
using namespace std;


// 라이브러리 내부 클래스
class Thread
{
public:

	void run()
	{
		CreateThread(0, 0, threadMain,(void*)this, 0, 0);
	}

	// 1. 아래 함수는 반드시 static 함수 이어야 합니다.
	// 2. 아래 함수는 this가 없다. 그래서 함수 인자로
	//    this를 전달하는 기술.

	static DWORD __stdcall threadMain(void* p)
	{
		Thread* const self = static_cast<Thread*>(p);

		self->Main(); // Main( self )

		//Main(); // 가상함수 호출
				// this->Main() => Main( this) 로 변해야 한다.

		return 0;
	}

	virtual void Main() // void Main(Thread* const this)
	{}
};


=============This map 만들기=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this6.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <string>
#include "ecourse.hpp"	
using namespace std;
using namespace ecourse;

// 타이머 개념을 사용해서 Clock 클래스 만들기.
#include <map>

//class Clock;
//map<int, Clock*> this_map;

class Clock
{
	static map<int, Clock*> this_map;
	string name;
public:
	Clock(string n) : name(n) {}

	void start(int ms)
	{
		int id = ec_set_timer(ms, timerHandler );

		this_map[id] = this;
	}

	// 핵심 1. 아래 함수는 반드시 static 멤버 이어야 합니다.

	static void timerHandler(int id)
	{
		Clock* const self = this_map[id];

		//cout << name << endl;	// this->name
		cout << self->name << endl;
	}
};

map<int, Clock*> Clock::this_map;

int main()
{
	Clock c1("A");
	Clock c2("\tB");

	c1.start(1000); // 1000ms 에 한번씩 이름출력
	c2.start(500);  // 500ms 에 한번씩 이름출력

	ec_process_message();
}