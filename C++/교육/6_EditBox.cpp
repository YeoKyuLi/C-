// 6_EditBox

#include <iostream>
#include <string>	// C++�� java ó�� string Ŭ������ �ֽ��ϴ�.
#include <conio.h>	// _getch()
using namespace std;

class EditBox
{
	string data;
public :
	string getData()
	{
		cin >> data;
		return data;
	}
};

int main()
{
	EditBox edit;
	string s = edit.getData();
	cout << s << endl;
}