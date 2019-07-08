https://github.com/codenuri/CPP1/tree/master/SECTION3/04_ABSTRACT
=============abstract class=============
추상 클래스
1. 순수 가상함수 (pure vitrual fucntion )
    함수의 구현부가 없고, 선언부가=0으로 끝나는 가상함수
    모든 subClass는 해당 function을 구현해야 한다.
2. 추상 클래스
    순수 가상 함수가 한개 이상 있는 클래스
3. 추상클래스 특징
    객체를 생성할 수 없다.
    포인터 변수는 만들 수 있다.
4. 추상 클래스로 부터 파생된 클래스
    기반 클래스의 순수 갓아함수의 구현부를 제공하지 않으면 역시 추상 클래스이다.
5. 추상 클래의 설계 의도
    파생 클래스에게 특정 멤버 함수를 반드시 만들어야 한다고 지시하는 것

class Shape
{
public:
    virtual void Draw() = 0; // 상속하지 않고 반드시 만들어라
    virtual void Draw(){} // 반드시 만드는건 아니고 안만들어도 물려받는다.
};

class Rect : public Shape
{
public:
    virtual void Draw() { }// 구현부..
};

int main()
{
    Shape  s; // error
    Shape* p; // ok
    
    Rect r; 
}

=============Interface=============
인터페이스 개념
1. 개방 폐쇄의 법칙 : 기능 확장(모듈, 클래스, 함수추가)에 열려 있고, 수정(기존 코드 수정)에는 닫혀 있어야 한다는 원칙
    새로운 카메라 클래스가 추가되어도 기존 클래스의 코들르 수정하지 않도록 만들어야 한다.
2. 강한결합 : tightly coupling
    객체와 다른 개체와의 관계가 강하게 연결되어 있는것, 교체 불가능하고 확장성이 없다. 
3. 약함결합 : loosely coupling
    객체와 다른 개체와의 관계가 약하게 연결되어 있는 것(인터페이스를 사용해서 통신). 교체 가능하고 확장성이 좋다.

1. 계약에 의한 설계
    --> 사람과 카메라 제작자 사이에 지켜야 하는 규칙을 먼저 설계한다.
    --> 규칙은 추상 클래스를 사용해서 설계한다.
2. 규칙
    --> 모든 카메라는 ICamera로 부터 파생 되어야 한다. ==> 모든 카메라는 ICamera 인터페이스를 구현 해야 한다.

3. 카메라 사용자 : 규칙대로만 사용하면 된다.
4. 모든 카메라 제작자 : 반드시 규칙을 지켜야 한다.

#include <iostream>
//인터페이스
// 인터페이스 불변의 법칙
struct ICamera
{
    virtual void take() = 0;
    //virtual void take(){} = 0; // 메모리에 잡힘
};


class People
{
public:    
    void useCamera(ICamera* p) { p->take();}
};

class Camera : public ICamera
{
public:
    void take() 
    {
         std::cout << "take picture" << std::endl; 
    }
};

class HDCamera : public ICamera
{
public:
    void take() 
    {
         std::cout << "take picture hd" << std::endl; 
    }
};

int main()
{
    People p;
    Camera c1;
    p.useCamera(&c1);
    
    HDCamera c2;
    p.useCamera(&c2);

}
