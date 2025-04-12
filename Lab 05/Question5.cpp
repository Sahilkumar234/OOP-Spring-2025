#include <iostream>
using namespace std;

class Doctor
{
    string name;
    string specialization;
    int experience;

public:
    Doctor(string name, string specialization, int experience) : name(name), specialization(specialization), experience(experience)
    {
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Experience: " << experience << " years." << endl;
        cout << "------------------------------" << endl;
    }

    string getName()
    {
        return name;
    }
};

class Hospital
{
    string hospitalName;
    int docNO;
    int docCount;
    Doctor **doctors;

public:
    Hospital(string hospitalName, int docNO) : hospitalName(hospitalName), docNO(docNO), docCount(0)
    {
        doctors = new Doctor *[docNO];
    }

    ~Hospital()
    {
        for (int i = 0; i < docCount; i++)
        {
            delete doctors[i];
        }
        delete[] doctors;
    }

    void addDoctor(Doctor *doc)
    {
        if (docCount < docNO)
        {
            doctors[docCount++] = doc;
            cout << "Doctor: " << doc->getName() << " Joined " << hospitalName << endl;
        }
        else
        {
            cout << "There is no capacit for extra doctors.." << endl;
        }
        cout << "<---------------------------------------->" << endl;
    }

    void displayHospital()
    {
        cout << "Hospital Name: " << hospitalName << endl;
        cout << "Doctors: " << docCount << endl;
        for (int i = 0; i < docCount; i++)
        {
            doctors[i]->display();
        }
    }
};

int main()
{
    Doctor D1("Dr.Javed Altaf", "Cardiologist", 3);
    Doctor D2("Dr.Mujahid Siddiqui", "Orthopedic", 5);
    Doctor D3("Dr.Sadaf", "physiologist", 7);

    Hospital H1("Bone care", 4);
    H1.addDoctor(&D1);
    H1.addDoctor(&D2);
    H1.addDoctor(&D3);

    H1.displayHospital();
}
