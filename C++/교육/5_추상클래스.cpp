// 5_추상클래스


// Abstract Class : 순수 가상 함수가 1개 이상 있는 클래스.
// 의도 : 파생 클래스에서 특정 함수를 만들라고 지시하는 것.

class Shape
{
public :
	virtual void Draw() = 0;	// 순수 가상함수(pure virtual function)
								// 구현부가 없고 "=0" 을 표시한다.
								// java : abstract method 개념.
};

class Rect : public Shape
{
public:
	// Draw의 구현부를 제공하지 않으면, Rect도 역시 추상 클래스이다.
	// 구현부을 제공하면 추상클래스가 아니다. 구체 클래스(Concreate class)이다.


};

int main()
{
	Shape s;	// error. 추상 클래스는 객체를 만들 수 없다.
	Rect r;		

}