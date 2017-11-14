//10_cout4

#include <iostream>
using namespace std;

class Point
{
	int x, y;

public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}
	friend ostream& operator<<(ostream& os, const Point& p);
};

ostream& operator<<(ostream& os, const Point& p)
{
	os << p.x << "," << p.y;
	return os;
}
int main()
{
	Point p(1, 2);
	cout << p; // cout.operator<<( Point) 가 있으면 된다.
				// 하지만 cout의 멤버로 추가할 수 없다.
				// operator<<(cout, p)로 할 수 있다.
}