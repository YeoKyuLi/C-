https://github.com/codenuri/CPP1/tree/master/SECTION1/10_MISC

=============New/Delete=============
C언어와 C++언어에서의 동적 메모리 할당
1. C언어
--> malloc으로 할당하고 free로 해지한다.
--> C언어에서는 캐스팅이 필요 없지만, C++에서 malloc 사용시 "반환되는 주소는 원하는 포인터 타입으로 캐스팅"해야한다.

2. C++
--> "new로 할당"하고 "delete"로 해지
--> new가 반환한 주소를 "캐스팅 할 필요 없다."
--> 배열로 형태로 할당한 경우 "delete[]"로 해지해야한다.

3. malloc은 생성잘르 호출하지 못하지만 "new는 생성자를 호출"한다.


#include <cstdlib>  

int main()
{
    int* p1 = (int*)malloc(sizeof(int)*10);

    free(p1);
    
    
    int* p2 = new int; // int 한개, 4bit
    
    delete p2;
    
    int* p3 = new int[10];
    //delete[] p3;
    delete p3; //미정의 동작(undefined) --> 컴파일러 마다 다르게 동작할 수 있다.
    
    int* p4 = new int[10][2]; // 80
    delete[] p4;
    

}

=============nullptr=============
핵심개념
1. null pointer value을 나태내는 pointer literal 
2. 포인터 변수를 초기화 하기 위해 기존의 방식대로 "0을 사용해도 되지만 nullptr을 사용하는 것"이 "안전"하고 "코드의 가독성"을 높일 수 있다.

int main()
{
    int* p1 = 0;
    int* p2 = nullptr;
}

0의 특징
1. 0은 "정수, 실수, bool, 포인터 등의 변수를 초기화"할 때 사용 가능
2. 0은 "정수형 literal이고 int 타입"
--> 0은 int 타입이고, "실수, bool, 포인터 타입으로 암시적 형 변환"될 수 있다.

리터럴과 데이터 타입
1. 리터럴(literal)
--> 소스 코드 내에서는 사용되는 "고정된 값."
--> 변수 초기화에서 구문 등에서 많이 사용된다.
--> 모든 리터널은 "데이터 타입이 있다"

nullptr과 코드 가독성
1. 0을 사용하는것보다 "nullptr을 사용하는 것이 코드 가독성이 좋다"

nullptr과 데이터 타입
1. nullptr은 "std:nullptr_t"타입

nullptr_t타입과 형 변환
1. std::nullptr_t 타입은 모든 타입의 포인터로 암시적 변환된다.
2. std::nullptr_t 타입은 "int 타입으로 변환 될 수 없다."
3. std::nullptr_t 타입은 "bool타입으로 직접초기화 시 초기값으로 사용이 가능"하다.
int main()
{
    0;      // int
    0.0;    // double
    nullptr;// std::nullptr_t
    
    int*  p1 = nullptr;
    char* p2 = nullptr;
    void(*f)() = nullptr;
    
    int n1 = nullptr; // error
    int n2 = 0;
    
//    bool b1 = nullptr; // error
    bool b2(nullptr); // ok
    bool b3{nullptr}; // ok
//    bool b4 = {nullptr}; // error
}

NULL과 nullptr 
C : void* --> 다른타입* 암시적 형 변환 허용
C++ : void* --> 다른타입* 암시적 형 변환 안됨

NULL
1. c/C++에 따라 구현 방법이 다르다.
2. 컴파일러의 종류, 버전에 따라서도 구현 방법이 다르다
3. 일반적으로 C++ 컴파일러는 "정수 리터럴 0" 으로 정의하는 경우가 많다.
** 포인터 변수를 초기화 하거나 값을 조사할때는 "0또는 NULL을 사용하지 말고 nullptr을 사용하자"
#include <iostream>

void foo(int   n) { std::cout << "int"   << std::endl; }
void foo(void* p) { std::cout << "void*" << std::endl; }

void goo(char* n) { std::cout << "goo" << std::endl; }

/*
#ifdef __cplusplus
    #define NULL 0
#else
    #define NULL (void*)0
#endif
*/

int main()
{
    foo(0); // int
    foo((void*)0); // void*
    foo(NULL); // int
    
    goo(NULL); //  ok
}