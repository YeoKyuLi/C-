https://github.com/codenuri/CPP1/tree/master/SECTION3/01_INHERITANCE
=============상속 기본 개념=============
상속 문법 사용하기
1. "공통의 특징을 모아서 하나의 클래스를 설계"한다.
2. 하위 클래스를 만들때 "부모로 부터 상속"을 받는다.

상속
1. 한 클래스가 다른 클래스에서 정의된 속성들(데이터,함수)를 이어 받아서 사용하는 것
2. 이미 정의된 클래스를 기반으로 새로운 클래스 설계
3. S/W의 재사용성 지원

상속 문법의 장점
1. 코드의 중복을 막을 수 있다.
2. 상속을 통해서 "기존 클래스에 새로운 특징을 추가"한 새로운 타입의 설계
3. 다형성(polymorphism)을 활용한 객체지향 디자인 기법

객체지향 언어별 상속 문법 표기법
c++     class sub : public super 
c#      class sub : super 
Java    class sub extends super


#include <iostream>
#include <string>

class Person
{
    std::string name;
    int age;
};

class Professor : public Person
{
    int major;    
};

class Student : public Person
{
    int id;
};

class ParttimeStudent : public Student
{
    int salary;
};

int main()
{
    Professor p;
    Student   s;
}

=============protected=============
상속과 접근 지정자 ( access specifiers )
private, protected, public

private & protected
1. private
--> 파생 클래스에서도 접근할 수 없다.
--> 값을 변경하거나 얻으려면 "기반 클래스의 멤버함수를 사용"해야 한다.
2. protected
--> 외부에서 접근할 수 없지만 "파생 클래스에서는 직접 접근할 수 있다."


=============상속에서의 생성자 소멸자=============
상속에서의 생성자/소멸자 호출 순서
1. 파생 클래스의 객체 생성시 생성자/소멸자 호출 순서
    --> 기반 클래스 생성자 / 파생 클래스 생성자
    --> 파생 클래스 소멸자 / 기발 클래스 소멸자
2. 파생 클래스의 객체 생성시 인자가 있을때
    --> 기반 클래스 생성자는 "디폴트 생성자 호출"
    --> 기반 클래스의 "다른 생성자를 호출하려면 명시적으로 호출"해야 한다.


#include <iostream>
using namespace std;

class Base
{
    int data;
public:
    Base()       { cout << "Base()"    << endl; }
    Base(int a)  { cout << "Base(int)" << endl; }
    ~Base()      { cout << "~Base()"   << endl; }
};

class Derived : public Base
{
public:
    Derived()       { cout << "Derived()"    << endl; }
    Derived(int a)  { cout << "Derived(int)" << endl; }
    Derived(int a) : Base(a) { cout << "Derived(int)" << endl; }
    ~Derived()      { cout << "~Derived()"   << endl; }
};

int main()
{
//    Derived d;
    Derived d(5);
    
}

생성자/소멸자 호출의 정확한 원리
1. 정확한 원리
    --> 파생 클래스의 생성자가 기반 클래스의 생성자를 호출하는 코드를 컴파일러가 생성해 주는 것

1. protected 생성자
--> 자기 자신은 객체를 만들 수 없지만 (추상적인 존재)
--> 파생 클래스의 객체는 만들 수 있게 하는 의미.


#include <iostream>
using namespace std;

class Base
{
    int data;
public:
    Base()       { cout << "Base()"    << endl; }
    Base(int a)  { cout << "Base(int)" << endl; }
    ~Base()      { cout << "~Base()"   << endl; }
};

class Derived : public Base
{
public:
    Derived()      : Base() { cout << "Derived()"    << endl; } //  : Base() 컴파일러가 추가
    Derived(int a) : Base() { cout << "Derived(int)" << endl; }
    ~Derived()      { cout << "~Derived()"   << endl; ~Base(); } //~Base(); 컴파일러가 추가
};

int main()
{
//    Derived d;
    Derived d(5);
    
}


주의 사항
1. 기반 클래스에 디폴트 생성자가 없다면
--> 파생 클래스를 만들 때 "반드시 기반 클래스의 생성자를 명시적으로 호출"해야 한다.
#include <string>

class Person
{
    std::string name;
    int age;
public:
    Person( std::string n, int a) : name(n), age(a) {}
};

class Student : public Person
{
    int id;
public:
    Student()      : Person("unknown", 0),  id(0) {}
    
    Student(std::string n, int a, int i) 
                   : Person(n, a),  id(i) {}
};

int main()
{
    Student s1;
    Student s2("kim", 20, 100);
}
