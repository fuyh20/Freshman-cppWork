#include <iostream>
using namespace std;
template <typename T>
T Max(T a, T b, T c)
{
    return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}
template <typename T, typename X, typename Y, typename Z>
T Max(X a, Y b, Z c)
{
    if (a > b)
        return a > c ? a : c;
    else
        return b > c ? b : c;
}
int main()
{
    char c1 = '1', c2 = '2', c3 = '3';
    short a1 = 1, a2 = 2, a3 = 3;
    int b1 = 1, b2 = 2, b3 = 3;
    long d1 = 1, d2 = 2, d3 = 3;
    float e1 = 1.0f, e2 = 2.0f, e3 = 3.0f;
    double f1 = 1, f2 = 2, f3 = 3;
    cout << Max(c1, c2, c3) << ' ' << Max(a1, a2, a3) << ' '
         << Max(b1, b2, b3) << ' ' << Max(d1, d2, d3) << ' '
         << Max(e1, e2, e3) << ' ' << Max(f1, f2, f3) << endl;
    cout << Max<long, short, int, long>(a1, b1, c1) << endl;
}