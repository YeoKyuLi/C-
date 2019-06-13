https://github.com/codenuri/CPP1/tree/master/SECTION1/01_NAMESPACE
namespace 요소접근 3가지 방법
1. 한정된 이름 : Qualified name
    Audio::init()
    ::init() 은 글로벌 함수를 호출한다. 만약 함수 이름이 겹칠때,
    * 가장 좋은 방법
2. using declaration
    using Audio::init
    init 함수는 Audio 이름 없이 사용 가능
3. Using directive
    using namespace Audio
    Audio namespace의 모든 요소를 Audio 이름 없이 사용가능


using 선언이나 지시어는 함수 안 또는 밖에서 만들 수 있다.

함수를 선언 파일과 구현 파일로 분리할 때
1. 함수의 선언부와 구현부를 모두 namespace로 묶어야 한다.
2. 함수 구현부를 만드는 2가지 방법
namespace Audio{
    void init(){}
}
void Audio::init(){}

c++ 헤더 파일의 특징
1. 확장자를 사용하지 않는다.

stdio.h vs cstdio의 차이점
printf()등의 표준함수는 "global namespace"에 있다.
표준은 아니지만 대부분의 컴파일러는 "global namespace에도 printf등의 표준 함수를 제공"한다.


전연공간에서 있는 함수를 namespace에 포함하는 방법
1. namespace안에서 전역공간에 있는 함수의 using 선언문을 만들면 된다.
void foo() {}

namespace Audio                               
{
    using ::foo;
    
    void init() {}
}

int main()
{
    Audio::init();    
    
    using Audio::init; // using 선언
    init();
    
    foo();
    Audio::foo();
    
}