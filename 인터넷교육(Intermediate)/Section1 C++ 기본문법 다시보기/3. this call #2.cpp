https://github.com/codenuri/CPPINTERMEDIATE/tree/master/102_THISCALL
=============this is ingeritance=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this10.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class A { int a; };
class B { int b; };

class C : public A, public B
{
	int c;
};

int main()
{
	C obj;

	A* pA = &obj;
	B* pB = &obj; // &obj + sizeof(A)

	cout << &obj << endl; // 1000 
	cout << pA   << endl; // 1000
	cout << pB   << endl; // 1004
}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this11.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class A
{
	int a;
public:
	void fa() { cout << this << endl; }
};

class B
{
	int b;
public:
	void fb() { cout << this << endl; }
};

class C : public A, public B
{
	int c;
};

int main()
{
	C obj;
	cout << &obj << endl; // 1000

	obj.fa(); // fa(&obj)   cout << this => 1000
	obj.fb(); // fb(&obj + sizeof(A)) cout << this => 1004
}




/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this12.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class A
{
	int a;
public:
	void fa() { cout << this << endl; }
};
class B
{
	int b;
public:
	void fb() { cout << this << endl; }
};

class C : public A, public B
{
	int c;
};

int main()
{
	C obj;
	cout << &obj << endl; // 1000

	obj.fa();  // 1000
	obj.fb();  // 1004

	void (C::*f)(); // 멤버 함수 포인터

	cout << sizeof(f) << endl; // 32bit 환경에서 8

	f = &C::fa; // f = { fa 주소, 0  };
	f = &C::fb; // f = { fb 주소, sizeof(A)};

	(obj.*f)(); // f.함수주소( &obj + f.this offset )
	/*
	if ( 사용자입력 == 1 )
		f = &C::fa;
	else 
		f = &C::fb;
	(obj.*f)(); // f( &obj  )
	*/
}


=============멤버 변수 포인터=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this13.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
};

int main()
{
	int   n = 10;
	int* p1 = &n;

	//void(Point::*f)() = &Point::print; // 멤버 함수 포인터
	
	int Point::*p2 = &Point::x; // 멤버 변수 포인터
							    // 0 (메모리상 처음이니깐 0)
	int Point::*p3 = &Point::y; // 4 (포인터 안에서 떨어진 위치 )
								// C의 offset_of

	//cout << p3 << endl;
	printf("%d, %d\n", p2, p3);

	Point pt;

	pt.y = 10;
	pt.*p3 = 20;

	cout << pt.y << endl; // 20
}