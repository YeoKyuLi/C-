https://github.com/codenuri/CPP1/tree/master/SECTION7/02_ADV_NAMESPACE
=============인자 기반 탐색=============
1. 인자 기반 탐색(Argument Dependent Lookup)
    컴파일러가 함수를 찾을 때 인자사 속함 namespace를 자동으로 검색하는 문법
    namespace의 이름이 없어도 함수를 호출할 수 있다.

namespace Video
{
    struct Card
    {
        //.....        
    };
    void init( Card card ) 
    {
    }
}

int main()
{
    Video::Card card;
    init(card);
}

핵심개념
1. namespace에 포함된 타입이 연산자 재정의 함수를 제공한 경우
    ADL 문법이 없으면 연산자 함수를 직접 호출해야 한다.
    기호(+)를 사용할 수 없다.


namespace Shape
{
    class Point
    {
        int x;
        int y;
    public:
        Point(int a = 0, int b = 0 ) : x(a), y(b) {}
        
        friend Point operator+(const Point& p1, const Point& p2);
    };
    
    Point operator+(const Point& p1, const Point& p2)
    {
        return Point( p1.x + p2.x, p1.y + p2.y);
    }    
}

int main()
{
    Shape::Point p1(1,1);
    Shape::Point p2(2,2);
    
    Shape::Point p3 = p1 + p2;
    Shape::Point p4 = operator+(p1, p2);
    Shape::Point p4 = Shape::operator+(p1, p2);
    
}