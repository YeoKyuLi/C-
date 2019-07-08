https://github.com/codenuri/CPP1/tree/master/SECTION4/02_OSTREAM
=============cout의 원리=============
cout의 원리
1. cout은 --> "ostream 타입의 객체"이다.
2. 모든 primitive 타입에 대헛 "operator<<연산자 함수가 구현" 되어 있다.
    cout << 3 --> cout.operator<<(int)
    cout << 3.4 --> cout.operator<<(double)
3. 여러개를 연속적으로 출력할 수 있다.
    operator << 함수에서 "자기 자신을 참조로 리턴"한다.
4. ostream과 cout은 "std" 이름 공간안에 있다.

#include <cstdio>

namespace std 
{
    class ostream
    {
    public:
        ostream& operator<<(int n) { printf("%d", n); return *this;}
        ostream& operator<<(double d) 
        {
             printf("%f", d);
             return *this;
        }
    };
    ostream cout;    
}

int main()
{
    std::cout << 3;  // cout.operator<<(3)
    std::cout << 3.4;
    std::cout << 3 << 3.4;
}

ostream과 C++ 표준
1. 1998년 표준화 이전
    ostream 클래스, 유니코드 등 문자열을 출력 할 수 없다.
2. 1998 효준화 이후
    basic_ostream<>클래스 템플릿
    유미코드 등 문자열을 출력할 수 없다.
#include <iostream>

int main()
{
    std::cout << "hello";
    std::wcout << L"hello"; //유니코드
}

=============사용자 정의 타입과 cout=============
cout의 특징
1. 다양한 타입의 값을 출력할 때 서식 문자열(%d)를 전달 할 필요가 없다
    operator<< 함수가 다양한 타입에 대해서 오버로딩 되어 있다.

사용자 정의 타입을 cout으로 출력할 수 있게 하려면
1. operator<< 연산자 함수를 멤버가 아닌 일반 함수로 제공한다.
2. private 멤버에 접근하기 위해서는 friend 함수를 선언한다.

#include <iostream>

class Point
{
    int x;
    int y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    
    friend std::ostream& 
    operator<<(std::ostream& os, const Point& pt);
};
// operator<<(cout, pt)
std::ostream& operator<<(std::ostream& os, const Point& pt) //x,y를 읽기만 하고 수정하지 않으니깐 const
                                                            //os에 const를 부치면 os.operator<<(pt.x)에서 에러남
{
    os << pt.x << ", " << pt.y;
    return os;
}

int main()
{
    Point pt(1,2);
    std::cout << pt << std::endl;  
                 // cout.operator<<(Point)
    
                // operator<<(cout, pt)
                // operator<<(ostream, Point)
                    
}


=============std::endl의 원리=============
핵심 개념
1. std::cout은 객체이므로 다양한 멤버 함수가 있다.
    cout.put('\n');
    cout.flush();

2. endl은 함수이다.
    인자로 cout을 전달받아서 개행 문자를 출력하고 버퍼를 비우고 cout을 반환.
    cout << endl;
    endl(cout)

#include <iostream>
using namespace std;

ostream& myendl( ostream& os)
{
    os.put('\n');
    os.flush();
    return os;
}
int main()
{
//    cout << endl << "A";
//    endl(cout) << "A";

    myendl(cout) << "A";
    
    cout << endl; // cout.operator<<(endl)
                  // cout.operator<<(ÇÔ¼öÆ÷ÀÎÅÍ)
    cout << myendl;
}

#include <cstdio>

class ostream
{
public:
    ostream& flush() { return *this;}  // 츨력 버퍼 비우기
    ostream& put(char c)       {printf("%c", c);return *this;}
    ostream& operator<<(int n) {printf("%d", n);return *this;}

    ostream& operator<<( ostream&(*f/*f == endl */)(ostream&) ) //함수 포인터
    {
        f(*this); // this == cout
        return *this;
    }
};
ostream cout;

ostream& endl( ostream& os)
{
    os.put('\n');
    os.flush();
    return os;
}

int main()
{
    cout << 3;
    cout << endl; // cout.operator<<(endl)
}



#include <iostream>
using namespace std;

ostream& tab( ostream& os)
{
    os << '\t';
    return os;
}
ostream& menu( ostream& os)
{
    os << "1. 설렁탕 \n";
    os << "2. 김밥\n";
    return os;
}

int main()
{
    cout << "A" << endl;
    cout << "A" << tab << "B" << endl;
    
    cout << endl; // cout.operator<<(함수포인터)                
    cout << tab; 
    
    cout << menu;
}

endl을 함수로 설계한 이유
확장성을 가지기 위해서 함수로 설계하였다.