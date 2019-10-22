// 11_����Ʈ������3
// 

#include <iostream>
#include <memory> // C++11 ǥ�� ����Ʈ�����͸� �����ϴ� ���,
using namespace std;

class Car
{
	int color;
public:
	void Go() { cout << "Car Go" << endl; }
	~Car() { cout << "~Car() " << endl; }
};

int main()
{
//	shared_ptr<Car> p1 = new Car; // error, �ݵ�� () �ʱ�ȭ�� �ش��մϴ�.
	shared_ptr<Car> p2(new Car); // ok

	shared_ptr<Car> p3 = p2;	// ��������� 2�� �����մϴ�.

	p3->Go();
}
