#include <iostream>
#include <cmath>
using namespace std;
#define pi 3.1416
class Point
{
public:
    Point(double x = 0, double y = 0) : x(x), y(y)
    {
        cout << "Point构造函数被调用 " << x << ',' << y << endl;
    }
    Point(const Point &p) : x(p.x), y(p.x)
    {
        cout << "Point复制构造函数被调用 " << x << ',' << y << endl;
    }
    virtual ~Point()
    {
        cout << "Point析构函数被调用 " << x << ',' << y << endl;
    }
    virtual double GetArea()
    {
        return 0;
    }

protected:
    double x, y;
};

class Circle : virtual public Point
{
public:
    Circle(double x, double y, double r = 0) : Point(x, y), R(r)
    {
        cout << "Circle构造函数被调用" << endl;
    }
    Circle(const Circle &x) : Point(x), R(x.R)
    {
        cout << "Circle复制构造函数被调用" << endl;
    }
    virtual ~Circle()
    {
        cout << "Circle析构函数被调用" << endl;
    }
    virtual double GetArea()
    {
        return pi * R * R;
    }

protected:
    double R;
};

class Square : virtual public Point
{
public:
    Square(double x, double y, double a = 0) : Point(x, y), L(a)
    {
        cout << "Square构造函数被调用" << endl;
    }
    Square(const Square &s) : Point(s.x, s.y), L(s.L)
    {
        cout << "Square复制构造函数被调用" << endl;
    }
    virtual ~Square()
    {
        cout << "Square析构函数被调用" << endl;
    }
    virtual double GetArea()
    {
        return L * L;
    }

protected:
    double L;
};

class Margin : public Circle, public Square
{
public:
    Margin(double x, double y, double r, double l) : Point(x, y), Circle(x, y, r), Square(x, y, l)
    {
        cout << "Margin构造函数被调用" << endl;
    }
    Margin(const Margin &m) : Point(m), Circle(m), Square(m)
    {
        cout << "Margin复制构造函数被调用" << endl;
    }
    virtual ~Margin()
    {
        cout << "Margin析构函数被调用" << endl;
    }
    virtual double GetArea()
    {
        if (L > 2 * R)
            return Square::GetArea() - Circle::GetArea();
        else if (L < sqrt(2))
            return Circle::GetArea() - Square::GetArea();
        else
            return 0;
    }
};

int main()
{
    Margin *p[] = {new Margin(1, 1, 1, 5), new Margin(0, 0, 5, 1), new Margin(1, 2, 4, 4)};
    for (int i = 0; i < 3; i++)
        cout << p[i]->GetArea() << endl;
    for (int i = 0; i < 3; i++)
        delete p[i];
    return 0;
}