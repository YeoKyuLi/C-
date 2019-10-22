https://github.com/codenuri/CPP1/tree/master/SECTION3/05_RTTI
=============RTTI(Run Time Type Information)=============
핵심 개념
1. Run Time Type Information
    실행시간에 "타입의 정보를 얻을 때 사용"하는 기술

사용하려면
1. <typeinfo> 헤더 포함
2. "typeid"연산자를 사용
3. 타입의 정보를 담은 "type_info" 객체를 얻을 수 있다.
4. type_info 객체의 멤버 함수 "name()" 사용 

#include <iostream>
#include <typeinfo>

int main()
{
    int  n1 = 10;
    auto n2 = n1; // n2 타입은? int 
    
    const std::type_info& t1 = typeid(n2);
    
    std::cout << t1.name() << std::endl;
}


핵심개념
1. typeid
    연산자
    typeid(변수명) / typeid(int) / typeid(3+4.3)
    typeid의 연산자의 결과로 const std::type_info&가 반환된다.
2. std::type_info
    타입의 정보를 담고 있는 클래스
    사용자가 직접 객체를 만들 수 없고, typeid() 연산자를 통해서만 얻을 수 있다.  :: 상수 참조로만 가능
    멤버 함수의 nmae을 통해서 타입의 이름을 얻을 수 있다. 

핵심개념
1. 타입을 출력하는 것이 아니라 "조사"하고 싶다면
    2개의 type_info 객체를 "==연산자로 비교"한다.
    typeid의 결과를 바로 비교해도 된다.
2. 변수 n이 int타입인지 조사하는 일반적인 코드

#include <iostream>
#include <typeinfo>

int main()
{
    auto n1 = 10;
    
    const std::type_info& t1 = typeid(n1);
    const std::type_info& t2 = typeid(int);
    
    if ( t1 == t2 )
    {
        std::cout << "same" << std::endl;
    }
    
    if ( t1.hash_code() == t2.hash_code() )
    {
        std::cout << "same" << std::endl;
    }
    
    std::cout << t1.name() << std::endl;
}


=============상속, RTTI, dynamic_cast=============
상속과 __RTTI
1. 함수가 인자로 기반 클래스의 포인터를 받으면
    기반 클래스 뿐 아니라 모든 파생 클래스를 전달 받을 수 있다.
    void foo(Animal* p) // Animal로 파생되 모든 클래스
2. 기반 클래스 포인터로 파생 클래스의 고유 멤버에 접근할 수 없다.
    파생 클래스의 고유 멤버에 접근하려면 파생 클래스 타입으로 캐스팅(DownCasting)해야 한다.

1. typeid 
    가상함수가 없는 객체(non polymorphic type) : 컴파일 시간에 포인터 타입으로 조사
    가상함수가 있는 객체 : 실행시간 타입 조사(가상 함수 테이블 등을 사용)

*RTTI가 제대로 동작하려면 기반 클래스에 가상함수가 하는 필요하다.

#include <iostream>
#include <typeinfo>

class Animal 
{
public:
    virtual ~Animal() {}
};

class Dog : public Animal 
{
public:
    int color;
};

void foo(Animal* p)
{
    //const std::type_info& t = typeid(p);
    const std::type_info& t = typeid(*p); //p가 가르키는 곳
    std::cout << t.name() << std::endl;
    
    if ( typeid(*p) == typeid(Dog))
    {
        Dog* pDog = static_cast<Dog*>(p);
        pDog->color = 10;
        std::cout << "Dog" << std::endl;
    }
}

int main()
{
    Animal a; foo(&a);
    Dog    d; foo(&d);    
}


다른방법,
1. upcasting vs downcasting
    upcasting : 파생 클래스 포인터를 기반 클래서 타입으로 캐스팅 하는 것 : 항상 안전하다.
    downcasting : 기반 클래스 포인터를 파생클래스 타입으로 캐스팅하는 것 : 안전하지 않을 수 도 있다.

2. Downcasting과 캐스팅 연산자
    static_cast : 잘못된 downcasting을 조사할 수 없다.
                    단, 컴파일 시간에 캐스팅을 수행하므로 오버헤드가 없다.
    dynamic_cast : 잘못된 downcasting을 하면 0을 반환한다.
                    실행시간에 캐스팅을 수행하므로 약간의 오버헤드가 있다.
#include <iostream>
#include <typeinfo>

class Animal 
{
public:
    virtual ~Animal() {} //보통의 경우에 많이 생성한다.
};

class Dog : public Animal 
{
public:
    int color;
};

void foo(Animal* p)
{
    //Dog* pDog = static_cast<Dog*>(p);
    
    Dog* pDog = dynamic_cast<Dog*>(p); // daynamic casting도 가상함수 테이블을 사용함
    // 기반클래스에 virtual function이 없으면, 사용안됨.
    
    if ( pDog != 0 )
    {
        pDog->color = 10;
    }
    std::cout << pDog << std::endl;
}

int main()
{
    Animal a; foo(&a);
    Dog    d; foo(&d);    
}


