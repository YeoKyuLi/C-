//11_OOP2
//프로그램에 필요한 타입을 먼저 설계한후 사용하자

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