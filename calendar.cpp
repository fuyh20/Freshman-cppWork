#include <iostream>
using namespace std;
int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char month[12][20] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
bool Isleapyear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}
void Title(int a, int b)
{
    cout << "               " << month[a] << "            " << b << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Sun\tMon\tTue\tWed\tThur\tFri\tSat" << endl;
}
int Week(int year, int month)
{
    int sum = 0;
    for (int i = 1800; i < year; i++)
        if (Isleapyear(i))
            sum += 366;
        else
            sum += 365;
    for (int i = 1; i < month; i++)
        sum += day[i - 1];
    return (sum + 3) % 7;
}
void Output(int start, int day)
{
    int k = start;
    while (start--)
        cout << '\t';
    for (int i = 1; i <= day; i++)
    {
        cout << i << '\t';
        if ((i + k) % 7 == 0)
            cout << endl;
    }
}
int main()
{
    int Year, Month;
    cout << "Year:";
    cin >> Year;
    cout << "Month:";
    cin >> Month;
    if (Isleapyear(Year))
        day[1]++;
    Title(Month - 1, Year);
    Output(Week(Year, Month), day[Month - 1]);
    return 0;
}