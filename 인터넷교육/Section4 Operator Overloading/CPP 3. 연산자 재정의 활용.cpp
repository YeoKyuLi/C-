https://github.com/codenuri/CPP1/tree/master/SECTION4/03_MISC1
=============증가/감소 연산자 재정의=============

1. 증가/감소 연산자 재정의가 사용되는 경우
--> C++ 표준 라이브러리 STL의 반복자
2. 증가/감소 연산자 재정의 예제를 통해서 : 연산자 재정의 문법 뿐 아니라 다양한 내용을 배울 수 있음.


연산자 핵심
1. 전위형과 후위형을 구별해야 한다
    후위형을 만들 때는 함수 인자로 int 타입을 한 개 가지도록 만든다.(사용되지 않지만 전위형과 구별하기 위해)
2. 전위형은 자기 자신을 참조로 반환 해야 한다.
    값을 반환하면 임시객체가 생성된다.

1. 후위형은 전위형을 사용해서 구현한다.
    정책을 관리하는 코드는 한 곳에 있는 것이 좋다.
2. 일반적으로 후위형보다 전위형이 빠르다.
3. 연속적인 ++을 사용하지 못하게 하기 위해
    상수 객체를 반환하는 경우도 있다.
#include <iostream>

class Point
{
    int x;
    int y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    
    void print() const 
    { 
        std::cout << x << ", " << y << std::endl;
    }
    
    Point& operator++()    
    {
        ++x;
        ++y;
        return *this; //참조반환
    }
        
    Point operator++()    
    {
        ++x;
        ++y;
        return *this; // 임시객체
    }
    //Point operator++(int) {  } // 후위형
    //const Point operator++(int) 
    Point operator++(int) 
    {
        Point temp(*this); // 자기자신의 복사본을 만듬 이전거 보관
    
        ++(*this); // 전위형 호출, 정책을 바꿀 때 관리하기 쉽다.
        //++x;
        //++y;
        
        return temp;
    }
};

int main()
{
    Point p(1,1);
    Point ret = p++;

    ++++p;  // ++(++p)
            // (p.operator++()).operator++()

    //p++;  // p.operator++()
    
    p.print(); // 3, 3
    ret.print();//1,1
    
//    int n = 3;
//    ++++n; // 5
}

=============대입 연산자=============
1. 대입연산자의 반환값
    자기자신을 참조로 반환해야 한다.
2. 대입연산자의 얕은 복사 문제..!

#include <iostream>

class Point
{
    int x;
    int y;
public:
    Point(int a, int b) : x(a), y(b) {}
    
    void print() const 
    { 
        std::cout << x << ", " << y << std::endl;
    }
    Point& operator=(const Point& p)
    {
        std::cout << "=" << std::endl;
        x = p.x;
        y = p.y;

        return *this;
    }

};

int main()
{
    Point p1(1,1); // 생성자 호출
    Point p2(2,2); // 생성자 호출
    Point p3(p1);  // 복사 생성자 호출
    Point p4 = p1; // 복사 생성자 호출
    
    p4 = p2;  // p4.operator=(p2)
    p2 = (p1 = p3); // 값으로(Point) 반환하면 복사본을 가르킨다.
    p4.print();
    
    int a = 0; // 초기화
    int b;
    b = 0; // 대입
    
}

=============스마트 포인터=============
1. 스마트 포인터란?
    객체지만 포인터 처럼 동작하는 객체
    Ptr p = new Car; // ptr p(new Car)
    p->Go(); // 객체인데 포인터 처럼 쓰이네요..? p.operator->()Go() ==>  p.operator->()->Go()
2. 구현 원리
    ->와 * 연산자를 재정의해서 포인터 처럼 동작하게 한다.
    * 연산자 재정의시는 반드시 참조를 반환해야 한다.
3. 장점
    포인터가 아니라 객체이므로 생성/복사/대입/ㅍ파괴의 모든 과정에 원하는 작업을 수행 할 수 있다.
    대표적인 활용 예는 소멸자에서 객체를 파괸
#include <iostream>

class Car
{
    int color;
public:
    ~Car()    { std::cout << "~Car()" << std::endl;}
    
    void Go() { std::cout << "Car Go" << std::endl;}
};

#include "car.h"

