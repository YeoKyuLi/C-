
/*
int square(int a)
{
	return a*a;
}
double square(double a)
{
	return a*a;
}
*/

//틀을 만들고 type이라는 인자를 받아서 정의된 type(T)를 바탕으로 함수를 생성.
//모든 타입읜 함수를 생성하는 것이다. template이
//함수 특징 3. 함수 템플릿
//				실제 함수가 아니라
//				함수를 만들어내는 틀(template)

template <typename T> T square(T a)
{
	return a*a;
}

int main()
{
	square<int>(3); //int 버전의 square 생성후, 사용
	square<double>(3.3); //double 버전의 square 생성후, 사용
	
	//template에서 <int><double> 제외 가능.
	square(3);
	square(3.3); //T를 double로 결정한 함수생성.
	
	//square(3);
	//square(3.3);
}