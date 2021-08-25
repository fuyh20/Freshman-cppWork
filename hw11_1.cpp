#include <iostream>
using namespace std;
int main()
{
    int *a;
    try
    {
        a = new (std::nothrow) int[10];
        if (a == NULL)
            throw "Can't get memory!\n";
        for (int i = 0; i < 10; i++)
            a[i] = i;
        int n;
        cin >> n;
        if (n >= 10)
            throw "Overflow!\n";
        else if (n <= 0)
            throw "Underflow!\n";
        else
            cout << a[n];
        if (a != NULL)
            delete[] a;
        else
            throw "deleting pointer is NULL!\n";
    }
    catch (const char *err)
    {
        cout << err;
    }
}