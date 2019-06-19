https://github.com/codenuri/CPP1/tree/master/SECTION1/05_FUNCTION1
https://github.com/codenuri/CPP1/tree/master/SECTION1/06_FUNCTION2
=============Default parameter=============
    주의사항
    1. 함수의 마지막 인자부터 차례대로 디폴트 값을 지정해야 한다.
    2. 함수를 선언과 구현으로 분리 할때는 함수 선언부에만 디폴트 값을 표기해야한다.
        --> 선언과 구현에 모두 디폴트 값을 표기하면 컴파일 시간 에러
        --> 선언에 표기하지 않고 구현에만 표기하면 함수 호출시 디폴트 값을 사용할 수 없다.
void setAlram(int h, int m = 0, int s =0){}
void foo(int a= 0, int b){} // error
void a(int a= 0, int b =0);
void b(int a =0, int b =0);
int main(){
    setAlram(3); // 3,0,0
}
void a(int a=0, int b=0){}//error
void b(int a, int b){} //OK

=============Function Overloading=============
1. C언어에서는 동일한이름의 함수를 2개 이상 만들 수 없다.
2. C++언어에서는 동일한 이름의 함수를 여러 개 만들 수 있다.
--> 단, 함수 호출 시 구별할 수 있도록, 인자의 개수나 인자의 타입이 달라야 한다.
3. 함수 사용자 입장에서는 동일한 함수처럼 생각하게 되므로 일관된 형태의 라이브러리를 구축할 수 있다.
4. C언어를 제외한 대부분 최신 언어들이 지원하는 특징

주의사항
1. 인자의 개수가 달라도 "디폴트 값"이 있는 경우는 주의해야 한다.
    void f3(int a) {}
    void f3(int a, int b = 0) {} // error
    f3(10);
2. 함수 반환 타입만 다른 경우는 오버로딩 할 수 없다.
    int    f4(int a) { return 0;}
    double f4(int a) { return 0;} // error

    f4(10);
3. 정수 타입과 포인터 타입에 대한 오버로딩은 사용하지 않는 것이 좋다 ==> 혼동을 줄 수 있다.
    void f5(int   n) {}
    void f5(char* s) {}

    f5(0); // f5(int);
    f5((char*)0);
    f5(nullptr); // f5(char*) // C++11
    nullptr :: null pointer,pointer literal

=============Template=============
기본개념
1. 타입만 다르고 구현이 동일하거나 유사한 함수가 여러개 있다면, 개발자가 직접 만들지 말고 컴파일러가 함수를 생성하게 하자
2. 컴파일러가 함수를 생성할 때 사용할 함수의 틀(template)이 있어야 한다.
3. 개발자는 함수 템플릿을 만들고, 컴파일러가 템블릿을 사용해서 필요한 함수를 생성하게 한다.

템블릿을 만들고 사용하는 방법
1. 함수가 아닌 함수를 만드는 틀
2. 템블릿을 사용하는 코드를 보고 컴파일러가 컴파일 시간에 필요한 타입의 함수를 생성
3. 컴파일 된 기계어 코드에는 int, double 버전의 square함수가 따로 존재

1. template parameter 
--> 컴파일 시간에 전달되어서 함수가 생성
--> 함수가 생성되는 과정을 템플릿 인스턴스화(template instantiation)이라고 한다.
2. call parameter 
--> 실행시간에 함수에 전달
3. template parameter를 표기할때 typename or class 사용가능
4. 함수 템플릿 사용시 타입을 명시적으로 지정하지 않으면 "함수 호출 인자를 보고 컴파일러가 결정 (type deduction) 추론/연역"

template<typename T> // template parameter
// template<class T> // 똑같은 의미이다.
T square(T a)       // call parameter
{
    return a * a;
}

int main()
{
    square<int>(3);     // int square(int a) 함수 생성
    square<double>(3.3);// double square(double) 함수 생성

    square(3);     // 컴파일러가 결정 (type deduction)
    square(3.3);// 컴파일러가 결정 (type deduction)
}


클래스(구조체) 템블릿
1. 함수 뿐 아니라 "클래스(구조체)도 템플릿"으로 만들 수 있다.
2. "C++17"부터는 생성자가 있으면 "템블릿 파라미터 전달을 생략"할 수 도 있다.

