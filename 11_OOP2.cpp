//11_OOP2
//���α׷��� �ʿ��� Ÿ���� ���� �������� �������

struct Complex
{
	int real;
	int image;
};

Complex Add(const Complex& c1, const Complex& c2)
{
	Complex temp;
	temp.real = c1.real + c2.real;
	temp.image = c1.image + c2.image;
	return temp;

}
int main()
{
	Complex c1 = { 1,1 };
	Complex c2 = { 2,2 };
	Complex c3 = Add(c1, c2);
}