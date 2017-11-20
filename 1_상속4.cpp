//1_상속4

// protected 생성자의 철학 : 자신의 객체는 만들 수 없지만 (추상적인 존재)
//							파생클래스는 만들 수 있게 (구체적 존재) 하는 기술

class Animal
{
/*error both of them.
private:
	Animal() {} // 생성자
*/
// error only Animal
protected:
	Animal() {} // 생성자

/* no error
public:
	Animal() {} // 생성자
*/
};

class Dog : public Animal
{

};
int main()
{
	// 다음중 에러는 ?
	//Animal a;	// protected -  error
	Dog d;		// protected - ok

}