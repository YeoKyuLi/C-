// 11_STL2
#include <iostream>
#include <vector>			// ũ�� ������ ������ �迭�� ������ �����̳�
#include <forward_list>		// �̱� ����Ʈ
#include <list>				// ���� ����Ʈ
#include <set>				// RB TREE
#include <map>				// Key ������ data ����

using namespace std;

// STL : Standard Template Library

// �ٽ� 3. ��κ��� �����̳ʴ� ��Ҹ� �����ϴ� �Լ���
//			������ �Լ��� �и��Ǿ� �Ӥ���.

//			back(), front(); // �����⸸ �Ѵ�.
//			pop_back(), pop_front(); // ���Ÿ��ϰ� �������� �ʴ´�.

		

int main()
{
	vector<int> s;
	s.push_back(10);
	s.push_back(20);

	//cout << s.pop_back() << endl;	// error, ���Ÿ� �ϰ� �������� �ʴ´�.

	cout << s.back() << endl;	// 20, ���ϸ��ϰ� ���žȵ�.
	cout << s.back() << endl;	// 20, ���ϸ� �ϰ� ���� �ȵ�.

	// vector, list ���� : push_back(), pop_back(), back()
	// stack : push(), pop(), top()
}