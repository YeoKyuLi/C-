//1_���4

// protected �������� ö�� : �ڽ��� ��ü�� ���� �� ������ (�߻����� ����)
//							�Ļ�Ŭ������ ���� �� �ְ� (��ü�� ����) �ϴ� ���

class Animal
{
/*error both of them.
private:
	Animal() {} // ������
*/
// error only Animal
protected:
	Animal() {} // ������

/* no error
public:
	Animal() {} // ������
*/
};

class Dog : public Animal
{

};
int main()
{
	// ������ ������ ?
	//Animal a;	// protected -  error
	Dog d;		// protected - ok

}