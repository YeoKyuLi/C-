//C++ �Լ� Ư¡ 6 - �Լ� ����

int gcd(int a, int b) //�ִ� ����� ���ϱ�
{
	return 0;
}
//�Լ� ���� ���� - C++11/ ����Ϸ��� �ϸ� ������ ����.
double gcd(double a, double b) = delete;

int main()
{
	gcd(10, 5);
	gcd(3.3, 5.5);
}