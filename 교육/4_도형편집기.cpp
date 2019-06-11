// 4_도형편집기

#include <iostream>
#include <vector>		// 배열과 유사한 컨테이너

using namespace std;

// 파워 포인터 같은 도형 편집기 만들어 보자
// 1. 모든 도형을 타입으로 설계한다.
// 2. 모든 도형의 공통의 기반 클래스가 있으면 묶어서 관리 할 수 있다.
// 3. 모든 도형의 공통의 특징은 반드시 기반 클래스에도 있어야 한다.
//		그래야 기반 클래스 포인터(자바는 참조)로 해당 특징을 사용 할 수 있다.
// 4. 파생 클래스가 재정의(override)하게 되는 함수는 반드시 가상함수이어야 한다.
//		java는 모든 함수수가 가상함수 이므로 무조건 ok
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
// 컴파일 하면 에러가 있다. 왜 에러인가??