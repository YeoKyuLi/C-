https://github.com/codenuri/CPP1/tree/master/SECTION2/03_INITALIZATION
=============memeber initializer list=============
1. 멤버 초기화 리스트
--> 생성자 괄호()뒤에 콜론(:)을 표기하고 멤버를 초기화 하는 것, 위임 생성자도 생성가능함 Point()
2. 특징
--> 대입(assignment)이 아닌 초기화(initialization)


반드시 멤버 초기화 리스트를 사용해야 하는 경우
1. 클래스 안에 멤버 데이터가 "const or reference"로 되어 있을 때
2. 클래스 안에 "디폴트 생성자가 없는 타입이 멤버 데이터로" 있을 때

#include <iostream>

class Point
{
    int x;
    int y;
    const int cval;
    int& r;
public:
    Point( int a, int b, int c) : x(a), y(b), cval(c), r(a) // cval, r 여기서 하는건 초기화
    {
    //    cval = c; // 대입
    //    x = a;    
    //    y = b;
    }
};

int main()
{
    Point p(1, 2, 10);
    

//    const int cval;
//    cval = 10;
}


class Point
{
    int x;
    int y;
public:
    Point( int a, int b) : x(a), y(b) {}
};

class Rect
{
    Point p1;
    Point p2;
public:
    Rect(int a, int b, int c, int d) : p1(a,b), p2(c,d) 
    {
        p1(a, b); // 제어문?
    }
};

int main()
{
    Rect r; // p1 Point 
            // p2 Point ťýźşŔÚ
            // Rect ťýźşŔÚ
}


주의사항
1. 초기화 순서
--> 초기화 리스트의 순서대로 초기화 되지 않고, "멤버 데이터가 놓인 순서대로 초기화"된다. 


멤버 데이터를 초기화 하는 3가지 방법
1. member field initialization
--> 생성자로 전달된 값을 사용할 수 없다.

2. member initializer list
--> 가장 널리 사용되는 방법, 대입이 아닌 "초기화"

3. 생성자 블록 안에서 초기화
--> 초기화가 아닌 "대입"

* 클래스를 선언과 구현으로 분리하는 경우 --> "초기화 리스트는 구현부에 작성한다."


=============explicit constructor=============
함수 인자 전달과 초기화 방법
1. 함수 인자 전달 시 복사 초기화를 사용한다.
2. 특정 클래스 설계 시 복사 초기화를 사용하지 못하게 하는 것이 좋을때가 있다.

explicit 생성자
1. 객체를 초기화 할 때 직접 초기화만 사용할 수 있고, 복사 초기화는 사용할 수 없다.
2.

#include <iostream>

class OFile
{
    FILE* file;
public:
    explicit OFile(const char* filename)
    {
        file = fopen(filename, "wt");
    }
    ~OFile() { fclose(file); }
};

void foo( OFile f) {} // OFile f = "hello";
                        // OFile f= f1;

int main()
{
    OFile f1("a.txt");
    OFile f2 = "a.txt"; // error
    
    foo( f1 );  // ok
    foo("hello"); // error
    
}


C++ 표준 라이브러리와 explicit 생성자
