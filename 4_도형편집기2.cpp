// 4_도형편집기2

#include <iostream>
#include <vector>		

using namespace std;

// 5. OCP : 기능 확장에는 열려있고 (Open, 클래스가 나중에 추가 되어도)
//			코드 수정에는 닫혀 있도록(Close, 기존 코드가 변경되지 않게)
//			디자인 하는 원칙(Principle)
//			다형성(가상함수 기반 설계)는 OCP를 만족한다.
// 6. Prototype 패턴 : 기존의 객체를 복사해서 새로운 객체를 만드는 패턴.
//						"객체 복사하기" 메뉴를 구할때 편리하다.
//						java의 최상위 클래스에는 clone() 함수가 있고
//						ios의 cocoa 라이브러리는 copy() 함수가 있다.
//						모두 이 패턴기반의 설계,,,

class Shape
{
public:
	virtual void Draw() { cout << "Shape Draw" << endl; }
	// 자신의 복사본을 만드는 가상함수가 있으면 편리하다.
	// 복사본으로 복사 생성자로 생성.
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
			cout << " 몇 번째 도형을 복사 할까요 ?? ";

			int k;
			cin >> k;
			// k 번째 도형의 복사본을 만들어서 v에 추가한다.
			// 그런데, k 번째 도형은 어떤 도형인가?????????????

			v.push_back(v[k]->Clone()); // 다형성...

		}

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw();	// 다형성(polymorphism)
								// 동일한 함수 호출 표현식이
								// 상황(객체의 종류)에 따라 다른 함수를 호출하는 것.

		}
	}
}
