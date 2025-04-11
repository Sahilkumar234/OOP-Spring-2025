#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    string contactNO;
    string optionallyAddress;

public:
    Person(string name, int age, string contactNO, string optionallyAdrdress) : name(name), age(age), contactNO(contactNO), optionallyAddress(optionallyAddress) {}

    virtual void updateInfo(string name, int age, string contactNO, string optionallyAdrdress)
    {
        this->name = name;
        this->age = age;
        this->contactNO = contactNO;
        this->optionallyAddress = optionallyAddress;
    }

    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact Number: " << contactNO << endl;
        cout << "Optionally Address: " << optionallyAddress << endl;
    }
};

class Patient : public Person
{
    int patientID;
    string assignedDoctor;
    string medicalHistory;

public:
    Patient(string name, int age, string contactNO, string optionallyAdrdress, int patientID, string assignedDoctor, string medicalHistory) : Person(name, age, contactNO, optionallyAddress), patientID(patientID), assignedDoctor(assignedDoctor), medicalHistory(medicalHistory) {}

    void displayInfo()
    {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << endl;
        cout << "Assigned Doctor: " << assignedDoctor << endl;
        cout << "Medical History: " << medicalHistory << endl;
        cout << "<------------------------------------------>" << endl;
    }
};

class Doctor : public Person
{
    int consultationFee;
    string specialization;
    string parentList;

public:
    Doctor(string name, int age, string contactNO, string optionallyAdrdress, int consultationFee, string specialization, string parentList) : Person(name, age, contactNO, optionallyAddress), consultationFee(consultationFee), specialization(specialization), parentList(parentList) {}

    void displayInfo()
    {
        cout << "Consultation Fee: " << consultationFee << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "ParentList: " << parentList << endl;
        cout << "<------------------------------------------>" << endl;
    }
};

class Nurse : public Person
{
    string assignedWork;
    int shiftTimings;

public:
    Nurse(string name, int age, string contactNO, string optionallyAdrdress, string assignedWork, int shiftTimings) : Person(name, age, contactNO, optionallyAddress), assignedWork(assignedWork), shiftTimings(shiftTimings) {}

    void displayInfo()
    {
        Person::displayInfo();
        cout << "Assigned Work: " << assignedWork << endl;
        cout << "Shift timing: " << shiftTimings << endl;
        cout << "<------------------------------------------>" << endl;
    }
};

class Administrartor : public Person
{
    string department;
    double salary;

public:
    Administrartor(string name, int age, string contactNO, string optionallyAdrdress, string department, double salary) : Person(name, age, contactNO, optionallyAddress), department(department), salary(salary) {}

    void updateInfo(string name, int age, string contactNO, string department, double salary, string optionallyAdrdress)
    {
        Person::updateInfo(name, age, contactNO, optionallyAddress);
        this->salary = salary;
        this->department = department;
        cout << "<------------------------------------------>" << endl;
    }

    void displayInfo()
    {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
        cout << "<------------------------------------------>" << endl;
    }
};

int main()
{
    Patient PP("John", 22, "*92-3--------2", "Toroto", 1122, "Smith", "XYZ");
    Person *P1 = &PP;
    P1->displayInfo();

    Doctor DD("Dr.javed Altaf", 62, "*92-3--------2", "Karachi", 5000, "Cardiologist", "Sahil,Jaidev and Dev");
    Person *P2 = &DD;
    P2->displayInfo();

    Nurse NN("Dr.Aiza", 28, "*92-3--------2", "Agha Khan Karachi", "Physiothropy", 12);
    Person *P3 = &NN;
    P3->displayInfo();

    Administrartor AA("Dr.Shafee", 74, "*92-3--------2", "Indus Hospital", "MBBS", 350000);
    Person *P4 = &AA;
    P4->displayInfo();
    AA.updateInfo("Dr.Aslam Khan", 67, "*92-345------2", "FCPS", 400000.0, "Liaqut National");
    P4->displayInfo();
}
