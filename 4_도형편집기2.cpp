// 4_����������2

#include <iostream>
#include <vector>		

using namespace std;

// 5. OCP : ��� Ȯ�忡�� �����ְ� (Open, Ŭ������ ���߿� �߰� �Ǿ)
//			�ڵ� �������� ���� �ֵ���(Close, ���� �ڵ尡 ������� �ʰ�)
//			������ �ϴ� ��Ģ(Principle)
//			������(�����Լ� ��� ����)�� OCP�� �����Ѵ�.
// 6. Prototype ���� : ������ ��ü�� �����ؼ� ���ο� ��ü�� ����� ����.
//						"��ü �����ϱ�" �޴��� ���Ҷ� ���ϴ�.
//						java�� �ֻ��� Ŭ�������� clone() �Լ��� �ְ�
//						ios�� cocoa ���̺귯���� copy() �Լ��� �ִ�.
//						��� �� ���ϱ���� ����,,,

class Shape
{
public:
	virtual void Draw() { cout << "Shape Draw" << endl; }
	// �ڽ��� ���纻�� ����� �����Լ��� ������ ���ϴ�.
	// ���纻���� ���� �����ڷ� ����.
	virtual Shape* Clone() { return new Shape(*this); }
};

class Rect : public Shape
{
public:
	virtual void Draw() { cout << "Rect Draw" << endl; }
	virtual Shape* Clone() { return new Rect(*this); }
};
class Circle : public Shape
{
public:
	virtual void Draw() { cout << "Circle Draw" << endl; }
	virtual Shape* Clone() { return new Circle(*this); }
};
class Triangle : public Shape
{
public:
	virtual void Draw() { cout << "Triangle Draw" << endl; }
	virtual Shape* Clone() { return new Triangle(*this); }
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

		else if (cmd == 8)
		{
			cout << " �� ��° ������ ���� �ұ�� ?? ";

			int k;
			cin >> k;
			// k ��° ������ ���纻�� ���� v�� �߰��Ѵ�.
			// �׷���, k ��° ������ � �����ΰ�?????????????

			v.push_back(v[k]->Clone()); // ������...

		}

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw();	// ������(polymorphism)
								// ������ �Լ� ȣ�� ǥ������
								// ��Ȳ(��ü�� ����)�� ���� �ٸ� �Լ��� ȣ���ϴ� ��.

		}
	}
}
