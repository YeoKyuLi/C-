//�ݺ���.cpp

#include <iostream>

using namespace std;

int main()
{
	int x[3] = { 1,2,3 };

	for (auto n : x)//range-for C++11, Java�� foreach
		cout << n << endl;

	/*
	for (int i = 0; i < 3; i++)
		cout << x[i] << endl;
		*/


}