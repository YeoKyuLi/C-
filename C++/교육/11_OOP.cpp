//11_OOP - ��ü���� ���α׷��� ����

// ������ 2���� ���� ���ؼ� �����ϴ� �Լ��� �����غ��ô�.

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