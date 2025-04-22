#include <iostream>
using namespace std;

class MenuItem
{
protected:
    string dishName;
    double price;

public:
    MenuItem(string dishName, double price) : dishName(dishName), price(price) {}

    virtual void showDetails() = 0;
    virtual void prepare() = 0;
    virtual ~MenuItem() {}
};

class Appetizers : public MenuItem
{
public:
    Appetizers(string dishName, double price) : MenuItem(dishName, price) {}

    void showDetails()
    {
        cout << "Dish name: " << dishName << endl;
        cout << "Price: " << price << endl;
    }

    void prepare()
    {
        cout << "preparing the " << dishName << " with the help of breads,making toopping,and Assemble bruscheta" << endl;
    }
};

class MainCourse : public MenuItem
{
public:
    MainCourse(string dishName, double price) : MenuItem(dishName, price) {}

    void showDetails()
    {
        cout << "Dish name: " << dishName << endl;
        cout << "Price: " << price << endl;
    }

    void prepare()
    {
        cout << "preparing the " << dishName << " Marinating,cooking and platting" << endl;
    }
};

int main()
{
    MenuItem *items[2];
    items[0] = new Appetizers("Dumplings", 220.0);
    items[1] = new MainCourse("Grilled chicken", 1470.0);

    for (int i = 0; i < 2; i++)
    {
        items[i]->showDetails();
        cout << "<<--Preparation-->>" << endl;
        items[i]->prepare();
        cout << "<<----------------------------------------->>" << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete items[i];
    }
}
