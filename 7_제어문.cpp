//7_���
#include <iostream>
using namespace std;

int foo() { return 0; }

int main() {
	/*
	int n = foo();
	if (n == 0)
		cout << "fail" << endl;
		*/

	//c++17

	if (  int n = foo() ; n == 0  )
		cout << "fail" << endl;

}
//���常 : ctrl + shift + B
//���� + ���� : ctrl + F5