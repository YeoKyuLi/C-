https://github.com/codenuri/CPPINTERMEDIATE/tree/master/304_PERFECT_FORWARDING
=============using perfect forwarding=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b, int& c)  { cout << "Point()" << endl; }
	~Point()             { cout << "~Point()" << endl; }
	Point(const Point&)  
	{
		cout << "Point(const Point&)" << endl; 
	}
};

int main()
{
	vector<Point> v;

//	Point p(1, 2);
//	v.push_back(p);

    
	// 소멸자 호출 횟수 : 2
	int n = 10;
	v.emplace_back(1, 2, n); // 객체를 만들어서 전달하는것이 아니라 생성자를 만들수 있는 인자를 넘긴다. perfect forwarding
	// 소멸자 호출 횟수 : 1
}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <memory>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
	Point(const Point&)
	{
		cout << "Point(const Point&)" << endl;
	}
};

int main()
{	
	// 메모리 할당은 몇번 될까?
	//shared_ptr<Point> sp( new Point(1,2) );


	shared_ptr<Point> sp
		= make_shared<Point>(1, 2);
	
}
=============std::forward #1=============

std::forward
    lvalue를 인자로 받아서 T의 타입에 따라 lvalue 또는 rvalue로 캐스팅 한다.

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/



#include <iostream>
using namespace std;

void goo(int& a)  { cout << "goo" << endl; } // l
void hoo(int&& a) { cout << "hoo" << endl; } // r


template<typename T> T&& xforward(T& arg)
{
	return static_cast<T&&>(arg);
}

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	//f(static_cast<T&&>(arg));

	f(forward<T&&>(static_cast<int&&>(arg)));  // T의 정보를 줌으로써 전단계에 어떤 데이터형인지 유추할 수 있다.

	// lvalue ÀÏ¶§ T : int& => int&
	// rvalue ÀÏ¶§ T : int  => int&&
	//f(xforward(arg));
}

int main()
{
	int n = 0;

//	chronometry(&goo, n);
	chronometry(&hoo, 10);

	cout << n << endl;
}


// static_cast<T&&>(arg); T의 타입에 따라가 rvalue 또는 lvalue 캐스팅.
// 함수 인자 : lvalue와 rvalue를 모두 받아서
// 리턴 타입 : rvalue로 캐스팅 
template<typename T>
typename remove_reference<T>::type&&
xmove(T&& obj)
{
    return static_cast<typename remove_reference<T>::type&&>(obj);
}

// 함수 인자 : lvalue를 받아서
// 리턴 타입 : T에 따라서 lvalue 또는 rvalue로 캐스팅 
template<typename T> T&& xforward(T& arg)
{
	return static_cast<T&&>(arg);
}

=============std::forward #2=============


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> T&& xforward(T& arg)
{
	return static_cast<T&&>(arg);
}
//rvalue를 인자로 가지는 forward
// rvalue를 인자로 받아서 rvalue로 캐스팅하는 xforword
/*
template<typename T> T&& xforward(typename remove_reference<T>::type && arg)
{
	return static_cast<T&&>(arg);
}
*/
struct Arg
{
	int i = 1;
	int  get() && { cout << "&&" << endl; return i; } // call to this overload is rvalue
	int& get() &  { cout << "&" << endl; return i; }  // call to this overload is lvalue
};
void foo(int&)  { cout << "foo int&" << endl;}
void foo(int&&) { cout << "foo int&&" << endl; }

template<class T>
void wrapper(T&& arg)
{
//	using Type = decltype(xforward<T>(arg).get());
//	foo(xforward<Type>( xforward<T>(arg).get()) );

	using Type = decltype(static_cast<T&&>(arg).get());
	foo(static_cast<Type&&>(static_cast<T&&>(arg).get()) );

}

int main()
{
	wrapper(Arg());

	Arg a;
	wrapper(a);
}

=============setter using move & copy=============

class Test
{
    Data data;
public:

    //--------------------------------------------------------------------------------------
    // 아래 코드는 무조건 copy= 사용 , 들어오는 값이 l or r이라고 해도 여기서 값의 이름을 가지니깐
    // lvalue가 된다.
    void setData(const Data& d){data = d;}
    // 아래 코드는 무조건 move= d이 아니고 copy=
    void setData(const Data& d){data = move(d);}

    //--------------------------------------------------------------------------------------
    // 아래 코드는 무조건 copy= 사용
    // 방법 1. move setter와 copy setter를 별도의 함수로 제공
    // 장점 : 오버헤드가 없다. 단점 : setter 함수를 2개를 제공해야 한다.
    void setData(const Data& d){data = d;}
    void setData(Data&& d){data = move(d);}

    //--------------------------------------------------------------------------------------
    //방법 2. call by value를 사용하는 방법
    // 장점 : setter 함수는 한개만 제공하면 된다. 단점 : 약간의 오버헤드가 있다. (move 1회)
    void setData(Data d){data = move(d);}

    //--------------------------------------------------------------------------------------

    // 방법 3. forwarding reference
    // 장점 : 오버헤드가 없고, 하나의 함수 템플릿만 제공하면 된다.
    // 단점 : side effect를 고려해야 한다. 꼭 Data type이 아니라도 함수가 생성될 수 있기 때문
    template<tyename T> void setData(T&& a)
    {
        data = a; // copy
        data = moew(a); // move
        data = std::forward<T>(a);
    }
}

int main()
{
    Test test;
    Data d;
    test.setData(d);        // 실행후에도 d 사용 가능 l       copy
                            // copy=
                            // copy 생성, move=
                            // copy=
    test.setData(move(d));  // 실행후에 d사용 못함  r       move
                            // move=
                            // move 생성, move=
                            // move=


    AAA a;
    test.setData(a);
}


