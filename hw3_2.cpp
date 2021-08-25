#include <iostream>
#include <cmath>
using namespace std;
class Rectangle
{
public:
    Rectangle(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0) : x1(x1), x2(x2), y1(y1), y2(y2) {}
    Rectangle(const Rectangle &p){};
    ~Rectangle()
    {
        cout << "析构函数被调用" << endl;
    }
    void Set(double x1, double y1, double x2, double y2);
    void Print();
    double Circumference();
    double Area();

private:
    double x1, y1, x2, y2;
};
void Rectangle::Set(double x1, double y1, double x2, double y2)
{
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
}
void Rectangle::Print()
{
    cout << "矩形左下角坐标为(" << x1 << '.' << y1 << "),"
         << "右上角坐标为(" << x2 << '.' << y2 << ')' << endl;
}
double Rectangle::Area()
{
    return fabs(x1 - x2) * fabs(y1 - y2);
}
double Rectangle::Circumference()
{
    return 2 * (fabs(x1 - x2) + fabs(y1 - y2));
}
int main()
{
    Rectangle x(0, 0, 2, 1);
    x.Print();
    cout << "矩形的面积为" << x.Area() << endl;
    cout << "矩形的周长为" << x.Circumference() << endl;
    x.Set(1, 1, 2, 3);
    x.Print();
    return 0;
}
