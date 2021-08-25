#define pi 3.14159
#include <iostream>
using namespace std;
class Circle
{
public:
    Circle(double x, double y, double r) : x(x), y(y), r(r){}
    Circle(const Circle &p) {}
    ~Circle()
    {
        cout << "析构函数被调用" << endl;
    }
    void Set(double x, double y, double r)
    {
        this->x = x;
        this->y = y;
        this->r = r;
    }
    void Print();
    double Area();

private:
    double x, y, r;
};
void Circle::Print()
{
    cout << "圆心坐标为" << '(' << x << ',' << y << ')' << ",半径为" << r << endl;
}
double Circle::Area()
{
    return pi * r * r;
}
int main()
{
    Circle O(0, 0, 1);
    cout << "圆面积为" << O.Area() << endl;
    O.Print();
    O.Set(1, 1, 1);
    O.Print();
    return 0;
}