#include <iostream>
using namespace std;

class Device
{
protected:
    int deviceID;
    bool status;

public:
    Device(int deviceID, bool status) : deviceID(deviceID), status(status) {}

    void display()
    {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << status << endl;
    }
};

class SmartPhone : public Device
{
protected:
    float screenSize;

public:
    SmartPhone(int deviceID, bool status, float screenSize) : Device(deviceID, status), screenSize(screenSize) {}

    void displaySmartPhone()
    {
        display();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : public SmartPhone
{
protected:
    bool heartMonitor;

public:
    SmartWatch(int deviceID, bool status, float screenSize, bool heartMonitor) : SmartPhone(deviceID, status, screenSize), heartMonitor(heartMonitor) {}

    void displaySmartWatch()
    {
        displaySmartPhone();
        cout << "HeartMonitor: " << heartMonitor << endl;
    }
};

class SmartWearable : public SmartWatch
{
protected:
    int stepCounter;

public:
    SmartWearable(int deviceID, bool status, float screenSize, bool heartMonitor, int stepCounter) : SmartWatch(deviceID, status, screenSize, heartMonitor), stepCounter(stepCounter) {}

    void displaySmartWearable()
    {
        displaySmartWatch();
        cout << "Steps: " << stepCounter << endl;
    }
};

int main()
{
    SmartWearable S1(2323, true, 7.5, false, 45);
    S1.displaySmartWearable();

    return 0;
}
