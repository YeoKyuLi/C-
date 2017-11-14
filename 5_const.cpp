//5_const
#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;

public :
	Point(int a = 0, int b = 0) : x(a), y(b) {}
	void set(int a, int b) { x = a, y = b; }

	void print() const // 상수 멤버 함수
	{
		//x = 10; //error. 상수 멤버함수 안에서는 멤버의 값을 수정할 수 없다.
		cout << x << "," << y << endl;
	}
};
int main()
{

}