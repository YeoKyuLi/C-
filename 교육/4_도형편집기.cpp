// 4_����������

#include <iostream>
#include <vector>		// �迭�� ������ �����̳�

using namespace std;

// �Ŀ� ������ ���� ���� ������ ����� ����
// 1. ��� ������ Ÿ������ �����Ѵ�.
// 2. ��� ������ ������ ��� Ŭ������ ������ ��� ���� �� �� �ִ�.
// 3. ��� ������ ������ Ư¡�� �ݵ�� ��� Ŭ�������� �־�� �Ѵ�.
//		�׷��� ��� Ŭ���� ������(�ڹٴ� ����)�� �ش� Ư¡�� ��� �� �� �ִ�.
// 4. �Ļ� Ŭ������ ������(override)�ϰ� �Ǵ� �Լ��� �ݵ�� �����Լ��̾�� �Ѵ�.
//		java�� ��� �Լ����� �����Լ� �̹Ƿ� ������ ok
class Shape 
{
public:
	virtual void Draw() { cout << "Shape Draw" << endl; }
};

class Rect : public Shape
{
public :
	virtual void Draw() { cout << "Rect Draw" << endl; }
};
class Circle : public Shape
{
public:
	virtual void Draw() { cout << "Circle Draw" << endl; }
};
int main()
{

	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw();
		}
	}
}
// ������ �ϸ� ������ �ִ�. �� �����ΰ�??