//2_�Ҹ���

#include <iostream>

using namespace std;


void foo(char* s)
{
	*s = 10;
}

int main()
{
	// C ���ڿ��� ���ؼ�
	// s1 ��  s2�� ������ ?

	char s1[] = "hello"; 

	// foo �� ���ڷ� ���ڿ��� �ް� �ֽ��ϴ�.
	foo(s1); // ���ۿ� �ִ� ���ڿ�, ( �а� ���Ⱑ ������ ���ڿ� ) OK
	foo("hello"); // ��� ���ڿ�		runtime error

	// ���ڿ� ��� �����
	char* s2 = "hello";			// ���⸦ �õ��ϸ� ����ð� ����
	const char* s2 = "hello";	// ���⸦ �õ��ϸ� ������ ����


	*s1 = 'X'; // ok
	char* s2 = "hello";
	*s2 = 'X'; // runtime error ==>  ��� �޸𸮴� read-only memory�� ����ϱ� ������ ����.

	const char* s2 = "hello";
	*s2 = 'X'; // complie error
}
