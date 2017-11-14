// 3_복사생성자7


#include <stack>
#include <iostream>
#include <complex>
#include <mutex>

using namespace std;

// 객체의 복사 기술
// 얕은 복사, 깊은 복사, 참조 계수, 복사 금지, 소유권 이전(move)
// 얕은 복사 그냥 통째로 복사하는거
// 깊은 복사 메모리를 참조?로 하는거 pointer
int main()
{
	mutex m1;
	//mutex m2 = m1; // 복사 금지
	m1.lock;


	stack<int> s1;
	s1.push(10);
	s1.push(20);

	stack<int> s2 = s1; // 어떤 방식일까요? --> 깊은 복사가 많다.

	complex<int> c1(1, 1);
	complex<int> c2 = c1; // 얕은 복사.
}