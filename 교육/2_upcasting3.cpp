// 2_upcasting3
// composite patern --> tree ����
// ��ü ���� �������� �ٽ� 1.
// A�� B�� ���� �ʹٸ� ������ ��� Ŭ������ �����ض�!!
// 

#include <list>
using namespace std;
class Item {};
class File : public Item
{

};
class Folder : public Item
{
	list<Item*> s;	// File �Ӹ� �ƴ϶� Folder�� ������ �� �ְ� �ȴ�
					// "Composite" ����
};

int main()
{

}