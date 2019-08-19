https://github.com/codenuri/CPPINTERMEDIATE/tree/master/201_CPP14
=============delete/default function=============
1. 함수 삭제 문법(delete function)
    C++11에서 추가된 문법, 함수를 삭제 달라는 문법
    함수를 제공하지 않을 때, 선언만 제공할 때, 삭제 할 때의 차이점
        
        제공하지 않을 때 : 함수 호출 시 인자가 변환 가능한 타입을 가지는 동일 이름의 다른 함수 호출
        선언만 제공 할 때 : 함수 호출 시 링크 에러
        삭제 할 때 : 함수 호출 시 컴파일 에러



#include <iostream>
using namespace std;

void foo(int n)
{
	cout << "foo(int)" << endl;
}

//void foo(double); // 선언만, 컴파일러는 어디에 있을것이라고 생하고 linker에게 넘겨야겠다고 하고 에러를 내지 않음
                    // 링커 에러 발생

//void foo(double) = delete; //이렇게 사용되면 Error 낼 수 있다.

int main()
{
	foo(3.4); // foo(double)
}

2. 함수 삭제 활용
    일반 함수 삭제
    함수 템플릿을 만들 때 특정 타입에 대해서 삭제
    멤버 함수 삭제, 복사 생성자 외 대입연산자를 삭제하는 기법이 널리 사용됨
    싱글톤, 복사 금치 스마트 포인터(unique_ptr), mutex

//goo(3.4);를 선언하였을때, 일반함수가 선언되어 있으면 템플릿 보다 먼저 간다.

template<typename T> void goo(T a)
{
}

//void goo(double) = delete; // Error

class Mutex
{
public:

	Mutex(const Mutex&) = delete;
	void operator=(const Mutex&) = delete;

//private: // 옛날 해결법 문법이 아니고 tech
//	Mutex(const Mutex&);
};

int main()
{
	goo(3.4);

	Mutex m1;
	Mutex m2 = m1; // 복사 생성자.
}


3. default function
    함수 삭제와 반대 개념으로 함수의 디폴트 구현을 제공해 달라는 ㅍ현
    사용자가 생성자의 구현을 제공할 때 와 default 구현을 제공 받을 때의 차이점
    Point(){}        Trivial x   멤버가 0으로 초기화 되지 않음
    Point()=default  Trivial O   멤버가 0으로 초기화 됨


#include <iostream>
#include <type_traits>
using namespace std;

struct Point
{
	int x, y;

	Point() {} // 사용자가 생성자 제공. default
            // trivial 하지 않다, 보통 소스를 구분할 때는 Point() 만 남겨 두기 때문에 컴파일러가 판단을 하지 못한다.
 
	//Point() = default; // 컴파일러가 제공. default

//	Point(const Point& ) = default;
//	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point p1{};  

	cout << p1.x << endl; // default 생성자 - 0
						  // 사용자가 제공 - garbage

	cout << is_trivially_constructible<Point>::value
		 << endl;
}

=============noexcept============= 17
1. 예외가 없음을 알리는 문법
    void foo() throw() = C++98/03, depreacted
    void foo() noexcept
    void foo() noexcept(true)

2. noexcept
    함수가 예외가 없음을 나타냄. C++11에서 도입
    noexcept로 선언된 함수에서 예외가 발생하면 std::terminate가 호출됨
    예외가 없음을 표기하면 보다 좋은 최적화 코드를 얻을 수 있다.
    예외가 있는지 없는지 조사 할 수 있게 된다.

#include <iostream>
using namespace std;
/*
// c++98
int foo()  // 예외가 있을수도 있고, 없을수도 있다.
int foo() throw(int) // 예외가 있다는 의미.
int foo() throw()    // 예외가 없다는 의미.
{
	throw 1;
	return 0;
}
*/
// C++11
//void goo() noexcept(true) // 예외가 없다.
void goo() noexcept // 위와 동일.
{
	throw 1;
}

void goo() 
{
	throw 1;
}

int main()
{
	goo();

	try
	{
		goo();
	}
	catch (...)
	{
		cout << "exception..." << endl;
	}
}

3. noexcept
    noexcept sepcifier - 지정자
    noexcept operator - 연산자

4. 함수가 예외가 없음을 조사하는 방법
    noexcept operator사용
    type traits 사용 - is_nothrow_xxxx<T>::value
    move_if_noexcept - "move semantics"
    실행 시간이 아닌 컴파일 시간에 조사


#include <iostream>
using namespace std;

