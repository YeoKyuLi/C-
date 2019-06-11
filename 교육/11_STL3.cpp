// 11_STL3
#include <iostream>
#include <vector>			// 크기 조절이 가능한 배열과 유사한 컨테이너
#include <forward_list>		// 싱글 리스트
#include <list>				// 더블 리스트
#include <set>				// RB TREE
#include <map>				// Key 값으로 data 보관

using namespace std;

// STL : Standard Template Library


int main()
{
	list<int> s;
	s.push_back(10);
	s.push_back(20);
	s.push_back(30);
	s.push_back(40);

	// 반복자 (iterator) : 컨테이너의 모든 요소를 열거하는 객체
	// java
	/*
	iterator it = s.iterator();
	int n = it.get(); // get data-- need to find
	it.next();	// move
	*/

	//list<int>::iterator p1 = s.begin();	// start
	//list<int>::iterator p2 = s.end();	// end 마지막 다음 요소

	auto p1 = s.begin();
	auto p2 = s.end();

	cout << *p1 << endl;	//10
	++p1;
	cout << *p1 << endl;	//20

	// STL 반복자 : 포인터와 유사하게 사용하도록 디자인 되어있다.
	//				++로 이동하고 *로 꺼낸다.

	// s.begin(); // 첫번째 요소를 가르키는 반복자
	// s.end();		// 마지막 다음요소, past the end 라고 부른다.

	auto p3 = s.end();
	*p3 = 10; // runtime error

	// 반복자를 사용해서 모든 요소 열거...
	// [first, last) [ ==> 포함 , ) ==> 포함 안함.
	auto p4 = s.begin();

	while (p4 != s.end())	// 종료인지 확인하기 위해서 사용.
	{
		cout << *p4 << endl;
		++p4;
	}

}