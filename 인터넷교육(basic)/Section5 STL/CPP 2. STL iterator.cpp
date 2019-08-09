https://github.com/codenuri/CPP1/tree/master/SECTION5/02_ITERATOR
=============STL iterator=============
핵심정리
1. 배열의 요소에 접근하는 방법
    1. 배열 연산자를 사용
    2. 포인터를 사용해서 접근
2. 반복자(iterator)
    포인터와 유사하게 동작하는 객체로서 반복자를 사용하면 컨테이너의 모든 요소를 순차적으로 접근할 수 있다.

3. 반복자의 장점
    컨테이너의 내부 구조(메모리 구조)에 상관없이 동일한 방법으로 요소에 접근 할 수 있다.
    그럼 포인터로 이동하는 방법은, ++로 다음을 가르킬 수 없다는 소리,, 연속된 메모리가 아니면(ex, list)
#include <iostream>
#include <vector>
#include <list>

int main()
{
    int x[10] = { 1,2,3,4,5,6,7,8,9,10};
    
    int* p1 = x;
    ++p1;
    *p1 = 20; // { 1,20,3,4,5,6,7,8,9,10};

    //std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    std::list<int> v = {1,2,3,4,5,6,7,8,9,10};
    
    auto p2 = v.begin();
    ++p2;
    *p2 = 20; //{1,20,3,4,5,6,7,8,9,10};
    ++p2;
    std::cout << *p2 << std::endl; //3
    
}

핵심 정리
1. 반복자 데이터 타입
    컨테이너이름::iterator -> std::vector<int>::iterator
    auto를 사용하는 것이 편리하다.
2. end()로 얻는 반복자는 컨테이너의 마지막 다음을 가르킨다.
    past the end
    end()로 얻는 반복자를 사용해서 요소에 접근하면 안된다.
    끝에 도달했는지 확인하는 용도로 사용해야 한다.

#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    
    //std::vector<int>::iterator p1 = v.begin();
    auto p1 = v.begin();
    auto p2 = v.end();
    
    //*p2 = 20; // runtime error
    
    while( p1 != p2 )
    {
        std::cout << *p1 << std::endl;
        ++p1;
    }
}

반복자를 꺼내는 방법
멤버함수 : v.begin() v.end() //배열에 사용 못함
일반함수(C++1) : std::begin(v), std::end(v) //배열 사용 가능

#include <iostream>
#include <vector>
#include <list>

int main()
{
    //int v[10] = {1,2,3,4,5,6,7,8,9,10}; // 배열
    
    std::list<int> v = {1,2,3,4,5,6,7,8,9,10};
    //std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    
//    auto p1 = v.begin();
//    auto p2 = v.end();

    auto p1 = std::begin(v); // 배열
    auto p2 = std::end(v); // 배열
    
    while( p1 != p2 )
    {
        std::cout << *p1 << std::endl;
        ++p1;
    }
}

컨테이너의 모든 요소를 열거하는 방법
1. 배열 연산자([])
    연속된 메모리와 유사한 구조를 가진 경우만 가능
    vector, array, deque, string 
    list or forward_list는 [] 연산자를 사용 할 수 없다.
2. 반복자 사용
    모든 컨테이너에 사용 가능
3. range for 구문 사용
    모든 컨테이너에 사용가능


#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
        
    // 방법 1.
    for ( int i = 0; i < std::size(v); i++) //v.size()
    {
        std::cout << v[i] << std:: endl;
    }

    
    // 방법 2.
    auto p1 = std::begin(v);
    
    while( p1 != std::end(v) )
    {
        std::cout << *p1 << std::endl;
        ++p1;
    }
    
    // 방법 3.
    for( auto& n : v ) //auto 요소의 복사본은 만듬 // auto& 요소의 복사본을 만들지 않음,
        std::cout << n << std::endl;
}

