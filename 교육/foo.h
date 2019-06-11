#pragma once

//foo.h
void foo();
inline void goo();


//internal linkage ?? ==> C 언어의 static와 같은거
// 헤더 파일은 같은 파일이다. ==> 헤더에 구현하면 다른 cpp에서 including 해도 괜찮음
// 함수 template도 헤더에 존재해야 된다.

// 일반함수는 다른 파일에 있어도 괜찮음. exteranl linkage
//inline 함수는 구현과 선언이 따로 안됨
//inline 함수는 헤더 파일에서 모든 구현을 마쳐야됨.
//컴파일 과정에서 inline 함수에 관한 정확한 정보를 요청하기 때문에
//헤더 파일로 참조만하고, 정확한 구현을 파악할 수 없게 따로 구현하면
//에러 발생.