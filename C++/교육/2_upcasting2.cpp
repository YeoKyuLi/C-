//2_upcasting2.cpp

//2_upcasting

class Animal
{
public:
	int age;
	void Cry() {}
};

class Dog : public Animal
{
public:
	int color;
};

class Cat : public Animal {};
// �ų��� �Ǹ� �� �� �����ϴ� �Լ�.
//void NewYear(Dog* p) // Dog�� ó���ϴ� �Լ�.
void NewYear(Animal* p)	// ����(��� ����, Animal �Ļ� Ŭ����)�� ó���ϴ� �Լ�.
{
	++(p->age);
}
int main()
{
	Dog d; NewYear(&d);
	Cat c; NewYear(&c);

	Dog* woori1[10];		// Dog�� ����
	Animal* woori2[10];		// ��� ������ �����ϴ� �����̳�
}