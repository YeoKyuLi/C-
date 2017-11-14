// 8_friend

class Point
{
private :
	int x, y;
public :
	//friend 함수 선언 : 멤버 함수가 아니지만, 일반 함수지만 private 멤버에 접근할 수 있게한다.
	friend int main();
};

int main()
{
	Point p;
	p.x = 10;
}