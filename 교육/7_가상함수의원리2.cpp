// 7_가상함수의원리2

#include <iostream>
using namespace std;

// 전역 변수로(complier's view) ==> 함수포인터 AnimalArray[2] = { &Animal::foo, &Animal::goo };
class Animal
{
	// (complier's view) 배열 포인터* vtptr;
	int age;

public :
	//(complier's view) Animal() : vtptr(AniamlArray) {}
	virtual void foo() {}
	virtual void goo() {}
};


//---------------------------------------------------------------------------------------------
// 전역 변수로(complier's view) ==> 함수포인터 DogArray[2] = { &Animal::foo, &Dog::goo };

class Dog : public Animal
{
	// 배열포인터 * vtptr;
	int color;

public :
	// Dog() : vtptr(DogArray) {}
	virtual void goo() {}
};

int main()
{
	Animal a;
	Dog d;
	Animal* p = &d;
	p->foo();	// 1. p는 animal* 라는 사실을 알고있다.
				// 2. Animal 선언에 가서 foo가 가상함수인지 아닌지 조사
				// 3. 가상이 아니면 무조건 Animal foo 호출
				// 4. 가상이면 몇 번째 가상함수인지 조사후에
				//		p ->vtptr[0]() 라는 기계어 코드 생성
}