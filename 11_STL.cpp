// 11_STL
#include <iostream>
#include <vector>			// 크기 조절이 가능한 배열과 유사한 컨테이너
#include <forward_list>		// 싱글 리스트
#include <list>				// 더블 리스트
#include <set>				// RB TREE
#include <map>				// Key 값으로 data 보관

using namespace std;

// STL : Standard Template Library

// 특징	1. 대부분 템플릿이다.
//		2. 멤버 함수의 이름이 대부분 동일하다.
//			컨테이너만 변경해서 성능을 비교해 볼 수 있다.
//		

int main()
{
	vector<int> v;		// 연속된 메모리, 삽입/삭제 속도 느리다.
	list<int> v;
	v.push_back(10);	// 
	v.push_back(20);

	for (auto n : v)
		cout << n << endl;
}