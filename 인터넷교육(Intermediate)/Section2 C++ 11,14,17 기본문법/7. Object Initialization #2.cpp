https://github.com/codenuri/CPPINTERMEDIATE/tree/master/206_OBJECT_INIT
=============initializer_list=============
initializer_list
1. brace-init-list로 초기화된 요소의 시작과 끝(개수)를 가리키는 클래스
2. 반복자는 상수를 가리킨다.


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <initializer_list>
using namespace std;

int main()
{
	// brace-init-list
	// VC++ : int* first, *last
	// g++  : int* first, count
	initializer_list<int> s = { 1, 2, 3, 4, 5 };

	auto p = begin(s); // 상수를 가리키는 반복자
	//*p = 20; // error

	cout << *p << endl;

}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <initializer_list>
using namespace std;

void foo( initializer_list<int> e )
{
	auto p1 = begin(e);
	auto p2 = end(e);

	for (auto n : e)
		cout << n << " ";
	cout << endl;
}

int main()
{
	initializer_list<int> e1 = { 1,2,3 }; // 연속적 메모리
	initializer_list<int> e2  { 1,2,3,4,5 };

	foo(e1);
	foo({ 1,2,3,4 });
	foo({ 1,2,3,4,5,6,7 });

}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <initializer_list>
using namespace std;
class Point
{
	int x, y;
public:
	Point(int a, int b)           { cout << "int, int" << endl; }				// 1
	Point(initializer_list<int> ) { cout << "initializer_list<int>" << endl; }	// 2
};

int main()
{
	// Point p1(1, 1);	// 1번, 없다면 error
		
	//Point p2( { 1, 1 } );  // 2번. {1,1} 변환생성자를 사용해서 임시객체생성. 복사생성자를 사용해서 p2복사
							// 없으면 error지만, explicit 가 아닐경우. 변환 생성.

	//Point p3{ 1,1 }; // 2. 없으면 1번 ********************************

	//Point p4 = { 1,1 }; // 2. 없으면 1번.
	
	//Point p5(1, 2, 3); // error
	
	//Point p6{ 1,2,3 }; // 2번.
	
	Point p7 = { 1,2,3 }; // explicit 가 아닐경우

	vector<int> v = { 1,2,3,4 };
	
}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
template<typename T, typename Ax = allocator<T>> class vector
{
	T* buff;
public:
	vector(size_t sz, T v = T() ) {} // 1
	vector(initializer_list<T> s) {} // 2
};
*/

int main()
{
	vector<int> v = { 1,2,3,4,5 }; // ok. 편리해 졌다

	vector<int> v1(10, 3);  // 1번. 10개를 3으로 초기화
	vector<int> v2{ 10,3 }; // 2번, 2개의 요소를 10, 3으로 초기화

	cout << v1.size() << endl; // 10
	cout << v2.size() << endl; // 2
}
=============aggregate initialization=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

//생성자가 없으면 컴파일러가 제공한다.

#include <iostream>
using namespace std;

// aggregate initialization
// aggregate type : {} 로 초기화 가능한것. 구조체, 배열.
struct Point
{
	int x, y;
	
	void foo() {} // aggregate

//	virtual void foo() {} 

//	Point() = default; // aggregate
//	Point() {}				// 1
//	Point(int a, int b) { }	// 2
};

int main()
{
	Point p1;			// 1. ok
	Point p2 { 1,2 };	// 2. ???
}

=============초기화 문제점 해결=============

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

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 1. 
	int n1{ 0 };
	int n2{ 0 };
	int ar[3]{ 1,2,3 };
//	Point p = { 1,2 };		// 구조체
//	complex c{ 1, 2 };		// 클래스

	// 2.
	class Test
	{
		int x[10]{ 1,2,3,4,5,6,7,8,9,10 };
	};

	// 3. 
	int* p = new int[3]{ 1,2,3 };

	// 4.
	vector<int> v{ 1,2,3 };

//	for (int i = 0; i < 10; i++)
//		v.push_back(1);
}


