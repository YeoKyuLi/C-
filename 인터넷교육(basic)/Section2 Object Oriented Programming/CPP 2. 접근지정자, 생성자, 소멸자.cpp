https://github.com/codenuri/CPP1/tree/master/SECTION2/02_PRIVATE_CTOR_DTOR
=============접근 지정자(Access specifiers)=============
1. 멤버 데이터를 "외부에서 직접 접근하면 객체가 잘못된 상태를 가지게 될 수" 있다.
2. "멤버 함수를 통해서만 멤버 데이터를 변경"할 수 있게 한다
--> 멤버 함수는 "인자의 유효성 여부를 조사"할 수 있다.

용어 정리
1. 객체의 "사용자는 객체의 내부 멤버 데이터의 구조에 대해서는 알 필요가 없다" 멤버 함수만 알면 된다.
--> 정보 은닉
2. 멤버 함수를 통해서만 객체의 상태를 변경할 수 있기 때문에 "객체의 상태를 항상 안전하게 유지"할 수 있다. 
--> 캡슐화
3. setter/ getter 
--> 멤버 데이터의 값을 변경하거나 얻기 위해 사용하는 멤버 함수를 나타대는 용어
4. struct vs class
    struct : 접근 지정자 생략시 기본 설정 값은 "public"
    class : 접근 지정자 생략 시 기본 설정 값은 "private"
5. friend 함수
    멤버 함수는 아니지만 private 멤버에 접근 할 수 있게 하고 싶을때
    왜 멤버 함수로 만들지 않는가?
        --> "멤버 함수로 만들 수 없는 경우"
        --> 연산자 재정의 참고
    왜  setter/ getter 를 사용하지 않는가?
        --> " setter/ getter 를 제공하면 모든 함수에서 접근"
        --> 모든 함수가 아닌 "특정 함수에서만 접근"할 수 있게 하고 싶을때
    class Airplane
    {
        int color;
        int speed;    
        int engineTemp;
    public:
        int getSpeed() { return speed;}
        
        friend void fixAirplane(Airplane& a);
    };

    void fixAirplane(Airplane& a)
    {
        int n = a.engineTemp;
    }

    int main()
    {
        Airplane a;
        fixAirplane(a);
    }


=============생성자(constructor) #1=============
기본 개념
1. 사용하는 이유 : 객체를 자동으로 초기화 하기 위해서
2. 생성자 모양
--> 클래스 이름과 동일한 함수
--> 리턴 타입을 표기하지 않는다.
--> 인자가 없어도 되고 있어도 됨
3. 객체를 생성하면
--> 객체의 크기 만큼 메모리를 할당
--> 생성자가 호출
--> 생성자가 없으면 객체를 만들 수 없다
4. "디폴트 생성자"
--> 사용자가 생성자를 한 개도 만들지 않으면 "컴파일러가 인자 없는 생성자를 제공"해 준다.

객체를 생성하는 다양한 방법
1. () 또는 {}를 사용해서 생성자 인자를 전달한다.
2. 직접 초기화와 복사 초기화
3. 배열 생성
    --> "배열의 개수 만큼 생성자가 호출"된다.
4. malloc vs new   
    malloc : 메모리만 할당, "생성자를 호출하지 못한다."
    new : 메모리 할당하고 생성자 호출


#include <iostream>
using namespace std;

class Point
{
    int x, y;
public:
    Point()             { x = 0; y = 0; cout << "1" << endl;}
    Point(int a, int b) { x = a; y = b; cout << "2" << endl;}
};

int main()
{
    /*
    Point p1(1,2);     // 2
    Point p2{1,2};     // 2,  C++11 직접 초기화
    Point p3 = {1,2};  // 2,  C++11  복사초기화
    */

    /*
    Point p4;       // 1
    Point p5();     // 객체 생성 아님. 함수 선언문
    Point p6{};     // 1
    Point p7 = {};  // 1
    */
/*
    Point p8[3];    // 1번 생성자 3번 호출
    
    Point p9[3] = {Point(1,1)}; // 2번 생성자 1회 호출
                                // 1번        2회
    
    Point p10[3] = { {1,1}, {2,2} }; // C++11
*/    

    Point* p11; // 객체 생성 아님.
    
    p11 = static_cast<Point*>( malloc(sizeof(Point))); // 해당 크기의 메모리만 할당 됨
    free(p11);
    
    p11 = new Point;  // 1번 생성자 호출 / 메모리를 할당하고 생성자를 호출
    delete p11;
    
    p11 = new Point(); // 1번.. 
    delete p11;
    
    p11 = new Point(1,2); // 2번 
    delete p11;

}5

