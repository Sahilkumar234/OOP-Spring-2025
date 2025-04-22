#include <iostream>
using namespace std;

class WeatherSensor
{
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor
{
    double temperature;

public:
    void readData()
    {
        temperature = 38.5;
    }
    void displayReport()
    {
        cout << "Thermometer temperature is: " << temperature << " oC" << endl;
    }
};

class Barometer : public WeatherSensor
{
    double barometricPressure;

public:
    void readData()
    {
        barometricPressure = 996.55;
    }
    void displayReport()
    {
        cout << "The pressure of Barometer is: " << barometricPressure << " Pa" << endl;
    }
};

int main()
{
    WeatherSensor *weatherSensors[2];
    Thermometer thermometer;
    Barometer barometer;

    weatherSensors[0] = new Thermometer;
    weatherSensors[1] = new Barometer;

    for (int i = 0; i < 2; i++)
    {
        weatherSensors[i]->readData();
        weatherSensors[i]->displayReport();
        cout << "----------------------------------" << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete weatherSensors[i];
    }
}
