//�ǽ�3.cpp - �Լ�5.cpp ������ ����.

	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	//int a = 1, b = 2;
	int n1 =  Add1(1, 2); //�Լ� ȣ��
	int n2 = Add2(1, 2); //�Լ� ���� �ڵ� ġȯ
}

//cl �ǽ�3.cpp /FAs /O2 ������ �ϸ� "�ǽ�3.asm" ����
// /FAs : ����� ����� �޶�.
// /O2 : �ӵ� ����ȭ
// /Ob1 : �̶��� ġȯ�� ������ �޶�.
//notepad �ǽ�3.asm �����

//g++ a.cpp -S ==> .s ���� �����˴ϴ�. ����ҽ�
