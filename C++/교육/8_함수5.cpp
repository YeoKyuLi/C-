//8_�Լ�5.cpp
//inline
// ���� : ������.
// ���� : ũ�Ⱑ ū �Լ��� ������ ġȯ�ϸ� ���� �ڵ尡 Ŀ����.
// static�̳� �Լ� ������, ���ȣ�ⰰ�� ��쿡�� � ������� ó���ϴ°� ==>

	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	Add1(1, 2); //�Լ� ȣ��
	Add2(1, 2); //�Լ� ���� �ڵ� ġȯ
}