https://github.com/codenuri/CPP1/tree/master/SECTION1/03_VARIABLE1
https://github.com/codenuri/CPP1/tree/master/SECTION1/04_VARIABLE2
=============c++ 표준 입출력을 사용하는 3가지 방법=============
1. fully Qualified name :: 권장방법..
2. using declaration
3. using directive

C언어와는 다른 C++변수의 특징
1. 함수의 "중간에서 변수 선언" 가능
2. 구조체를 사용할 때 "Struct를 표기하지 않아도" 된다.
3. 구조체를 만들 때 "멤버를 초기화" 할 수 있다.
4. "2진수 표기법", "자릿수 표기법"
    int n1 = 0b00; int n2 = 1'000'000;

일관된 초기화
1. 변수를 초기활 할때 중괄호를 사용해서 초기화하는 것
    -- 중괄호 초기화(brace-init)이라고도 표현

기존 초기화 방법의 문제점
1. 변수의 타입/종류에 따라 초기화 방법이 다르다
    =값, (값), {값}
2. 암시적 형 변화에 따른 데이터 손실이 발생할 수 있다.

일관된 초기화의 장점
1. 모든 종류의 변수를 초기화 할때 하나의 방식으로 초기화 할 수 있다.
    데이터 손실이 발생하는 모든 코드는 컴파일 에러가 발생한다.
2. 데이터 손실이 발생할 경우 컴파일 에러 발생 :: prevent narrow

일관된 초기화 문법과 함수 인자
1. 함수의 인자로 중괄호를 사용한 초기값을 전달할 수 있다.
    goo({1,2});

직접 초기화 (direct initialization)
    int n(0); int n{0};
복사 초기화 (copy initialization)
    int n = 0; int n = {0};
explicit 생성자를 가지는 타입은 직접 초기화만 가능하다.

struct Point
{
    int x;
    int y;
};
void foo( int   n) {} // int n = 10
void goo( Point p) {}
int main()
{
    /*
    int n1 = 10;
    int n2(10);  // C++
    
    int x[2] = {1,2};
    Point pt = {1,2};
    
    int n3 = 3.4;
    char c = 300;
    */
    foo(10);
    foo({10}); // 
    int n1 = {10};
    int n2{10};  // C++
    
    int x[2] = {1,2};
    Point pt = {1,2};
    goo({1,2});
    
    int n3 = {3.4}; // error
    char c = {300}; // error

}


=============auto / decltype=============
1. 변수의 타입을 컴파일러가 결정하는 문법
--> 컴파일 시간에 결정 되므로 실행시간 오버헤드는 없다.
2. auto 
--> 우변의 수식으로 좌변의 타입을 결정
--> 반드시 초기값(우변식)이 필요하다
3. decltype :: decltype(n1) n3;
--> ()안의 표현식을 가지고 타입을 결정
--> 초기값이 없어도 된다.

배열과 타입 추론
1. auto 
    우변이 배열이면 요소를 가리키는 포인터 타입으로 타입을 결정된다.
2. decltype 
    ()안의 표현식이 배열이면 ()안의 표현식과 완전히 동일한 배열 타입으로 결정
    이 경우 동일 표현식으로 초기화 할 수 없다.
decltype(x) d2; // int d2[3]로 추론
decltype(x) d3 =x; // int d3[3] = x; 컴파일 에러

3. auto와 deltype은 표현식이 따라 타입이 다르게 결정 되는 경우가 있다.
int y[2] = {1,2};
auto a4 = y[0]; // int
decltype(y[0]) d4; // int 가 아니고 int&

decltype과 함수 호출식

#include <iostream>
#include <typeinfo>

int foo(int a, double d)
{
     return 0;
}

int main()
{
    foo(1, 3.1);
    
    decltype( foo )  d1; // 함수 타입 - int(int, double)
    decltype( &foo ) d2; // 함수 포인터 타입- int(*)(int, double)
    decltype( foo(1, 3.1) ) d3; // 함수 반환 타입 - int
    // 실제로 함수가 호출되는 것은 아님 unevaluated expression
    
    std::cout << typeid(d1).name() << std::endl;
    std::cout << typeid(d2).name() << std::endl;
    std::cout << typeid(d3).name() << std::endl;
    
    
    const int c = 0;
    std::cout << typeid(c).name() << std::endl; // 
    
}

using vs typedef
--> typedef는 타입의 별칭만 만들 수 있다.
--> using은 타입 뿐 아니라 템플릿의 별칭도 만들 수 있다.
--> template alias라고도 함
//typedef int DWORD;
//typedef void(*F)(int, int);

using DWORD = int;
using F = void(*)(int, int);


int main()
{
    DWORD n; // int n
    F f;     // void(*f)(int, int)
}



=============constexpr=============
1. 컴파일 시간 상수를 만드는 새로운 키워드
    --> 컴파일 시간에 결정되는 상수 값으로만 초기화 가능
상수도, 컴파일 시간에 결정되는 경우도 있고, 실행시간에 결정되는 경우도 있다.

const vs constexpr
1. const
    --> 컴파일 시간 상수와 실행시간 상수를 모두 만들 수 있다.
    --> 변수 값으로 초기화 할 수 있다.
    int s1=10;
    const int s2= 10; // 컴파일 시간 상수, 배열 크기
    const int s3 = s1; // 실행 시간 상수, 배열 크기 안됨
2. constexpr
    --> 컴파일 시간 상수만 만들 수 있다.
    --> 컴파일 시간에 계산될 수 있는 값으로만 초기화 가능
    --> 텀플릿 인자로 사용될 수 있다.
    constexpr int c3 = 10; // ok
    constexpr int c4 = n; //error

=============structured binding  =============
1. 구조체 또는 배열에서 각 멤버의 값을 꺼낼때 사용
2. 타입은 반드시 auto를 사용해야 한다.
const auto [x, y] = pt ==> 여기서 x를 일반적인 변수라고 생각해야 됨.

#include <iostream>

struct Point
{
    int x{10};
    int y{20};
};

int main()
{
    Point pt;
    
    //int x = pt.x;
    //int y = pt.y;
    
    //auto [x, y] = pt;
    
//    int arr[2] = {1,2};
//    auto [x,y] = arr;

    //int [x, y] = pt; // error
    
    const auto [x, y] = pt; // ok
    //const auto [x, y] = pt; // ok
    
    //int x = 10; // error
    
    std::cout << x << ", " << y << std::endl;
}

=============c언어와 c++언어에서의 문자열 처리 방법=============
1. c언어에서의 문자열
char* 또는 char 배열 사용
배입 또는 비교시 문자열 전용 함수를 사용해야한다.
문자열 연산이 직관적이지 않다.
string.h or cstring

2. c++언어에서의 문자열
std::string 타입 (STL의 string 클래스)를 사용
<string> 헤더
문자열관련 연산이 정수형 변수처럼 직관적으로 사용 할 수 있다.

string을 const char*로 변환하려면 c_str() 멤버함수를 사용한다.