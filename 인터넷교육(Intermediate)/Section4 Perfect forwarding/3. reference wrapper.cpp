https://github.com/codenuri/CPPINTERMEDIATE/tree/master/304_PERFECT_FORWARDING
=============std::bind=============

핵심정리

1. std::function
    함수 포인터역활을 하는 템플릿
    일반 함수 뿐 아니라 함수 객체, 람다 표현식 등도 담을 수 있다.
    bind와 함께 사용하면 인자의 개수가 다른 함수(함수 객체)도 사용할 수 있다.

2. std:: bind
    함수 또는 함수 객체의 인자를 고정할 때 사용한다.
    인자의 값을 고정 할 때 값 방식을 사용한다. 
        --> life cycle이랑 관련있음, bind하는 시점과 실제롤 사용하는 시점이 다르므로, 참조로 하는 경우 error 유발
    참조로 인자를 고정하려면 ref() or cref()를 사용한다.


#include <iostream>
#include <functional>

using namespace std;
void foo(){}
void goo(int a){}

int main()
{
    void(*f)() = &foo; // 일반함수 포인터, 인자없는것만 받을 수 있다.
    // f= &goo; error

    function<void()> f2 = &foo;

    f2(); // foo()
    f2 = bind(&goo, 5);
    f2(); // goo(5);
}



#include <iostream>
#include <functional>

using namespace std;

void goo(int& a){ a = 30;}

int main()
{
    int n = 0;

    function<void()> f;
    f = &goo;
    f = bind(&goo, n); // 값으로 고정 // 0
    f = bind(&goo, ref(n)); // 참조로 고정 //30
    
    f(); // goo(n)
    cout << n << endl; // 30 ? 실행결과는 0,
}

=============reference_wrapper=============

void foo(int& a) { a = 30};
template<typename F, typename T>
void chronometry(F f, T& arg)
{
    f(arg);
}

int main()
{
    int n = 0;
    chronometry(&foo, n); // n의 파괴를 걱정할 필요가 없으니깐 참조로 받아도 된다.

    function<void()> f;
    f = bind(&foo, n);
    f();
}


// 값을 넘길때 복사본을 안만드는 방법은 참조로 받거나, 주소값을 넘기는것이다.
// 핵심 1, 주소를 전달한다.
// 햄심 2, 포인터가 참조로 암시적 형변환 되면 가능하다.
void foo(int& a) { a = 30};
template<typename F, typename T>
void chronometry(F f, T arg)
{
    f(arg);
}

int main()
{
    int n = 0;
    chronometry(&foo, &n); 


}

1. reference_wrapper
    참조와 유사하게 동작하는 클래스 템플릿
    참조로 변환 간으한 포인터
2. ref, cref
    reference_wrapper를 생성하는 helper함수
#include<iostream>
using namespace std;

template<typename T> struct xreference_wrapper
{
    T* ptr;
public:
    xreference_wrapper(T& r) : ptr(&r){}

    operator T&{return *ptr; }
};

int main()
{
    int n = 0;
    xreference_wrapper<int> ref(n); // 결국 주소 보관
    int& r = ref; // ref.operator int&()

    r = 30;
    cout << n << endl; //30
}



#include<iostream>
using namespace std;

template<typename T> struct xreference_wrapper
{
    T* ptr;
public:
    xreference_wrapper(T& r) : ptr(&r){}

    operator T&{return *ptr; }
};


void foo(int& a) { a = 30};
template<typename F, typename T>
void chronometry(F f, T arg)
{
    f(arg);
}
template<typename T>
xreference_wrapper<T> xref(T& obj)
{
    return xreference_wrapper<T>(obj);
}

int main()
{
    int n = 0;
    xreference_wrapper<int> r(n); // n address
    chronometry(&foo, r); 

    chronometry(&foo, xreference_wrapper<int>(n)); 

    chronometry(&foo, xref(n)); // 주소를 보관하고 있는데 다시 참조로 바꿔서 값을 바꿀수 있도록,

}

1. 일반참조
    대입시 참조가 아닌 값이 이동한다.
2. reference_wrapper
    값이 아닌 참조가 이동한다.
    이동가능한 참조




