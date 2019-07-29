https://github.com/codenuri/CPP1/tree/master/SECTION4/04_STRING
============= string 클래스 만들기 =============
1. string 클래스 만들기 : 다양한 연산자 재정의 문법과 얕은 복사, 깊은 복사 개념 복습

1. 내부적으로 문자열을 보관해야 한다.
    배열을 사용하면 문자열의 개수가 고정된다., 동적 메모리 할당 사용

2. String 클래스의 메모리 구조

3. C++자원 관리의 기본
    생성자 : 자원할당
    소멸자 : 자원 반납


#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char* buff;
    int   size;
public:
    String(const char* s)
    {
        size = strlen(s);        
        buff = new char[size + 1];
        strcpy(buff, s);
    }
    ~String() { delete[] buff;}
    
    
    String( const String& s) : size(s.size) // 깊은 복사
    {
        buff = new char[size + 1];
        strcpy(buff, s.buff);
    }
    
    String& operator=(const String& s) // 대입연산, 자신의 참조를 리턴해야함
    {
        //대입연산자는 자신과의 대입을 조사해야 한다.
        if(&s == this)
            return *this;

        size = s.size;
        
        delete[] buff; //자기가 사용하던 버퍼 삭제, world
        
        buff = new char[size + 1];
        
        strcpy(buff, s.buff);
        
        return *this;
    }
    
    
    
    friend ostream& operator<<(ostream& os, const String& s);
};

ostream& operator<<(ostream& os, const String& s) //print
{
    return os << s.buff; 
}

int main()
{
    String s1 = "hello"; 
    cout << s1 << endl;  //print
    
    String s2 = s1; //복사 생성자를 만들지 않으면 얕은 복사 문제가 발생함.
    cout << s2 << endl;
     
    String s3 = "world";
    cout << s3 << endl;
    
    s3 = s1; // s3.operator=(s1); 대입연산자
    
    cout << s3 << endl;

    String s4 = "hello";
    s4 = s4; s4.operator(s4);
    cout << s4 << endl;
    
}
