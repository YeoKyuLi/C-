https://github.com/codenuri/CPP1/tree/master/SECTION5/03_ALGORITHM
=============STL algorithm=============
핵심 정리
1. 알고리즘(algorithm)의 일반적인 의미
    어떤 문제를 해결하기 위한 절차, 방법, 명령어들의 집합
2. STL 알고리즘
    C++ 표준 라이브러리인 STL이 제공하는 함수
    정렬, 검색, 순열 등 다양한 알고리즘을 구현한 함수의 집합

STL 알고리즘의 특징
1. 멤버 함수가 아니 일반 함수(템플릿)로 제공된다.
    하나의 함수(템플릿)으로 다양한 컨테이너에 사용할 수 있다. -> 자료구조에 독립적
    대부분의 알고리즘은 함수 인자와 반환 타입으로 반복자를 사용한다. 
    --> 반복자를 사용하면 컨테이너의 내부 구조에 상관없이 동일한 방법으로 요소에 접근할 수 있다.
2. <algorithm> 헤더가 필요함

find 알고리즘
1. 2개의 반복자([first, end), 구간)와 검색할 값을 받아서 선형 검색을 수행하는 알고리즘
    first는 검색 대상에 포함되지만, last는 검색 대상에 포함되지 않는다.
    [first, last)
2. 반환값
    검색 성공시 : 요소를 가리키는 반복자
    검색 실패시 : last 주의(null이 아님!!!!)
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    
    std::list<int>   s = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    //s.find(5);
    //v.find(5);
    
    std::find( begin(v), end(v), 3  );

    //auto p = std::find( begin(x), end(x), 3  );
    
    // auto p = std::find( x, x+10, 3  );
    
    auto p = std::find( begin(v), end(v), 3  );

    if ( p == end(v) )
    {
        std::cout << "fail" << std::endl;
    }
    else
        std::cout << *p << std::endl; //역참조
}


=============STL algorithm and predicator(조건자)=============
핵심 정리
1. 조건자 (predicator)
    bool을 반환하는 함수, 함수객체, 람다 표현식
    _if로 끝나는 알고리즘에 전달되어서 정책으로 사용된다.

#include <iostream>
#include <algorithm>
#include <vector>

bool foo( int n )
{
    return n % 3 == 0;
}
int main()
{
    std::vector<int> v = {10,9,8,7,6,5,4,3,2,1};
    
    // v 안에서 처음 나오는 3의 배수를 구해 보세요

    //auto p = std::find(begin(v), end(v), 3);   
    
    //auto p = std::find_if(begin(v), end(v), foo(함수..!) );   
    
    auto p = std::find_if(begin(v), end(v), 
                [](int n) { return n % 3 == 0;} );   
    

    std::cout << *p << std::endl;
}

핵심정리

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<int> v;

    int n = 0;
    
    while( 1 )
    {
        cin >> n;
        
        if ( n == -1 )
            break;
            
        v.push_back(n);    
    }
    

    // 입력한 값 중 10보다 큰 값은 모두 0으로 변경해 주세요.
        replace, replace_if
    /*
    for ( auto& n : v)
    {
        if ( n >= 10 )
            n = 0;
    }
    */
    //replace( begin(v), end(v), 10, 0);

    replace_if( begin(v), end(v), 
            [](int n) { return n >= 10;}, 0);

    // 모든 요소의 합 구하기, numeric에 포하ㅣㅁ
    int sum = accumulate( begin(v), end(v), 0);

    //sort( begin(v), end(v)); // 오름차순, 퀵소트
                                // <
    sort( begin(v), end(v), 
        [](int a, int b) { return a > b; });
    
    
    // 1로 채워서 출력해보기
    fill( begin(v), end(v), 1);


    for ( auto& n : v)
        std::cout << n << ", ";
        
    std::cout << endl;
}