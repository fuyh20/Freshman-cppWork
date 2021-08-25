#include <iostream> // 可运行的完整程序
using namespace std;
class List;    // 链表类定义（复合方式）
class ListNode // 链表结点类
{
public:
    friend class List;              // 链表类为其友元类
    ListNode(int x, ListNode *next) //构造函数
    {
        this->data = x;
        this->next = next;
    }

private:
    int data;       //结点数据, 整型
    ListNode *next; //结点指针
};
class List //链表类
{
public:
    List() { first = current = NULL; } //构造函数
    int Insert(int x, int i);
    int Remove(int &x, int i);
    void Print();

private:
    ListNode *first, *current; //表头指针，当前指针
};
int List::Insert(int x, int i) //在链表第i个结点处插入新元素x
{
    ListNode *p = current;
    current = first;
    for (int k = 0; k < i - 1; k++) //找第i-1个结点
    {
        if (current == NULL)
            break;
        else
            current = current->next;
    }
    if (current == NULL && first != NULL)
    {
        cout << "无效的插入位置!\n";
        current = p;
        return 0;
    }
    ListNode *newnode = new ListNode(x, NULL);
    if (first == NULL || i == 0) //插在表前
    {
        newnode->next = first;
        first = current = newnode;
    }
    else //插在表中间或表尾
    {
        newnode->next = current->next;
        current = current->next = newnode;
    }
    return 1;
}
int List::Remove(int &x, int i)
{ //在链表中删除第i个结点, 通过x返回其值
    ListNode *p, *q;
    if (i == 0) //删除表中第1 个结点
    {
        q = first;
        current = first = first->next;
    }
    else
    {
        p = current;
        current = first; //找第i-1个结点
        for (int k = 0; k < i - 1; k++)
        {
            if (current == NULL)
                break;
            else
                current = current->next;
        }
        if (current == NULL || current->next == NULL)
        {
            cout << "无效的删除位置!\n";
            current = p;
            return 0;
        }
        else //删除表中间或表尾元素
        {
            q = current->next; //重新链接
            current = current->next = q->next;
        }
    }
    x = q->data; // 返回第i个结点的值
    delete q;    //  删除链表节点q
    return 1;
}
void List ::Print()
{
    ListNode *p = first;
    while (p)
    {
        cout << p->data << ',';
        p = p->next;
    }
    cout << endl;
}
int main()
{
    List A; // 创建一个List链表对象A
    int x, i;
    for (i = 0; i < 10; i++)
        A.Insert(i, 0); // 每个元素插在链表头部
    A.Print();
    for (i = 0; i < 10; i++)
    {
        if (A.Remove(x, 0)) // 删除链表第一个元素
            cout << x << ',';
    }
    cout << endl;
    return 0;
}