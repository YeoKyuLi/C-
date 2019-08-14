https://github.com/codenuri/CPPINTERMEDIATE/tree/master/105_NAME_MANGLING
=============name manling=============
name manling or name decoration
1. 컴파일러가 컴파일 시간에 심볼의 이름을 변경하는 현상
2. 함수 오버로딩, namespace, template등의 문법


=============extern=============
// square.h
//extern "C" // C++ 컴파일러에게 C 처럼 해석해 달라.

#ifdef __cplusplus
extern "C" {
#endif

	int square(int);

#ifdef __cplusplus
}
#endif


=============함수 이름과 함수 주소=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : name2.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <cstdio>

int square(int n)
{
	return n * n;
}
double square(double d)	
{
	return d * d;
}
int main()
{
	//printf("%p\n", &square); // error

	//printf("%p\n", static_cast<int(*)(int)>(&square)); // ok. int square(int n)

	//auto p = &square; // error

	int(*f)(int) = &square; // ok
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : name3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <typeinfo>
using namespace std;

void foo(int a) 
{
}
// a.exe | c++filt -t
int main()
{
	void(*f1)(int) = &foo; // ok. 함수 주소 꺼내기
	void(*f2)(int) = foo;  // 함수 이름은 함수 주소로 암시적 형변환 foo 함수 타입인데 함수의 주소로 암시적 형 변환

	typedef void(*PF)(int); // 함수 포인터 타입
	typedef void F(int);    // 함수 타입..

	cout << typeid(&foo).name() << endl; // void(*)(int)
	cout << typeid(foo).name() << endl;  // void(int)
}


=============함수 찾는 순서=============
컴파일러가 함수를 찾는 순서
1. exactly matching - foo(float)
2. template - too(T)
3. promotion - foo(double)
4. standard conversion - foo(int)
5. user define conversion - foo(FLOAT)
6. variadic argument - foo(...)

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : name4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct FLOAT 
{
	FLOAT(float) {} // 변환 생성자
					// float => FLOAT로 변환허용
};

//template<typename T> 
//void foo(T  )    { cout << "T"      << endl; }
//void foo(int)    { cout << "int"    << endl; }
//void foo(double) { cout << "double" << endl; }
//void foo(float)  { cout << "float"  << endl; } 
//void foo(FLOAT)  { cout << "FLOAT"  << endl; }
void foo(...)    { cout << "..."    << endl; }

int main()
{
	float f = 3.4f;
	foo(f);
}