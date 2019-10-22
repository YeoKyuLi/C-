https://github.com/codenuri/CPPINTERMEDIATE/tree/master/202_CPP17
=============if-init, if constexpr=============
#include <iostream>
using namespace std;

int foo()
{
	return 0;
}

int main()
{
	// 예전 스타일.
	int ret = foo();

	if (ret == 0)
	{
	}

	// C++17 스타일
	// if ( init 구문; 조건문 )
	if (int ret = foo(); ret == 0)
	{
		cout << "ret is 0" << endl;
	}

	// switch 문에도 초기화 구문을 추가할수 있습니다.
	switch (int n = foo(); n)
	{
        case 0: break;
        case 1: break;
	}
}

#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void printv(T v)
{
    //static-if 컴파일 시간에 검사해달라..! if constexpr ( v== 10 ) error
	if constexpr (is_pointer<T>::value)	
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}

=============structure binding=============

#include <iostream>
#include <tuple>
using namespace std;

struct Point
{
	int x;
	int y;
};
int main()
{
	Point pt = { 1,2 };
	//int a = pt.x;
	//int b = pt.y;

    //구조체 bindling
	auto  [a,  b] = pt;
	auto& [rx, ry] = pt; //참조,,!


	int x[2] = { 1,2 };
	auto[e1, e2] = x;


	pair<int, double> p(1, 3.4);
	auto[n, d] = p;

	tuple<int, short, double> t3(1, 2, 3.4);
	auto[a1, a2, a3] = t3;
}



#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;

	s.insert(10);
	//pair<set<int>::iterator, bool> ret = s.insert(10); // ½ÇÆÐ
	/*
	auto ret = s.insert(10); // ½ÇÆÐ
	if (ret.second == false)
	{
		cout << "실패" << endl;
	}
	*/
	/*
	auto [it, success] = s.insert(10); // ½ÇÆÐ
	if ( success == false)
	{
		cout << "실패" << endl;
	}
	*/

	if ( auto[it, success] = s.insert(10); success == false)
	{
		cout << "실패" << endl;
	}

}
