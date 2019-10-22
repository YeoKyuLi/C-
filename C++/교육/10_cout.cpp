//10_cout

//#include <iostream>
//using namespace std;

#include <stdio.h>
class ostream
{
public :
	ostream& operator<<(int n)			{ printf("%d", n); return *this; }
	ostream& operator<<(double d)		{ printf("%f", d); return *this;}
	ostream& operator<<(const char* s)	{ printf("%s", s); return *this;}
};
ostream cout; //  생성자를 부르면 객체라고 한다.

int main()
{
	int n = 3;
	double d = 3.3;

	cout << n << "A" << "B" << "\n";		// cout.operator<<(n)
	cout << "  ";
	cout << d;		// cout.operator<<(d)
}