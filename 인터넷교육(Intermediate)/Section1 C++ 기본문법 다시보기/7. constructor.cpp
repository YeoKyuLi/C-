https://github.com/codenuri/CPPINTERMEDIATE/tree/master/106_CONSTRUCTOR
=============생성자 호출순서 #1=============
1. 파생 클래스 생성시 기반 클래스의 생성자가 먼저 호출된다.
2. 기반 클래스의 생성자는 항상 디폴트 생성자를 호출된다.
3. 기반 클래스의 디폴트 생성자가 없는 경우 파생 클래스 객체를 만들 수 없다.
4. 기반 클래스의 다른 생성자를 호출하려면 파생 클래스 생성자의 초기화 리스트에서 명시적으로 호출해야 한다.

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor1.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Base
{
public:
//	Base()      { cout << "B()"    << endl; }
	Base(int a) { cout << "B(int)" << endl; }
	~Base()     { cout << "~B()"   << endl; }
};

class Derived : public Base
{
public:
	Derived()     : Base(0) { cout << "D()" << endl; }
	Derived(int a): Base(a) { cout << "D(int)" << endl; }
	~Derived()     { cout << "~D()" << endl; }
};

int main()
{
	//Derived d;
	Derived d(5);
}



/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor2.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Base
{
public:
//	Base()      { cout << "B()"    << endl; } // 없으면 Base에 Default constructror가 없다고 Error
	Base(int a) { cout << "B(int)" << endl; }
	~Base()     { cout << "~B()" << endl; }
};
class Derived : public Base
{
public:
	Derived() : Base() // Base() 사용자가 안만들면 컴파일러가 기본적으로 생성한다.
	{
		cout << "D()" << endl; 
	}
	Derived(int a) : Base(a) // Base() 사용자가 안만들면 컴파일러가 기본적으로 생성한다.
	{ 
		cout << "D(int)" << endl; 
	}
	~Derived()      { cout << "~D()" << endl; }
};

int main()
{
	Derived d(5);
}


protected constructor
자신은 객체를 만들 수 없지만(추상적인 존재), 파생클래스의 객체는 만들 수 있게 한다.

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

//최상위 클래스를 protected로 넣는 경우가 많다.
class Animal
{
// private:
// 두개다 error
protected:
	Animal() {}
};

class Dog : public Animal
{
public:
	Dog() : Animal() {}
};

int main()
{
	// 다음중 에러를 모두 골라 보세요.
	Animal a; // error.
	Dog    d; // ok..
}
=============생성자 호출순서 #2=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

class Point
{
	int x, y;
public:
//	Point()             : x(0), y(0) {} // : p1(), p2() 
	Point(int a, int b) : x(a), y(b) {} //  p1(0,0), p2(0,0)
};
class Rect
{
	Point p1;
	Point p2;
public:
	Rect() : p1(0,0), p2(0,0) //: p1(), p2() 컴파일러가 자동으로 생성해줌
	{
	}
};

int main()
{
	Rect r; // p1의 생성자, P2의 생성자, Rect 생성자
}


생성자의 순서는 메모리에 올라오는 순서대로
1. 기반 클래스의 멤버의 생성자
2. 기반 클래스의 생성자
3. 파생 클래스의 멤버의 생성자
4. 파생 클래스의 생성자

BM -> Base -> DM -> Derived

생성자의 순서를 바꿀 수 없음,
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor5.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct BM { BM() { cout << "BM()" << endl; } };
struct DM { DM() { cout << "DM()" << endl; } };

struct Base
{
	BM bm;
	int x;
	Base() { cout << "Base()" << endl; }
};

struct Derived : public Base
{
	DM dm;
	int y;
	Derived() : dm(), Base()
	{
		cout << "Derived()" << endl; 
	}
};

int main()
{
	Derived d;
}

