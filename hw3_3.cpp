#include <iostream>
using namespace std;
class Car;
class Boat
{
public:
    Boat(double weight = 0) : weight(weight) {}
    void Set(double weight)
    {
        this->weight = weight;
    }
    void Print();
    friend double TotalWeight(Boat B, Car C);

private:
    double weight;
};
class Car
{
public:
    Car(double weight = 0) : weight(weight) {}
    void Set(double weight)
    {
        this->weight = weight;
    }
    void Print();
    friend double TotalWeight(Boat B, Car C);

private:
    double weight;
};
void Boat::Print()
{
    cout << "该船的重量为" << weight << endl;
}
void Car::Print()
{
    cout << "该车的重量为" << weight << endl;
}
double TotalWeight(Boat B, Car C)
{
    return B.weight + C.weight;
}
int main()
{
    Boat B(1);
    Car C(2);
    cout << "船和车的总重量为" << TotalWeight(B, C) << endl;
    return 0;
}