template<typename T> class Ptr
{
    T* pObj;
public:
    Ptr(T* p = 0) : pObj(p) {}
    
    ~Ptr() { delete pObj;}
    
    T* operator->() { return pObj;}
    T& operator*()  { return *pObj;} // 참조 리턴
};

int main()
{
    //Car* p = new Car;
    Ptr<Car> p = new Car; // Ptr p(new Car) // 객체지만 실제 내부는 포인터 기능을 가진다.  
                                            // 포인터의 경우는 {} Life cycle이 한정되어 있기때문에, 따로 delete를 구현을 해야하지만
                                            // 이 경우는 객체임으로 자동으로 소멸자를 호출함으로써, 자동으로 삭제가 된다.
    
    p->Go(); // p.operator->()Go()
             // p.operator->()->Go() // 1000->Go()
             
    (*p).Go(); // (p.operator*()).Go()
}

C++ 표준의 스마트 포인터
1. C++ 자원 관리 : new로 할당한 메모리는 반드시 delete로 파괴해야 한다.
2. 스마트 포인터를 사용하면 자동으로 자원을 관리해 준다.
    스마트 포인터의 소멸자에서 자원 삭제
3. std::shared_ptr<>
    C++ 표준 스마트 포인터 // <memory>
#include <memory>
#include "car.h"

int main()
{
//    Car* p = new Car;
//    delete p;

    //std::shared_ptr<Car> p1 = new Car; // error 복사 초기화
    std::shared_ptr<Car> p1 (new Car); // ok. 직접초기화 explicit(분명한)
    
    p1->Go();
}


=============함수 객체 (Function object, functor)=============
함수 객체
1. 클래스가 "()연산자 함수를 제공"하면 "함수 처럼 사용"할 수 있다.
2. "함수 객체 (function object)" or "함수자(functor)"

함수 객체의 장점
1. 상태를 가지는 함수
2. 인라인 치환성 :: 특정 상황에서는 일반 함수 보다 "함수 객체가 빠르다."
--> 함수의 인자로 함수를 전달할 때 일반함수는 인라인 치환 될 수 없지만 "함수 객체는 인라인 치환 될 수 있다"

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
    Plus p; // p 는 객체

    int n = p(1,2); // p.operator()(1,2)
    
    // a + b; // a.operator+(b) 
    // a - b; // a.operator-(b)
    // a();   // a.operator()() 
    // a(1,2);// a.operator()(1,2)
}

상태를 가지는 함수
1. 함수객체는 () 연산자 함수 뿐 아니라 "멤버 데이터"를 가질 수 있다.
2. 생성자/소멸자 멤버 함수 등도 활용 할 수 있다.
#include <iostream>
#include <ctime>

// 0~9 사이의 난수 얻기
int frand() 
{
    static char history[10] = {0}; // 초기화가 한 번 밖에 안됨..
    
    return rand() % 10;
}

class URandom
{
    char history[10]; // bit로 바꿀 수 있다.
public:
    void reset() 
    { 
        for (int i = 0; i < 10; i++)
            history[i] = 0;
    }
    URandom()
    {
        for (int i = 0; i < 10; i++)
            history[i] = 0;
        srand(time(0));
    }
    int operator()()
    {
        int n = -1;
        do
        {
            n = rand() % 10;
        } while( history[n] == 1);
        
        history[n] = 1;
        
        return n;
    }
};

int main()
{
    URandom orand;
    
    // 3번의 결과가 무조건 달라야 한다.
    std::cout << orand() << std::endl;
    std::cout << orand() << std::endl;
    std::cout << orand() << std::endl;
    
    std::cout << frand() << std::endl;   
}

함수 객체 (Function Object)용어의 의미
1. 용어가 처음 사용 될 때 : "() 연산자 함수를 재정의한 클래스"의 객체
2. 요즘
    "() 연산자를 사용해서 함수 처럼 호출 간으한 모든 것 객체"
    () 연산자를 재정의한 클래스, "함수 포인터", "멤버 함수 포인터"...
3. 호출 가능한 객체(callable object)
    C++1 이후 함수 객체를 대신해서 새롭게 불림.
#include <iostream>
#include <functional> // plus<>, minus<>, multilies<>
/*
template<typename T>
class Plus
{
public:
    T operator()(T a, T b)
    {
        return a + b;
    }
};
*/

int main()
{
    std::plus<double> p;
    std::cout << p(1,1) << std::endl;
    
}