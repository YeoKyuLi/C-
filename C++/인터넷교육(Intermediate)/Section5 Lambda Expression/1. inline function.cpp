https://github.com/codenuri/CPPINTERMEDIATE/tree/master/401_INLINE
=============inline 함수=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// inline1.cpp

	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // 호출
	int n2 = Add2(1, 2); // 치환
						 // 장점 : 속도가 빠르다
						 // 단점 : 목적코드가 커진다. 함수가 클때,

	// g++ inline1.cpp -S        => inline1.s
	// cl  inline1.cpp /FAs /Ob1 => inline1.asm
}


=============인라인 함수와 함수 포인터=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// inline2.cpp
// 1. 인라인 함수 문법은 컴파일 시간 동작한다.
// 2. 인라인 함수라도 함수포인터에 담아서 사용하면 호출된다.

	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // 호출
	int n2 = Add2(1, 2); // 치환
	
	int(*f)(int, int);

	f = &Add2;
	//if (사용자입력이 1 이면)
	//	f = &Add1;

	int n3 = f(1, 2); // 호출 ? 치환 ?
}

=============linkage=============

inline함수는 h에서 만들어야 한다.
cpp파일에 만드면 linking error 발생,
컴파일 타임에 함수의 원본을 알지 못하지 때문에 에러가 발생한다.
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// add.cpp
int Add1(int a, int b)
{ 
	return a + b; 
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// add.h
	   int Add1(int a, int b);

inline int Add2(int a, int b)
{
	return a + b;
}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// inline3.cpp
#include "add.h"

int main()
{
	Add1(1, 2); // call (4¹ÙÀÌÆ®ºó°ø°£)
	Add2(1, 2); //
}