#include <iostream>
using namespace std;

class Patient
{
protected:
    string name;
    string id;
    double fees;

public:
    Patient(string name, string id) : name(name), id(id) {}
    virtual void displayTreatement() = 0;
    virtual double calculateCost() = 0;
    virtual ~Patient() {}
};

class InPatient : public Patient
{
    int admittingDays;
    double dailyRoomCharge;

public:
    InPatient(string name, string id, int admittingDays, double dailyRoomCharge) : Patient(name, id), admittingDays(admittingDays), dailyRoomCharge(dailyRoomCharge) {}

    double calculateCost()
    {
        return admittingDays * dailyRoomCharge;
    }

    void displayTreatement()
    {
        cout << "Patient Name: " << name << endl;
        cout << "Patient ID: " << id << endl;
        cout << "Admitting Days: " << admittingDays << endl;
        cout << "Daily Room Charging: " << dailyRoomCharge << endl;
    }
};

class OutPatient : public Patient
{
    int noOfVisitor;
    double perVisitorCharge;

public:
    OutPatient(string name, string id, int noOfVisitor, double perVisitorCharge) : Patient(name, id), noOfVisitor(noOfVisitor), perVisitorCharge(perVisitorCharge) {}

    double calculateCost()
    {
        return noOfVisitor * perVisitorCharge;
    }

    void displayTreatement()
    {
        cout << "Patient Name: " << name << endl;
        cout << "Patient ID: " << id << endl;
        cout << "The Number of Visitor: " << noOfVisitor << endl;
        cout << "The charge on per Visitor: " << perVisitorCharge << endl;
    }
};

int main()
{
    Patient *patients[2];
    patients[0] = new InPatient("Hafeez", "jk1011", 6, 2250.0);
    patients[1] = new OutPatient("Aizaz", "Seq1212", 4, 670.0);

    for (int i = 0; i < 2; i++)
    {
        patients[i]->displayTreatement();
        cout << "Total Cost: " << patients[i]->calculateCost() << endl;
        cout << "<<------------------------------------------>>" << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete patients[i];
    }
}
