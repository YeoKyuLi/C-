//5_const3
// ���п��� ����� �� ���� ������ �ʴ� �Һ�������, ������ �ݴ븻�̴�.
// ��� �Լ��� ������ �ƴ� �ʼ�
// ��ü�� ����(��� ������)�� �������� ���� ��� ��� �Լ���
// �ݵ�� ��� �Լ��� �Ǿ���մϴ�.
// C++���� getter�� ��� ��� �Լ� �̾�� �մϴ�.
class Rect
{
	int x, y, w, h;

public :
	int getArea() const { return w*h; }
};

void foo(const Rect& r) 
{
	int n = r.getArea(); // r => ���, complie error
}

int main()
{
	Rect r; // �ʱ�ȭ�ߴٰ� �����ϰ�...

	int n = r.getArea(); // ok...

	foo(r);
}