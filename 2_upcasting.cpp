//2_upcasting

class Animal
{
public :
	int age;
	void Cry() {}
};

class Dog : public Animal
{
public:
	int color;
};

int main()
{
	Dog d;	// memory --> age, color
	Dog* p1 = &d;	// ok
	int* p2 = &d;	// error, ���� ���� Ÿ���� �ּҸ� ���� �� ����.
	Animal* p3 = &d;	// ok. ��� Ŭ���� �����ʹ� �Ļ� Ŭ������ �ּҸ� ���� �� �ִ�. 
						// �ڹ� - ���Ŭ������ ����,

	p3->age = 10;		// ok
	p3->color = 20;		// animal �ȿ� color�� ���� ������ error, animal�� color�� ���� �Ұ���.
						// ��� Ŭ���� �����ͷ� �ڽ��� ���� ����� ������ �� ����.
	((Dog*)p3)->color = 20; // ok
}