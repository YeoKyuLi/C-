// 9_���漱��

class Car;	// Ŭ������ ���� ����( class forward declaration)
			// ������ ������ ��� �����ͺ����� ��밡��.
			// ����, ������ Ÿ�� ������...!!!

void foo(); // �Լ� ����...
int main()
{
	foo();

	Car* c;
	Car c2;	//error, ���漱���� �ƴ� ������ ���� �ʿ�.
}

void foo()
{

}
class Car
{

};