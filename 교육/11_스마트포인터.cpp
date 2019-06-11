// 11_����Ʈ������
// 

#include <iostream>
using namespace std;

class Car
{
	int color;
public :
	void Go()	{ cout << "Car Go" << endl; }
	~Car() { cout << "~Car() " << endl; }
};
// �ٽ� �ڵ�
// ����Ʈ ������, ���� : ��ü�� �ٸ� Ÿ���� ������ ������ �ϴ� ��,
// ���� : ��¥ �����Ͱ� �ƴ� ��ü�̴�.
//			����/����/����/�Ҹ��� ������ ������ �� �ְ� �ȴ�.
//			ex) �Ҹ��ڿ��� ��ü�� �ڵ� �����ϴ� ��� �ο�..................
// ���� : -> �� * �����ڸ� ������ �ؼ� ������ ó�� ���̰� �Ѵ�.
class Ptr
{
	Car* obj;
public :
	Ptr(Car* p = 0) : obj(p) {}
	~Ptr() { delete obj; } // �ڿ� ����
	Car* operator->() { return obj; }
	Car& operator*() { return *obj; } // ��, ����
};
int main()
{
	Ptr p = new Car;	// Ptr p(new Car) �� ����
	p->Go();			// p +a ==> p.operator+(a)
						// p-> : p.operator->() �� ã�� �ȴ�.
						// ( p.operator->() ) Go()�� ����� �Ǵµ�,
						// ( p.operator->() )-> Go()�� �ؼ����ش�.

	(*p).Go();			// �� ǥ���� �Ǿ��Ѵ�.
						// p.operator*()
	// �����ʹ� �Լ��� ������ �޸𸮿��� ���ŵǰų� ��� ������ ����.
}
