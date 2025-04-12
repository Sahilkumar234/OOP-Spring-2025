#include <iostream>
using namespace std;

class AlarmSystem
{
    string securityLevel;

public:
    AlarmSystem(const string &s) : securityLevel(s)
    {
        cout << "Alarm system with security " << securityLevel << " is created" << endl;
    }

    ~AlarmSystem()
    {
        cout << "Alarm sydtem with security " << securityLevel << " is destroyed" << endl;
    }

    void displayAlarm() const
    {
        cout << "Alarm system with security " << securityLevel << " is created" << endl;
    }
};

class SmartHome
{
    int homeNO;
    string homeName;
    AlarmSystem A1;

public:
    SmartHome(const string &homeName, int homeNO, const string &securityLevel)
        : homeName(homeName), homeNO(homeNO), A1(securityLevel)
    {
        cout << "The Home " << homeName << " (" << homeNO << ") is created" << endl;
    }

    ~SmartHome()
    {
        cout << "The Home " << homeName << " (" << homeNO << ") is destroyed" << endl;
    }

    void displayHome() const
    {
        cout << "Home Name: " << homeName << endl;
        cout << "Home NO: " << homeNO << endl;
        A1.displayAlarm();
        cout << "--------------------------" << endl;
    }
};

int main()
{
    SmartHome S1("XYZ", 443, "High");
    S1.displayHome();
    SmartHome S2("ABC", 232, "Medium");
    S2.displayHome();
}
