https://github.com/codenuri/CPPINTERMEDIATE/tree/master/301_TEMPORARY
=============참조리턴 vs 값리턴=============
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
// temp6.cpp

Point p; // 전역변수

Point foo() // 값리턴 : 임시객체가 리턴된다.
{
	return p;
}

Point& goo() // 참조리턴 : 임시객체가 생성되지 않는다.
{
	return p;
}
int main()
{
	//Point ret = foo();

	foo().x = 10; // error
	goo().x = 20; // ok 함수호출 왼쪽
	cout << p.x << endl;

    vector<int> v(10,2);
    v[0] = 10; //v.operator[](0) = 10;
}

int x = 0;

int  foo() { return x; }
int& goo() { return x; }

int main()
{
	foo() = 10; // error
	goo() = 10; // ok
}


=============임시객체가 생성되는 다양한 경우=============


#include <iostream>
using namespace std;

struct Base
{
	int v = 10;
};

struct Derived : public Base
{
	int v = 20;
};

int main()
{
	Derived d;
	cout << d.v << endl; // 20
	cout << d.Base::v << endl; // 10

	// 값캐스팅 : 임시객체 생성 / 참조캐스팅 : 임시객체 안만듬
	cout << (static_cast<Base>(d)).v << endl; // 10
	cout << (static_cast<Base&>(d)).v << endl; // 10

	(static_cast<Base>(d)).v = 30; // error
	(static_cast<Base&>(d)).v = 30; // ok
	
}

연산자와 임시객체

//  후위형.
int operator++(int& n, int )
{
	int temp = n;
	n = n + 1;
	return temp;
}
// 전위형.
int& operator++(int& n)
{
	n = n + 1;
	return n;
}
int main()
{
	int n = 3;
	n++; // operator++(n, int)
	++n; // operator++(n)

	++(++n);

	n++ = 10; // error
	++n = 10; // ok
}

=============임시객체와 멤버함수=============
#include <iostream>
using namespace std;

class Test
{
public:
	int data;

	void foo() &  { cout << "foo &" << endl; } // lvalue 객체에 대해서만 호출.
	void foo() && { cout << "foo &&" << endl; }  //Rvalue

	int& goo() & { return data; } //lvalue일때만
};

int main()
{
	Test t;
	t.foo(); //lvalue
	int& ret = t.goo();

	int& ret2 = Test().goo(); // error

	Test().foo();  //Rvalue

}

