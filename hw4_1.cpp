#include <iostream>
#include <cmath>
using namespace std;
class Point
{
public:
    Point(int xx = 0, int yy = 0) : x(xx), y(yy)
    {
        cout << "构造函数被调用" << '(' << x << ',' << y << ')' << endl;
    }
    Point(const Point &p)
    {
        this->x = p.x;
        this->y = p.y;
        cout << "复制构造函数被调用" << '(' << x << ',' << y << ')' << endl;
    }
    ~Point()
    {
        cout << "析构函数被调用" << '(' << x << ',' << y << ')' << endl;
    }
    void Set(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void Set(Point p)
    {
        this->x = p.x;
        this->y = p.y;
    }
    void Print() const
    {
        cout << '(' << x << ',' << y << ')' << endl;
    }
    int Getx() { return x; }
    int Gety() { return y; }

private:
    int x, y;
};
class Rectangle
{
public:
    Rectangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : p1(x1, y1), p2(x2, y2)
    {
        cout << "构造函数被调用" << endl;
    }
    Rectangle(Point pp1, Point pp2) : p1(pp1), p2(pp2)
    {
        cout << "构造函数被调用" << endl;
    }
    Rectangle(const Rectangle &p) : p1(p.p1), p2(p.p2)
    {
        cout << "复制构造函数被调用" << endl;
    }
    ~Rectangle()
    {
        cout << "析构函数被调用" << endl;
    }
    void Set(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0)
    {
        p1.Set(x1, y1);
        p2.Set(x2, y2);
    }
    void Set(Point pp1, Point pp2)
    {
        p1.Set(pp1);
        p2.Set(pp2);
    }
    void Print()
    {
        cout << "矩形左下角坐标为";
        p1.Print();
        cout << "矩形右上角角坐标为";
        p2.Print();
    }
    double Circumference();
    double Area();

private:
    Point p1, p2;
};
double Rectangle::Area()
{
    return abs(p1.Getx() - p2.Getx()) * abs(p1.Gety() - p2.Gety());
}
double Rectangle::Circumference()
{
    return 2 * (abs(p1.Getx() - p2.Getx()) + abs(p1.Gety() - p2.Gety()));
}
int main()
{
    Rectangle R(1, 1, 2, 3);
    Point p1(1, 1), p2(2, 2);
    R.Print();
    cout << "矩形R1的面积为" << R.Area() << endl;
    cout << "矩形R1的周长为" << R.Circumference() << endl;
    R.Set(p1, p2);
    R.Print();
    return 0;
}