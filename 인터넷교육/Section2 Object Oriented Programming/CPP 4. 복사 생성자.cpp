https://github.com/codenuri/CPP1/tree/master/SECTION2/04_COPYCTOR
=============copy constructor=============
핵심 개념
1. 복사 생성자란
--> 자신과 동일한 타입 한개를 인자로 가지느 ㄴ생성자
2. 사용자가 복사 생성자를 만들지 ㅇ낳으면
--> 컴파일러가 제공
--> default copy constrcutor 
--> 모든 멤버를 복사한다. (bitwise copy)

#include <iostream>

class Point
{
public:
    int x;
    int y;

    Point()             : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
    
    // 사용자가 만드는 복사 생성자
    Point( const Point& p) : x(p.y), y(p.x)
    {
        std::cout << "copy ctor" << std::endl;
    }
};

int main()
{
    Point p1;       // ok
    Point p2(1,2);  // ok
    //Point p3(1);    // Point( int ) - error
    Point p4(p2);   // Point( Point ) - ok. 
    
    std::cout << p4.x << std::endl; // 2
    std::cout << p4.y << std::endl; // 1
}


복사 생성자가 호출되는 3가지 경우
1. 자신과 동일한 타입의 객체로 초기화 될때
--> Point p2(p1);
--> Point p2{p1};
--> Point p2 = p1; // explicit가 아닌 경우만
2. 함수 인자를 call by value로 받을 경우
--> 함수 인자를 const reference로 사용하면 복사본을 만들지 않으므로 복사 생성자가 호출되지 않는다.
3. 함수가 객체를 값으로 반환 할때
리턴용 임시객체가 생성될때 복사 생성자 호출
--> 참조로 반환 하면 리턴 용 임시객체가 생성되지 않는다.
#include <iostream>

class Point
{
public:
    int x;
    int y;
    
    Point(int a, int b) : x(a), y(b) 
    {
        std::cout << "ctor" << std::endl;
    }    
    Point( const Point& p) : x(p.x), y(p.y)
    {
        std::cout << "copy ctor" << std::endl;
    }
};

int main()
{
    Point p1(1,2); // 생성자
    Point p2{p1};  // 복사 생성자
    Point p3{p1};    //집적 초기화
    Point p4 = {p1};    // 복사 초기화 explicit이면 사용 못함
    Point p5 = p1;    // 복사 초기화 explicit이면 사용 못함
}


#include <iostream>

class Point
{
public:
    int x;
    int y;

    Point(int a = 0, int b = 0) : x(a), y(b) 
    {
        std::cout << "ctor" << std::endl;
    }
    Point( const Point& p)      : x(p.y), y(p.x)
    {
        std::cout << "copy ctor" << std::endl;
    }
};

//void foo( Point pt) // Point pt = p1
void foo( const Point& pt) // const Point& pt = p1
{
}

int main()
{
    Point p1(1,2);
    foo(p1);
}

#include <iostream>

class Point
{
public:
    int x;
    int y;

    Point(int a = 0, int b = 0) : x(a), y(b) 
    {
        std::cout << "ctor" << std::endl;
    }
    Point( const Point& p)      : x(p.y), y(p.x)
    {
        std::cout << "copy ctor" << std::endl;
    }
};


Point p; // 생성자

//Point foo()  // 값 타입 반환

Point& foo()
{
//    Point p; // 생성자 지역변수는 참조로 반환하면 안된다...!
    return p;
}

int main()
{
    foo();
    
}

=============디폴트 복사 생성자의 문제점=============
핵심 정리
1. 객체가 자신의 동일한 타입의 객체로 초기화 될때
--> 복사 생성자가 사용된다
--> 사용자가 만들지 않은 경우 디폴트 복사 생성자가 사용된다.
--> 디폴트 복사 생성자는 모든 멤보를 복사해 준다. 
2. 디폴트 복사 생성자가 모든 멤버를 복사 해주는 것은
--> 편리한 경우도 있지만 "문제가 되는 경우도 있다."


핵심정리
1. 얕은 복사 (shallow copy)
--> 클래스 안에 포인터 멤버가 있을 때 디폴트 복사 생성자가 "메모리 자체를 복사하지 않고 주소만 복사하는 현상"
--> 개발자가 직접 복사 생성자를 만들어야 한다.
--> 어떻게 복사할 것인가? 다양한 방법이 있다.

#include <iostream>
#include <cstring>

class Person
{
    char* name;
    int   age;
public:
    Person(const char* n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    ~Person() { delete[] name;}
};

int main()
{
    Person p1("kim", 20);
    Person p2 = p1; // 실행시 오류발생.. shallow copy

}


=============Object Copy #1============= 6:58
핵심 정리
1. 얕은 복사란 (shallow copy)
--> 클래스 안에 포인터 멤버가 있을 때 디폴트 복사 생성자가 "메모리 자체를 복사하지 않고 주소만 복사하는 현상"

2. 깊은 복사
--> 메모리까지 모두 복사한다.

3. 참조 계수 (reference counting)
--> 여러 객체가 하나의 자원을 공유하게 한다.
--> 단, 몇 명의 객체가 자원을 사용하는지 개수를 관리한다.

#include <iostream>
#include <cstring>

class Person
{
    char* name;
    int   age;
public:
    Person(const char* n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    ~Person() { delete[] name;}


    Person(const Person& p) : age(p.age)
    {
    //    age = p.age; //초기화 리스트로~
    //    name = p.name;
    
        // 포인터는 복사 하지말고. 새롭게 메모리 할당
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);        
    }
};


int main()
{
    Person p1("kim", 20);
    Person p2 = p1; 

}