=============생성자 호출순서 예제=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor6.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct stream_buf
{
	stream_buf(size_t sz) 
	{ 
		cout << "stream_buf" << endl; 
	}
};
struct stream
{
	stream(stream_buf& buf) 
	{
		cout << "stream : using stream_buf" << endl; 
	}
};

// 버퍼를 가지고 있는 stream
struct mystream : public stream
{
	stream_buf buf;
public:
	mystream(int sz) : buf(sz), stream(buf) {}
};


int main()
{
//	stream_buf buf(1024);
//	stream st(buf);

	mystream mst(1024);
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor7.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct stream_buf
{
	stream_buf(size_t sz)
	{
		cout << "stream_buf" << endl;
	}
};
struct stream
{
	stream(stream_buf& buf)
	{
		cout << "stream : using stream_buf" << endl;
	}
};

// 버퍼만 관리하는 클래스, 생성자가 호출 순서를 명확히 알아봐야한다.
struct buf_manager
{
protected:
	stream_buf buf;
public:
	buf_manager(size_t sz) : buf(sz) {}
};

struct mystream : public buf_manager, public stream
{
public:
	mystream(size_t sz) : buf_manager(sz), stream(buf) {}
};


int main()
{
	mystream mst(1024);
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor8.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// 생성자에서는 가상함수가 동작하지 않는다.
// 그 이유는 기반 클래스의 생성자가 호출되었을때, 파생클래스의 멤버들은 아직 초기화 되어 있지 않음
struct Base
{
	Base() { goo(); } // 동작하지 ㅇ낳고
	
//	void foo() { goo(); }
	virtual void goo() { cout << "Base::goo" << endl; } // 
};

struct Derived : public Base
{
	int x;

	Derived() : x(10) {}
	virtual void goo() { cout << "Derived::goo" << x << endl; }
};

int main()
{
	Derived d;
//	d.foo();
}

=============생성자와 예외=============


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor9.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct Resource
{
	Resource()  { cout << "acquire Resource" << endl; }
	~Resource() { cout << "release Resource" << endl; }
};

class Test
{
	Resource* p;
public:
	Test() : p( new Resource )
	{
		cout << "Test()" << endl;
		throw 1;
	}
	~Test()
	{
		delete p;
		cout << "~Test()" << endl;
	}
};
int main()
{
	try
	{
		Test t;
	}
	catch (...)
	{
		cout << "예외 발생" << endl;
	}
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor10.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <memory>
using namespace std;

struct Resource
{
	Resource() { cout << "acquire Resource" << endl; }
	~Resource() { cout << "release Resource" << endl; }
};

// 해결책 1. Raw Pointer 대신 스마트 포인터 사용

class Test
{
//	Resource* p;
	unique_ptr<Resource> p; //share_ptr
public:
	Test() : p(new Resource) //~Test()는 부르지 못하지만, 멤버데이터의 소멸자는 부를수 있다.
	{
		cout << "Test()" << endl;
		throw 1;
	}
	~Test()
	{
		//delete p;
		cout << "~Test()" << endl;
	}
};

int main()
{
	try
	{
		Test t;
	}
	catch (...)
	{
		cout << "예외 발생" << endl;
	}
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor11.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <memory>
using namespace std;

struct Resource
{
	Resource() { cout << "acquire Resource" << endl; }
	~Resource() { cout << "release Resource" << endl; }
};

// 해결책 2. two-phase constructor

class Test
{
	Resource* p;
public:
	Test() : p(0)
	{
		// 예외 가능성이 있는 어떠한 작업도 하지 않는다.
		// 가상함수 호출()
	}

	// 자원 할당 전용함수
	void Construct()
	{
		p = new Resource;
		//cout << "Test()" << endl;
		// 가상함수 호출()
		throw 1;
	}

	~Test()
	{
		delete p;
		cout << "~Test()" << endl;
	}
};


int main()
{
	try
	{
		Test t;
		t.Construct(); // 필요한 자원 할당.
	}
	catch (...)
	{
		cout << "예외 발생" << endl;
	}
}