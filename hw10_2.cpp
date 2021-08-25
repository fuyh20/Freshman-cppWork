#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
    int a[100], i = 0;
    ifstream infile1("D:\\Coding cpp\\Script\\data1.txt");
    ofstream outfile("D:\\Coding cpp\\Script\\data2.dat", ios_base::binary);
    for (int i = 0; i < 100; i++)
        infile1 >> a[i];
    infile1.close();
    outfile.write((char *)a, sizeof(int) * 100);
    outfile.close();
    ifstream infile2("D:\\Coding cpp\\Script\\data2.dat", ios_base::binary);
    infile2.seekg(4 * sizeof(int), ios_base::beg);
    while (infile2.good())
    {
        infile2.read((char *)&a[i], sizeof(int) * 2);
        infile2.seekg(2 * sizeof(int), ios_base::cur);
        i += 2;
    }
    for (int j = 0; j < 48; j++)
    {
        cout << setw(8) << setiosflags(ios_base::left) << a[j];
        if ((j + 1) % 10 == 0)
            cout << endl;
    }
    infile2.close();
    return 0;
}