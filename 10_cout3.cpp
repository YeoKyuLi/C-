//10_cout3

//#include <iostream>
//using namespace std;
/*
#include <stdio.h>
class ostream
{
public:
	ostream& operator<<(int n) { printf("%d", n); return *this; }
	ostream& operator<<(double d) { printf("%f", d); return *this; }
	ostream& operator<<(const char* s) { printf("%s", s); return *this; }
	ostream& operator<<(ostream&(*f)(ostream&)) // **�Լ� ������**
	{
		f(*this);
		return *this;
	}


};
ostream cout; //  �����ڸ� �θ��� ��ü��� �Ѵ�.


ostream& endl(ostream& os)
{
	os << "\n";
	return os;
}
*/
#include <iostream>
using namespace std;
ostream& twoendl(ostream& os)
{
	os << "\n\n";
	return os;
}

ostream& menu(ostream& os)
{
	os << "1. \n";
	os << "2. \n";
	return os;
}
int main()
{
	cout << endl;	// cout.operator<<(endl)

	cout << "111"<< twoendl;

	cout <<"menu \n" << menu;
}