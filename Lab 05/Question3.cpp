#include <iostream>
using namespace std;

class Employee
{
    string employeeName;
    string designation;

public:
    Employee(string employeeName, string designation) : employeeName(employeeName), designation(designation) {}

    void displayEmployee() const
    {
        cout << "Name: " << employeeName << endl;
        cout << "Employee Designation: " << designation << endl;
        cout << "-----------------------------" << endl;
    }
};

class Project
{
    string title;
    string deadline;
    Employee *employee[5];
    int empCount = 0;

public:
    Project(string title, string deadline) : title(title), deadline(deadline) {}

    void addEmployee(Employee *emp)
    {
        employee[empCount++] = emp;
    }

    void displayDetails() const
    {
        cout << "Project Title: " << title << endl;
        cout << "Project deadline: " << deadline << endl;

        for (int i = 0; i < empCount; i++)
        {
            employee[i]->displayEmployee();
        }
    }
};

int main()
{
    Employee E1("Gotam", "XYZ");
    Employee E2("Dev", "ABC");

    Project P1("TIC TAC TOE", "5 April 2025");
    P1.addEmployee(&E1);
    P1.addEmployee(&E2);
    P1.displayDetails();
}
