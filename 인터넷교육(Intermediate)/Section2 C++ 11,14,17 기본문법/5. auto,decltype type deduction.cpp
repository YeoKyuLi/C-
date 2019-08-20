https://github.com/codenuri/CPPINTERMEDIATE/tree/master/207_AUTO_DECLTYPE
=============auto=============
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
	int  n = 10;
	int& r = n;

	auto a = r; // a ? int ? int&
	a = 30;

	cout << n << endl; // 30 ? 10
}


auto를 값 타입으로 사용할 때
    우변 수식이 가진 reference, const, valatile 속성을 제거하고 타입 결정

auto를 참조 타입으로 사용할 때
    우변 수식이 가진 reference 속성만 제거되고 const, valatile 속성은 유지된다.
주의사항
    변수 자체의 const 속성만 제거된다.
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int main()
{
	int n = 10;
	int& r = n;
	const int c = n;
	const int& cr = c;

	// auto : 값 복사 방식
	auto a1 = n;	// int
	auto a2 = r;	// int, 
	auto a3 = c;	// int
	auto a4 = cr;	// int


	auto& a5 = n;	// auto : int   a5 : int&
	auto& a6 = r;	// auto : int   a6 : int&
	auto& a7 = c;   // auto : const int a7 : const int& 
	auto& a8 = cr;	// auto : const int a8 : const int&


    //여길 이해하도록.....
	const char* s1 = "hello"; // s1 자체는 const 아님
							  // s1을 따라가면 const
	auto a9 = s1;	// const char*

	const char* const s2 = "hello";
	auto a10 = s2;  // const char*
}


=============decltype=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int main()
{
	int  n = 0;
	int* p = &n;


	decltype(n) d1;	// int   // n = 10;
	decltype(p) d2;	// int*

					// (수식) : 수식이 lvalue라면 참조, 아니면 값 타입, 참조 변수이기 때문에 초기값 정의 해야됨.
	decltype(*p)  d3; // *p = 10;   int&
	decltype((n)) d4; // (n) = 10;  int&

	decltype(n + n) d5; // n+n = 10 가 될수 없다.  int 
	decltype(++n)   d6; // ++n = 10; ok..     int&
	decltype(n++)   d7; // n++ = 10; error.   int

	int x[3] = { 1,2,3 };

	decltype(x[0]) d8;  // x[0] = 10; ok    int&
	auto a1 = x[0];		// int
}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int x = 10;

int& foo(int a, int b) 
{
	return x;
}

int main()
{
	auto ret1 = foo(1, 2); // int 

	// 평가되지않는 표현식 (unevaluated expression)
	decltype( foo(1, 2) ) ret2 = foo(1,2);  // int&

	// C++14
	decltype(auto) ret3 = foo(1, 2); // int&


}



=============array name=============

int main()
{
    int n; // n, int
    int *p1 = &n;
    double d; // d, double
    double *p2 = &d;

    int x[3] = {1,2,3}; //x, int[3]
    //배열 x의 주소
    int (*p3)[3] = &x;
    int *p4 = x; // 배열의 주소 아님..

}

int main()
{
    // 모든 변수는 자신과 동일한 타입의 변수로 초기화(복사) 될 수 있다.
    int n1 = 10;
    int n2 = n1;

    int x1[3]= {1,2,3};
    itn x2[3] = x1; // 배열은 자신과 동일한 타입의 배열로 복사가 안됨.

    int *p1 = x1; // 배열의 이름은 첫번째 요소의 주소로 암시적 형변환된다.
}

int main(){

    int x[3] = {1,2,3};
    int (*p1)[3] = &x; // 배열의 주소

    int *p2 = x; //배열의 첫번째 요소의 주소로 암시적 형변환 된 표현

    printf("%p %p", p1, p1+1); //12
    printf("%p %p", p2, p2+1); //4

    //p1 : 배열의 주소, *p1 : 배열 : 역참조
    (*p1)[0] = 10;
    //p2 : 요소의 주소 , int*
    *p2 = 10;
    
    
}
// p1 = p1 + 1 에서 뜻은 자기 요소 만큼 더한다는 뜻이다. 내가 12byte이면 12byte 커지는것


=============auto 주의사항=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

int main()
{
	// 배열
	int x[3] = { 1,2,3 }; // x : int[3]

	auto  a1 = x;	// int a1[3] = x; error
					// int* a1 = x; 

	auto& a2 = x;	// int (&a2)[3] = x; // ok
					// a2 : int (&)[3]
	
	decltype(x) d;  // int [3]

	cout << typeid(a1).name() << endl; // int*
	cout << typeid(a2).name() << endl; // int(&)[3] // boost쓰면 더 정확히 알 수 있음
	cout << typeid(d).name() << endl;  // int [3]

	//------------------------

	auto a3 = 1;	// int
	auto a4{ 1 };	// int
	auto a5 = { 1 };// int ? initializer_list => initializer_list

	cout << typeid(a4).name() << endl;
	cout << typeid(a5).name() << endl;

	//--------------------------

	vector<int> v1(10, 0);
	auto a6 = v1[0];	// int

	vector<bool> v2(10, 0);
	auto a7 = v2[0];	// bool xx

	cout << typeid(a6).name() << endl; // int
	cout << typeid(a7).name() << endl; // temporary proxy 

}