https://github.com/codenuri/CPP1/tree/master/SECTION2/06_STATIC
=============static member data#1=============
핵심 개념
1. 객체의 생성과 소멸
--> 모든 객체는 생성될때 "생성자 호출"
--> 소멸할때 "소멸자를 호출"
2. 객체가 몇 개 생성되었닌 개수를 알 고 싶다면 --> +1, -1
3. 객체의 개수를 관리할 변수가 필요하다.


1. 멤버 데이터를 사용해서 객체의 개수를 관리하는 경우
--> 멤버 데이터는 "객체당 하나씩 별도의 메모리 공간"사용
--> 객체의 개수를 항상 1
2. 전역 변수를 사용해서 객체의 개수를 관리하는 경우
--> 전역 변수는 메모리에 하만 있고 모든 객체가 공유
--> 모든 객체가 공유 하므로 객체의 개수를 구할 수 있다.
--> 실수로 외부에서 카운트 변수를 수정한다면?


1. 객체의 개수를 관리하는 변수
--> 모든 객체가 공유해야 한다.
--> 외부에 잘못된 사용으로 부터 보호 할 수 있어야 한다.

2. 정적 멤버 데이터
--> "static"
--> 모든 객체가 공유한다.
--> 클래수 내부에서 선언하고,
--> 클래스 외부에서 정의를 만들어야 한다.. int Car::cnt = 0;

3. 정적 멤버 데이터의 특징
--> 모든 객체가 공유한다.
--> 멤버 이므로 접근 지정자를 사용 할 수 있다.


1. 정적 멤버 데이터를 만드는 방법
--> 클래스 안에 변수 선언부를 제공하고 "클래스 외부(소스 파일)에 정의을 제공"한다. 


정적 멤버 데이터와 일반 멤버 데이터
--> 정적 멤버 데이터는 객체가 없어도 메모리에 놓인다.
--> 클래스 이름으로 접근 가능


접근방법
1. 일반 멤버 데이터에 접근하는 방법
--> 객체 이름으로 만 접근 가능 --> c.speed
2. 정적 멤버 데이터에 접근하는 방법
--> 객체 이름을 사용 하거나 클래스 이름을 사용해서 접근할 수 있다. 
--> 되도록이면 "클래스 이름을 사용해서 접근하는 것이 좋다."
    c.cnt / Car::cnt
=============static member data#2=============
정적 멤버 데이터와 초기화
1. C++11부터 일반 멤버 데이터는 멤버 필드 초기화를 사용 가능하지만 정적 멤버 데이터는 필드 치기화를 사용할 수 없다.
    --> 클래스 외부의 정의(definition)에서 초기값을 지정해야 한다.

class Test
{
public:
    int data = 0; // C++11 부터 가능 선언 & 정의

    //static int sdata1 = 0;  // error
    
    static int sdata1;  // 선언 (declaration)
    
    static const int        sdata2 = 0; // ok
    //static const double     sdata3 = 0; // error 외부의 정의부를 만들어야한다.
    static constexpr int    sdata4 = 0; // ok
    static constexpr double sdata5 = 0; // ok
    
    inline static int sdata6 = 0; // C++17
};
int Test::sdata1 = 0; // 정의(definition)

int main()
{
    int n1 = Test::sdata1;
    int n2 = Test::sdata2;
    //int n3 = Test::sdata3;
    int n4 = Test::sdata4;
    int n5 = Test::sdata5;
    int n6 = Test::sdata6;
}

=============static member function=============
핵심 개념
1. 정적 멤버 함수
--> 객체 없이 호출 가능한 멤버 함수
--> 클래스 이름::함수이름()으로 호출
2. 정적 멤버 함수를 호출하는 2가지 방법
--> 클래스 이름으로 호출 Car::getCount()
--> 객체 이름으로 호출 c1.getCount()
3. 객체이름보다 클래스 이름을 사용하는 것이 좋다.

class Car
{
    int speed;
    static int cnt; 
public:    
    Car()  {++cnt;}
    ~Car() {--cnt;}
    
    static int getCount() { return cnt;}
};
int Car::cnt = 0;   // 

int main()
{
    // 자동차 갯수를 알고 싶다.
    // getCount() 호출
    Car::getCount();
    
    Car c1, c2, c3;
    
    c1.getCount();
}

1. 정적멤버 함수의 특징
--> 객체 없이 호출 가능한 멤버 함수 / static member만 접근 가능
--> 일반 멤버(데이터,함수)에 접근할 수 없다
--> 정적 멤버(데이터, 함수)에 접근할 수 있다.

일반멤버 함수 : 각각의 객체에 대한 개별 연산
정적멤버 함수 : 모든 객체의 공통에 대한 연산

class Test
{
    int        data1;
    static int data2;  // 객체가 없더라도 메모리에 존재
public:
    static void foo() // 여기안에서는 static 멤버들만 호출할 수 있음
    {
        data1 = 0; // error 메모리에 없기 때문에
        data2 = 0; // ok 메모리에 있음
        goo();     // error
    }
    void goo() // 객체 없이 못 부르고, 반드시 객체를 생성하고 호출해야됨
    {
        data1 = 0; // ok
        data2 = 0; // ok
        foo();     // ok
    }    
};
int Test::data2 = 0;
int main()
{
    Test::foo();
    Test t;
    t.goo();
}