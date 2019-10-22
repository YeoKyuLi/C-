// 6_EditBox

#include <iostream>
#include <string>	// C++도 java 처럼 string 클래스가 있습니다.
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