
/*
int square(int a)
{
	return a*a;
}
double square(double a)
{
	return a*a;
}
*/

//Ʋ�� ����� type�̶�� ���ڸ� �޾Ƽ� ���ǵ� type(T)�� �������� �Լ��� ����.
//��� Ÿ���� �Լ��� �����ϴ� ���̴�. template��
//�Լ� Ư¡ 3. �Լ� ���ø�
//				���� �Լ��� �ƴ϶�
//				�Լ��� ������ Ʋ(template)

template <typename T> T square(T a)
{
	return a*a;
}

int main()
{
	square<int>(3); //int ������ square ������, ���
	square<double>(3.3); //double ������ square ������, ���
	
	//template���� <int><double> ���� ����.
	square(3);
	square(3.3); //T�� double�� ������ �Լ�����.
	
	//square(3);
	//square(3.3);
}