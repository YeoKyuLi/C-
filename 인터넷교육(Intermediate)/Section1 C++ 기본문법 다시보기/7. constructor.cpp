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


=============생성자와 예외=============