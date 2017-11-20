// 참고

class Car
{
	int color;
	int speed;
};

int main()
{
	// C++, 객체의 갯수는 몇개 인가요?
	Car c1;
	Car c2 = c1;
	Car* p1 = new Car;
	Car* p2 = p1;

	//java code
	Car p1 = new Car;
	Car p2 = p1;
}