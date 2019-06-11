c++ 표준 입출력을 사용하는 3가지 방법
1. fully Qualified name :: 권장방법..
2. using declaration
3. using directive

C언어와는 다른 C++변수의 특징
1. 함수의 "중간에서 변수 선언" 가능
2. 구조체를 사용할 때 "Struct를 표기하지 않아도" 된다.
3. 구조체를 만들 때 "멤버를 초기화" 할 수 있다.
4. "2진수 표기법", "자릿수 표기법"
    int n1 = 0b00; int n2 = 1'000'000;

일관된 초기화
1. 변수를 초기활 할때 중괄호를 사용해서 초기화하는 것
    -- 중괄호 초기화(brace-init)이라고도 표현

기존 초기화 방법의 문제점
1. 변수의 타입/종류에 따라 초기화 방법이 다르다
    =값, (값), {값}
2. 암시적 형 변화에 따른 데이터 손실이 발생할 수 있다.

일관된 초기화의 장점
1. 모든 종류의 변수를 초기화 할때 하나의 방식으로 초기화 할 수 있다.
    데이터 손실이 발생하는 모든 코드는 컴파일 에러가 발생한다.
2. 데이터 손실이 발생할 경우 컴파일 에러 발생 :: prevent narrow
struct Point
{
    int x;
    int y;
};
void foo( int   n) {} // int n = 10
void goo( Point p) {}
int main()
{
    /*
    int n1 = 10;
    int n2(10);  // C++
    
    int x[2] = {1,2};
    Point pt = {1,2};
    
    int n3 = 3.4;
    char c = 300;
    */
    foo(10);
    foo({10}); // 
    int n1 = {10};
    int n2{10};  // C++
    
    int x[2] = {1,2};
    Point pt = {1,2};
    goo({1,2});
    
    int n3 = {3.4}; // error
    char c = {300}; // error

}

constexpr
1. 컴파일 시간 상수를 만드는 새로운 키워드
    --> 컴파일 시간에 결정되는 상수 값으로만 초기화 가능
상수도, 컴파일 시간에 결정되는 경우도 있고, 실행시간에 결정되는 경우도 있다.

const vs constexpr
1. const
    --> 컴파일 시간 상수와 실행시간 상수를 모두 만들 수 있다.
    --> 변수 값으로 초기화 할 수 있다.
    int s1=10;
    const int s2= 10; // 컴파일 시간 상수, 배열 크기
    cont int s3 = s1; // 실행 시간 상수, 배열 크기 안됨
2. constexpr
    --> 컴파일 시간 상수만 만들 수 있다.
    --> 컴파일 시간에 계산될 수 있는 값으로만 초기화 가능
    --> 텀플릿 인자로 사용될 수 있다.
    constexpr int c3 = 10; // ok
    constexpr int c4 = n; //error
