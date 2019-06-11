//주제 1. namespace
//namespace.cpp


#include <stdio.h>
namespace Video
{
	void init()
	{
		printf("Video init \n");		
	}
	void check()
	{
		printf("Video checkcheck \n");		
	}
}

namespace Audio
{
	void init()
	{
		printf("Audio init \n");		
	}
}
void init()
{
	printf("global init \n");		
}

int main()
{
	init();// global namespace 
	Audio::init(); //방법1. 완전한 이름을 사용한 접근

	using Audio::init; //방법2, using Declaration
	init();
	::init();//::은 global namespace를 의미합니다.

	using namespace Video; //방법 3, using directive (Video안의 ㅁ든 이름을 열어 놓는다)

}