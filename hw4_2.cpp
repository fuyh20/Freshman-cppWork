#include <iostream>
#include <cstdlib>
#include <cmath>
#define pi 3.14159
using namespace std;
class Ball
{
public:
    Ball(int x = 0, int y = 0, int z = 0, int r = 0) : x(x), y(y), z(z), r(r)
    {
        cout << "constructor called " << x << ',' << y << ',' << z << endl;
    }
    Ball(const Ball &p)
    {
        this->x = p.x;
        this->y = p.y;
        this->z = p.z;
        this->r = p.r;
    }
    ~Ball()
    {
        cout << "destructor called " << x << ',' << y << ',' << z << endl;
    }
    void Set(int x, int y, int z, int r)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->r = r;
    }
    void Set(Ball a)
    {
        this->x = a.GetX();
        this->y = a.GetY();
        this->z = a.GetZ();
        this->r = a.GetR();
    }
    int GetX() { return x; }
    int GetY() { return y; }
    int GetZ() { return z; }
    int GetR() { return r; }
    void Print() const
    {
        cout << "coordinate of Ball center is "
             << '(' << x << ',' << y << ',' << z << ')' << ','
             << "radius is " << r << endl;
    }
    double Volume()
    {
        return 4.0 / 3 * pi * r * r * r;
    }

private:
    int x, y, z, r;
};
void sort(Ball a[], int n)
{
    int i, j, k;
    Ball d;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j].GetR() < a[k].GetR())
                k = j;
        }
        if (k != i)
            d.Set(a[i]), a[i].Set(a[k]), a[k].Set(d);
    }
}
int main()
{
    int sx = 0, sy = 0, sz = 0, sr = 0;
    double sV = 0;
    Ball a[10], *b;
    b = new Ball[20];
    srand(0);
    for (int i = 0; i < 10; i++)
        a[i] = Ball(rand(), rand(), rand(), abs(rand()));
    for (int i = 0; i < 20; i++)
        b[i] = Ball(rand(), rand(), rand(), abs(rand()));
    sort(a, 10);
    sort(b, 20);
    for (int i = 0; i < 10; i++)
    {
        cout << "Ball a[" << i << "]";
        a[i].Print();
        cout << "volume is " << a[i].Volume() << endl;
    }
    for (int i = 0; i < 20; i++)
    {
        cout << "Ball b[" << i << "]";
        b[i].Print();
        cout << "volume is " << b[i].Volume() << endl;
    }
    for (int i = 0; i < 20; i++)
        if (i < 10)
        {
            sx += a[i].GetX();
            sy += a[i].GetY();
            sz += a[i].GetZ();
            sr += a[i].GetR();
            sV += a[i].Volume();
            sx += b[i].GetX();
            sy += b[i].GetY();
            sz += b[i].GetZ();
            sr += b[i].GetR();
            sV += b[i].Volume();
        }
        else
        {
            sx += b[i].GetX();
            sy += b[i].GetY();
            sz += b[i].GetZ();
            sr += b[i].GetR();
            sV += b[i].Volume();
        }
    cout << "averge coordinate of all Ball center is "
         << "(" << sx / 30 << ',' << sy / 30 << ',' << sz / 30 << ")" << endl
         << "averge radius is " << sr / 30 << endl
         << "averge Volume is " << sV / 30 << endl;
    delete[] b;
    return 0;
}