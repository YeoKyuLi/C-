https://github.com/codenuri/CPPINTERMEDIATE/tree/master/201_CPP14
=============using=============
using - template alias

using vs typedef
    typedef : 타입에 대해서만 alias를 만들 수 있다.
    using : 타입 뿐 아니라 템플릿에 대한 별칭도 만들 수 있다.

using 문법 기본 모양
    using id = type-id;

    template <template-parameter-list>
    using id = type-id;
template<typename T> struct Point
{
	T x, y;
};

typedef Point Pixel; // ??? error

template<typename T> 
using Pixel = Point<T>;

//typedef int DWORD;
//typedef void(*FP)(int);

using DWORD = int;
using FP = void(*)(int);

int main()
{
	DWORD n; // int
	FP    p; // void(*p)(int)

	Point<int> p1;
	Pixel<int> p2; // Point<int> p2
}

using 활용
1. 타입에 대한 별칭
    using DWORD = int;
    using FP = void(*)(int);
    using ARR = int[3];
2. 템플릿에 대한 별칭
    template<typename T, typename U> using Duo = pair<T,U>
    template<typename T> using Ptr = T*;
3. 템플릿의 인자를 고정하는 방식
    template<typename T> using Pint = pair<T,T>
    template<typename T> using SET = set<T. greater<T>>;
4. 복잡한 표현을 단순하게
    template<typename T>
    using remove_pointer_t = typename remove_pointer<T>::type;
#include <type_traits>
#include <set>
using namespace std;

// 1. type alias
using DWORD = int;

// 2. template alias
template<typename T, typename U>
using Duo = pair<T, U>;

Duo<int, double> d1; // pair<int, double>

template<typename T> 
using Ptr = T*;

Ptr<int> p2; // int*


// 3. 
template<typename T>
using Point = pair<T, T>;

Point<int> p;   // pair<int, int>


// 4. 

template<typename T>
using remove_pointer_t =
			typename remove_pointer<T>::type;

template<typename T> void foo(T a)
{
	// T에서 포인터를 제거한 타입을 구하고 싶다.
	//typename remove_pointer<T>::type t; // C++11

	remove_pointer_t<T> t; // C++14 style
}

=============static_assert=============
1. assert 
    <cassert>
    assert(expression of scalar type)
    실행시간에 expr가 거짓이면 메시지를 출력하고 프로그램을 종료. (abort)
2. static_assert
    C++11에서 도입된 문법
    실행 시간이 아닌 컴파일 시간에 주어진 식(expression)을 조서해서 거짓이면 진단 메시지를 출력하고 컴파일을 멈춤
    컴파일 시간에 조사 가능한 상수 표현식만 사용 가능. 변수는 사용할 수 없다.
3. static_assert 기본 모양
    static_assert(bool_constexpr, message);
    static_assert(bool_constexpr); // C++17
    컴파일 타입에서 검사를 하니깐 멈출 수 있다.
#include <iostream>
#include <cassert>
using namespace std;

void foo(int age)
{
	assert(age > 0);
	static_assert(age > 0, "error");
	// ......
}

int main()
{
//	static_assert(sizeof(void*) >= 8,"error. 32bit");
//	static_assert(sizeof(void*) >= 16); // C++17 에러 메시지 생략가능

	foo(-10);
}

함수 공간이나 전역공간 내가 만들고 싶은곳에 만들 수 있다.

4. static_assert활용
    함수 안에 만들 수 도 있고, 함수 밖에 만들 수 있다.
    함수 또는 클래스 템플릿을 만들 때 Type_traits를 사용해서 T가 가져야 하는 조건을 static_assert로 조사하는 코드가 널리 사용됨
    static_assert를 잘 활용하면 가독성 높은 에러 메시지를 만들수 있다.
        코드가 방대해질수록 에러문장이 중요하기 때문이다.
#include <iostream>
#include <mutex>
using namespace std;

#pragma pack(1)
struct PACKET
{
	char cmd;
	int  data;
}; //8 byit (padding)
static_assert(
	sizeof(PACKET) == sizeof(char) + sizeof(int),
	"error, unexpected padding !");


