//7_Á¦¾î¹®
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
//ºôµå¸¸ : ctrl + shift + B
//ºôµå + ½ÇÇà : ctrl + F5