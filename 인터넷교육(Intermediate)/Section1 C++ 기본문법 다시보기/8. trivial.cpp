https://github.com/codenuri/CPPINTERMEDIATE/tree/master/108_TRIVIAL
=============trivial 개념=============
// Trivial default Constructor : 기본 생성자가 하는 일이 없는 경우.

#include <iostream>
#include <type_traits>
using namespace std;

class A
{
public:
	virtual void foo() {}
};

int main()
{
	cout << is_trivially_constructible<A>::value << endl;
}
=============trivial 활용=============

//왜 trivial 개념이 필요한가 ?
#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void copy_type(T* dst, T* arc, int sz)
{
	if (is_trivially_copyable<T>::value) // 컴파일 타임에 알게됨
	{
		cout << "복사 생성자가 trivial" << endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else
	{
		cout << "복사 생성자가 trivial 하지 않은 경우" << endl;
		while (sz--)
		{
			new(dst) T(*src);
			++dst, ++src;
		}
	}
}

=============trivial 정리=============
// Trivial default Constructor 조건
struct Base
{
    Base() {}
};

class A : public Base{
    // Data data; // 객체형 멤버가 없어야 한다.
    int n = 10;
public :
    // A() {} // user define 생성자가 없어야 한다.
    // virtual void foo() {} // 가상함수가 없어야 한다.
};

int main(){
    cout << is_trivially_constructible<A>::value << endl;
}