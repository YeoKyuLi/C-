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
	ostream& operator<<(ostream&(*f)(ostream&)) // �Լ� ������
	{
		// ���� f : endl �Լ�
		// *this : cout
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
int main()
{
	cout << "\n"; // ���� cout�� "\n" ��� ����.
	endl(cout);
	cout << endl; // cout.operator<<(endl)
					// cout.operator<<( �Լ� ������ )
}