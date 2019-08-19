https://github.com/codenuri/CPPINTERMEDIATE/tree/master/107_CONVERSION
=============return type resolver=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <cstdlib>
using namespace std;


template<typename T> T* memAlloc(int sz )
{
	return (T*)malloc(sz);
}

int main()
{
	//double* p = memAlloc<double>(40);

	double* p1 = memAlloc(40);
	int*    p2 = memAlloc(40);

}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

/*
template<typename T> T* memAlloc(int sz)
{
	return (T*)malloc(sz);
}
*/

class memAlloc
{
	int size;
public:
	inline memAlloc(int sz) : size(sz) {}

	template<typename T> operator T*()
	{
		return (T*)malloc(size);
	}
};

int main()
{
	double* p1 = memAlloc(40); // 클래스이름() : 임시객체..
							   // 임시객체.operator double*()
	int*    p2 = memAlloc(40);

}
=============safe bool=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

int main()
{
	int n = 0;

	cin >> n;  // 'a'

	if (cin.fail())
		cout << "실패" << endl;

	if ( cin )  // if ( bool, 정수, 포인터, 실수 )
				// cin.operator void*() => C++98/03
				// cin.operator bool()  => C++11

		cout << "성공" << endl;

}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

void true_function() {}

class istream   // basic_istream
{
public:
	bool fail() { return false; }

	// 방법 1. bool 로 변환 - 단점. shift  연산이 허용된다.
	//operator bool() { return fail() ? false : true; }

	// 방법 2. void* 로의 변환 - C++ 98/03
	// operator void*() { return fail() ? 0 : this; }

	// 방법 3. 함수 포인터로의 변환.
	//typedef void(*F)();
	//operator F() { return fail() ? 0 : &true_function; }

	// 방법 4. 멤버 함수 포인터로의 변환. - Safe BOOL
	//          if() 문에 넣을수 있는 side effect가 가장 적다..
	struct Dummy
	{
		void true_function() {}
	};
	typedef void(Dummy::*F)();
	operator F() { return fail() ? 0 : &Dummy::true_function; }

};
istream cin;

int main()
{
	int n = 0;
	if ( cin ) {}
//	cin << n;
//	delete cin;

//	void(*f)() = cin;
}

=============Explicit Conversion Operator=============
explicit conversion operator
	C++11부터는 변환 연산자에서도 explicit를 붙일 수 있다.
	명시적 변환은 허용되지만 암시적 변환은 될 수 없다.
	if문을 사용해서 객체를 조사 할 수 있다.
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// 아래 소스에 대한 설명은 https://youtu.be/ncV44oB2GSA  에서 보실수 있습니다.
class istream
{
public:
	bool fail() { return false; }

	// C++11 변환 연산자 앞에도 explicit를 붙일수 있다.
	// 암시적 변환은 error. 명시적 허용
	// if 문안에 객체를 넣을수도 있다.
	// C++11전까지는 void*로 변환되었었음.
	explicit operator bool() { return fail() ? false : true; }

};
istream cin;

int main()
{
	int n = 0;

	//bool b = cin; //error 암시적 변환 안됨
	bool b = static_cast<bool > (cin); // ok 명시적 변환 허용

	//cin << n; // error

	if ( cin ) {}  // ok
	if ( cin == false ) {}// error
}


=============brace-init과 변환=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/


class Point
{
	int x, y;
public:
	explicit Point(int a, int b) : x(a), y(b) {}
};

void foo(Point p) {}

int main()
{
	foo({ 1,1 }); // no explicit

//	Point p1(1, 1);

//	Point p2{ 1, 1 };	// direct initialize

//	Point p3 = { 1, 1 };// copy initialize. error(explicit)
}