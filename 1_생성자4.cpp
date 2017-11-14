//1_생성자4

#include <iostream>
using namespace std;

// 핵심 : 초기화 리스트의 실행순서는 멤버가 놓인 순서대로 초기화 된다.
//			코드의 순서는 의미가 없다.
class Point
{
	//멤버버버버버버
public:
	int y;
	int x;


public:
	// 초기화는 메모리의 순서대로 진행한다.
	Point(int a = 0, int b = 0 ) : y(b), x(y) // defalut param 으로 설정
	{

	}
};



int main()
{
	Point p; //1,1로 초기화 됨.

	cout << p.x << endl;	// 쓰레기 값
	cout << p.y << endl;	// 0
}