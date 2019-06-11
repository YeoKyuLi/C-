// 11_STL5
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;

	// STL list 하나 만들기
	list<int> s;

	// 사용자가 -1을 입력할때까지 숫자를 입력받아서
	// s에 넣으세요.
	
	while (n != (-1))
	{
		cin >> n;
		s.push_back(n);
	}

	// s의 모든 내용 출력해 보세요 -> range for 문 사용

	for (auto n : s)
		cout << n << " ";
	cout << endl;
	// s에서 3이 몇 번 나오는지 찾아 보세요 - cppreference.com에서
	// count() 함수 사용법 확인해 보세요.
	int n2 = count(s.begin(), s.end(), 3);

	cout << n2 << endl;
}