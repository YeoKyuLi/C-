https://github.com/codenuri/CPP1/tree/master/SECTION2/07_CONST_THIS
=============const member function#1=============
1. 상수 멤버 함수
--> 함수 선언 및 구현시 "함수 괄호 () 뒤에 const가 붙는 함수"
--> void print() const
2. 상수 멤버 함수의 특징
--> 상수 멤버 함수 안에서는 "모든 멤버를 상수 취급"한다.
--> 멤버 데이터의 값을 읽을 수는 있지만 "변경할 수는 없다."
3. 상수 멤버 함수를 사용하는 이유 !!!!
--> 코드 작성시 안정성
--> "상수 객체는 상수 멤버 함수만 호출할 수 있다."

상수멤버 함수가 필요한 이유!
1. 핵심
--> "상수 객체는 상수 멤버 함수만 호출할 수 있다."
2. const Point pt(1,1);
--> 상수 객체이므로 객체의 상태를 변경할 수 없어야 한다.
--> 하지만 "상태를 얻거나 출력 할 수는 있어야" 한다.
--> print 멤버 함수는 "반드시" 상수 멤버 함수로 해야한다.
#include <iostream>

class Point
{
public:
    int x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    
    void set( int a, int b ) { x = a; y = b; }
    
    void print() const 
    {
        std::cout << x << ",  " << y << std::endl;
    }
};


int main()
{
    const Point pt(1,1);  // 상수 객체 메모리에 x,y 잡히지만 값을 바꿀수 없다.
    pt.x = 10;      // error          
    pt.set(10,10);  // error      
    pt.print();     // error    : 컴파일라가 선언부만 보았을때, 해당 function이 어떤 일을 하는지 알 수 없기 때문이다
                    // 단, print()가 상수 함수라면
                    // ok..
}

1. 사용자 정의 타입을 함수로 전달할 때
--> call by value보다 "const reference"가 좋다

2. const reference로 전달 받는 경우 "상수 객체"이다.
--> 상수 객체라도 객체의 상태를 읽을 수는 있어야 한다.

    "객체의 상태를 변경하지 않은 모든 멤버 함수는 반드시 상수 멤버 함수로 만들어야 한다."

class Rect
{
    int xpos, ypos, width, height;
public:
    Rect( int x = 0, int y = 0, int w = 0, int h = 0 ) 
        : xpos(x), ypos(y), width(w), height(h) {}
        
    int getArea() const { return width * height;}
};

//void foo( Rect r )
void foo( const Rect& r )
{
    int n = r.getArea();
}

int main()
{
    Rect r(1, 1, 10, 10); // 비 상수 객체
    
    int n = r.getArea();
    
    foo(r);
}

=============const member function#2=============
상수 멤버 함수 문법 정리
1. mutable 멤버 데이터
--> 상수 멤버 함수 안에서도 값을 변경할 수 있다.
2. "동일 이름의 상수 멤버 함수와 비 상수 멤버 함수"를 만들 수 있다.
3. 상수 멤버 함수 안에서 "모든 멤버는 const"이다.
    const int* getData() const {return &data;}
4. 함수를 선언과 구현으로 분리할 때는 "선언과 구현 모두에 const를 표기"해야 한다.

#include <iostream>

class Point
{
    int x, y;
    mutable int cnt = 0;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}

    void print() const 
    {
        ++cnt;
        std::cout << x << ",  " << y << std::endl;
    }
};

int main()
{
    Point pt(1,1);
    pt.print();
    pt.print();
}


=============This pointer=============
this 포인터 개념
1. 객체를 여러 개 생성할떄
--> 멤버 데이터는 "객체당 한개씩 메모리에 놓이게"된다.
--> 멤버 함수는 "객체의 개수에 상관없이 코드 메모리에 한 개"만 있다.

2. this 
--> 멤버 함수 안에서 사용가능한 "키워드"
--> 자신을 호출한 "객체의 주소"를 담고 있다.

#include <iostream>

class Point
{
    int x = 0;
    int y = 0;
public:
    void set(int a, int b)
    {
        std::cout << this << std::endl;
        x = a; 
        y = b; 
    }
};
int main()
{
    Point p1;
    Point p2;
    
    p1.set(10, 20); //set(&p1,10,20)
    p2.set(30, 40);    
    
    std::cout << &p1 << std::endl;
    std::cout << &p2 << std::endl;
}    

this 포인터 활용
1. 이름 충돌 시
--> 멤버의 이름과 지역변수(함수인자)의 이름이 동일할 때 지역변수가 우선시 된다.
--> "this를 사용하면 멤버에 접근"할 수 있다.

2. this를 반환하는 함수
--> this 또는 *this를 반환하면 "멤버 함수를 연속적으로 호출"할 수 있다.
--> cout의 원리
[주의]참조 반환
--> *this를 반환 할 때는 임시객체의 생성을 막기 위해 "참조를 반환"해야 한다.

#include <iostream>

class Point
{
    int x = 0;
    int y = 0;
public:
    //Point* set(int x, int y)
    //Point set(int x, int y)
    Point& set(int x, int y)
    {
        x(함수 인자 x) = x; // c or c++는 가까운 인자를 택함
        y = y;
        this->x = x; 
        this->y = y; 
        
        return *this;
    }
};
int main()
{
    Point p1;
    //p1.set(10,20)->set(30,40)->set(40,50); return this;일때 사용가능
    p1.set(10,20).set(30,40).set(40,50);
    
    //cout << "A" << "B" << "C";
}    


this 포인터 주의사항
1. 정적 멤버 함수에서는 this를 사용할 수 없다.

#include <iostream>

class Test
{
public:
    static void foo()
    {
        std::cout << this << std::endl;
    }
};

int main()
{
    Test::foo();
    
    Test t;
    t.foo();
}