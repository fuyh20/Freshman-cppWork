#include <iostream>
using namespace std;
template <class T>
class Queue
{
private:
    T *Front, *Tail;
    int max;

public:
    Queue(int size);
    Queue(const Queue<T> &p);
    ~Queue();
    void In(const T &a);
    T Out();
    bool isEmpty();
};

template <class T>
Queue<T>::Queue(int size)
{
    max = size;
    Front = new T[max];
    Tail = Front;
}

template <class T>
Queue<T>::Queue(const Queue<T> &p)
{
    Front = new T[max = p.max];
    Tail = &Front[max];
    for (int i = 0; i < max; i++)
        Front[i] = p.Front[i];
}

template <class T>
Queue<T>::~Queue()
{
    delete[] Front;
}

template <class T>
void Queue<T>::In(const T &a)
{
    if (Tail - Front == max)
        cout << "overflow!" << endl;
    else
    {
        *Tail = a;
        Tail++;
    }
}

template <class T>
T Queue<T>::Out()
{
    if (Front == Tail)
    {
        cout << "underflow!" << endl;
        return Front[0];
    }
    else
    {
        T d = Front[0];
        Tail--;
        for (int i = 0; i < int(Tail - Front); i++)
            Front[i] = Front[i + 1];
        return d;
    }
}

template <class T>
bool Queue<T>::isEmpty()
{
    return Front == Tail;
}

int main()
{
    Queue<double> doubleQueue(10);
    Queue<int> intQueue(15);
    for (double i = 1.0; i <= 20.0; i += 2.0)
        doubleQueue.In(i);
    while (!doubleQueue.isEmpty())
        cout << doubleQueue.Out() << " ";
    cout << endl;
    for (int i = 0; i < 75; i += 5)
        intQueue.In(i);
    while (!intQueue.isEmpty())
        cout << intQueue.Out() << " ";
    cout << endl;
    return 0;
}