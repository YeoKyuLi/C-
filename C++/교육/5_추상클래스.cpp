// 5_�߻�Ŭ����


// Abstract Class : ���� ���� �Լ��� 1�� �̻� �ִ� Ŭ����.
// �ǵ� : �Ļ� Ŭ�������� Ư�� �Լ��� ������ �����ϴ� ��.

class Shape
{
public :
	virtual void Draw() = 0;	// ���� �����Լ�(pure virtual function)
								// �����ΰ� ���� "=0" �� ǥ���Ѵ�.
								// java : abstract method ����.
};

class Rect : public Shape
{
public:
	// Draw�� �����θ� �������� ������, Rect�� ���� �߻� Ŭ�����̴�.
	// �������� �����ϸ� �߻�Ŭ������ �ƴϴ�. ��ü Ŭ����(Concreate class)�̴�.


};

int main()
{
	Shape s;	// error. �߻� Ŭ������ ��ü�� ���� �� ����.
	Rect r;		

}