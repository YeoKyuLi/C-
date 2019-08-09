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
    std::exception으로

#include <iostream>

class FileNotFound : public std::exception
{
public:
    virtual const char* what() const noexcept
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
    catch(FileNotFound e)
    {
        std::cout << e.what() << std::endl;
    }
}