//11_OOP - 객체지향 프로그램의 개념

// 복수수 2개의 합을 구해서 리턴하는 함수를 생각해봅시다.

void Add(int xr, int xi, int yr, int yi, int* sr, int* si)
{
	*sr = xr + yr;
	*si = xi + yi;
}
int main()
{
	int ar = 1, ai = 1; // 1+1i
	int br = 2, bi = 2; // 2+2i
	int sr, si;

	Add(ar, ai, br, bi, &sr, &si);

}