// 8_friend

class Point
{
private :
	int x, y;
public :
	//friend �Լ� ���� : ��� �Լ��� �ƴ�����, �Ϲ� �Լ����� private ����� ������ �� �ְ��Ѵ�.
	friend int main();
};

int main()
{
	Point p;
	p.x = 10;
}