template<typename T> void Swap(T& a, T& b)
{
	// T가 가져야하는 조건을 조사
	static_assert(is_copy_constructible<T>::value,
		"error. T is not copyable");

	T tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	mutex m1;
	mutex m2;
	Swap(m1, m2);
}
=============begin/end=============
non member begin/end
1. 반복자를 꺼내는 2가지 방법
    01 컨테이너의 멤버 함수 사용
        STL의 대부분의 컴테이너에 사용할 수 있지만, raw 배열에는 사용할 수 없다.
        auto p1 = c.being() c.end()
    02 멤버가 아닌 함수 사용
        STL의 컴테이너 뿐 아니라, raw 배열에도 사용 할 수 있다.
        auto p1 = begin(c), end(c)

2. 일반 함수 begin()/end()
    C++11부터 제공
    <iterator> 헤더 사용
    STL 컨테이너 뿐 아니라 raw 배열에서 사용 간으한 알고리즘을 만들 수 있다.
    C++11 : begin(), end()
    C++14 : cbegin(), cend(), rbegin(), rend(), crbegin(), crend()
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

// 컨테이너의 모든 요소를 출력하는 함수.
template<typename T> void show(T& c)
{
    // 아래 두개의 차이점...!
//	auto p1 = c.begin();
//	auto p2 = c.end();

	auto p1 = begin(c);
	auto p2 = end(c);

	while (p1 != p2)
	{
		cout << *p1 << endl;
		++p1;
	}
}

int main()
{
	list<int> c = { 1,2,3 };
	//vector<int> c = { 1,2,3 };
	
	show(c);

	int x[3] = { 1,2, 3 };

	show(x);

}

원리
2. 멤버가 아닌 begin()/end()함수의 원리
    인자로 STL 컨테이너를 받는 것과 배열을 받는 버전을 별도로 제공

#include <iostream>
#include <list>
#include <vector>
using namespace std;

// container version.
template<typename C> 
constexpr auto begin(C& c) -> decltype(c.begin()) //후위형 반환 타입, 선언이 먼저되어있는 경우
{
	return c.begin();
}
template<typename C>
constexpr auto end(C& c) -> decltype(c.end())
{
	return c.end();
}

// arr version
template<typename T, std::size_t N>
constexpr T* begin(T(&arr)[N])
{
	return arr;
}
template<typename T, std::size_t N>
constexpr T* end(T(&arr)[N])
{
	return arr + N;
}



int main()
{
	list<int> s = { 1,2,3 };
	int x[3]    = { 1,2,3 };

	auto p1 = begin(s);
	auto p2 = begin(x);
}

=============ranged-for=============
1. range for
    C++1
    STL 컨테이너, raw 배열에 있는 모든 요소에 접근하기 위한 편리한 방법
    java, c#등의 foreach()와 유사한 개념
#include <iostream>
#include <list>
using namespace std;

int main()
{
	//int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// foreach() : java
	for ( auto& n : s ) // 배열, STR 컨테이너
		cout << n << endl;

//	for (int i = 0; i < 10; i++)
//		cout << x[i] << endl;
}

2.range for 원리
    begin()/end()를 사용해서 얻어진 반복자를 통해서 요소에 접근하는 것

3. user define type과 range for
    STL이나 배열이 아닌 사용자가 만든 컨테이너의 경우, begin()/end() 함수를 일반 함수 또는 멤보 함수로 제공하면 range for에 넣을 수 있다.


#include <iostream>
#include <list>
using namespace std;

struct Point3D
{
	int x = 1;
	int y = 2;
	int z = 3;

};
int* begin(Point3D& p3) { return &(p3.x); }
int* end(Point3D& p3) { return &(p3.z)+1; }

int main()
{
	Point3D p3;

	for (auto& n : p3)  // begin(p3)
		cout << n << endl;
}


/*
int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
//	for (auto& n : s) 
//		cout << n << endl;
//컴파일 해셕
	for ( auto p = begin(s); p != end(s); ++p )
	{
		auto& n = *p;
		cout << n << endl;
	}
}
*/