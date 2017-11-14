// 11_스마트포인터2
// 1. 템플릿으로 만들어야 한다.
// 2. 얕은 복사를 해결해야 한다.
//	깊은 복사, 참조계수, 복사금지. 중에서 주로 참조계수를 사용한다.

// 도전과제 : 아래 코드에 참조계수 추가해 보세요... *^^*

#include <iostream>
using namespace std;

template<typename T> class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) {}
	~Ptr() { delete obj; } // 자원 삭제
	T* operator->() { return obj; }
	T& operator*() { return *obj; } // 값, 참조
};
int main()
{
	Ptr<int> p1 = new int;

	*p1 = 10;
	cout << *p1 << endl;

	Ptr<int> p2 = p1; // runtime error why? -- 
}
