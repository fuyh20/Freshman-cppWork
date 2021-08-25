#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
    int x, cnt = 1;
    ifstream ifile("D:\\Coding cpp\\Script\\data.txt");
    while (ifile >> x)
    {
        cout << setw(8) << x;
        if ((cnt++) % 10 == 0)
            cout << endl;
    }
    ifile.close();
    return 0;
}