https://github.com/codenuri/CPP1/tree/master/SECTION3/03_VIRTUAL_FUNCTION2
=============가상 함수 문법 정리=============
virtual / override / final

가상 함수 문법 정리
1. 파생 클래스에서 가상함서 재정의 (override)할때
--> "virtual 키워드는 붙여도 되고 붙이지 않아도 된다."
--> 되도록이면 붙이는 것이 가독성이 좋다.

2. override - C++11
--> 실수를 방지하기 위해 "override를 붙이는 것이 좋다."

3. final = C++11
--> 파생 클래스에서 "가상함수를 재정의 할 수 없도록 하기 위해"

4. 선언과 구현으로 분리할 때는
--> "virtual / override / final 키워드는 선언부에만 표기"하고 구현부에는 표기하지 않는다.

=============가상소멸자=============
핵심 정리
1. 어떤 클래스가 기반 클래스로 사용된다면
--> "소멸자를 반드시 가상함수로 만들어야 한다."

#include <iostream>
using namespace std;

class Base
{
public:
    Base()  { cout << "Base()" << endl;}
    virtual ~Base() { cout << "~Base()" << endl;} // virtual 메모리를 검사해서 부르도록, 실행될때 메모리를 조사하고 호출
};

class Derived : public Base
{
public:
    Derived()  { cout << "Derived()"  << endl;}
    virtual  ~Derived() { cout << "~Derived()" << endl;}    // virtual 생략도 가능하지만 가독성을 위해서 사용
};

int main()
{
    Base* p = new Derived; // Derived 객체 생성
    
    // 컴파일러는 p가 Base 라고만 생각.
    delete p;  // 1. p는 Base*이다.
               // 2. 소멸자는 가상함수가 아니다.
}

=============가상 함수의 호출 원리=============
가상 함수의 원리
가상함수 콜 테이블 :: 가상 함수의 주소를 담고 있는 테이블
1. 가상 함수의 오버 헤드 - 메모리 사용량
--> 가상함수 테이블 (가상 함수가 많은 경우는 메모리 사용량 증가)
--> 객체당 한개의 가상함수 테이블을 가리키는 포인터(vptr)추가
2. 가상함수의 오버헤드 - 성능
--> 함수 호출 시 실행시간에 메모리를 한번 참조 후 호출
--> 가상함수는 인라인 함수가 될 수 없다.

#include <iostream>
using namespace std;

class Base
{
    int data1;
public:
    void f1()         {}
    virtual void f2() {}
    virtual void f3() {}
    virtual void f4() {}    
};

class Derived : public Base
{
    int data2;
public:
    void f1()         {}
    virtual void f2() {}    
};

int main()
{
    Base    base1;
    Derived derv1;
    
    Base* p = &derv1;
    
    p->f1(); // Base::f1
    p->f2(); // Derived::f2  
        // p->vptr[0]()
             
    Base base2;
    Derived derv2;
}


