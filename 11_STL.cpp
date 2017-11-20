// 11_STL
#include <iostream>
#include <vector>			// ũ�� ������ ������ �迭�� ������ �����̳�
#include <forward_list>		// �̱� ����Ʈ
#include <list>				// ���� ����Ʈ
#include <set>				// RB TREE
#include <map>				// Key ������ data ����

using namespace std;

// STL : Standard Template Library

// Ư¡	1. ��κ� ���ø��̴�.
//		2. ��� �Լ��� �̸��� ��κ� �����ϴ�.
//			�����̳ʸ� �����ؼ� ������ ���� �� �� �ִ�.
//		

int main()
{
	vector<int> v;		// ���ӵ� �޸�, ����/���� �ӵ� ������.
	list<int> v;
	v.push_back(10);	// 
	v.push_back(20);

	for (auto n : v)
		cout << n << endl;
}