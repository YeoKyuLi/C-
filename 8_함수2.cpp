//함수2.cpp - C++함수의 특징2. 오버로딩
//인자의 타입이나 객수가 다르면 동일이름의 함수를 2개이상 만들수 있다.
int square(int a)
{
	return a*a;
}
double square(double a)
{
	return a*a;
}
int main()
{
	square(3);
	square(3.3);
}
// 주의 사항
void f1(int a){}
void f1(int a, int b) {} //ok

//주의 1. 디폴트 값 주의
void f2(int a) {}
void f2(int a, int b=0) {} //error overload (X)
f2(10);

//주의 2.리턴타입만 다른경우 오버로딩 할 수 없다.
void f3(int a) {}
int f3(int a) {}
f3(10);
