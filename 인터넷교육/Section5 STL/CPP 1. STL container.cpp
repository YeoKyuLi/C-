https://github.com/codenuri/CPP1/tree/master/SECTION5/01_STL_INTRO
=============STL 소개=============
핵심 정리
Linked List, Stack, Queue, Tree, Hash : container
sort, binary search, heap opeartion : algorithm
자료구조와 알고리즘을 연결하는 포인터와 유사한 객체 : iterator(반복자)

=============STL Container=============
컨테이너 종류
sing list : <forward_list>

#include <array>
#include <vector> // 메모리상 붙어 있음 (연속된 메모리)
#include <list> // 메모리 상 떨어져 있음
#include <forward_list>
#include <deque>
#include <stack>
#include <queue> // queue, priority_queue
#include <set> 
#include <map> 
#include <unordered_set> 
#include <unordered_map> 

컨테이너의 특징
1. 대부분 컨테이너의 멤버함수의 이름이 동일한다
    대부분의 코드를 수정하지 않고도 컨테이너를 교체 할 수 있다.
    단, vector는 push_front()가 없다. 자료구조 특성상 앞쪽에 요소를 넣는 것은 성능이 좋지 않기 때문에

2. 제거와 반환을 동시에 하지 않는다.
    pop_front(), pop_back()함수는 제거만 하고, front(), back() 함수는 반환만 한다.

핵심 정리
1. 컨테이너 생성하는 방법
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::list<int> s1;
    std::list<int> s2(10); // 10개를 0으로 초기화
    
    std::list<int> s3(10,3); // 10개 3으로 초기화
    std::list<int> s4{10,3}; // 2개를 10, 3으로 초기화 직접초기화
    std::list<int> s5 = {10,3};    // 복사 초기화
    
    std::list<int> s6 = {1,2,3,4,5,6,7,8,9,10};
    std::list<int> s7{1,2,3,4,5,6,7,8,9,10};    
    
    std::list s8 = {1,2,3,4,5,6,7,8,9,10}; //C++17 부터 사용 가능, 값을 보고 타입을 예측
}


#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    
    v.push_back(20);
    
    /*
    for( int i = 0; i < v.size(); i++ )
        std::cout << v[i] << std::endl;
    */
    for ( auto& n : v)
        std::cout << n << std::endl;
    
}