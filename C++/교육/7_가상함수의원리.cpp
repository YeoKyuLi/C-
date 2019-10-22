// 7_�����Լ��ǿ���
#include <iostream>

class Animal
{
public:
	void Cry() {}
};
class Dog : public Animal
{
public:
	void Cry() {}
};

int main()
{
	Animal a;
	Dog d;
	Animal *p = &d;
	p->Cry();
}
// p->Cry(); �� ��� �Լ��� �����ұ �����ϴ� �۾� - �Լ� ���ε�(binding)

// 1. static binding : static ������ �ð��� �ǹ�
//						������ �ð��� �����Ϸ��� ��� �Լ��� ȣ������ ����
//						�����Ϸ��� ���� ��ü�� �� �� ����. ������ Ÿ�Ը� �˰��ִ�.
//						Animal Cry ȣ��
//						early binding, ������. C++, C#

// 2. dynamic binding : ������ �ð��� p�� ����Ű�� �޸𸮸� �����ϴ� ���� �ڵ� ����
//						����ð��� ���� �� ȣ��
//						Dog Cry ȣ��
//						late binding, ������. JAVA(������ �켱��) , Objective-C, swift
//											  virtual �Լ� dynamic binding ���� in C++ / C# 


