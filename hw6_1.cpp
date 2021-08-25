#include <iostream>
#include <cstring>
using namespace std;
class String
{
public:
    String(const char *p = NULL)
    {
        if (p == NULL)
        {
            str = new char(0);
            cout << "构造函数被调用" << endl;
        }
        else
        {
            str = new char[strlen(p) + 1];
            strcpy(str, p);
            cout << "构造函数被调用" << str << endl;
        }
    }
    String(const String &p)
    {
        this->str = new char[strlen(p.str) + 1];
        strcpy(str, p.str);
        cout << "复制构造函数被调用" << str << endl;
    }
    ~String()
    {
        cout << "析构函数被调用" << str << endl;
        delete[] str;
    }
    void Set(char *p)
    {
        delete[] this->str;
        str = new char[strlen(p) + 1];
        strcpy(str, p);
    }
    void Print() const
    {
        cout << str << endl;
    }
    String operator+(const String &s1)
    {
        char *tmp = new char[strlen(str) + strlen(s1.str) + 1];
        strcpy(tmp, str);
        strcat(tmp, s1.str);
        return String(tmp);
    }
    String &operator=(const String &s1)
    {
        char *tmp = new char[strlen(s1.str) + 1];
        strcpy(tmp, s1.str);
        delete[] this->str;
        this->str = tmp;
        return *this;
    }

private:
    char *str;
};

int main()
{
    String s1("abcd"), s2("efghij"), s3("lmnop"), s4, s5;
    s4 = s1 + s2 + s3;
    s4.Print();
    s5 = s5 + s3 + s4;
    s5.Print();
    return 0;
}