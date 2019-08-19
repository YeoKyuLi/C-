https://github.com/codenuri/CPPINTERMEDIATE/tree/master/107_CONVERSION
=============변환 연산자/변환 생성자=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv1.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point()             : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

	// 변환 연산자 : 객체를 다른 타입으로 변환할때 호출된다.
	// 특징 : 리턴 타입을 표기하지 않는다.
	operator int()
	{
		return x;
	}
};

int main()
{
	int    n = 3;
	double d = n; // 암시적 형변환 발생.

	Point p1(1, 2);
	n = p1;		// p1.operator int()

	cout << n << endl; // 1
}
/*
*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv2.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// Point => int : 변환 연산자   p.operator int()
// int => Point : 변환 생성자   Point(int)

class Point
{
	int x, y;
public:
	Point()				: x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

	// 인자가 한개인 생성자 -  변환 생성자
	//							다른 타입이 Point로 변환 되게 한다.
	Point(int a) : x(a), y(0) {}

	operator int() 	{ return x; }
};

int main()
{
	Point p1;
	Point p2(1, 1);

	int n = 3;
	Point p(1, 2);

	n = p; // Point => int   p.operator int()
	p = n; // int => Point   n.operator Point() 가 있으면 된다.
		   //		         하지만, n은 사용자정의 타입이 아니다
}


=============변환의 장단점=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;
// RAII : Resource Acquision Is Initialization
class OFile
{
	FILE* file;
public:
	OFile(const char* filename, const char* mode = "wt")
	{
		file = fopen(filename, mode);
	}
	~OFile() {	fclose(file);	}

	operator FILE*() { return file; }
};
int main()
{
	OFile f("a.txt");

	// C 함수를 사용해서 화일 작업
	fputs("hello", f);
	fprintf(f, "n = %d", 10);	// OFile => FILE* 로 암시적 변환되면 가능.
							// f.operator FILE*()
	
	String s1 = "hello";
	char s2[10];

	strcpy(s2, s1); // String => const char* 암시적 변환..
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class OFile
{
	FILE* file;
public:
	// explicit 생성자 : 인자가 한개인 생성자가 암시적 변환을
	//					허용하는 것을 막는다.

	explicit OFile(const char* filename, const char* mode = "wt")
	{
		file = fopen(filename, mode);
	}
	~OFile() { fclose(file); }

	operator FILE*() { return file; }
};

void foo(OFile f) {}

int main()
{
	OFile f("a.txt");
	foo(f); // ok..

	//foo("hello"); // const char* => OFile 로 암시적 변환 발생.
				  // 변환 생성자
	//foo(static_cast<OFile>("hello"));

}



=============explicit=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

class Test
{
	int value;
public:
	explicit Test(int n) : value(n) {}
};

int main()
{
	// 아래 2줄의 차이점은 ?
	
	Test t1(5);  // 인자가 한개인 생성자 호출
				 // direct initialization

	Test t2 = 5; // 1. 변환 생성자를 사용해서 5를 가지고 Test의 임시객체 생성
				 // 2. 임시객체를 복사 생성자를 사용해서 t2에 복사
				 // copy initialization
}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv6.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <string>
#include <memory>
using namespace std;

class String16
{
public:
	explicit                    String16(const char16_t* o);
};

void foo(String16 s)  // String16 s = "hello"
{}

int main()
{
	foo("hello"); // error
	foo(String16("hello")); // ok..


	String16 s = "hello"; // error

	// STL 의 string 클래스는 생성자가 explicit 가 아님.
	string s1("hello");		// ok
	string s2 = "hello";	// ok


	shared_ptr<int> p1 = new int;	// error  생성자가 explicit
	shared_ptr<int> p2(new int);	// ok.. 함부로 변환이 일어나지 않도록 하기위해서
}
=============make nullptr=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv7.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int main()
{
	int   n1 = 10; // ok
	void* p1 = 10; // error.

	int   n2 = 0; // ok
	void* p2 = 0; // ok. 0은 정수지만 포인터로 암시적 형변환된다.

}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void foo(int n)   { cout << "int" << endl; }	// 1
void foo(void* p) { cout << "void*" << endl; }	// 2

void goo(char* p) { cout << "goo" << endl; }	// 3

int main()
{
	foo(0);			// 1
	foo((void*)0);	// 2

#ifdef __cplusplus
	#define NULL	0
#else
	#define NULL (void*)0
#endif

	foo(NULL);		// 2

	goo(NULL);	// void* => char* 로의 암시적 변환 필요.
				// C   : ok
				// C++ : 암시적 변환 안됨.
}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void foo(int n)   { cout << "int" << endl; }	// 1
void foo(void* p) { cout << "void*" << endl; }	// 2
void goo(char* p) { cout << "goo" << endl; }	// 3

/*
struct xnullptr_t
{
	//operator void*() { return 0; }
	//operator char*() { return 0; }
	template<typename T>
	operator T*() { return 0; }
};
xnullptr_t xnullptr; // 포인터 0
*/
// C++ 11: nullptr
int main()
{
//	foo(0);			// 1
//	foo(xnullptr);	// 2. xnullptr_t => void* 로의 암시적 변환 필요..
					//    xnullptr.operator void*()
//	goo(xnullptr);  // 3 goo

	int n = 0;
//	double* p1 = xnullptr;

	double* p2 = nullptr; // C++11 의 포인터 0
						  
	nullptr_t a = nullptr;

	int* p = a;
}
