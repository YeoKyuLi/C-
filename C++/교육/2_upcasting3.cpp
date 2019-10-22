// 2_upcasting3
// composite patern --> tree 형태
// 객체 지향 디자인의 핵심 1.
// A와 B를 묶고 싶다면 공통의 기반 클래스를 설계해라!!
// 

#include <list>
using namespace std;
class Item {};
class File : public Item
{

};
class Folder : public Item
{
	list<Item*> s;	// File 뿐만 아니라 Folder도 보관할 수 있게 된다
					// "Composite" 패턴
};

int main()
{

}