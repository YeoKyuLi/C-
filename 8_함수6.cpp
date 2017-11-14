//C++ 함수 특징 6 - 함수 삭제

int gcd(int a, int b) //최대 공약수 구하기
{
	return 0;
}
//함수 삭제 문법 - C++11/ 사용하려고 하면 컴파일 에러.
double gcd(double a, double b) = delete;

int main()
{
	gcd(10, 5);
	gcd(3.3, 5.5);
}