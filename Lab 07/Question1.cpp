#include <iostream>
using namespace std;

class Device
{
protected:
    int deviceID;
    string deviceName;
    bool status;
    string optionalLocation;

public:
    Device() {}

    Device(int deviceID, string deviceName,string optionalLocation) : deviceID(deviceID), deviceName(deviceName), status(false), optionalLocation(optionalLocation) {}
    virtual void turnOn()
    {
        status = true;
        cout << deviceName << " is turn on" << endl;
        cout<<"<----------------------------------------->"<<endl;
    }
    virtual void turnOf()
    {
        status = false;
        cout << deviceName << " is Turn off" << endl;
        cout<<"<----------------------------------------->"<<endl;
    }
    virtual string getStatus()
    {
        if (status)
        {
            return "On";
            cout<<"<----------------------------------------->"<<endl;
        }
        else
        {
            return "Off";
            cout<<"<----------------------------------------->"<<endl;
        }
    }
    virtual void display()
    {
        cout << "Device ID: " << deviceID << endl;
        cout << "Device Name: " << deviceName << endl;
        cout << "Status: " << getStatus() << endl;
        cout << "Optional Location: " << optionalLocation << endl;
        cout<<"<----------------------------------------->"<<endl;
    }
};

class Light : public Device
{
    string colorMode;
    int brightnessLevel;

public:
    Light(int deviceID, string deviceName,string optionalLocation, int brightnessLevel, string colorMode) : Device(deviceID, deviceName,optionalLocation), brightnessLevel(brightnessLevel), colorMode(colorMode) {}

    void display() override
    {
        Device::display();
        cout << "Brightness Level: " << brightnessLevel << endl;
        cout << "Color Mode: " << colorMode << endl;
        cout<<"<----------------------------------------->"<<endl;
    }
};

class Temperature : public Device
{
    double temperature;
    string mode;
    double targetTemperature;

public:
    Temperature(int deviceID, string deviceName,string optionalLocation, double temperature, string mode, double targetTemperature) : Device(deviceID, deviceName, optionalLocation), temperature(temperature), mode(mode), targetTemperature(targetTemperature) {}

    string getStatus() override
    {
        cout<<"Temperature is: "<<temperature<<endl;
        cout<<"Targeted temperature is: "<<targetTemperature<<endl;
        cout<<"Mode: "<<mode<<endl;
        cout<<"<----------------------------------------->"<<endl;
        return "";
    }
};

class SecurityCamera : public Device
{
    bool recordingStatus;
    int resolution;
    bool nightVisionEnabled;

public:
    SecurityCamera(int deviceID, string deviceName, string optionalLocation, int resolution,bool nightVisionEnabled) : Device(deviceID, deviceName,optionalLocation), resolution(resolution), recordingStatus(false), nightVisionEnabled(nightVisionEnabled) {}

    void turnOn() override
    {
        status = true;
        recordingStatus = true;
        cout << deviceName<<" has been turned on Recording started" << endl;
        cout<<"<----------------------------------------->"<<endl;
    }

    void display() override {
        Device:: display();
        cout<<"Resolution: "<<resolution<<endl;
        if(recordingStatus) {
            cout<<"Ready for recording"<<endl;
            cout<<"<----------------------------------------->"<<endl;
        }
        else {
            cout<<"Not ready for recording"<<endl;
            cout<<"<----------------------------------------->"<<endl;
        }
        if(nightVisionEnabled) {
            cout<<"Night vision enable"<<endl;
            cout<<"<----------------------------------------->"<<endl;
        }
        else {
            cout<<"Night vision diabled"<<endl;
            cout<<"<----------------------------------------->"<<endl;
        }
    }
};

class SmartPlug : public Device
{
    double powerConsumption;
    int timerSetting;

public:
    SmartPlug(int deviceID, string deviceName,string optionalLocation, double powerConsumption, int timerSetting) : Device(deviceID, deviceName,optionalLocation), powerConsumption(powerConsumption), timerSetting(timerSetting) {}

    void turnOf() override
    {
        status = false;
        cout <<deviceName<<"Loged Off and power consumption is: "<<powerConsumption << endl;
        cout<<"<----------------------------------------->"<<endl;
    }
};

int main()
{
    Light L1(1122, "LED torch","XYZ", 55, "Dark");
    Device *D1 = &L1;
    D1->display();

    Temperature T1(1122, "LED torch","XYZ", 37.5, "Colling", 40.0);
    Device *D2 = &T1;
    D2->getStatus();

    SecurityCamera S1(1122, "LED torch","XYZ",720,true);
    Device* D3 = &S1;
    D3->turnOn();

    SmartPlug SS(1122, "LED torch","XYZ", 454.66, 52);
    Device* D4 = &SS;
    D4->turnOf();
}
