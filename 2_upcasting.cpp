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
	int* p2 = &d;	// error, 관련 없는 타입의 주소를 담을 수 없다.
	Animal* p3 = &d;	// ok. 기반 클래스 포인터는 파생 클래스의 주소를 담을 수 있다. 
						// 자바 - 기반클래스의 참조,

	p3->age = 10;		// ok
	p3->color = 20;		// animal 안에 color가 없기 때문에 error, animal이 color에 접근 불가능.
						// 기반 클래스 포인터로 자식의 고유 멤버를 접근할 수 없다.
	((Dog*)p3)->color = 20; // ok
}