// 11_����Ʈ������2
// 1. ���ø����� ������ �Ѵ�.
// 2. ���� ���縦 �ذ��ؾ� �Ѵ�.
//	���� ����, �������, �������. �߿��� �ַ� ��������� ����Ѵ�.

// �������� : �Ʒ� �ڵ忡 ������� �߰��� ������... *^^*

#include <iostream>
using namespace std;

template<typename T> class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) {}
	~Ptr() { delete obj; } // �ڿ� ����
	T* operator->() { return obj; }
	T& operator*() { return *obj; } // ��, ����
};
int main()
{
	Ptr<int> p1 = new int;

	*p1 = 10;
	cout << *p1 << endl;

	Ptr<int> p2 = p1; // runtime error why? -- 
}
