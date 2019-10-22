// 11_STL5
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;

	// STL list �ϳ� �����
	list<int> s;

	// ����ڰ� -1�� �Է��Ҷ����� ���ڸ� �Է¹޾Ƽ�
	// s�� ��������.
	
	while (n != (-1))
	{
		cin >> n;
		s.push_back(n);
	}

	// s�� ��� ���� ����� ������ -> range for �� ���

	for (auto n : s)
		cout << n << " ";
	cout << endl;
	// s���� 3�� �� �� �������� ã�� ������ - cppreference.com����
	// count() �Լ� ���� Ȯ���� ������.
	int n2 = count(s.begin(), s.end(), 3);

	cout << n2 << endl;
}