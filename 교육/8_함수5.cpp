//8_함수5.cpp
//inline
// 장점 : 빠르다.
// 단점 : 크기가 큰 함수를 여러번 치환하면 기계어 코드가 커진다.
// static이나 함수 포인터, 재귀호출같은 경우에는 어떤 방법으로 처리하는가 ==>

	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	Add1(1, 2); //함수 호출
	Add2(1, 2); //함수 기계어 코드 치환
}