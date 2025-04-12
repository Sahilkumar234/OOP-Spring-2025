#include <iostream>
#include <cstring>
using namespace std;

class WareHouse
{
    int ID;
    string name;
    int stock;

public:
    WareHouse(string name, int ID, int stock) : name(name), ID(ID), stock(stock) {}

    int getID()
    {
        return ID;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Stock: " << stock << endl;
        cout << "<-------------------------------->" << endl;
    }
};

class Inventory
{
    int space;
    int productCount;
    WareHouse **products;

public:
    Inventory(int space) : space(space), productCount(0)
    {
        products = new WareHouse *[space];
    }

    ~Inventory()
    {
        for (int i = 0; i < productCount; i++)
        {
            delete products[i];
        }
        delete[] products;
    }

    void addProduct(string name, int id, int stock)
    {
        if (productCount < space)
        {
            products[productCount++] = new WareHouse(name, id, stock);
            cout << "Product " << name << " added to an inventory" << endl;
        }
        else
        {
            cout << "There is no extra space to add a product..." << endl;
        }

        cout << "----------------------------" << endl;
    }

    void sortProducts()
    {
        cout << "After sorting Product Names..." << endl;
        for (int i = 0; i < productCount - 1; i++)
        {
            for (int j = i + 1; j < productCount; j++)
            {
                if (products[i]->getID() > products[j]->getID())
                {
                    WareHouse *temp = products[i];
                    products[i] = products[j];
                    products[j] = temp;
                }
            }
        }
    }

    void searchProducts(int id)
    {

        bool found = false;
        for (int i = 0; i < productCount; i++)
        {
            if (products[i]->getID() == id)
            {
                cout << "Searched Product with ID: " << id << " is..." << endl;
                products[i]->display();
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Product with ID: " << id << " not found" << endl;
            cout << "-----------------------------" << endl;
        }
    }

    void display()
    {
        for (int i = 0; i < productCount; i++)
        {
            products[i]->display();
        }
    }
};

int main()
{
    Inventory inventory(4);

    inventory.addProduct("Soap", 3322, 50);
    inventory.addProduct("J. perfume", 2333, 40);
    inventory.addProduct("Toothpaste", 1255, 58);

    inventory.display();

    inventory.sortProducts();

    inventory.display();

    inventory.searchProducts(2333);
    inventory.searchProducts(1234);

    return 0;
}
