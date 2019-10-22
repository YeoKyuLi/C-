//½Ç½À1.cpp

#include <iostream>

using namespace std;

template<typename T> T Add(T a, T b)
{
	return a + b;
}
template<typename T, typename U> auto Add2(T a, U b) -> decltype(a + b)
{
	return a + b;
}
int main()
{
	cout << Add(1, 2) << endl;
	cout << Add(1.1, 2.2) << endl;

	cout << Add2(4, 5.5) << endl;
}