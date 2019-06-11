// 7_가상함수의원리
#include <iostream>

class Animal
{
public:
	void Cry() {}
};
class Dog : public Animal
{
public:
	void Cry() {}
};

int main()
{
	Animal a;
	Dog d;
	Animal *p = &d;
	p->Cry();
}
// p->Cry(); 를 어느 함수와 연결할까를 결정하는 작업 - 함수 바인딩(binding)

// 1. static binding : static 컴파일 시간을 의미
//						컴파일 시간에 컴파일러가 어느 함수를 호출할지 결정
//						컴파일러는 실제 객체를 알 수 없다. 포인터 타입만 알고있다.
//						Animal Cry 호출
//						early binding, 빠르다. C++, C#

// 2. dynamic binding : 컴파일 시간에 p가 가르키는 메모리를 조사하는 기계어 코드 생성
//						실행시간에 조사 후 호출
//						Dog Cry 호출
//						late binding, 느리다. JAVA(디자인 우선적) , Objective-C, swift
//											  virtual 함수 dynamic binding 해줘 in C++ / C# 


