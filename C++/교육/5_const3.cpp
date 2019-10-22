//5_const3
// 수학에서 상수란 그 값이 변하지 않는 불변량으로, 변수의 반대말이다.
// 상수 함수는 선택이 아닌 필수
// 객체의 상태(멤버 데이터)를 변경하지 않은 모든 멤버 함수는
// 반드시 상수 함수가 되어야합니다.
// C++에서 getter는 상수 멤버 함수 이어야 합니다.
class Rect
{
	int x, y, w, h;

public :
	int getArea() const { return w*h; }
};

void foo(const Rect& r) 
{
	int n = r.getArea(); // r => 상수, complie error
}

int main()
{
	Rect r; // 초기화했다고 가정하고...

	int n = r.getArea(); // ok...

	foo(r);
}