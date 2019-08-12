https://github.com/codenuri/CPP1/tree/master/SECTION6/01_EXCEPTION
=============예외=============
핵심 정리
1. c언에서 함수가 실패할면
    함수의 반환 값을 사용해서 실패 했음을 알린다.
2. C방식의 단점
    반환 값과 실패를 나태내는 것이 명확히 분리되어 있지 않다.
    정상적인 실행 흐름과 오류 처리의 코드가 분리되어 있지 않다.
    오류를 무시할 수 있다.(중요하고 심각한 오류라면?)
3. 객체지향 언어에들이 사용하는 오류 처리 방법
    예외 문법 사용 (exception)


C style
#include <iostream>

int readFile()
{
    FILE* f = fopen("a.txt", "rt");
    
    if ( f == 0 )
        return -1;
    //....    
    fclose(f);
    return 0;
}

int main()
{
    int ret = readFile();
    
    /*
    if ( ret == -1 )
    {
        // 실패처리
    }
    */

}

예외 문법 사용하기
1. 함수가 실패하면
    throw 키워드를 사용해서 예외를 던진다
    던져진 예외를 처리하지 않으면 프로그램은 종료된다.
2. 예외를 처리 하려면
    try{
        정상적인 처리
    }catch(const char* s){
        예외!
    }
3. catch문은 여러 개를 만들 수 있다.
4. catch(...)은 모든 종류의 예외를 잡을 수 있다.
    반드시 마지막 부분에 놓여야 한다.
#include <iostream>

int readFile()
{
    FILE* f = fopen("a.txt", "rt");
    
    if ( f == 0 )
        throw "FileNotFound";
        
    //....    
    fclose(f);
    return 0;
}

int main()
{
    try
    {
        int ret = readFile();
        //....
    }
    catch( const char* s)
    {
        std::cout << s << std::endl;
        //exit(0)
    }
    catch( int n)
    {
    }
    catch( ... )
    {
    }

    
    std::cout << "main" << std::endl;

}

=============예외와 클래스=============
핵심 정리
1. 무엇을 던질 것인가?
    예외 전용 클래스를 만들어서 사용한다. (FileNotFound)
    std::exception으로 부터 상속 받아서 만드는 것이 좋다.

2. 어떻게 catch할 것인가?
    가상함수 what을 사용하려면 값이 아닌 참조 타입으로 받아야 한다.
#include <iostream>

class FileNotFound : public std::exception
{
public:
    virtual const char* what() const noexcept //std::exception 여기에 정의되어 있는거니깐 해당하는 형태로 따라야함
    {
        return "File Not Found";
    }
};

void foo() 
{
    throw FileNotFound();
}

int main()
{
    try
    {
        foo();
    }
    catch(std::exception& e) // 참조, 가상함수이므로 실제로 가르키는 것을 호출한다.
    // (std::exception e)  값으로 받는 경우 복사본을 만들기 때문에 어떤 것이 호출 될지 모르고, 컴파일러마다 결과가 다름
    {
        std::cout << e.what() << std::endl;
    }
    catch(FileNotFound e)
    {
        std::cout << e.what() << std::endl;
    }
}


=============noexcept=============
핵심 정리
1. 왜 표기 하는가?
    예외가 없는 함수가 컴파일러 최적화가 더욱 잘 된다.
    예외가 있는지 없는지 조사후에 다른 알고리즘을 사용 할 수 있다.

//void foo() throw()
//void foo() 
//void foo() throw(int)

C++11이후
//void foo() // 예외가 있다.
//void foo() noexcept(false)  // 예외 가 있다.
//void foo() noexcept(true )  // 예외가 없다.
void foo() //noexcept        // 예외가 없다.
{
    throw 1;
}

int main()
{
    try
    {
        foo();
    }
    catch(...) 
    {
        
    }
}

핵심정리
1. 함수가 예외가 없음을 조사하는 방법
    noexcept(함수 호출식)

#include <iostream>

void foo() //noexcept
{
}

int main()
{
    bool b = noexcept( foo() );
    
    std::cout << b << std::endl;
}