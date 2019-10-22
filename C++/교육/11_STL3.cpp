// 11_STL3
#include <iostream>
#include <vector>			// ũ�� ������ ������ �迭�� ������ �����̳�
#include <forward_list>		// �̱� ����Ʈ
#include <list>				// ���� ����Ʈ
#include <set>				// RB TREE
#include <map>				// Key ������ data ����

using namespace std;

// STL : Standard Template Library


int main()
{
	list<int> s;
	s.push_back(10);
	s.push_back(20);
	s.push_back(30);
	s.push_back(40);

	// �ݺ��� (iterator) : �����̳��� ��� ��Ҹ� �����ϴ� ��ü
	// java
	/*
	iterator it = s.iterator();
	int n = it.get(); // get data-- need to find
	it.next();	// move
	*/

	//list<int>::iterator p1 = s.begin();	// start
	//list<int>::iterator p2 = s.end();	// end ������ ���� ���

	auto p1 = s.begin();
	auto p2 = s.end();

	cout << *p1 << endl;	//10
	++p1;
	cout << *p1 << endl;	//20

	// STL �ݺ��� : �����Ϳ� �����ϰ� ����ϵ��� ������ �Ǿ��ִ�.
	//				++�� �̵��ϰ� *�� ������.

	// s.begin(); // ù��° ��Ҹ� ����Ű�� �ݺ���
	// s.end();		// ������ �������, past the end ��� �θ���.

	auto p3 = s.end();
	*p3 = 10; // runtime error

	// �ݺ��ڸ� ����ؼ� ��� ��� ����...
	// [first, last) [ ==> ���� , ) ==> ���� ����.
	auto p4 = s.begin();

	while (p4 != s.end())	// �������� Ȯ���ϱ� ���ؼ� ���.
	{
		cout << *p4 << endl;
		++p4;
	}

}