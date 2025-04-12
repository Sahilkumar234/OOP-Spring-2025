#include <iostream>
using namespace std;

class Employee
{
protected:
    string name;
    string address;

public:
    Employee(string name, string address) : name(name), address(address) {}

    void displayEmp()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }
};

class Manager : public Employee
{
protected:
    float salary;

public:
    Manager(string name, string address, float salary) : Employee(name, address), salary(salary) {}

    void display()
    {
        displayEmp();
        cout << "Salary is: " << salary << endl;
    }
};

int main()
{
    Manager M1("Sahil", "XYZ", 34000.70);
    M1.display();
}