생성자/소멸자 호출 순서
1. 객체를 생성하면
--> "멤버의 생성자가 먼저 호출"되고
--> "자신의 생성자가 호출"된다.
2. 객체 파괴도면
--> "자신의 소멸자가 먼저 호출"되고
--> "멤버의 소멸자가 호출"된다.

=============생성자(constructor) #2=============
위임 생성자 (delegate constructor) 핵심 개념
1. 생성자에서 다른 생성자를 호출하는 문법
--> 클래스의 "구현부에 표기"한다.
class Point
{
    int x, y;
public:
    Point() : Point(0, 0)
    {
    //    x = 0;
    //    y = 0;
    }
    Point(int a, int b) 
    {
        x = a;
        y = b;
    }
};

int main()
{
    Point p;

}

분리하는 경우
    class Point
    {
        int x, y;
    public:
        Point();
        Point(int a, int b);
    }

    #include "Point.h"

    Point::Point() : Point(0,0)
    {
    }

    Point::Point( int a, int b)
    {
        x = a;
        y = b;
    }

default constructor
1. Point() = default;
--> 컴파일러에게 디폴트 생성자를 만들어 달라는 문법
--> 클래스 선언부에만 표기하면 되고 구현부는 만들지 않아도 된다.
2. Point() = delete; // 복사생성자를 위해서..?

class Point
{
    int x;
    int y;
public:
    
    //Point() = delete;
    Point() = default;
    
    //Point() {}
    
    Point(int a, int b) {}
};

int main()
{
    Point p1;
    Point p2(1,2); // ok
}


분리하는 경우
    class Point
    {
        int x;
        int y;
    public:
        Point() = default;
        Point(int a, int b);
    };

    #include "Point2.cpp"

    Point::Point(int a, int b)
    {
        x = a;
        y = b;
    }

=============소멸자(destrutor)=============
1. 소멸자 모양
--> ~클래스이름()
--> 리턴 타입을 표기하지 않는다. / 인자를 가질 수 없다 - "한개만 만들 수 있다"

2. 특징
--> 객체를 생성하면 "생성자가 호출" 호출되고
--> 객체가 파괴되면 "소멸자가 호출"된다.
2. 소멸자를 만들지 않으면
--> "컴파일러가 소멸자를 제공"해 준다.
4. 소멸자가 필요한 경우
--> 생성자 등에서 자원을 할당한 경우 "소멸자에서 자원을 해지"해야 한다.
--> 자원 해지 등이 필요 없는 경우는 소멸자를 만들 필요는 없다.

5. C스타일 코드의 단점
--> 획득한 자원을 "반드시 사용자가 직접 반납"해야 한다.
--> 자원의 핸들을 담은 "변수에 직접 접근"할 수 있다.

6. 자원 할당과 자원 해지가 필요한 코드
--> C++를 사용해서 "생성자에서 자원을 할당"하고 "소멸자에서 자원을 해지"하면 자동으로 자원이 관리 된다.
--> RAII (Resource Acquistion Is Initialization)


#include <stdio.h>

int main()
{
    FILE* f = fopen("a.txt", "wt");

    f = 0;
    
    fputs("hello", f);

    //fclose(f);
}

#include <iostream>
#include <cstdio>
#include <string>

class File 
{
    FILE* file = 0; // 파일의 번호에 접근하지 못함!
public:
    File( std::string filename, std::string mode)
    {
        file = fopen(filename.c_str(), mode.c_str() );
    }
    ~File()
    {
        fclose(file);
    }
    // RW 함수들
    void puts( std::string s)
    {
        fputs( s.c_str(), file);
    }
};

int main()
{
    File f("a.txt", "wt");
    
    f.puts("hello");
    
    
//    FILE* f = fopen("a.txt", "wt");
//    f = 0;
//    fputs("hello", f);
//    fclose(f);
}

1. 널리사용하는 스타일
--> " 생성자에서 자원을 할당"
--> "소멸자에서 자원을 반납"
--> 자원의 번호를 담은 멤버 변수는 private 영역에 놓고 "외부에서 직접 접근할 수 없게"만든다.