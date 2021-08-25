#include <iostream>
using namespace std;
int main()
{
    int m, n, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    int *a = new int[100];
    int(*b)[25] = new int[20][25];
    int(*c)[8][5] = new int[9][8][5];
    int **d;
    cin >> m;
    cin >> n;
    d = new int *[m];
    for (int i = 0; i < m; i++)
        d[i] = new int[n];
    for (int i = 0; i < 100; i++)
    {
        a[i] = i;
        s1 += a[i];
    }
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 25; j++)
        {
            b[i][j] = 25 * i + j;
            s2 += b[i][j];
        }
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 8; j++)
            for (int k = 0; k < 5; k++)
            {
                c[i][j][k] = 100 * i + 10 * j + k;
                s3 += c[i][j][k];
            }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            d[i][j] = i * n + j;
            s4 += d[i][j];
        }
    cout << "the sum of a is " << s1 << endl
         << "the sum of b is " << s2 << endl
         << "the sum of c is " << s3 << endl
         << "the sum of d is " << s4 << endl;
    delete[] d;
    delete[] c;
    delete[] b;
    delete[] a;
}