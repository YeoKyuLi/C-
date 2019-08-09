https://github.com/codenuri/CPP1/tree/master/SECTION1/07_CONTROL
=============range for=============
1. 새로운 모양의 반복문
2. foreach와 유사
3. STL의 다양한 컨테이너(list, vector, set)를 사용 가능
4. auto와 함께
5. 사용자가 만든 list도 사용 가능
int main()
{
    int x[10]={2,3,4,5,6};
    for(auto n : x){
        std::cout << n << " , ";
    }
}


=============if init=============
핵심 개념
1. "조건문(if, switch)"을 만들때 "초기화 구문을 추가"할 수 있다.
2. "C++17"부터 지원하는 문법

int foo() { return -1;}

int main()
{
    /*
    int ret = foo();
    
    if ( ret == -1 )
    {
        //....
    }
    */
    if ( int ret = foo() ; ret == -1  )
    {
        
    }
    
    
    /*
    int n = foo();
    switch( n )
    {
    case 10: break;
    case 20: break;
    }
    */
    
    switch( int n = foo(); n )
    {
    case 10: break;
    case 20: break;
    }

}

=============if constexpr=============
1. if 
--> "실행시간"에 조건식을 조사
2. if constexpr 
--> "컴파일 시간"에 조건식을 검사
--> "조건식은 반드시 컴파일 시간에 값을 결정"할 수 있어야 한다.
--> "static if"라고도 불리는 문법

if constexpr(컴파일시간표현식){}
sizeof :: 컴파일 타임에 하는 연산자
int main()
{
    int n = 0;
    
    if ( n == 0 )
    {
        //....
    }
    
    /*
    if constexpr ( n == 0 ) // error
    
    {
        //....
    }
    */
    
    if constexpr ( sizeof(n) == 0 ) // ok..
    {
        //....
    }

}

if constexpr 활용
1. 함수 템플릿을 만들 때 조건에 따라 "특정 코드를 생성하지 못하게 할 때"

template<typename T> 
void foo(T a)
{
//    if ( 0 ) //조사는 실행시간에 하는것임!

    if constexpr ( 0 ) // 포인터인지 조사하는 조건이 있음,, C++17에서
        *a = 0; // 역참조 해서 0으로 바꿈,
}

int main()
{
    int n = 0;

    foo(&n); // T : int* , 주소가 보내는것임
    foo(n);  // T : int
}