void algo1()
{
	// 빠르지만 예외 가능성이 있다.
}

void algo2() noexcept  // 지정자
{
	// 느리지만 예외가 나오지 않는다.
}

class Test
{
public:
	Test() noexcept {}
};

int main()
{
    //예외있는지 없는지 조사
	bool b1 = noexcept(algo1()); // 0. 연산자
	bool b2 = noexcept(algo2()); // 1

	cout << b1 << ", " << b2 << endl;

	bool b3 = is_nothrow_constructible<Test>::value;
	cout << b3 << endl;

}


=============scoped enum=============

1. enum 상수의 단점을 개선한 새로운 enum 상수 문법
2. 기존 enum 상수의 단점
    타입의 이름 없이 사용 가능 - Unscoped enum 
    요소의 타입을 지정할 수 없다.

3. 요소의 타입을 알아내는 방법 = C++11
    <type_traits>
    underlying_type<Color>::type
    underlying_type_t<Color>

#include <iostream>
#include <type_traits>
using namespace std;

enum Color { red = 1, green = 2 };

int main()
{
	int n1 = Color::red;
	int n2 = red;
	int red = 0;
	int n3 = red;

	cout << typeid(underlying_type_t<Color>).name()
		<< endl;

}

4. C++11에 도입된 새로운 enum 상수
    enum class Color : char { red = 1, green = 2 };
    요소의 타입을 지정할 수 있다.
    다른 타입으로 암시적 형변환 되지 않는다. 명시적 변환 필요
    반드시 타입의 이름과 함께 사용해야 한다. = Scoped enum


#include <iostream>
#include <type_traits>
using namespace std;

// C++98/03
//enum Color { red = 1, green = 2 };

// C++11
enum class Color : char { red = 1, green = 2 };

int main()
{
//	int n1 = Color::red; // error

	Color n1 = Color::red; // ok
	int   n2 = static_cast<int>(Color::red); // ok

	int n3 = red; // error

//	int red = 0;
//	int n3 = red;

	cout << typeid(underlying_type_t<Color>).name()
		<< endl;

}
=============user define literal=============
1. literal 종류
    integer literals
    floating point literals
    character literals 
    string literals
#include <iostream>
using namespace std;

int operator""_k(unsigned long long v)
{
	return 1000 * v;
}

int main()
{
	int n1 = 10; // meter
	int n2 = 10_k;// 10000  operator""k(10)

	cout << n2 << endl; /// 10000
}

2. user define literal 
    literal 뒤에 사용자 정의 접미사 suffix를 붙이는 문법
    literal이 값 뿐 아니라 단위를 가질 수 있게 된다.
    operator""suffix 
    사용자가 제공하는 접미사는 반드시 "_"로 시작해야 한다.
    _가 붙지 않은 것은 C++ 표준 라이브러리를 위해서 예약 되어 있음.

#include <iostream>
using namespace std;

// _ : 사용자 사용가능.
// _로 시작하지 않은것 : reserved

int operator""_k(unsigned long long v)
{
	return v * 1000;
}

int main()
{
	int n1 = 10_k; // operator""k(10)

	cout << n1 << endl; // 10000
}


3. user define literals과 함수 인자

4. user define literal과 user define type
    사용자 정의 접미사를 사용해서 literal로 부터 객체를 생성할 수 있다.

#include <iostream>
using namespace std;

class second
{
	int value;
public:
	second(long long s) : value(s) {}
};

class minute
{
	int value;
public:
	minute(long long s) : value(s) {}
};

second operator""_s(unsigned long long v)
{
	return v;
}

minute operator""_m(unsigned long long v)
{
	return v;
}

int main()
{
	second n1 = 10_s; 
	minute n2 = 10_m;
}

5. literal operators in the Standard library
    std::literals namespace
    std::complex, std::chrono, std::string, std::string_view
#include <iostream>
#include <string>
#include <chrono> // 시간
using namespace std;
using namespace std::chrono;
//using namespace std::literals::string_literals;
//using namespace std::literals::chrono_literals;
using namespace std::literals;

void foo(string s)      { cout << "string" << endl; }
void foo(const char* s) { cout << "char*" << endl; }

int main()
{
	foo("hello"); // char*
	foo("hello"s); // string operator""s("hello")

	seconds s1 = 10s;
	minutes m1 = 10min;

	//minutes m2 = 120s; // Ä³½ºÆÃ ÇÊ¿ä..
	seconds s2 = 10min;
	cout << s2.count() << endl; // 600
}


