#include <iostream>
#include <cstring>
using namespace std;

class Apartment
{
    int ID;
    string address;
    char *ownerName;

public:
    Apartment(const char *ownerName, int ID, const string &address) : ID(ID), address(address)
    {
        this->ownerName = new char[strlen(ownerName) + 1];
        strcpy(this->ownerName, ownerName);
    }

    Apartment(const Apartment &obj)
    {
        ID = obj.ID;
        address = obj.address;
        ownerName = new char[strlen(obj.ownerName) + 1];
        strcpy(ownerName, obj.ownerName);
    }

    ~Apartment()
    {
        delete[] ownerName;
    }

    void displayDetails()
    {
        cout << "Apartment's Owner Name: " << ownerName << endl;
        cout << "Apartment ID: " << ID << endl;
        cout << "Appartment address: " << address << endl;
        cout << "--------------------------" << endl;
    }
};

int main()
{
    Apartment A1("Arif builders", 221, "Hyderabad Sindh");
    A1.displayDetails();
    Apartment A2("Sheikh Aziz", 434, "Karachi");
    A2.displayDetails();

    Apartment A3 = A1;
    cout << "Copied COnstructor of Appartment ID(221)..." << endl;
    A3.displayDetails();

    Apartment A4 = A2;
    cout << "Copied COnstructor of Appartment ID(434)..." << endl;
    A4.displayDetails();
}
