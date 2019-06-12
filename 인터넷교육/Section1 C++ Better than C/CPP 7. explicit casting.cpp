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