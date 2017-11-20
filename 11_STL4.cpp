// 11_STL4

#include <iostream>
#include <vector>			// 크기 조절이 가능한 배열과 유사한 컨테이너
#include <forward_list>		// 싱글 리스트
#include <list>				// 더블 리스트
#include <set>				// RB TREE
#include <map>				// Key 값으로 data 보관
#include <algorithm>		// "reverse()" 같은 일반함수를 STL에서 알고리즘이라고 부른다.

using namespace std;

// STL : Standard Template Library
//	컨터네이너에 적용되는 대부분의 알고리즘은 멤버 함수가 아닌 일반 함수이다.
//	"자료구조와 알고리즘이 분리된 라이브러리"
//	www.cppreference.com

int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 뒤집고 싶다.
	reverse(s.begin(), s.end());
	
	for (auto n : s)
		cout << n << " ";
	cout << endl;

	//vector도 뒤집은 후에 출력해 보세요.
	reverse(v.begin(), v.end());
	for (auto n : v)
		cout << n << " " ;
	cout << endl;
}