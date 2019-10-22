https://github.com/codenuri/CPPINTERMEDIATE/tree/master/402_FUNCTOR
=============functor=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// functor1.cpp
// Function Object(functor)
class Plus
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	Plus p; // Plus 타입의 객체

	int n = p(1, 2); // p.operator()(1,2), 객체를 함수타입으로..

	cout << n << endl; // 3

	// a + b;	// a.operator+(b)
	// a - b;	// a.operator-(b)
	// a();		// a.operator()()
	// a(1,2);	// a.operator()(1,2)
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

template<typename T> struct Plus
{
	T operator()(T a, T b) const 
	{
		return a + b;
	}
};

void foo(const Plus<int>& p) 
{
	int n = p(1, 2);
} 

int main()
{
	Plus<int> p;

}

=============functor 장점=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <algorithm>	
#include <iostream>
using namespace std;

// 변하지 않은 전체 흐름속에서.. 변경되어야 하는 부분을 분리한다.
// qsort() 함수와 유사한 방법

// 일반함수는 자신만의 타입이 없다.
// signature가 동일하면 모두 같은 타입이다.
void Sort(int* x, int n, bool(*cmp)(int, int))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			//	if (x[i] > x[j])

			if (cmp(x[i], x[j]))
				swap(x[i], x[j]);
		}
	}
}

inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10, cmp2);
}



/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

// 함수 객체는 자신만의 타입이 있다.
// signature가 동일 해도 모든 함수객체는 다른 타입이다.

struct Less
{
	inline bool operator()(int a, int b) const  {	return a < b; }
};

struct Greater
{
	inline bool operator()(int a, int b) const { return a > b;	}
};

//void Sort(int* x, int n, bool(*cmp)(int, int))

//void Sort(int* x, int n, Less cmp )

// 정책 변경가능하고 정책이 인라인 치환되는 함수. ( 템플릿 + 함수 객체)
template<typename T> void Sort(int* x, int n, T cmp)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cmp(x[i], x[j]))
				swap(x[i], x[j]);
		}
	}
}
int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Less	f1; // 타입 Less
	Greater f2; // 타입 Greater
	Sort(x, 10, f1); // 
	Sort(x, 10, f2); // 
}

=============function vs functor=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <algorithm>
using namespace std;

// 일반 함수
inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

// functor
struct Less    { inline bool operator()(int a, int b) const { return a < b; }};
struct Greater { inline bool operator()(int a, int b) const { return a > b; }};

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// STL sort : 모든 인자가 템플릿으로 되어 있다
	// 1. 비교정책으로 일반함수를 전달할때.
	// 장점 : 정책을 교체해도 sort()기계어는 한개이다. - 코드 메모리 절약
	// 단점 : 정책 함수가 인라인 치환될수 없다.
	sort(x, x + 10, cmp1); // sort( int*, int*, bool(*)(int, int)) 인 함수 생성.
	sort(x, x + 10, cmp2); // sort( int*, int*, bool(*)(int, int)) 인 함수 생성.

	// 2. 비교정책으로 함수객체 전달할때.
	// 장점 : 정책함수가 인라인 치환될수 있다 - 빠르다.!
	// 단점 : 정책을 교체한 횟수 만큼의 sort()기계어 생성.
	Less    f1;
	Greater f2;
	sort(x, x + 10, f1); // sort( int*, int*, Less) 인 함수 생성.
	sort(x, x + 10, f2); // sort( int*, int*, Greater) 인 함수 생성.
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <functional>  // less<>, greater<>
using namespace std;

//struct Less    { inline bool operator()(int a, int b) const { return a < b; } };
//struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	less<int> f1;
	sort(x, x + 10, f1);

	sort(x, x + 10, less<int>());
}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }
struct Less		{ inline bool operator()(int a, int b) const { return a < b; } };
struct Greater	{ inline bool operator()(int a, int b) const { return a > b; } };

template<typename T> void foo(T f)
{
	bool b = f(1, 2);
}
int main()
{
	foo(cmp1);
	foo(cmp2);
	foo(Less());
	foo(Greater());
}
// 문제 1. 컴파일 했을때 foo 함수는 몇개 생성될까요 ? 3개
// 문제 2. 각각의 foo 함수에서 f(1,2) 의 인라인 치환 여부는 ? 객체 넘긴것만.
// 문제 3. 컴파일했을때 foo를 제외한 함수의 갯수는 ?

=============상태를 가지는 함수=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <string>
#include <bitset>	
using namespace std;

int main()
{
	bitset<10> bs;

	bs.reset(); // 모든 요소를 0
	bs.reset(4); // 4번째 비트를 0으로

	bs[2] = 1;
	bs[1].flip(); // 1번째가 1
	// 0000000110

	string s = bs.to_string();
	unsigned long n = bs.to_ulong();

	cout << s << endl; // 0000000110
	cout << n << endl; // 6
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <bitset>
using namespace std;

// 0 ~ 9 사이의 중복되지 않은 난수를 리턴하는 함수.

// 일반함수 : 동작만 있고 상태가 없다.
// 상태를 관리하기 위해서 전역변수를 많이 쓰다보니깐, 상태에 따라서 전역변수가 늘어난다.
bitset<10> bs;
bitset<10> bs1;
void clear_random() { bs.reset(); }
int random()
{
	int v = -1;
	//static bitset<10> bs; // 10개가 0으로 초기화
	do
	{
		v = rand() % 10;
	} while (bs.test(v));

	bs.set(v);	
	return v;
}

int main()
{
	for ( int i = 0; i < 10; i++)
		cout << random() << " "; 
	random();
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <bitset>
using namespace std;


// 일반함수 : 동작만 있고 상태가 없다.
// 함수객체(fuctor) : 동작과 상태가 있다.
class Random
{
	bitset<10> bs; // 상태
public:
	Random() {	bs.reset(); // 모든 비트를 0으로,
                            // 상태를 초기화하기 위해서 생성자와 소멸자있음.
	}
	int operator()()
	{
		int v = -1;
		do
		{
			v = rand() % 10;
		} while (bs.test(v));

		bs.set(v);
		return v;
	}
};


int main()
{
	Random random;
	Random random1;
	for (int i = 0; i < 10; i++)
		cout << random() << " ";
	random();
}

=============함수 객체 요점정리=============
핵심정리
함수 객체(function Object, Functor)
    A functionObject type is the type of an object that can be used on the left of the function call operator
    ()연산자를 정의한 클래스
    함수 포인터, 멤버함수포인터등

일반함수와 함수 객체의 차이점
    일반함수는 자신만의 타입이 없다.
    Signature가 동일하면 모두 같은 타입이다.

    함수객체는 자신만의 타입이 있다.
    Signature가 동일해도 모든 함수 객체는 다른 타입이다.

함수 객체의 장점
    다른 함수의 인자로 사용 될때 인라인 치환 가능
    상태를 가지는 함수


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

// 함수 객체는 자신만의 타입이 있다.
// signature가 동일 해도 모든 함수객체는 다른 타입이다.

struct Less
{
	inline bool operator()(int a, int b) const 
	{
		return a < b; 
	}
};
struct Greater
{
	inline bool operator()(int a, int b) const 
	{ 
		return a > b; 
	}
};
template<typename T> void Sort(int* x, int n, T cmp)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cmp(x[i], x[j]))
				swap(x[i], x[j]);
		}
	}
}
int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Less	f1; 
	Greater f2; 
	Sort(x, 10, f1);  
	Sort(x, 10, f2); 
}
