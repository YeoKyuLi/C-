// 6_EditBox4

#include <iostream>
#include <string>	// C++�� java ó�� string Ŭ������ �ֽ��ϴ�.
#include <conio.h>	// _getch()
using namespace std;


// ������ ���� �ڵ峻�� �ִ� ���ؾ� �ϴ� ���(��å)�� �и��ϴ� ���
// 1. ���ϴ� ���� �����Լ���
// 2. ���ϴ� ���� �ٸ� Ŭ������
// ��ü �����ؾ� �ϹǷ� �������̽� ���� �����Ѵ�.
// ��� ��å�� �Ʒ� �������̽��� �����ؾ��Ѵ�.

struct Ivalidator
{
	virtual bool validate(string s, char c) = 0;
	virtual bool iscomplete(string s) { return true; }
};
// �ֹ� ��ȣ : 901 Ȯ��?/??...,/.,.


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
			if (pVal == 0 || pVal ->validate(data,c)) // ���� ��ȿ�� ���θ� �ٸ� Ŭ������ ����ؼ� Ȯ��.
			{
				cout << c;
				data.push_back(c);
			}
		}
		cout << endl;
		return data;
	}
};

// �پ��� ������ validator�� �����Ѵ�.
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
	// ��å ��ü�� �ȴ�.....
	// ��å�� ȿ������ ���� ����. 
	// ���� ����...
	EditBox edit;
	LimitDigitValidator v(5);
	edit.setValidate(&v); // validator ��å ����.


	string s = edit.getData();
	cout << s << endl;
}