#include <iostream>
#include <cstring>
using namespace std;
class String
{
public:
    String(const char *p)
    {
        s = new char[strlen(p) + 1];
        strcpy(s, p);
        cout << "构造函数被调用" << s << endl;
    }
    String(const String &p)
    {
        this->s = new char[strlen(p.s) + 1];
        strcpy(s, p.s);
        cout << "复制构造函数被调用" << s << endl;
    }
    ~String()
    {
        cout << "析构函数被调用" << s << endl;
        delete[] s;
    }
    void Set(char *p)
    {
        delete[] this->s;
        s = new char[strlen(p) + 1];
        strcpy(s, p);
    }
    void Print() const
    {
        cout << s;
    }
    friend int operator==(String &p1, String &p2);
    friend int operator>(String &p1, String &p2);
    friend int operator<(String &p1, String &p2);
    friend int operator!=(String &p1, String &p2);
    friend int operator>=(String &p1, String &p2);
    friend int operator<=(String &p1, String &p2);

private:
    char *s;
};

int operator==(String &p1, String &p2)
{
    if (strcmp(p1.s, p2.s) == 0)
        return 1;
    else
        return 0;
}

int operator!=(String &p1, String &p2)
{
    if (strcmp(p1.s, p2.s) != 0)
        return 1;
    else
        return 0;
}

int operator>=(String &p1, String &p2)
{
    if (strcmp(p1.s, p2.s) >= 0)
        return 1;
    else
        return 0;
}

int operator<=(String &p1, String &p2)
{
    if (strcmp(p1.s, p2.s) <= 0)
        return 1;
    else
        return 0;
}

int operator<(String &p1, String &p2)
{
    if (strcmp(p1.s, p2.s) < 0)
        return 1;
    else
        return 0;
}

int operator>(String &p1, String &p2)
{
    if (strcmp(p1.s, p2.s) > 0)
        return 1;
    else
        return 0;
}

int main()
{
    String s1("abcd"), s2("abce");
    if (s1 > s2)
        cout << "s1 > s2!" << endl;
    else if (s1 < s2)
        cout << "s1 < s2!" << endl;
    if (s1 == s2)
        cout << "s1 == s2!" << endl;
    if (s1 != s2)
        cout << "s1 != s2!" << endl;
    if (s1 <= s2)
        cout << "s1 <= s2!" << endl;
    if (s1 >= s2)
        cout << "s1 >= s2!" << endl;
    return 0;
}