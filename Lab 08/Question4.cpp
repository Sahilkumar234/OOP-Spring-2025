#include <iostream>
using namespace std;

class Inventory;

class Car
{
    string modelName;
    int price;

public:
    Car(string name, double price) : modelName(name), price(price) {}

    friend class Inventory;

    friend void compareCars(Car &obj, Car &obj1);
};

class Inventory
{
public:
    void modify(Car &obj, double newPrice)
    {
        obj.price = newPrice;
    }

    void displayDetails(Car &car1)
    {
        cout << "Car Model: " << car1.modelName << endl;
        cout << "Car price: " << car1.price << endl;
        cout << "<<----------------------------------->>" << endl;
    }
};

void compareCars(Car &obj, Car &obj1)
{
    if (obj.price > obj1.price)
    {
        cout << "Car " << obj.modelName << " is more expensive than " << obj1.modelName << endl;
    }
    else if (obj1.price > obj.price)
    {
        cout << "Car " << obj1.modelName << " is more expensive than " << obj.modelName << endl;
    }
    else
    {
        cout << "Car " << obj1.modelName << " and " << obj.modelName << " are same price model " << endl;
    }
}

int main()
{
    Car car1("Toyota Cross", 9000000);
    Car car2("Kia Sportage", 7800000);

    Inventory invent;

    invent.displayDetails(car1);
    invent.displayDetails(car2);

    compareCars(car1, car2);
    cout << "<<----------------------------------->>" << endl;

    invent.modify(car2, 17000000);

    invent.displayDetails(car1);
    invent.displayDetails(car2);

    compareCars(car1, car2);
    cout << "<<----------------------------------->>" << endl;
}
