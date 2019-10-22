https://github.com/codenuri/CPPINTERMEDIATE/tree/master/201_CPP14
=============delegate constructor=============
1. 위임 생성자
    하나의 생성자에서 다른 생성자를 호출하는 문법
    주의! 임시 객체를 생성하는 표현과 생성자를 호출하는 코드를 헷갈리면 안됨
#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	
	//Point()				: x(0), y(0) {}

	Point() : Point(0,0) // 다른 생성자를 호출
	{
		// 다른 생성자를 호출할수 없을까 ?
		//Point(0, 0);	// 임시객체를 생성하는 표현.

		//new(this) Point(0, 0);

	}
	Point(int a, int b) : x(a), y(b) {}
	//void init() {}
};

int main()
{
	Point p;

	cout << p.x << endl;
	cout << p.y << endl;
}

=============inherit constrcutor=============
1. 상속에서 함수 이름 충돌
    파생 클래스와 동일한 이름을 가지는 함수그 기반 클래스에 있다면, 기반 클래스의 함수를 가려지게(사용할 수 없게) 된다.
    버그를 방지하기 위해 만든 문법
    사용하려면 using을 사용해야 한다.
class Base
{
public:
	void foo(int a) {}
};

class Derived : public Base
{
public:
	using Base::foo;

	void foo() { }
};

int main()
{
	Derived d;
	d.foo(10); // error
	d.foo();
}

2.생성자 상속
    using을 사용하면 할 수 있다.

#include <iostream>
#include <string>
using namespace std;

class Base
{
	string name;
public:
	Base(string s) : name(s) {}
};

class Derived : public Base
{
public:
	using Base::Base;

	//Derived(string s) : Base(s) {}
};

int main()
{
	Derived d("aa");
}

=============override=============
1. override specifier
    c++11
    가상 함수 재정의 시에 override를 붙여도 되고 붙이지 않아도 된다.
    가상 함수 재정의 시 override를 붙이면 보다 안전한 코드를 작성 할 수 있다.
class Base
{
public:
	virtual void f1(int) {}
	virtual void f2() const {}
	virtual void f3() {}
			void f4() {}
};
class Derived : public Base
{
public:
	virtual void f1(int) override {}
	virtual void f2() const override {}
	virtual void f3() override {} // 가상 함수만 재정의
	//void f4() override {}
};

int main()
{

}

2. final specifier
    c+11
    가삼함수를 재정의 못하게 하거나, 파생 클래스를 만들 수 없게 한다.
    가상함수 뒤에 붙이는 경우 : 해당 가상 함수를 파생 클래스에서 더 이상 재정의 할 수 없다.
    클래스 뒤에 붙이는 경우 : 파생 클래스를 만들 수 없다.


3. is_final 
    C++14에서 추가된 traits
    특정 타입이 final 인지 조사

#include <type_traits>
#include <iostream>
using namespace std;
class A
{
public:
	virtual void f1() {}
};

class B final : public A
{
public:
	virtual void f1() override final{}
};

/*
class C : public B
{
public:
	//virtual void f1() override  {}
};
*/
int main()
{
	bool b = is_final<B>::value;
	cout << b << endl;
}




#include <iostream>
using namespace std;

template<typename T> class Base
{
public:
	virtual void foo(const T a)
	{
		cout << "Base foo" << endl;
	}
};
class Derived : public Base<int*>
{
public:
	// 가상 함수 foo를 재정의해서
	// "Derived foo" 라고 출력해 보세요.
	// override 사용하지 말고.
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0);	// "Derived foo"
}