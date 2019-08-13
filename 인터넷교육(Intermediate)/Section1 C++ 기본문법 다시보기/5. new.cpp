https://github.com/codenuri/CPPINTERMEDIATE/tree/master/103_CONST_MEMBER_FUNCTION
=============new vs operator new=============
new 동작방식
1. 메모리 할당 - operator new()함수 사용
2. 생성자 호출
3. 메모리 주소를 해당 타입으로 반환

delete 동작방식
1. 소멸자 호출
2. 메모리 해지 - operator delete()함수 사용

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new1.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point()  { cout << "Point()"  << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
    //생성자 호출자 없이 메모리 할당/삭제
	Point* p1 = static_cast<Point*>(
				operator new(sizeof(Point)));

	operator delete(p1);

	/*
	// malloc : 메모리만 할당
	Point* p1 = (Point*)malloc(sizeof(Point));
	free(p1);
	// new : 메모리 할당 + 생성자 호출
	Point* p2 = new Point;	
	delete p2;									
	*/
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new2.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

operator new 재정의

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

void* operator new(size_t sz)
{
	cout << "my new" << endl;
	return malloc(sz);
}

void operator delete(void* p) noexcept
{
	cout << "my delete" << endl;
	free(p);
}

int main()
{
	Point* p = new Point;	// 1. 메모리 할당- operator new( sizeof(Point))
							// 2. 생성자 호출
	delete p;
}


// 여러개 생성가능
// 첫번째 인자값만 지켜주면 된다.
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

void* operator new(size_t sz)
{
	cout << "my new" << endl;
	return malloc(sz);
}

void* operator new(size_t sz, const char* s, int n)
{
	cout << "my new2" << endl;
	return malloc(sz);
}

void operator delete(void* p) noexcept
{
	cout << "my delete" << endl;
	free(p);
}

int main()
{
	//Point* p = new Point; // operator new( sizeof(Point))	
	Point* p = new("AA", 2) Point; // operator new( sizeof(Point), "AA", 2)	
	delete p;
}


=============placement new=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point()  { cout << "Point()"  << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
	Point p;

	//p.Point(); // error. //명시적으로 호출
	p.~Point(); // ok.
}




/*
* NEW 명시적으로 호출
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new5.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point()  { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

// placement new : 생성자를 호출하기 위해 만든 new
// 
/*
void* operator new(size_t sz, void* p)
{
	return p;
}
*/
int main()
{
	Point p;	

	//new Point; // 인자가 1개인 operator new()호출.

	new(&p) Point; // 인자가 2개인 operator new()호출.
					// 메모리 할당이 아닌 생성자를
					// 호출하는 코드
                    // 새로운 것을 할당 하는것이 아니라, 생성자를 재호출
	p.~Point(); 
}


/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new6.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
	// malloc : 메모리만 할당
	Point* p1 = (Point*)malloc(sizeof(Point));


	// new : 객체의 생성 ( 메모리 할당 + **생성자 호출**)
	Point* p2 = new Point;

	Point* p3 = new Point;		// 새로운메모리에 객체를 생성해 달라
	Point* p4 = new(p1) Point;	// 기존 메모리에 객체를 생성해 달라.
} 



=============생성자의 명시적 호출이 필요한 이유=============
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new7.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) 
	{
		cout << "Point(int, int)" << endl;
	} 
};

int main()
{
	// Point 객체를 힙에 한개 만들고 싶다.
	Point* p1 = new Point(0, 0); // ok.


	// Point 객체를 힙에 10개 만들고 싶다.
	//Point* p2 = new Point[10]; // error. (default 생성자가 없어서)

	// 1. 메모리만 먼저 힙에 할당
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));
	
	// 2. 할당한 메모리에 객체를 생성(생성자 호출)
	for (int i = 0; i < 10; i++)
		new(&p2[i]) Point(0,0);


	// 3. 소멸자 호출
	for (int i = 9; i >= 0; i--)
		p2[i].~Point();

	// 4. 메모리 해지.
	operator delete(p2);

	//vector<Point> v(10, Point(0,0));
}


벡터와 같이 호율적으로 사용하고 사용자 정의 타입 사용하는 경우
    
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new8.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v(10, 0);
	v.resize(7);
	cout << v.size() << endl; // 7
	cout << v.capacity() << endl; // 10


	// DBConnect : 생성자에서 DB 접속.
	vector<DBConnect> v2(10);

	v2.resize(7); // 메모리는 제거하지 않지만
				  // 줄어든 객체의 소멸자는 호출해야한다
				
	v2.resize(8); // 새로운 객체에 대한 메모리는 있다
				  // 하지만 생성자를 호출해서
				  // 다시 DB 접속을 해야 한다.
}



/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new9.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <Windows.h>
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b)
	{
		cout << "Point(int, int)" << endl;
	}
};

int main()
{
	// IPC : 공유메모리를 사용한 프로세스간 통신, mmap()

	HANDLE hMap = CreateFileMappingA(INVALID_HANDLE_VALUE, 0, PAGE_READWRITE, 0, sizeof(Point), 0);
	
	Point* p = (Point*)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0); // 공유메모리

	new(p) Point(0, 0); // 공유메모리에 객체 생성

}