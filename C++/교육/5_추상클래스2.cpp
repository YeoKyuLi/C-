// 5_추상클래스2
#include <iostream>
using namespace std;

// tightly coupling ( 강한 결합 ) : 하나의 클래스가 다른 클래스를 사용할때
//									클래스 이름을 직접 사용하는 것.

//									교체 불가능한 경직된 디자인
//									OCP를 만족할 수 없다.

class Camera
{
public :
	void take() { cout << "take picture using Camera" << endl; }
};

class HDCamera
{
public:
	void take() { cout << "take picture using HDCamera" << endl; }
};


class People
{
public:
	void useCamera(Camera* p) { p->take(); }
	void useCamera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera c2;
	p.useCamera(&c2);	// ???
}