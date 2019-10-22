https://github.com/codenuri/CPP1/tree/master/SECTION7
=============name mangling=============
함수 오버로딩 문법의 원리
1. 동일한 이름의 함수라도 "컴파일 후 (어셈블리)에는 이름이 달라"야 한다.
2. C++ 컴파일러가 모든 함수가 다른 이름이 되도록 "컴파일 시간에 함수 이름을 변경"한다.
3. name mangling / name decoration

C와 C++ 차이점
1. C 언어는 동일한 이름의 함수를 여러 개 만들 수 없다.
    컴파일 해도 "함수 이름이 변경되지 않는다."
    windows OS 환경에서도 함수 이름 앞에 "_" 추가
2. 소스 코드에 확장자에 상관없이 "컴파일러에게 언어를 지정하는 방법."

C언어와 C++ 언어의 호환성 문제
1. 컴파일러는 "소스 코드 확장자를 보고 작성된 언어를 판단"한다.
2. extern "C"
    C++ 컴파일러에게 현재 "함수(변수)가 C언어로 작성되었다고 알려주는 지시어"

3. 문제점
    C 컴파일러는 extern "C"를 알지 못한다.
    C/C++ 을 모두 고려하려면 "조건부 컴파일"해야한다.

C언어와 C++ 언어의 호환성
1. C언어로 작성된 함수를 "C와 C++ 소스에서 모두 사용"하기 위한 헤더 파일
2/ stdio.h도 헤더 안에 함수 선언부가 위처럼 되어 있다.
3. windows/ linux/ mac 등의 환경에서 "정적/ 동적 라이브러리 만들 때" 반드시 알아야 하는 내용.

square.h
// extern "C"
// C++ 컴파일러에게
// 아래 함수가 C라고 알려준다.
//extern "C" int square(int a);

#ifdef __cplusplus
extern "C" {
#endif
    
     int square(int a);
     
#ifdef __cplusplus
}
#endif

=============함수 오버로딩과 함수 주소=============
핵심 개념
1. 동일한 이름의 함수가 2개 이상 있을 경우 함수의 주소룰 구하려면 "함수 포인터 타입으로 캐스팅"해야 한다.
2. 함수 템플릿의 경우
    주소를 구하려면 "템플릿 파라미터를 전달"해야 한다.


#include <iostream>

int square(int a)
{
    return a * a;
}

double square(double a)
{
    return a * a;
}

template<typename T> void foo(T a) 
{
    
}

int main()
{
    //printf("%p\n", &foo);
    printf("%p\n", &foo<int> );

    //printf("%p\n", &square); // ??
    printf("%p\n", static_cast<int(*)(int)>(&square)); //캐스팅 해줘야함
    
    //auto a = &square; // ok..
    //auto a = square; // error
    int(*f)(int) = &square; // ok

    //std::cout << (void*)&square << std::endl; 
    // cout.operator<<(함수주소)       
    // cout.operator<<( int(*f)(int) )       
}


=============함수 찾는 순서=============
동일 이름의 함수가 여러 개 있을 때 함수 찾는 순서
1. exactly matching - foo(float)
2. template - foo(T)
3. promotion - foo(double) 데이터의 손실이 없는 걸로
4. standard - conversion - foo(int)
5. user define conversion - foo(FLOAT)
6. variadic argument - foo(...)
#include <iostream>
using namespace std;

struct FLOAT
{
    FLOAT(float f) {} // 변환 생성자.
};

//template<typename T> 
//void foo( T )      { cout << "T"      << endl;}
//void foo( int )    { cout << "int"    << endl;}
//void foo( char )   { cout << "char"   << endl;}
//void foo( double ) { cout << "double" << endl;}
//void foo( float )  { cout << "float"  << endl;}
//void foo( FLOAT )  { cout << "FLOAT"  << endl;}
void foo( ... )    { cout << "..."    << endl;}

int main()
{
    float f = 3.4f;
    foo(f); // ?
    
    //FLOAT FL(f); // FLOAT FL = f;
}
