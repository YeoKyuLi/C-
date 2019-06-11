

class People
{

};

int main()
{
	// C++ : 모든 메모리에 객체를 만들 수 있따. 자유롭게
	// JAVA, C# : 객체는 힙에만 만들 수 있다. - 자류옵지 않지만, 쉽다.
	// 전연 변수 --> DATA memory
	People peo1;				// 스택 객체
	People* p1 = new People;	// heap 객체

	People peo2 = peo1;			// 복사 생성자
	People* p2 = p1;			// 객체 복사가 아니다. 객체를 가르키는 죽소를 복사한다.

	// 자바 코드
	People p1 = new People;
	People p2 = p1;				// p1과 동일한 객체를 가르킨다.
	People p3 = p1.clone();		// p1과 동일한 모양의 객체를 만ㄷㄹ어서
								// p3가 가리키게 한다.
								// 즉, 복사생성.
}