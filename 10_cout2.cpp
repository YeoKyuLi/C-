//10_cout2

//#include <iostream>
//using namespace std;

#include <stdio.h>
class ostream
{
public:
	ostream& operator<<(int n) { printf("%d", n); return *this; }
	ostream& operator<<(double d) { printf("%f", d); return *this; }
	ostream& operator<<(const char* s) { printf("%s", s); return *this; }
	ostream& operator<<(ostream&(*f)(ostream&)) // 함수 포인터
	{
		// 현재 f : endl 함수
		// *this : cout
		f(*this);
		return *this; 
	}


};
ostream cout; //  생성자를 부르면 객체라고 한다.


ostream& endl(ostream& os)
{
	os << "\n";
	return os;
}
int main()
{
	cout << "\n"; // 현재 cout은 "\n" 출력 가능.
	endl(cout);
	cout << endl; // cout.operator<<(endl)
					// cout.operator<<( 함수 포인터 )
}