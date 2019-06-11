//1_상속2

#include <iostream>
using namespace std;

// 

class Animal
{
	// 자바의 상속 개념에는 하나의 개념이 더 있다.
private:
	int age;	// 자신의 멤버 함수, friend 함수만 접근 가능.

protected :
	int data;	// 자심의 멤버함수, friend 함수, 
				// 파생 클래스의 멤버 함수, friend 함수에서 접근가능.
public:
	int data2;	// 모든 함수가 접근 가능.
	void Cry() {}
};

class Dog : public Animal	
{
	int color;
public:
	void foo()
	{
		age = 10;	//error
	}
};

int main()
{


}