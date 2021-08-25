#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct student
{
    int sno;
    string name;
    int score;
};

student st[] = {
    {11856, "Alice", 95},
    {12345, "Bob", 90},
    {27338, "Bob", 93},
    {60017, "Carol", 88},
    {38456, "Dave", 86},
    {23201, "Eve", 90},
    {23205, "Eve", 90},
    {41933, "Frank", 92},
    {68477, "Grace", 91},
    {85566, "Hans", 83},
    {77711, "Issac", 97},
    {54298, "John", 88}};

bool cmp(student st1, student st2)
{
    if (st1.score != st2.score)
        return st1.score > st2.score;
    else if (st1.name != st2.name)
        return st1.name < st2.name;
    else
        return st1.sno < st2.sno;
}

int main()
{
    sort(st, st + 12, cmp);
    for (int i = 0; i < 12; i++)
        cout << st[i].sno << ' ' << st[i].name << ' ' << st[i].score << endl;
    return 0;
}