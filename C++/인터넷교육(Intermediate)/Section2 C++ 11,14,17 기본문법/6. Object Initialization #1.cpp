https://github.com/codenuri/CPPINTERMEDIATE/tree/master/206_OBJECT_INIT
=============초기화 문제점=============

1. 객체(변수)의 종류에 따라 초기화 방법이 다르다.
2. 클래스의 멤버로 있는 배열을 초기화 할 수 없다.
3. 동적 메모리 할당으로 만들어진 배열을 초기화 할 수 없다.
4. STL 컴테이너를 초기화하는 편리한 방법이 없다.

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int main()
{
	// 1. 
	int n1 = 0;
	int n2(0);
	int ar[3] = { 1,2,3 };
	Point p = { 1,2 };		// 구조체
	complex c(1, 2);		// 클래스

	// 2.
	class Test
	{
		int x[10];
	};

	// 3. 
	int* p = new int[3];

	// 4.
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(1);
}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

int cnt = 0;

class Test
{
public:
//	int data = 0; // member initializer

	int data = ++cnt;

	Test() {}
	Test(int n) {}  //: data(n) {} // 생성자에서 멤버 데이터에 접근하는 경우가 있으면 위의 int data = ++cnt;가 실행되지 않음.
};

int main()
{
	Test t1;	// data = 1	
	Test t2(3);	// data = 3

	cout << cnt << endl; // 1

	cout << t1.data << endl;
	cout << t2.data << endl;
}


=============uniform Initialization=============

일관된 초기화 Uniform initialize, brace init
1. 객체의 형태에 상관없이 중괄호 (brace, {})를 사용해서 초기화 하는 것

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

struct Point
{
	int x, y;
};

class Complex
{
	int re, im;
public:
	Complex(int r, int i) : re(r), im(i) {}
};

int main()
{
//	int n = 0;
//	int x[2] = { 1,2 };
//	Point p = { 1,2 };
//	Complex c(1, 2);
//일관도 초기화
	/*
	int  n{ 0 };
	int  x[2]{ 1,2 };
	Point   p{ 1,2 };
	Complex c{ 1, 2 };
	*/

	int  n = { 0 };
	int  x[2] = { 1,2 };
	Point   p = { 1,2 };
	Complex c = { 1, 2 };


	int n2 = 3.4; // ok
	//int n3 = { 3.4 }; // error.

	//char c1{ 300 }; // error
	char c2{ 100 }; // ok

}

=============direct vs copy=============
direct initialization
    초기화 시에 = 을 사용하지 않는 것
copy initialization
    초기화 시에 =을 사용하는 것

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int main()
{
	int n1 = 0; // copy initialization
	int n2(0);	// direct initialization

	int n3 = { 0 };
	int n4{ 0 };
}


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
	// explicit : 변환 생성자로 사용될수 없다.
	//		      copy initialization 될수 없다.
	explicit Point()    		 : x(0), y(0) {}
	explicit Point(int a)        : x(a), y(0) {}
	explicit Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point p1(5);	// ok.
	//Point p2 = 5;	// ok. 하지만 생성자 explicit 라면 error.
    // 5을 가지고 변환 생성자를 사용해서 포인터의 객체를 만들고 복사 생성자

	Point p3(1, 1);		// ok
	//Point p4 = (1, 1);	// error.

	Point p5{ 1,1 };	// ok
	//Point p6 = { 1,1 };	// ok. 하지만 생성자 explicit 라면 error.

    //default 생성자 부르는 방법,,
	Point p7;
	Point p8{};		// direct
	//Point p9 = {};  // copy. error
}


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
	Point() : x(0), y(0) {}
	Point(int a) : x(a), y(0) {}
	explicit Point(int a, int b) : x(a), y(b) {}
};

void foo(Point p) {}

int main()
{
	Point p1{ 1,1 };
//	Point p2 = { 1,1 };

	foo( { 1,1 } ); 
}

=============default vs value=============
default initialization
    초기화 구문 없이 (no initializer) 초기화 하는것
value initialization
    빈 초기화 구문 (empty initializer)를 가지고 초기화 하는것
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
	// direct initialization
	int n1(0);
	int n2{ 0 };    

	// copy initialization
	int n3 = 0;
	int n4 = { 0 }; 

	//---------------------------
	int n5;		// defalut initialization. 쓰레기값	
	int n6{};	// value initialization.   0으로 초기화

	cout << n5 << endl; // 쓰레기값
	cout << n6 << endl; // 0

	int n7(); // 주의. 함수 선언. 

}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
public:
	int x;
	int y;

	//Point() {}
	Point() = default;
};
int main()
{
	// www.cppreference.com
	Point p1;   // default initialization
	Point p2{}; // value   initialization

	cout << p1.x << endl; // 쓰레기값
	cout << p2.x << endl; // 0
}


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
	int n1;		// default. 쓰레기값
	int n2{};	// value.   0
	int n3();   // 함수선언.

	int* p1 = new int;	// default. 쓰레기값.
	int* p2 = new int();// value.   0
	int* p3 = new int{};// value.   0

	cout << *p1 << endl; // 쓰레기 값
	cout << *p2 << endl; // 0
	cout << *p3 << endl; // 0
}