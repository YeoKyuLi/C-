// 5_추상클래스3
#include <iostream>
using namespace std;
//------------------------------------------------------------------------------------------//
// tightly coupling ( 강한 결합 ) : 하나의 클래스가 다른 클래스를 사용할때
//									클래스 이름을 직접 사용하는 것.

//									교체 불가능한 경직된 디자인
//									OCP를 만족할 수 없다.

//------------------------------------------------------------------------------------------//
// loosely coupling ( 약한 결합 ) : 하나의 클래스가 다른 클래스를 사용할때
//									기반 클래스인 추상클래스(인터페이스)를 통해서 사용하는 것

//									교체 가능한 유연한 디자인.
//									OCP를 만족한다.

//------------------------------------------------------------------------------------------//
// 카메라 제작자와 카메라 사용자 사이에 지켜야하는 규칙을 먼저 설계한다.
// 규칙 : 모든 카메라는 아래 클래스로부터 파생되어야 한다. ( take를 만들어야 한다. )
//		" 모든 카메라는 아래 인터페이스를 구현해야 한다."라고 표현한다.
// ICamera* p ==> 포인터,,,
// 추상 클래스 = 규칙 + 구현
// 인터페이스 : 규칙
/*
#define interface struct


interface ICamera
{
	virtual void take() = 0;

	// java
	void take();
};
*/
class ICamera
{
public:
	virtual void take() = 0;
};

// 아직 진짜 카메라는 없다... 하지만 규칙은 있다.
// 사용자는 규칙 대로만 사용하면 된다.
class People
{
public:
	void useCamera(ICamera* p) { p->take(); }
};

// 이제, 모든 카메라 제작자는 규칙을 지켜야 한다.
class Camera : public ICamera
{
public:
	void take() { cout << "take picture using Camera" << endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { cout << "take picture using HDCamera" << endl; }
};
class UHDCamera : public ICamera
{
public:
	void take() { cout << "take picture using UHDCamera" << endl; }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera c2;
	p.useCamera(&c2);	// ???

	UHDCamera c3;
	p.useCamera(&c3);
}