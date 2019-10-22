// 6_EditBox4

#include <iostream>
#include <string>	// C++도 java 처럼 string 클래스가 있습니다.
#include <conio.h>	// _getch()
using namespace std;


// 변하지 않은 코드내에 있는 변해야 하는 요소(정책)을 분리하는 방법
// 1. 변하는 것을 가상함수로
// 2. 변하는 것을 다른 클래스로
// 교체 가능해야 하므로 인터페이스 먼저 설계한다.
// 모든 정책은 아래 인터페이스를 구현해야한다.

struct Ivalidator
{
	virtual bool validate(string s, char c) = 0;
	virtual bool iscomplete(string s) { return true; }
};
// 주민 번호 : 901 확인?/??...,/.,.


class EditBox
{
	string data;

	Ivalidator* pVal;
public:
	EditBox() : pVal(0) {}	// defalut

	void setValidate(Ivalidator* p) { pVal = p; }
	string getData()
	{
		data.clear();
		while (1)
		{
			char c = _getch();	

			if (c == 13 && (pVal == 0 || pVal -> iscomplete(data)) ) break;
			if (pVal == 0 || pVal ->validate(data,c)) // 값의 유효성 여부를 다른 클래스를 사용해서 확인.
			{
				cout << c;
				data.push_back(c);
			}
		}
		cout << endl;
		return data;
	}
};

// 다양한 종류의 validator를 제공한다.
class LimitDigitValidator : public Ivalidator
{
	int limit;
public :
	LimitDigitValidator(int n) : limit(n) {}

	virtual bool validate(string s, char c)
	{
		return s.size() < limit && isdigit(c);
	}
	
	virtual bool iscomplete(string s)
	{
		return s.size() == limit;

	}
};

int main()
{
	// 정책 교체가 된다.....
	// 정책의 효율성이 높아 진다. 
	// 전략 패턴...
	EditBox edit;
	LimitDigitValidator v(5);
	edit.setValidate(&v); // validator 정책 전달.


	string s = edit.getData();
	cout << s << endl;
}