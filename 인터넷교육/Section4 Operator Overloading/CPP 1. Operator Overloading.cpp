https://github.com/codenuri/CPP1/tree/master/SECTION4
=============Operator Overloading=============
연산자 재정의의 기본개념
1. +,-,* 등의 "연산자도 함수로 만들 수 있다."
    operator+, operator-, operator* 

"a+b"를 컴파일러가 해석하는 방법
1. a,b가 모두 "primitive type (int, double..)"인 경우 ==> 일반 덧셈 수행
1. a,b중 "한 개 라도 사용자 정의 타입"이 있는 경우 ==> operator+ 함수를 찾게 된다.
    방법 1. 멤버 함수 검색 a.operator+(b)
    방법 2. 멤버가 아닌 일반 함수 검색 operator+(a,b)

방법 1. 멤버가 아닌 일반 함수로 구현하는 operator+
1. +는 이항 연산자 이므로 인자가 2개 이어야 한다.
2. 타입이 크기가 큰 경우 call by value보다 "const 참조"가 좋다.
3. friend 함수로 만드는 경우가 많다.

#include <iostream>

class Point
{
    int x;
    int y;
public:
    Point( int a = 0, int b = 0) : x(a), y(b) {}
    
    void print() const 
    { 
        std::cout << x << ", " << y << std::endl;
    }
    
    friend Point operator+(const Point& p1, const Point& p2);
};

Point operator+(const Point& p1, const Point& p2)
{
    Point temp;
    temp.x = p1.x + p2.x;
    temp.y = p1.y + p2.y;
    return temp;
}

int main()
{
    Point p1(1,1);
    Point p2(2,2);
    Point p3 = p1 + p2;  // operator+(p1, p2)
    
    p3.print(); // 3, 3
}

방법 2. 멤버 함수로 구현하는 operator+
1. +는 이항 연산자 이지만 "인자가 1개" 이어야 한다.

#include <iostream>

class Point
{
    int x;
    int y;
public:
    Point( int a = 0, int b = 0) : x(a), y(b) {}
    
    void print() const 
    { 
        std::cout << x << ", " << y << std::endl;
    }
    
    // 멤버로 만드는 operator+
    Point operator+( const Point& p )
    {
        Point temp;
        temp.x = p.x + x;
        temp.y = p.y + y;
        return temp;        
    }
};

int main()
{
    Point p1(1,1);
    Point p2(2,2);
    Point p3 = p1 + p2;  // operator+(p1, p2)
                         // p1.operator+(p2)
    p3.print(); 
}

멤버 함수 vs 멤버가 아닌 함수
1. operator+함수의 "인자의 개수"
    멤버 함수 : 1개 / 멤버가 아닌 함수 :2개
2. 멤버와 멤버가 아닌 함수를 "동시에 제공"하면 --> "멤버 함수가 우선"시 된다.
3. a+b에서 첫번째 인자인 "a의 타입이"
    --> "user type" : 멤버 함수와 멤버가 아닌 함수 "모두 사용 가능"
    --> "non user type" : "멤버가 아닌 일반 함수"로만 만들 수 있다.
4. 멤버 함수가 좋을까? 멤버가 아닌 함수가 좋을까?


#include <iostream>

class Point
{
    int x;
    int y;
public:
    Point( int a = 0, int b = 0) : x(a), y(b) {}
    
    void print() const { std::cout << x << ", " << y << std::endl;  }

    // 멤버로 구현
    Point operator+( const Point& p )
    {
        std::cout << "member" << std::endl;
        
        Point temp;
        temp.x = p.x + x;
        temp.y = p.y + y;
        return temp;        
    }
    
    friend Point operator+(const Point& p1, const Point& p2);
};

// 일반 함수로 구현
Point operator+(const Point& p1, const Point& p2)
{
    std::cout << "non member" << std::endl;
    
    Point temp;
    temp.x = p1.x + p2.x;
    temp.y = p1.y + p2.y;
    return temp;
}

int main()
{
    Point p1(1,1);
    Point p2(2,2);
    Point p3 = p1 + p2; // 1. p1.operator+(p2)
                        // 2. operator+(p1, p2)
                        
    p1 + 1; // 1. p1.operator+(int)
            // 2. operator+(Point, int)
            
    1 + p1; // 1. 1.operator+(Point) - 만들수 없다.
            // 2. operator+( int, Point) - 만들수 있다.
    p3.print(); 
}

operator+함수를 호출하는 방법
1. 컴파일러가 코드를 분석해서 호출
2. 사용자가 직접 호출
    Point p3 = p1 + p2; 
    operator+(p1, p2);
    p1.operator+(p2);


=============Operator Overloading 주의사항=============
연산자 재정의 문법 주의 사항
1. 인자가 모두 primitive 타입인 경우는 오버 로딩 할 수 없다. 
2. 다음의 연산자는 오버로딩 할 수 없다.
    .* :: ?: sizeof typeid static_cast dynamic_cast reinterpret_cast const_cast
    . (c++2부터 오버로딩 가능)
3. 멤버 함수로만 오버로딩 가능한 연산자: =, (), [], ->
4. 새로운 연산자를 만들거나, 인자의 개수를 변경하거나, 연산자 우선 순위를 변경할 수 없다.
5. 디폴트 파라미터를 사용할 수 없다.
6. 연산자 재정의에서 중요한 연산자들
    <<, ++, [], (), ->, =
int operator+(int a, int b)
{
    return a - b;
}

//3 + 2;

//p.print();

Point operator+(const Point& p, int n )
{
    //.....
}

Point p1;
Point p2 = p1 + 1;// 1;


Point operator+(const Point& p, int n =10 )
{
    //.....
}

Point p1;
Point p2 = p1 + ; 안됨.