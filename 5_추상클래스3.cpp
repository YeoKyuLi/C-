// 5_�߻�Ŭ����3
#include <iostream>
using namespace std;
//------------------------------------------------------------------------------------------//
// tightly coupling ( ���� ���� ) : �ϳ��� Ŭ������ �ٸ� Ŭ������ ����Ҷ�
//									Ŭ���� �̸��� ���� ����ϴ� ��.

//									��ü �Ұ����� ������ ������
//									OCP�� ������ �� ����.

//------------------------------------------------------------------------------------------//
// loosely coupling ( ���� ���� ) : �ϳ��� Ŭ������ �ٸ� Ŭ������ ����Ҷ�
//									��� Ŭ������ �߻�Ŭ����(�������̽�)�� ���ؼ� ����ϴ� ��

//									��ü ������ ������ ������.
//									OCP�� �����Ѵ�.

//------------------------------------------------------------------------------------------//
// ī�޶� �����ڿ� ī�޶� ����� ���̿� ���Ѿ��ϴ� ��Ģ�� ���� �����Ѵ�.
// ��Ģ : ��� ī�޶�� �Ʒ� Ŭ�����κ��� �Ļ��Ǿ�� �Ѵ�. ( take�� ������ �Ѵ�. )
//		" ��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�."��� ǥ���Ѵ�.
// ICamera* p ==> ������,,,
// �߻� Ŭ���� = ��Ģ + ����
// �������̽� : ��Ģ
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

// ���� ��¥ ī�޶�� ����... ������ ��Ģ�� �ִ�.
// ����ڴ� ��Ģ ��θ� ����ϸ� �ȴ�.
class People
{
public:
	void useCamera(ICamera* p) { p->take(); }
};

// ����, ��� ī�޶� �����ڴ� ��Ģ�� ���Ѿ� �Ѵ�.
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