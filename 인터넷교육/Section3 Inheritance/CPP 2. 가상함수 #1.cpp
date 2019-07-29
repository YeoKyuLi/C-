https://github.com/codenuri/CPP1/tree/master/SECTION3/02_VIRTUAL_FUNCTION
=============upcasting=============
1. Up casting 
--> 기반 클래스 타입의 포인터로 파생 클래스를 가리킬 수 있다.
--> 기반 클래스 타입의 참조로 파생 클래스를 가리킬 수 있다.

class Shape
{
public:
    int color;
};

class Rect : public Shape
{
public:
    int x, y, w, h;
};

int main()
{
    Rect rect;
    
    Rect*  p1 = &rect; // ok
    int*   p2 = &rect; // error. 
    Shape* p3 = &rect; // ok  
    
    Shape& r = rect;   // ok. 
    
}
 
핵심 정리
1. 기반 클래스 타입의 포인터로 파생 클래스를 가리킬때
--> 기반 클래스의 멤버는 접근할 수 있지만
--> 파생 클래스가 추가한 멤버는 접근할 수 없다.
--> 파생 클래스가 추가한 멤버에 접근 하려면 포인터를 파생 클래스 타입으로 캐스팅 해야 한다.


 class Shape
{
public:
    int color;
};
class Rect : public Shape
{
public:
    int x, y, w, h;
};

int main()
{
    Rect rect;

    Shape* p = &rect; 
    
    p->color = 0; // ok
    p->x = 0;     // error
    static_cast<Rect*>(p)->x = 0; // ok
    
}

Upcasting 활용
1. 동종(동일한 기반 클래스를 사용하는 클래스)을 처리하는 함수를 만들 수 있다.
2. 동종을 보관하는 컨테이너를 만들 수 있다.

class Shape
{
public:
    int color;
};
class Rect : public Shape
{
public:
    int x, y, w, h;
};

// 인자로 전달된 도형을 검정색으로 변경하는 함수
void changeBlack(Shape* p)
{
    p->color = 0;
}
/*
void changeBlack(Triangle* p)
{
    p->color = 0;
}
*/
int main()
{
    Rect r;
    changeBlack(&r);
    
    Rect* buffer[10]; // 사각형만 보관
    Shape* buffer[10]; // 모든 도형 보관
}

탐색기 프로그램을 객체 지향 기법으로 설계하다면
--> Composite Pattern


=============Virtual Function=============
Function Override 
1. 함수 오버 라이드 (Function override)
--> 기반 클래스가 가진 함수를 파생클래스가 다시 만드는 것
--> 주의 overloading과 다른 용어
2. 기반 클래스 포인터로 파생 클래스를 기리킬 때 override된 함수를 호출 하면
-->C++, C# 등으 ㅣ언어는 기반 클래스 함수 호출
--> java, swift 등의 언어는 파생 클래스 함수 호출

함수 바인딩 (binding)
1. p->Draw()를 어느 함수와 연결할 것인가?
--> 방법1. "컴파일 할 때 결정"하는 방법 - static binding 
--> 방법2. "실행 할 때 결정"하는 방법 - dynamic binding
2. C++은 기본적으로 컴파일 할 때 함수 호출을 결정한다.
--> 컴파일러는 "컴파일 시간에 실제로 P가 어느 객체를 가르키는지 알 수 없다."
--> 컴파일러가 컴파일 시간에 "알고 있는 정보는 p는 shape*라는 사실 밖에 없다."
3. 가상 함수 (virtual function)
--> 어느 함수를 호출 할지는 컴파일 시간에 하지 말고 "실행할 때 결정해 달라는 것"
--> 메모리에 있는 객체를 조사한 후 호출
#include <iostream>

class Shape
{
public:
    virtual void Draw() { std::cout << "Shape::Draw" << std::endl; }
};
class Rect : public Shape
{
public:
    virtual void Draw() { std::cout << "Rect::Draw" << std::endl; }
};

int main()
{
    Shape s; 
    Rect r;  
    
    Shape* p = &r;
    
    //--------------
    //int n = 0;
    //std::cin >> n;
    //if ( n == 1 ) p = &s;
    //--------------
    
    // 아래 코드를 컴파일 할때
    // p가 어느객체를 가리킬지 컴파일러가 알수 있을까 ?
    
    p->Draw();    // Rect::Draw
}

=============예제로 배우는 상속 문법=============
1. 다형성 (polymorphism)
--> 동일한 코드 표현(함수 호출)이 "상황에 따라 다르게 동작"하는 것

2. 개방 폐쇄의 법칙 (Open Close Principle, OCP)
--> 기능 확장에 열려 있고, (Open, 기능이 추가되어도)
--> 코드 수정에는 닫혀 있어야(Cloase, 코드는 수정되면 안된다)한다는 이론
--> 다형성은 OCP를 만족하는 좋은 코드 스타일

DIP, SRP, LSP, ISP, OCP