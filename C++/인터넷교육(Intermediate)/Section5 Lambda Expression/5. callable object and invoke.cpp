https://github.com/codenuri/CPPINTERMEDIATE/tree/master/405_Callable
=============callable Object & invoke=============
Function Object
    A FunctionObject type is the type of an object that can be used on the left of the function call operator.
    모든 종류의 함수 포인터
    ()연산자를 재정의한 클래스
    Lambda Expression
    함수와 함수를 가리키는 참조는 Function Object가 아니다.

#include <iostream>
#include <functional>
using namespace std;

void foo()
{

}

int main()
{
	void(&r)() = foo; // 참조는 객체가 아니다.
	r();

	foo();

	less<int> f;
	f(1, 2);

	[](int a, int b) { return  a + b; }(1, 2);
	
}

#include <iostream>
#include <functional>
using namespace std;


template<typename F, typename ... Types>
decltype(auto) chronometry(F&& f, Types&& ... args) // forwarding reference 
{
	std::forward<F>(f)(std::forward<Types>(args)...); 
}

int main()
{
	chronometry(less<int>(), 10, 20);
}


#include <iostream>
#include <functional>
using namespace std;

template<typename F, typename ... Types>
decltype(auto) chronometry(F&& f, Types&& ... args)
{
//	std::forward<F>(f)(std::forward<Types>(args)...);

	//f(std::forward<Types>(args)...);

	return  invoke(std::forward<F>(f),
	   	std::forward<Types>(args)...);

}

class Dialog
{
public:
	void Close() {} 
};

int main()
{
	Dialog dlg;
	chronometry(&Dialog::Close, &dlg);
	
//	void (Dialog::*f)() = &Dialog::Close;

//	(dlg.*f)();
//	f(&dlg);
//	invoke(f, &dlg); dig를 가지고 멤버 함수 f를 호출하겠다.
}

Callable 
    A callable type is a type for which the INVOKE operation(used by, std::fucntion, std::bind, std::thread::thread) is applicable.
    Function Object
    Pointer to member

#include <iostream>
#include <functional>
using namespace std;

void foo(int a, int b) {}

class Dialog
{
public:
	int color;

	void setColor(int c) { color = c; }
};

int main()
{
	invoke(&foo, 10, 20); // foo(10,20)
	Dialog dlg;
	invoke(&Dialog::setColor, &dlg, 2); 
						// dlg.setColor(2);

	// 멤버 변수 포인터
	invoke(&Dialog::color, &dlg) = 20;
			// dlg.color = 20

	cout << dlg.color << endl; // 20

}
