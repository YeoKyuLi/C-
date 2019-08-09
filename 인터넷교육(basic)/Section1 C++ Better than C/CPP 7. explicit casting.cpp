https://github.com/codenuri/CPP1/tree/master/SECTION1/09_CASTING
=============Explicit Casting =============

C언어 : void* --> 다른타입*의 암시적 변환 허용
C++ : void* --> 다른타입*의 암시적 변환 허용 안함

왜 새로운 캐스팅이 필요한가?
--> C의 캐스팅은 논리적이지 않고, 위험하고, 버그의 가능성이 높다.!

#include <iostream>
#include <cstdlib>

int main()
{
    //int* p1 = (int*)malloc(sizeof(int)*10); //C언어
    
    int* p1 = static_cast<int*>(malloc(sizeof(int)*10)); //C++

    free(p1);
}

C언어 방식 캐스팅의 단점

    
#include <iostream>

int main()
{
    int n = 0;  
    
    //double* p1 = &n; // error
    
    double* p1 = (double*)&n;  // ok

    // *p1 = 3.4; // 잘못된 메모리 참조가 되거나, 다른 변수의 값을 바꿀 수 도 있음..
    
    
    const int c = 10;
    
    //int* p2 = &c;  // error 
    int* p2 = (int*)&c;  // ok
    
    *p2 = 20; 
    
    std::cout << c << std::endl; // 10 ? 20

    return 0;
}


=============Explicit Casting2 =============
종류 : static_cast / reinterpret_cast / const_cast / dynamic_cast
1. static_cast :: 주로 사용
--> static_cast< new_type>(expression);
<void(*)(int) // void를 반환하는 함수인데 인자가 int다.
상수성을 제거하거나 서로 다른 타입의 포인터 끼리의 변환은 허용하지 않음

2. reinterpret_cast
서로 다른 타입의 포인터 사이의 변환
정수와 포인터 사이의 변환
* 역참조를 하면 안되고, 포인터를 저장하거나 필요한 용도에만 사용해야 됨.

int main()
{
    int n = 10;
    
    double* p1 = reinterpret_cast<double*>(&n);
    int* p2 = reinterpret_cast<int*>(10); // 정수 -> 포인터
    
    //double d = reinterpret_cast<double>(n); // error 용도가 아님
}

3. const_cast
포인터 변수와 참조 변수 사이의 상수성과 volatile 속성을 제거하기 위한 캐스팅
int main()
{
    const    int c = 10;
    volatile int v = 20;
    
    int n = c;
    
    int* p1 = const_cast<int*>(&c);
    int* p2 = const_cast<int*>(&v);
    
    double* p3 = const_cast<double*>(&c); // error, 다른 타입으로 바꿀수 없기때문에,
}
* 여러번 cast하는 경우
char* p1 = reinterpret_cast<char*>(
                        const_cast<int*>( &c ) );                    

char* p2 = const_cast<char*>(
                reinterpret_cast<const char*>( &c ) );
                
char* p3 = (char*)&c; // 해당방법도 가능하지만, 개발자의 의도가 명확하지 않음.

4. dynamic_cast
--> 상속후, 

