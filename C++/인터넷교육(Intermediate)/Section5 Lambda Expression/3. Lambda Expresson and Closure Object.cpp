https://github.com/codenuri/CPPINTERMEDIATE/tree/master/403_LAMBDA_EXPRESSION
=============Closure Object=============

Lambda Expression
[](int a, int b){return a<b;}
[]: lambda - introducer, 람다표현식이 시작 됨을 나타냄.

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

bool cmp(int a, int b) { return a < b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// 비교정책으로 함수 사용.
	sort(x, x+10, cmp);

	// 비교정책으로 함수객체 사용.
	sort(x, x+10, less<int>());

	// C++11. 람다 표현식(lambda expression) 함수 코드 자체를 보내는것
	sort(x, x + 10, 
		  [](int a, int b) { return a < b; } );

}



/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	
	sort(x, x+10, less<int>());


	sort(x, x+10, [](int a, int b) { return a < b; }); // ClosureType이라는 임시객체로 치환됨


	bool b = [](int a, int b) { return a < b; }(1, 2);
		// class ClosureType{};ClosureType()(1,2);

	cout << b << endl; // 1
}

class ClosureType
{
public:
	bool operator()(int a, int b) const
	{
		return a < b;
	}
};
sort(x, x + 10, ClosureType() );

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// ClosureType.h
// [](int a, int b) { return a < b; }

class ClosureType
{
public:
	bool operator()(int a, int b) const
	{
		return a < b;
	}
	~ClosureType() = default;
	ClosureType(const ClosureType&) = default;
	ClosureType(ClosureType&&) = default;
	ClosureType& operator=(const ClosureType&) = delete;

	// convert to function pointer
	operator bool(*)(int, int)()  { return &static_method; }

	static bool static_method(int a, int b) 
	{
		return a < b;
	}
};

sort(x, x + 10, ClosureType() );


=============Lambda & type=============
람다 활용
1. 함수 인자로 전달
2. auto 변수에 담아서 함수 처럼 사용
3. 함수 리턴 값 등으로 활용 가능
    고차함수, higher-order function

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	// lambda expression 활용 1. 함수 인자로 사용
	//sort(x, x+10, [](int a, int b) { return a < b; });


	//[](int a, int b) { return a + b; };//임시객체생성

	//int n = [](int a, int b) { return a + b; }(1,2);

	// lambda expression 활용 2. auto 변수에 담아서
	//						함수 처럼 사용.
	auto f = [](int a, int b) { return a + b; };

	cout << f(1, 2) << endl; // 3

}


핵심
모든 lambda expression은 서로 다른 타입이다. 대입연산이 delete되어 있기 때문
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	auto f1 = [](int a, int b) { return a + b; };
		// class ClosureType{}; ClosureType();

	auto f2 = [](int a, int b) { return a + b; };

	//f2 = [](int a, int b) { return a + b; };

	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl;

}
=============Lambda & function argument=============

람다 담는 방법
1. auto 변수 사용 - inline 가능성이 높다
2. 함수 포인터 - inline 치환이 어렵다
3. std::function - inline 치환이 어렵다.
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <functional>
using namespace std;

int main()
{
    // 변수에 담는 3가지 방법
	auto f1 = [](int a, int b) { return a + b; };

	int(*f2)(int, int) = 
			  [](int a, int b) { return a + b; };

	//f2 = [](int a, int b) { return a - b; };

	function<int(int, int)> f3 =
		[](int a, int b) { return a + b; };


	f1(1, 2); // inline 치환 가능.
	f2(1, 2); // inline 치환이 어렵다
	f3(1, 2); // inline 치환이 어렵다
}

람다를 함수 인자로 받는 방법
1. 함수 포인터, function -> inline 치환이 어렵다.
2. template 
3. 임시객체 이므로 non-const lvalue referene로 받을 수 없다.
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <functional>
using namespace std;


//void foo( int (*f)(int, int) ) // 타입이 지워진다. 이 방법을 람다표현식의 타입 지우기, 인라인 안됨
//void foo(function<int(int, int)> f) // 전달받지만 인라인 안됨

//void foo(auto f) // auto는 함수 인자가 될 수 없다.
				 // error

//template<typename T> void foo( T f )
//template<typename T> void foo(T& f)
template<typename T> void foo(const T& f)
{
	f(1, 2);
}

int main()
{
	foo( [](int a, int b) { return a + b; } );
	foo( [](int a, int b) { return a - b; });

}

=============Lambda & suffix return type=============
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
	auto f1 = [](int a, int b) { return a + b; };

	auto f2 = [](int a, int b) -> int { return a + b; }; // 후위형 리턴타입 

	auto f3 = [](int a, int b){ 
						if (a == 1)
							return a;
						else
							return b;
						};

	auto f4 = [](int a, double b) -> double {
						if (a == 1)
							return a;
						else
							return b;
					};

}