template<typename T>
struct Point
{
    T x;
    T y;
};

int main()
{
    square(3);
    
    Point<int> pt;
    
    pt.x = 1;
    pt.y = 1;
    
    Point<double> pt2;
    
}

=============inline function=============
핵심개념
1. 함수 반환 타입 앞에 "inline"을 표기한 함수
2. 함수 호출 시 함수로 이동하지 않고 "함수의 기계어 코드를 치환"한다.
3. 장점
==> 실제 함수 호출 보다 "빠르다."
4. 단점
--> 치환되는 함수가 큰 경우 "목적 코드가 커질 수 있다."

컴파일러와 인라인, Linkage 
1. "어셈블리 소스 코드"를 확인하는 방법
cl *.cpp /FAs --> *.asm
g++ *.cpp -S --> *.s
2. 인라인 함수의 실제 치환 여부는 "컴파일러 종류", "컴파일 옵션", "함수 크기" 등에 따라 달라진다.
3.
int add1(int a, int b)
{
    return a + b;
}

inline int add2(int a, int b)
{
    return a + b;
}

int main()
{
    int n1 = add1(1,2); // 호출
    int n2 = add2(1,2); // 치환
}

=============delete function =============
1. 함수를 삭제하는 방법
2. 삭제된 함수를 호출하면 컴파일 시간에 오류가 발생한다.
- 함수를 삭제하는 이유는 무엇일까?
- 함수를 제공 하지 않는 것과 삭제하는 것은 어떤 차이가 있을까?
- 이 문법은 언제 어떻게 활용 할까?
void foo(int) = delete; //함수 삭제
int main()
{
    foo(10); // 컴파일 에러
}
함수를 제공 하지 않는 것과 삭제하는 것은 어떤 차이가 있을까?
    1. 함수를 제공하지 않으면, 함수 호출 시 인자의 암시적 형 변환을 통해서 호출 가능한 함수를 찾게 된다.
    2. 함수를 선언만 제공하면, 함수 호출시 링크 에러 발생
    3. 함수를 삭제하면, 함수 호출 시 컴파일 에러 발생
    int gcd(int a, int b){return a}
    double gcd(double a, double b);//함수 선언만
    double gcd(double a, double b)=delete;
    int main()
    {
        gcd(2,10);//ok
        gcd(2.2, 3.3);// double로 선언되어 있지않으면 암수적 형 변환을 통해서 호출 가능한 함수를 찾게되고,
                        // 런타임시 에러 발생하게 됨.
    }

함수를 삭제하는 이유
    1. 암시적 변환을 의한 의도하지 않은 함수를 호출되는 것을 막기 위해
    2. 템플릿이 특정 타입의 함수를 생성하지 못하게 하기 위해
    3. 컴파일러가 자동으로 생성하는 멤버함수를 사용하지 못하게(생성하지 못하게)하기 위해 - 가장 널리 사용!!
template<typename T>
T square(T a){return a*a};
char square(char)=delete;
int main(){
    square(3);
    square(3.3);
    square('a');//error
}

=============suffix return=============
함수의 후위 반환 타입 표기법
1. 함수를 만들 때 사용하는 "새로운 표기법"
--> 함수의 "이름 앞에는 auto"를 적고, 괄호 뒤쪽에 "-> 반환 타입"을 적는 표기법
2. trailing return type or suffix return type 
3. c++11부터 지원
4. 람다 표현식 또는 함수 템블릿을 만들 때 주로 사용
//int square(int a)

auto square(int a) -> int
{
    return a * a;
}

//int main()
auto main() -> int
{
    square(3);
}

후휘 반환 타입 표기법이 필요한 경우


template<typename T1, typename T2>
//decltype(a + b) add(T1 a, T2 b) // a와 b를 더했을때 나오는 타입
//--> error, 선언부보다 앞에 있어서 실제 타입을 알 수 없기 때문에, 컴파일 에러
//auto add(T1 a, T2 b) -> decltype(a + b) // C++11 

auto add(T1 a, T2 b) // C++14 
{
    return a + b;
}

