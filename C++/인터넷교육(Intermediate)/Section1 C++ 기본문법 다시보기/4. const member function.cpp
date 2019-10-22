https://github.com/codenuri/CPPINTERMEDIATE/tree/master/103_CONST_MEMBER_FUNCTION
=============상수 멤버 함수의 필요성=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const1.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}

	void set(int a, int b) 
	{
		x = a; 
		y = b; 
	}
	void print()  //const	// 상수 멤버 함수
	{
	//	x = 10;	// error. 모든 멤버를 상수 취급한다.

		cout << x << ", " << y << endl;
	}
};

int main()
{
	const Point p(1, 1);

	p.x = 10;		// error
	p.set(10, 20);	// error
	p.print();		// ok. error.

}

분리
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : Point.h
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// Point.h
class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0);
	void set(int a, int b);
	void print() const;
};

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const2.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
	const Point p(1, 1);

	p.x = 10;		// error
	p.set(10, 20);	// error
	p.print();		// error.
					// 호출되게 하려면 print()를
					// 반드시 상수멤버함수가 되어야한다.
}

// 상수객체는 상수 멤버함수만 호출할수 있다.



/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// 객체의 상태를 변경하지 않은 모든 멤버함수는(getxxx)
// 반드시 const 멤버 함수가 되어야 한다.
struct Rect
{
	int ox, oy, width, height;

	Rect(int x = 0, int y = 0, int w = 0, int h = 0) 
		: ox(x), oy(y), width(w), height(h) {}

	int getArea() const {	return width * height; }
};

void foo(  const Rect& r) // call by value 보다는 const & 가 좋다.
{
	int n = r.getArea(); // error.
}

int main()
{
	Rect r(0, 0, 10, 10);

	int n = r.getArea(); // ok.

	foo(r);
}


=============논리적 상수성=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	const char* toString() const
	{
		static char s[16];
		sprintf(s, "%d, %d", x, y);
		return s;
	}
};

int main()
{
	const Point p1(1, 1);

	cout << p1.toString() << endl;
}

해결방안 1. mutable
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const5.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;

	// mutable  멤버 변수 : 상수멤버함수 안에서도 값을 변경가능.
	mutable char cache[16];
	mutable bool cache_valid = false;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	const char* toString() const
	{
		if (cache_valid == false)
		{
			sprintf(cache, "%d, %d", x, y);
			cache_valid = true;
		}
		return cache;
	}
};

int main()
{
	Point p1(1, 1);

	cout << p1.toString() << endl;
	cout << p1.toString() << endl;

}

해결방안2. cache 분리
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const6.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct Cache
{
	char cache[16];
	bool cache_valid = false;
};

class Point
{
	int x, y;
	Cache* pCache;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) 
	{
		pCache = new Cache;
	}

	const char* toString() const
	{
		if (pCache->cache_valid == false)
		{
			sprintf(pCache->cache, "%d, %d", x, y);
			pCache->cache_valid = true;
		}
		return pCache->cache;
	}
	~Point() { delete pCache; }
};

int main()
{
	Point p1(1, 1);

	cout << p1.toString() << endl;
	cout << p1.toString() << endl;

}


=============상수 멤버 함수 참고 사항=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const7.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

struct Test
{
	void foo()		 { cout << "foo()" << endl; }		  // 1
	void foo() const { cout << "foo() const" << endl;	} // 2

	void goo() const;
};

void Test::goo() const
{

}


int main()
{
	Test t1;
	t1.foo(); // 1번 없으면 2번

	const Test t2;
	t2.foo(); // 2번 없으면 error
}