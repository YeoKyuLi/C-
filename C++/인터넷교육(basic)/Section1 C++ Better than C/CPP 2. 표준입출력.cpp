https://github.com/codenuri/CPP1/tree/master/SECTION1/02_IO
// iomanipulator
1. 입출력의 형태를 지정하기 위해 사용
2. 조정자 함수 또는 조작자 함수라고도 표현

#include <iostream>
#include <iomanip>
//using namespace std;

int main()
{
    //cout << hex << n << endl; 
    
    int n = 10;
    
    std::cout << n << std::endl;  // 10진수
    
    std::cout << std::hex;
    
    std::cout << n << std::endl;  // 16진수
    
    std::cout << std::hex << n << std::endl;  // 16진수
    
    std::cout << std::dec;
    std::cout << n << std::endl;  // 10진수
    
    
    std::cout << "hello" << std::endl;    
    
    std::cout << std::setw(10) << std::setfill('#') 
              << std::left    << "hello" << std::endl;    
    return 0;
}