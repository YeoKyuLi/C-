//4_static4

class Car
{
	int speed;
	static int cnt;

public :
	void init() { speed = 0; }

	// static 멤버 함수에서는 static 멤버만 접근할 수 있다.
	static void foo()
	{
		// 다음 중 에러를 모두 고르세요.
		speed = 10;	// 1. error
		cnt = 0;	// 2. ok
		init();		// 3. error
	}
};

int Car::cnt = 0;

int main()
{
	Car::foo();	// 객체없이 호출가능.

}