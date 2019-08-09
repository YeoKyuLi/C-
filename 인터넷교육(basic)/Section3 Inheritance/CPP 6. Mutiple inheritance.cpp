https://github.com/codenuri/CPP1/tree/master/SECTION3/06_MULTI
=============다중 상속 (Multiple inheritance)=============
핵심정리
1. 다중상속이란?
    클래스가 2개 이상의 기반 클래스로 부터 상속되는 것
        Java, C#은 제공 안함
2. 다중 상속의 문제점
    서로 다른 기반 클래스에 동일 이름의 멤버가 있을 때 이름 충돌
    -->Diamond 형태의 상속


class InputFile
{
public:
    void read() {}
    void open() {}
};

class OutputFile
{
public:
    void write(){}
    void open() {}
};

class IOFile : public InputFile, public OutputFile
{    
};

int main()
{
    IOFile file;
    //file.open();
    file.InputFile::open();
}

1. Diamond 상속이란?
2. IOFile의 객체를 생성하면?


#include <iostream>
#include <string>

class File 
{
public:
    std::string filename;
    void open() {} // filename 을 사용한다면
};

class InputFile : virtual public File //가상 상속
{
public:
    void read() {}
};
class OutputFile : virtual public File
{
public:
    void write(){}
    void open() {}
};
class IOFile : public InputFile, public OutputFile
{    
public:
};

int main()
{
    IOFile file;    
    
    file.open();
   
}