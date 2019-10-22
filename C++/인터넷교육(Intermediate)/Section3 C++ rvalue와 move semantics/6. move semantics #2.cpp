https://github.com/codenuri/CPPINTERMEDIATE/tree/master/303_MOVE
=============using move=============

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Test
{
public:
	Test() {}
	~Test() {}
	Test(const Test& t) { cout << "Copy" << endl; }
	Test(Test&& t)      { cout << "Move" << endl; }

	Test& operator=(const Test& t) 
	{
		cout << "Copy=" << endl; 
		return *this; 
	} 
	
	Test& operator=(Test&& t) 
	{
		cout << "Move=" << endl; 
		return *this; 
	} 
};


template<typename T> void Swap(T& x, T& y)
{
//	Test temp = x; // 복사 생성자
//	x = y;		   // 복사 대입
//	y = temp;

//move는 임시객체일때만 사용하는 것이 아니다. 만약 rvalue 복사 생성사 (move 생성자)가 만들어져 있지 않으면 copy 생성자 호출
// 임시객체뿐만 아니라, 다른 경우에도 move를 사용
	Test temp = move(x); // static_cast<Test&&>
	x = move(y);
	y = move(temp);
}

int main()
{
	Test t1, t2;
	//Swap(t1, t2);
	swap(t1, t2);

}



/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Test
{
public:
	Test() {}
	~Test() {}
	Test(const Test& t) { cout << "Copy" << endl; }
	Test(Test&& t) noexcept     { cout << "Move" << endl; }

	Test& operator=(const Test& t)
	{
		cout << "Copy=" << endl;
		return *this;
	}
	Test& operator=(Test&& t) noexcept
	{
		cout << "Move=" << endl;
		return *this;
	}
};

int main()
{
	/*
	Test* p1 = new Test[2];
	Test* p2 = new Test[4];
	for (int i = 0; i < 2; i++)
		//	p2[i] = p1[i];   // copy 대입
		p2[i] = move(p1[i]); // move 대입
	*/
	vector<Test> v(2);
	v.resize(4);

}

=============move_if_noexcept=============
// move 생성자는 포인터 복사,,


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>

class Test
{
public:
	Test()  { std::cout << "Test()" << std::endl; }
	~Test() { std::cout << "~Test()" << std::endl; }

	Test(const Test& t) 
	{ 
		std::cout << "Copy" << std::endl;
	}
	Test(Test&& t) noexcept
	{
		std::cout << "Move" << std::endl;
	}

	Test& operator=(const Test& t)
	{
		std::cout << "Copy=" << std::endl;
		return *this;
	}
	Test& operator=(Test&& t) noexcept
	{
		std::cout << "Move=" << std::endl;
		return *this;
	}
};
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <type_traits>
#include "Test.h"		// class Test {}
using namespace std;

int main()
{
	Test t1;
	Test t2 = t1; // copy
	Test t3 = move(t2); // move
	 
	bool b = is_nothrow_move_constructible<Test>::value;
	cout << b << endl;

	Test t4 = move_if_noexcept(t1);



	/*
	Test* p1 = new Test[2];
	Test* p2 = new Test[4];
	
	for (int i = 0; i < 2; i++)
		p2[i] = move( p1[i] );
		*/
}

=============grow buffer example=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <type_traits>
#include "Test.h"		
using namespace std;

int main()
{
	Test* p1 = new Test[2];

	//Test* p2 = new Test[4];

	// 1. 신규 버퍼는 메모리만 할당 한다.
	Test* p2 = static_cast<Test*>(
			operator new(sizeof(Test) * 4));

	for (int i = 0; i < 2; i++)
	{
		//p2[i] = move(p1[i]); // move 대입..
		//new(&p2[i]) Test;		// 디폴트 생성자 호출
		//new(&p2[i]) Test(p1[i]); // 복사 생성자
		//new(&p2[i]) Test(move(p1[i])); // move 생성자

		new(&p2[i]) Test(move_if_noexcept(p1[i])); 
	}

	// 2. 새로운 객체는 디폴트 생성자 호출
	for (int i = 2; i < 4; i++)
		new(&p2[i]) Test; // 디폴트 생성자 호출.

}

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <type_traits>
#include "Test.h"		
using namespace std;

int main()
{
	vector<Test> v(2);
	v.resize(4);
	cout << "--" << endl;
}


/*
int main()
{
	Test* p1 = static_cast<Test*>(
		operator new(sizeof(Test) * 2));
	for (int i = 0; i < 2; i++)
		new(&p1[i]) Test;
	//-----------------------------
	Test* p2 = static_cast<Test*>(
		operator new(sizeof(Test) * 4));
	for (int i = 0; i < 2; i++)
	{
		new(&p2[i]) Test(move_if_noexcept(p1[i]));
	}
	for (int i = 2; i < 4; i++)
		new(&p2[i]) Test;
	//---------------
	// 최초 버퍼 파괴
	for (int i = 1; i >= 0; i--)
		p1[i].~Test();
	operator delete(p1);
	cout << "---" << endl;
	//--------------------
	for (int i = 3; i >= 0; i--)
		p2[i].~Test();
	operator delete(p2);
}
*/