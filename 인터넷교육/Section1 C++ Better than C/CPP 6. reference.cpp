https://github.com/codenuri/CPP1/tree/master/SECTION1/08_REFERENCE

=============reference=============

변수
    --> 메모리의 특정 위치를 가리키는 이름
    --> 코드안에서 해당 메모리에 접근하기 위해서 사용

레퍼런스 변수
    --> 기존 변수(메모리)에 또 다른 이름(alias)를 부여하는 것
#include <iostream>

int main()
{
    int n = 10;
    n = 20;
    int& r= n; //reference
    r = 30; // n =30
    //&n == &r
}

함수 인자 전달 방식

#include <iostream>

void f1(int n)  { ++n;}
void f2(int* p) { ++(*p);}
void f3(int& r) { ++r;}   // int& r = c

int main()
{
    int a = 0, b = 0, c = 0;
    
    f1(a);
    f2(&b); // b가 변경될수 있다고 예측가능.
    f3(c);  // 선언부를 보기 전까지 예측하지 못함...
    
    std::cout << a << std::endl; // 0 call by value : 원본을 수정할 수 없다.
    std::cout << b << std::endl; // 1 call by reference(c), call by pointer(c++) : 원본을 수정 할 수 있다.
    std::cout << c << std::endl; // 1 call by reference : 원본을 수정 할 수 있다.
    
    int* p = &n;
    int& r = n;
}

포인터와 레퍼런스
1. 유사한 점
    --> 기존 변수(메모리)를 가리킨다.
2. 차이점
포인터::초기화 : 변수 주소로 초기화 초기값 생량 가능
레퍼런스::초기화 : 변수 이름으로 초기화 초기값이 반드시 필요
포인터::요소접근 : *연산자 사용
레퍼런스:요서접근 : 연산자가 필요없다.
포인터:null : null값을 가질 수 있다.
레퍼런스:null : null값을 가질 수 없다.
포인터:주소출력 : 포인터 변수의 주소
레퍼런스:주소출력 : 기존 변수와 동일 주소

#include <iostream>

int main()
{
    int n = 10;
    
    int* p1 = &n;
    int& r1 = n;
        
    int* p2 = 0; // null pointer 가능.
    // int& r2;     // error. 
    
    *p1 = 20;
    r1 = 20; // 자동 * 연산되는 포인터
    
    if ( p1 != 0 ) {}
    if ( r1 != 0 ) {} // r1은 if 문으로 조사할필요 없다.
    
    std::cout << &p1 << std::endl;
    std::cout << r1 << std::endl;

    return 0;
}


=============const reference=============
const reference 인자
1. call by value의 특징
--> 인자로 전달된 객체의 "복사본이 생성"된다.
--> 원본 객체를 밴경할 수 없다 - "안전"하다
--> 하지만, 복사본에 대한 오버헤드가 있다.

2. 인자의 값을 변경하지 못하는 함수를 만들려면
--> call by value보다 const reference를 사용 하는 것이 좋다.

3. const reference의 장점
--> 인자에 대한 "복사본을 만들지 않는다."
--> "복사 생성자와 소멸자가 호출되지 않는다."

#include <iostream>

struct Date
{
    int year;
    int month;
    int day;
};

//void foo(Date d) // call by value 
void foo(const Date& d) // const reference --> 구조체인 경우엔 훨씬 유리함
{
    // d.year = 1000; // error
}

int main()
{
    Date date = {2020, 3, 28};
    
    foo(date);
    
    std::cout << date.year << std::endl; // 2020
}

함수 인자 전달 방법 정리
1. 함수 안에서 인자의 값을 변경하고 싶다면
--> 포인터 또는 참조 사용해서 전달 받는다.
2. 함수 안에서 인자의 값을 변경하지 못하게 하려면
-- primitive type :: call by value가 좋다 , int ..
-- user define type :: const reference가 좋다 struct..

#include <iostream>

void foo(int x) // call by value
//void foo(const int& x) // const reference
{
}

int main()
{
    int n = 10;
    
    // foo 함수에서는 절대로 n의 값을 변경하면 안된다.
    foo(n);
    
    std::cout << n << std::endl; // 반드시 10이 나와야 한다.
}

=============reference return=============
referecne와 함수 반환값

struct Point
{
    int x;
    int y;
    
    //Point() {}
};

void f1(Point  pt) {} // 복사본 생성
void f2(Point& pt) {} // 복사본 생성 안함.

Point pt = {0,0};

//Point foo()  // 값 타입반환  return by value
Point& foo()  // return by reference
{
     return pt; 
}    

int main()
{
    foo().x = 10;
    
    // pt.x => 10
}

** 지역변수를 참조로 반환하면 안된다.

#include <iostream>

int x = 10;

int  f1() { return x;} // 값 리턴
int& f2() { return x;} // x라는것을 리턴, 메모리를

int& f3()
{
    int n = 10;
    return n;
}

int main()
{
//    f1() = 20; // 10 = 20
    f2() = 20; // x = 20 ok
    
    std::cout << x << std::endl; // 20
}

=============rvalue reference=============
핵심 정리
1. rvalue : 등호(=)의 오른쪽에만 올 수 있는 것
    --> move semantics, perfect forwarding
2. lvalue : 등호(=)의 오른쪽과 왼쪽에 모두 올 수 있는 것
lvalue reference : lavalue만 가르킬 수 있다.
const lvalue reference : lvalue 와 rvlue를 모두 가르킬 수 있다.
rvalue reference : rvalue만 가르킬 수 있다 : C+11에서 추가
int main()
{
    int v1 = 0, v2 = 0;
    
    v1 = 10; // ok       10 : rvalue
    10 = v1; // error    v1 : lvalue
    v2 = v1; 
    
    
    // lvalue reference
    int& r1 = v1; // ok 
    int& r2 = 10; // error

    const int& r3 = v1; // ok 
    const int& r4 = 10; // ok
    
    // rvalue reference : rvalue 만 가르킨다.
    int&& r5 = v1; // error. 
    int&& r6 = 10; // ok
}
