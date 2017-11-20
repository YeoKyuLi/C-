// 11_STL4

#include <iostream>
#include <vector>			// ũ�� ������ ������ �迭�� ������ �����̳�
#include <forward_list>		// �̱� ����Ʈ
#include <list>				// ���� ����Ʈ
#include <set>				// RB TREE
#include <map>				// Key ������ data ����
#include <algorithm>		// "reverse()" ���� �Ϲ��Լ��� STL���� �˰����̶�� �θ���.

using namespace std;

// STL : Standard Template Library
//	���ͳ��̳ʿ� ����Ǵ� ��κ��� �˰����� ��� �Լ��� �ƴ� �Ϲ� �Լ��̴�.
//	"�ڷᱸ���� �˰����� �и��� ���̺귯��"
//	www.cppreference.com

int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// s�� ��� ��Ҹ� ������ �ʹ�.
	reverse(s.begin(), s.end());
	
	for (auto n : s)
		cout << n << " ";
	cout << endl;

	//vector�� ������ �Ŀ� ����� ������.
	reverse(v.begin(), v.end());
	for (auto n : v)
		cout << n << " " ;
	cout << endl;
}