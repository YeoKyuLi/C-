

class People
{

};

int main()
{
	// C++ : ��� �޸𸮿� ��ü�� ���� �� �ֵ�. �����Ӱ�
	// JAVA, C# : ��ü�� ������ ���� �� �ִ�. - �ڷ����� ������, ����.
	// ���� ���� --> DATA memory
	People peo1;				// ���� ��ü
	People* p1 = new People;	// heap ��ü

	People peo2 = peo1;			// ���� ������
	People* p2 = p1;			// ��ü ���簡 �ƴϴ�. ��ü�� ����Ű�� �׼Ҹ� �����Ѵ�.

	// �ڹ� �ڵ�
	People p1 = new People;
	People p2 = p1;				// p1�� ������ ��ü�� ����Ų��.
	People p3 = p1.clone();		// p1�� ������ ����� ��ü�� �������
								// p3�� ����Ű�� �Ѵ�.
								// ��, �������.
}