https://github.com/codenuri/CPPINTERMEDIATE/tree/master/303_MOVE
=============복사생성자의 모양=============
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
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	//Point(Point p) // Point p = p1. 결국 복사 생성자가 무한히 호출.

	// Point(Point& p)	// lvalue 객체만 인자로 받을수 있다.
						// 함수 리턴값으로 반환되는 임시객체를 
						// 받을수 없다.
	Point(const Point& p) // lvalue객체와 rvalue 객체를 모두 받을수
						  // 있다.
	{
		// 모든 멤버 복사.
	}
};

Point foo()
{
	Point ret(0, 0);
	return ret;
}

int main()
{
	Point p1(1, 1);	// 생성자 호출
	Point p2(p1);	// Point( Point )  복사 생성자.

	Point p3( foo() );
}

=============move semantics=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <cstring>
using namespace std;

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}
};

int main()
{
	Cat c1("NABI", 2);
	Cat c2 = c1; // error(sallow copy) -> solution : deep copy
}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <cstring>
using namespace std;

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~Cat() { delete[] name; }

	// 깊은 복사로 구현한 복사 생성자
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}
	// 소유권 이전(자원전달)의  이동(move) 생성자
	// rvalue만 되도록
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = 0; // 자원 포기
	}
};

Cat foo()	// 값리턴 : 임시객체(rvalue)
{
	Cat cat("NABI", 2);
	return cat;	
}

int main()
{
	Cat c = foo(); // 임시객체.
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Test
{
	int* resource;
public:
	Test()  {}	// 자원할당
	~Test() {}	// 자원해지
	
	// 복사 생성자 : 깊은복사 또는 참조계수
	// 인자로 lvalue 와 rvalue 를 모두 받을수 있다
	Test(const Test& t) { cout << "Copy" << endl; }

	// Move 생성자 : 소유권 이전(자원 전달)
	// rvalue만 전달 받을수 있다.
	Test(Test&& t)      { cout << "Move" << endl; }
};
Test foo()
{
	Test t;
	return t;
}
int main()
{
	Test t1;
	Test t2 = t1;		// 복사 생성자
	//Test t3 = Test();	// 복사 생성자.  //move 생성자
	Test t4 = foo();
}


=============std::move=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Test
{
public:
	Test() {}	
	~Test() {}	
	Test(const Test& t) { cout << "Copy" << endl; }
	Test(Test&& t)      { cout << "Move" << endl; }
};

int main()
{
	Test t1;
	Test t2 = t1;		// Copy 	
	Test t3 = Test();	// Move
	Test t4 = static_cast<Test&&>(t1);	// Move
						// 복사가 아닌 move 생성자를 호출해 달라.
	Test t5 = move(t2); // move가 내부적으로 위처럼 캐스팅한다.
}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Test
{
public:
	Test() {}
	~Test() {}
	Test(const Test& t) { cout << "Copy" << endl; }
	Test(Test&& t)      { cout << "Move" << endl; }

	Test& operator=(const Test& t) { return *this; } // 복사 대입연산자
	Test& operator=(Test&& t)      { return *this; } // move 대입연산자
};

int main()
{
	Test t1;
	Test t2 = t1;	// 초기화. 복사 생성자
	t2 = t1;		// 대입.   대입 연산자

	t2 = move(t1);
}
