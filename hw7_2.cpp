#include <iostream>
using namespace std;
class Point
{
public:
    Point(int x = 0, int y = 0) : x(x), y(y)
    {
        cout << "构造函数被调用" << x << ',' << y << endl;
    }
    ~Point()
    {
        cout << "析构函数被调用" << x << ',' << y << endl;
    }
    Point(const Point &p);
    void Set(int x, int y);
    void Print() const;

protected:
    int x, y;
};

Point::Point(const Point &p)
{
    this->x = p.x;
    this->y = p.y;
    cout << "复制构造函数被调用" << x << ',' << y << endl;
}
void Point::Set(int x, int y)
{
    this->x = x;
    this->y = y;
}
void Point::Print() const
{
    cout << x << ',' << y << endl;
}

class Line : public Point
{
public:
    Line(int x = 0, int y = 0, double S = 0) : Point(x, y), S(S)
    {
        cout << "构造函数被调用" << x << ',' << y << ',' << S << endl;
    }
    Line(Point p, double S = 0) : Point(p)
    {
        this->S = S;
        cout << "构造函数被调用";
        cout << x << ',' << y << ',' << S << endl;
    }
    ~Line()
    {
        cout << "析构函数被调用";
        cout << x << ',' << y << ',' << S << endl;
    }
    Line(const Line &p) : Point(p)
    {
        this->S = p.S;
    }
    void Set(int x, int y, double S)
    {
        this->x = x;
        this->y = y;
        this->S = S;
    }
    void Print() const
    {
        cout << x << ',' << y << ',' << S << endl;
    }

private:
    double S;
};

int main()
{
    Point p(1, 1);
    Line l1(2, 2, 1);
    Line l2(p, 1);
    Line l3(l1);
    l1.Set(3, 3, 1);
    l1.Print();
    return 0;
}