#include <iostream>
#include <iomanip>
using namespace std;
int Combination(int n, int m)
{
    if ((n > m) && (m > 1))
        return Combination(n - 1, m - 1) + Combination(n - 1, m);
    else if (n == m)
        return 1;
    else if (m == 1)
        return n;
    if (m == 0)
        return 1;
    return 0;
}
int main()
{
    int k;
    cout << setw(33) << 1 << endl;
    for (int n = 1; n < 10; n++)
    {
        k = 3 * (9 - n);
        for (int a = 0; a < k; a++)
            cout << " ";
        for (int m = 0; m <= n; m++)
        {
            cout << setw(6) << Combination(n, m);
            if (n == m)
                cout << endl;
        }
    }
    return 0;
}