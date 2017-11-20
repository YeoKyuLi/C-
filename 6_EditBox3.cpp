// 6_EditBox3

#include <iostream>
#include <string>	// C++도 java 처럼 string 클래스가 있습니다.
#include <conio.h>	// _getch()
using namespace std;

class EditBox
{
	string data;
public:
	// 변하지 않은 전체흐름(알고리즘)속에 변해야하는 요소(정책)이 있다면
	// 변해야 하는 것을 분리해야 한다.
	
	// 방법1, 변하는 것을 가상함수로 분리한다. (자바는 모든 함수가 가상이므로
	//											변하는 부분을 그냥 다른 함수로 분리)

	virtual bool validate(char c)
	{
		return isdigit(c);
	}

	string getData()
	{
		data.clear();	
		while (1)
		{
			char c = _getch();	

			if (c == 13) break;
			if (validate(c))
			{
				cout << c;
				data.push_back(c);
			}
		}
		cout << endl;
		return data;
	}
};


// validation 정책을 변경하려면 파생 클래스를 만들어서 갓아함수를 재정의 한다.
class AddressEdit : public EditBox
{
public :
	virtual bool validate(char c) { return true; }; // 모든 문자 입력.
};

class CountEdit : public EditBox
{
public:
	virtual bool validate(int i) { return true; }; // 숫자만 입력.
};
int main()
{
	//EditBox edit;
	// 정책 교체가 안된다.
	AddressEdit edit;
	string s = edit.getData();
	cout << s << endl;

	CountEdit edit2;
	string s1 = edit2.getData();
	cout << s1 << endl;
}