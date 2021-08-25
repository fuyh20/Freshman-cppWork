#include <iostream>
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

class Rectangle : public Point
{
public:
    Rectangle(double x, double y, double h = 0, double w = 0) : Point(x, y), Height(h), Width(w)
    {
        cout << "Rectangle构造函数被调用" << endl;
    }
    Rectangle(const Rectangle &x) : Point(x), Height(x.Height), Width(x.Width)
    {
        cout << "Rectangle复制构造函数被调用" << endl;
    }
    virtual ~Rectangle()
    {
        cout << "Rectangle析构函数被调用 " << endl;
    }
    virtual double GetArea()
    {
        return Height * Width;
    }

protected:
    double Height, Width;
};

class Circle : public Point
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

class Square : public Rectangle
{
public:
    Square(double x, double y, double a = 0) : Rectangle(x, y, a, a)
    {
        cout << "Square构造函数被调用" << endl;
    }
    Square(const Square &s) : Rectangle(s.x, s.y, s.Height, s.Width)
    {
        cout << "Square复制构造函数被调用" << endl;
    }
    virtual ~Square()
    {
        cout << "Square析构函数被调用" << endl;
    }
    virtual double GetArea()
    {
        return Height * Width;
    }
};

double f(Point &a)
{
    return a.GetArea();
}

int main()
{
    Point *pp[] = {new Point(1, 1), new Rectangle(1, 1, 1, 2),
                   new Circle(1, 1, 1), new Square(1, 1, 1)};
    for (int i = 0; i < 4; i++)
        cout << pp[i]->GetArea() << endl;
    for (int i = 0; i < 4; i++)
        delete pp[i];
    return 0;
}