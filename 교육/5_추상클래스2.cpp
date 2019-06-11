// 5_�߻�Ŭ����2
#include <iostream>
using namespace std;

// tightly coupling ( ���� ���� ) : �ϳ��� Ŭ������ �ٸ� Ŭ������ ����Ҷ�
//									Ŭ���� �̸��� ���� ����ϴ� ��.

//									��ü �Ұ����� ������ ������
//									OCP�� ������ �� ����.

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