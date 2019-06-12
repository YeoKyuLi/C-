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