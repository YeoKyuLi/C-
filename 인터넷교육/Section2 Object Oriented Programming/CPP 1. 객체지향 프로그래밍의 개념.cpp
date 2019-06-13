https://github.com/codenuri/CPP1/tree/master/SECTION2/01_OOP
=============객체 지향 프로그래밍의 개념=============
1. "현실 세계에 존재"하는 것들
2. "어떠한 데이터 타입이 있다면"편리하지 않을까?
--> C언어의 "구조체를 사용하면 새로운 타입"을 만들 수 있다.

1. 프로그램에서 필요한 타입을 먼저 설계한다.
2. 현실세계에 존재하는 사물은 "상태"와 "동작"이 있다.
3. 타입을 설계할때
--> 상태와 동작을 표현할 수 있어야 한다.
--> "상태는 변수" "동작은 함수"로 표현한다.
4. C의 구초제와 C++의 구조체
--> C : 데이터 만 포함 할 수 있다.
--> C++ : 데이터 뿐 아니라 "함수도 포함 할 수" 있다.

struct Complex
{
    double real;
    double image;
};

Complex add(const Complex& c1, const Complex& c2)
{
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.image = c1.image + c2.image;
    
    return temp;
}

int main()
{
    Complex c1 = { 1, 1}; // 1 + 1i
    Complex c2 = { 2, 2}; // 2 + 2i
    
    Complex ret = add(c1, c2);    
}

=============예제로 배우는 OOP #1=============
1. "상태를 나타내는 데이터와 상태를 조작하는 함수를 묶는다."
--> C++언어는 "구조체가 함수를 포함"할 수 있다.
--> 멤버 함수와 멤버 데이터
--> 멤버 함수에서는 멤버 데이터에 접근할 수 있다.
2. 접근 지정자
private
public
2. 정보 은닉( Information hiding) encapsulation, 
--> 멤버 변수를 외부에서 직접 접근할 수 없게 하고, 멤버 함수를 통해서만 멤버 변수에 접근하게 한다.
--> 외부의 잘못된 사용으로 객체의 상태가 불안정 해지는 것을 막는다.

3. struct vs class
--> struct : 접근지정자 생략시 디폴트가 public
--> class : 접근지정자 생략시 디폴트가 private