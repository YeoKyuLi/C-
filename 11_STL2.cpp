// 11_STL2
#include <iostream>
#include <vector>			// 크기 조절이 가능한 배열과 유사한 컨테이너
#include <forward_list>		// 싱글 리스트
#include <list>				// 더블 리스트
#include <set>				// RB TREE
#include <map>				// Key 값으로 data 보관

using namespace std;

// STL : Standard Template Library

// 핵심 3. 대부분의 컨테이너는 요소를 제거하는 함수와
//			꺼내는 함수가 분리되엉 ㅣㅆ다.

//			back(), front(); // 꺼내기만 한다.
//			pop_back(), pop_front(); // 제거만하고 리턴하지 않는다.

		

int main()
{
	vector<int> s;
	s.push_back(10);
	s.push_back(20);

	//cout << s.pop_back() << endl;	// error, 제거만 하고 리턴하지 않는다.

	cout << s.back() << endl;	// 20, 리턴만하고 제거안됨.
	cout << s.back() << endl;	// 20, 리턴만 하고 제거 안됨.

	// vector, list 등은 : push_back(), pop_back(), back()
	// stack : push(), pop(), top()
}