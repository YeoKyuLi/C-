// 6_EditBox2

#include <iostream>
#include <string>	// C++도 java 처럼 string 클래스가 있습니다.
#include <conio.h>	// _getch()
using namespace std;

class EditBox
{
	string data;
public:
	string getData()
	{
		data.clear();	// 기존입력 내용 제거 후
		while (1)
		{
			char c = _getch();	// 한 자 입력받는 함수 - 화면에 나타나지 않음.

			if (c == 13) break;	// 엔터키 입력
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