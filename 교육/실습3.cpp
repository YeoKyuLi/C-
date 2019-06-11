//실습3.cpp - 함수5.cpp 복사해 오기.

	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	//int a = 1, b = 2;
	int n1 =  Add1(1, 2); //함수 호출
	int n2 = Add2(1, 2); //함수 기계어 코드 치환
}

//cl 실습3.cpp /FAs /O2 컴파일 하면 "실습3.asm" 생성
// /FAs : 어셈을 만들어 달라.
// /O2 : 속도 최적화
// /Ob1 : 이라인 치환을 적용해 달라.
//notepad 실습3.asm 열어보기

//g++ a.cpp -S ==> .s 파일 생성됩니다. 어셈소스
