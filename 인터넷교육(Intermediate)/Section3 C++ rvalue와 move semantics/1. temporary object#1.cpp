https://github.com/codenuri/CPPINTERMEDIATE/tree/master/301_TEMPORARY
=============임시객체의 개념과 수명=============

컴파일러가 컴파일 타임에 임시적으로 필요해서 만들었다가 지우는 변수나 객체들을 임시객체, 변수라고 한다.

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : temp1.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

int main()
{
	int a = 1, b = 2, c = 3;

	int sum = a + b + c;	// int temp = a + b;
							// int sum  = temp + c;
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : temp2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/
#include <iostream>

// 핵심 1. 임시객체를 생성하는 방법 - "클래스이름(생성자인자)"
//      2. 임시객체의 수명 - 문장의 끝.

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { std::cout << "Point()"  << std::endl; }
	~Point()					{ std::cout << "~Point()" << std::endl; }
};

int main()
{
//	Point p1(1, 2);	//  named object. 이름 : p1 파괴 : 함수 {}을 벗어날때
//	Point(1, 2);	// unamed object. temporary. 파괴 : 문장의 끝(;)
                    // 임시객체 : 클래스이름()

	Point(1, 2), std::cout << "X" << std::endl;

	std::cout << "----------" << std::endl;
}

=============임시객체와 참조=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : temp3.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	~Point()					{ cout << "~Point()" << endl; }
};

int main()
{
	Point p1;	// 임시객체 아님. 이름있는 객체

	// 핵심 1. 임시객체는 등호(=)의 왼쪽에 올수 없다.
	p1.x = 10;		// ok
	//Point().x = 10;	// error 임시객체는 lvalue가 될 수 없다.

	// 핵심 2. 임시객체는 주소를 구할수 없다.
	Point* pp1 = &p1;		// ok
	Point* pp2 = &Point(1,1);	// error

	// 핵심 3. non-const reference 는 임시객체를 참조할 수 없다.
	//         const     reference 는 임시객체를 참조할 수 있다.
	Point& r1 = p1;			// ok
	Point& r2 = Point();	// error

	const Point& r3 = p1;		// ok
	const Point& r4 = Point(1,1);	// ok 핵심 3. 임새 객체는 const 참조로 참조할 수 있다.
                                    // 임시객체의 수명이 r4의 수명과 동일해진다.

	r4.x = 10; // error

	// C++11 : rvalue reference는 상수성 없이 rvalue를 가리킬수있다.
	Point&& r5 = p1; // error, rvalue reference 는 rvalue만 가리킬수 있다.
	Point&& r6 = Point();

}


=============임시객체와 함수=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	~Point()					{ cout << "~Point()" << endl; }
};

// 임시객체와 함수 인자
void foo(const Point& p) 
// void foo(Point& p) // 임시객체를 전달 받을 수 없다.
{
}
int main()
{
	Point p(1,1);
	foo(p);

    //임시 객체를 사용한 인자 전달.
	foo(Point(1, 1));

	// STL에서 임시객체를 사용하는 경우
//	sort(x, x + 10, less<int>());

	cout << "end" << endl;

}


임시객체와 함수의 리턴값
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : temp3.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};
// temp5.cpp

Point foo()
{
    //NRVO ( Named RVO) : 최적화를 통해서 return Point(1, 1); 처럼 만들어 준다.
	Point pt(1, 1); // 2. 생성자
	return pt;		// return Point(pt) 임시객체 생성
					// 3. 복사 생성자

	// 임시객체를 사용한 리턴
	// RVO ( Return Value Optimization )
	return Point(1, 1);
}					
int main()
{
	Point ret(0, 0); // 1. 생성자
	ret = foo();
	cout << endl;

}
