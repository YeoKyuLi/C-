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
// 신년이 되면 한 살 증가하는 함수.
//void NewYear(Dog* p) // Dog만 처리하는 함수.
void NewYear(Animal* p)	// 동종(모든 동물, Animal 파생 클래스)을 처리하는 함수.
{
	++(p->age);
}
int main()
{
	Dog d; NewYear(&d);
	Cat c; NewYear(&c);

	Dog* woori1[10];		// Dog만 저장
	Animal* woori2[10];		// 모든 동물을 저장하는 컨테이너
}