// 6_EditBox2

#include <iostream>
#include <string>	// C++�� java ó�� string Ŭ������ �ֽ��ϴ�.
#include <conio.h>	// _getch()
using namespace std;

class EditBox
{
	string data;
public:
	string getData()
	{
		data.clear();	// �����Է� ���� ���� ��
		while (1)
		{
			char c = _getch();	// �� �� �Է¹޴� �Լ� - ȭ�鿡 ��Ÿ���� ����.

			if (c == 13) break;	// ����Ű �Է�
			if (isdigit(c))
			{
				cout << c;
				data.push_back(c);
			}
		}
		cout << endl;
		return data;
	}
};

int main()
{
	EditBox edit;
	string s = edit.getData();
	cout << s << endl;
}