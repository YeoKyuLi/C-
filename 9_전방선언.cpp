// 9_전방선언

class Car;	// 클래스의 전방 선언( class forward declaration)
			// 완전한 선언이 없어도 포인터변수는 사용가능.
			// 주의, 포인터 타입 변수만...!!!

void foo(); // 함수 선언...
int main()
{
	foo();

	Car* c;
	Car c2;	//error, 전방선언이 아닌 완전한 선언 필요.
}

void foo()
{

}
class Car
{

};