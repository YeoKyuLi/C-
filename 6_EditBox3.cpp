// 6_EditBox3

#include <iostream>
#include <string>	// C++�� java ó�� string Ŭ������ �ֽ��ϴ�.
#include <conio.h>	// _getch()
using namespace std;

class EditBox
{
	string data;
public:
	// ������ ���� ��ü�帧(�˰���)�ӿ� ���ؾ��ϴ� ���(��å)�� �ִٸ�
	// ���ؾ� �ϴ� ���� �и��ؾ� �Ѵ�.
	
	// ���1, ���ϴ� ���� �����Լ��� �и��Ѵ�. (�ڹٴ� ��� �Լ��� �����̹Ƿ�
	//											���ϴ� �κ��� �׳� �ٸ� �Լ��� �и�)

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


// validation ��å�� �����Ϸ��� �Ļ� Ŭ������ ���� �����Լ��� ������ �Ѵ�.
class AddressEdit : public EditBox
{
public :
	virtual bool validate(char c) { return true; }; // ��� ���� �Է�.
};

class CountEdit : public EditBox
{
public:
	virtual bool validate(int i) { return true; }; // ���ڸ� �Է�.
};
int main()
{
	//EditBox edit;
	// ��å ��ü�� �ȵȴ�.
	AddressEdit edit;
	string s = edit.getData();
	cout << s << endl;

	CountEdit edit2;
	string s1 = edit2.getData();
	cout << s1 << endl;
}