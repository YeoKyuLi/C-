https://github.com/codenuri/CPPINTERMEDIATE/tree/master/403_LAMBDA_EXPRESSION
람다에서 지역변수와 멤버 변수를 캡쳐하는 방식
=============Capture Variable #1=============


#include<iostream>
using namespace std;

int g = 10;
int main()
{
    int v1 = 0, v2 = 0;

    auto f1 = [](int a){g = 0 ; return a+g; }; // ok
        // class ClosureType{};

    auto f2 = [](int a){return a+v1; }; // error
    
    auto f3 = [v1](int a){return a+v1; }; //ok

    auto f4 = [v1, v2](int a){return a+v1 + v2; }; //ok

    auto f5 = [v1](int a){v1 = 10; return a+v1; }; //컨파일 타입에 에러
    auto f5 = [v1](int a)mutable{v1 = 10; return a+v1; }; //ok, 원본이 아닌 복사본이 변경되는 것임.

    
}


#include <iostream>
using namespace std;

int main()
{
	int v1 = 0, v2 = 0;

	// capture

	auto f0 = []()       { return 0; };
	auto f1 = [v1, v2]() { return v1 + v2; };

	cout << sizeof(f0) << endl; // 1 empty
	cout << sizeof(f1) << endl; // 8

}


#include <iostream>
using namespace std;

int main()
{
	int v1 = 0, v2 = 0;

	//auto f1 = [v1, v2]() { v1 = 10; v2 = 20;};// error 
	
	// mutable lambda : () 연산자 함수를 비상수 함수로
	auto f1 = [v1, v2]() mutable { v1 = 10; v2 = 20; }; // 복사본을 변경해서 원본은 변경되지 않았음

	f1(); // 람다 표현식 실행..

	cout << v1 << endl; // 0
	cout << v2 << endl; // 0

}


#include <iostream>
using namespace std;

int main()
{
	int v1 = 0, v2 = 0;

	// capture by value, capture by copy (더 많이 씀)
	//auto f1 = [v1, v2]() mutable { v1 = 10; v2 = 20; };

	// capture by reference
	auto f1 = [&v1, &v2]() { v1 = 10; v2 = 20; };

	f1(); 

	cout << v1 << endl; // 10
	cout << v2 << endl; // 20
}

=============Capture Variable #2=============

#include <iostream>
#include <memory>
#include <string>
#include <tuple>
using namespace std;

int main()
{
	int v1 = 0, v2 = 0, v3 = 0;

	// capture by copy, capture by reference
	auto f1 = [v1]() {};
	auto f2 = [&v1]() {};
	auto f3 = [v1, &v2]() {};


	
	// default capture
	auto f4 = [=]() {};	// capture by copy , 모든 지역변수를 값으로
	auto f5 = [&]() {}; // capture by reference , 모든 지역변수를 레퍼런스로 
	auto f6 = [=, &v1]() {};
	auto f7 = [&, v1]() {};
	//auto f8 = [=, v1]() {}; // error



	auto f9  = [x = v1, v2 = v2, v3]() {}; // 이름 바꿀수 있음
	auto f10 = [v1, y = v2, &r = v3]() {};

	

	string s = "hello";
	auto f11 = [s1 = move(s)] ()  { };

	f11();
	cout << s << endl; // empty string 자원이 move 되었으니,


	unique_ptr<int> p(new int);
	auto f12 = [p = move(p)]() {};
}



void foo(int a, int b)
{
	//int a, b;
	auto f = [a, b]() { return a + b; }// ok
	auto f = [=]() { return a + b; } // ok
}



template<typename ... Types> void goo(Types ... args)//가변인자 템플릿
{
	int x = 0;
	auto f = [=]() { auto t = make_tuple(args...); };
	auto f = [args...]() { auto t = make_tuple(args...); };
}


#include <iostream>
using namespace std;

class Test
{
	int data = 0;
public:
	void foo() // Test* const this
	{
		int v = 0;

		//auto f = [this]() { this->data = 10; };
		//auto f = [this]() { data = 10; };
        f();
		cout << data << endl; // 10
		// 멤버 데이타를 복사본으로 캡쳐 - C++17
		auto f = [*this]() mutable { data = 10; };
		f();
		cout << data << endl; // 0
	}
};

int main()
{
	Test t;
	t.foo();
}

=============Conversion=============
int main()
{

    int(*f)(int, int) = [](int a, int b)
    {
        return a+b;
    };

    int v = 0;
    // capture 구문을 사용하면, 함수포인터로 암시적 변환 될 수 없다.
    int(*f1)(int, int) = [v](int a, int b)
    {
        return a+b+v;
    };
}

=============lambda MISC=============

#include <iostream>
using namespace std;

// Concept Ts
//void foo(auto n) {}

int main()
{
	// generic lambda : C++14
	auto f1 = [](auto a, auto b)  { return a + b; };

	cout << f1(1, 2.1) << endl; // 3.1


	// nullary lambda
    auto f2 = [](){return 10; }; 
	auto f2 = [] {return 10; }; 


	// C++17 : () 함수를 constexpr 함수로..
	auto f3 = [](int a, int b) constexpr
	{
		return a + b; 
	};

	int y[f3(1, 2)];
	
}

#include <iostream>
using namespace std;

int main()
{
	auto f1 = [](int a, int b) { return a + b; };

	decltype(f1) f2; // error // default 생성자 부르는거라서 에러

	decltype(f1) f3 = f1; // ok.

	decltype(f1) f4 = move(f1); // ok

	
}


#include <iostream>
#include <functional>
using namespace std;

template<typename F, typename ... Types> 
decltype(auto) chronometry(F f, Types&& ... args)
{
	return f(std::forward<Types>(args)...);
}

int main()
{
	

}

//A FunctionObject type is the type of an object that can be used on the left of the function call operator.


=============람다 표현식 테크닉=============

#include <iostream>
using namespace std;

int main()
{
	auto f = [](int a, int b) { return a + b; };

	f(1, 2);
	f(1, 2, 3);
	f(1, 2, 3, 4);
}

    
#include <iostream>
using namespace std;

template<typename ... Types> class mi : public Types... // public lambda1, public lambda2
{
public:
	mi(Types&& ... args) : Types(args)... {} 

	// 기반 클래스의 특정함수를 사용할수 있게..
	using Types::operator()...;
};

int main()
{
	mi f([](int a, int b)        { return a + b; },			// class lambda1{}; lambda1();
	 	 [](int a, int b, int c) { return a + b + c; });    // class lambda2{}; lambda2();

	cout << f(1, 2) << endl; // 3
	cout << f(1, 2, 3) << endl; // 6
}

#include <iostream>

using namespace std;

template<typename ... Types> class mi : public Types...
{
    public:
    mi(Types... args){}
}

int main()
{
    mi f([](int a, int b) {return a + b;},          //class lambda1{}; lambda1();
        [](int a, int b ,int c){return a + b+ c;}); //class lambda2{}; lambda2();

    f(1,2);
    f(1,2,3);
}