int main()
{
    add(1, 2.1);
    
//    a = 10;
//    int a;
    
}

=============constexpr function=============
constexpr 키워드
-->컴파일 시간의 의미를 가지는 키워드
1. constexpr 상수 constexpr int c = 10;
2. constexpr function 
3. if constexpr : if constexpr(c==10)

constexpr function 의미
1. 함수의 인자 값을 컴파일 시간에 결정할 수 있으면 "컴파일 시간에 함수를 실행"
2. 함수의 인자 값을 컴파일 시간에 결정할 수 없으면 "실행시간에 함수를 실행"

template parameter 
1. 템플릿 인자로 타입 뿐 아니라 "정수형 상수"도 사용할 수 있다.
2. 모든 템플릿 인자는 "컴파일 시간에 결정" 되어야 한다.
    ==> 변수를 사용 할 수 없음,,
template<typename T, int N>
struct Buffer
{
    T data[N];
};
constexpr int add(int a, int b)
{
    return a + b;
}
int main()
{
    int x = 1;
    int y = 1;
    
    int n1 = add(1, 1); // 컴파일 시간에
    int n2 = add(x, y); // 실행 시간에
    
    Buffer<int, 1024> b1;
//    Buffer<int, x> b2; // error
    Buffer<int, add(1,2)> b2; // ok
    Buffer<int, add(x,2)> b2; // error
}


constexpr function의 제약
1. C++11에서는 constexpr 함수가 컴파일 시간에 수행되기 위한 "제약조건을 많이 가지고 있었다"
--> return 문장이 한번만 나와야 한다.
2. C++14에서는 "대부분 제약이 사라지고 일부 조건"만 남아있다.
--> 파일을 오픈하거나 동적으로 메모리를 할당 할 수 없다.
--> 가상함수가 될 수 없다.

#include <iostream>

constexpr int factorial(int n )
{
    if ( n == 1 ) 
        return 1;
    return n * factorial( n-1 );
}

int main()
{
    int n = factorial(5);

    std::cout << n << std::endl;
}

=============lambda expression=============
람다 표현식의 개념
1. 일반적인 함수
--> global space에 만들어 놓고 필요할때 "함수의 이름을 사용해서 호출"한다.

2. 람다 표현식
--> 코드 안에서 "이름이 없는 함수를 만들어서 사용"하는 것
--> "익명의 함수 (anonymous function)", "함수 리터럴(literal)"
--> "함수 반환타입과 이름을 제거"하고 "[]"를 표기한다.
#include <iostream>

void foo(int a)
{
    std::cout << "foo : " << a << std::endl;
}

int main()
{
    foo(1);   // 함수  ( 함수 인자 ) : 함수 호출   
    
    
    // 람다표현식, 
    [](int a)
    {
        std::cout << "foo : " << a << std::endl;
    } (10) ; //()제외한 부분은 함수 생성, ()는 함수 호출
    
}


람다 표현식의 모양
1. 일반 함수의 모양에서 "반환타입과 함수 이름을 제거"하고 "[]"를 표기한다.
2. "[]"
--> lambda introducer :: 람다 표현식이 시작 됨을 나타낸다.
#include <iostream>

int add(int a, int b) { return a + b;}

int main()
{
    int n1 = add(1, 2);
    
    // 람다표현식 생성, 함수
    [](int a, int b) { return a + b;};
    
    
    int n2 = [](int a, int b) { return a + b;}(1,2); // 함수 호출
    
    std::cout << n1 << ", " << n2 << std::endl;
}

람다 표현식의 활용
1. 함수가 필요한 곳에 "함수 이름 대신 람다 표현식을 사용"할 수 있다.


#include <iostream>
#include <algorithm>

bool cmp( int a, int b) { return a > b;}

int main()
{
    int x[10] = {1,3,5,7,9,2,4,6,8,10};
    
    //std::sort(x, x+10); // 시작, 마지막 요소의 다음주소
    
    
    //std::sort(x, x+10, cmp); 
    
    std::sort(x, x+10, 
               []( int a, int b) { return a > b;} ); 
    
    for( auto n : x )
        std::cout << n << ", ";
}