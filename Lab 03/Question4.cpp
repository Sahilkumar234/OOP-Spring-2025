#include<iostream>
using namespace std;

class Car {
    string brand;
    double fuelCapacity;
    string model;
    double currentFuelLevel;

    public:
    void setValue(string brand,double fuelCapacity,string model,double currentFuelLevel) {
        this->brand = brand;
        this->fuelCapacity = fuelCapacity;
        this->model = model;
        this->currentFuelLevel = currentFuelLevel;
    }
    void driveCar(double distance,double fuelBurnRate) {
        double fuelUsage = (distance * fuelBurnRate) / 100;
        if(fuelUsage > currentFuelLevel) {
            cout<<"You fuel tank is empty..."<<endl;
        }
        else {
            currentFuelLevel -= fuelUsage;
            cout<<"Your fuel used "<<fuelUsage<<" litres."<<endl;
            cout<<"your current fuel is: "<<currentFuelLevel<<endl;
        }
    }

    void reFuel(double fuel) {
        cout<<endl;
        if(currentFuelLevel + fuel > fuelCapacity){
            currentFuelLevel = fuelCapacity;
            cout<<"Your fuel tank is full.. Current fuel is: "<<currentFuelLevel<<endl;
        }
        else {
            currentFuelLevel += fuel;
            cout<<"Your tank refuled with "<<fuel<<" litres, and current fuel is: "<<currentFuelLevel<<endl;
        }
        
    }
    void checkFuel() {
        if(currentFuelLevel < 10) {
            cout<<endl;
            cout<<"Warning!!! Your fuel tank is low..."<<endl;
            cout<<"your current fuel is: "<<currentFuelLevel<<endl;
        }
        else {
            cout<<"your current fuel is: "<<currentFuelLevel<<endl;
        }
    }
    void displayFuelDetails() {
        cout<<"Car brand is: "<<brand<<endl;
        cout<<"Car Fuel Capacity is: "<<fuelCapacity<<endl;
        cout<<"Car model is: "<<model<<endl;
        cout<<"Car current fuel is: "<<currentFuelLevel<<endl;
        cout<<endl;
    }

};

int main() {
    Car C1;
    C1.setValue("Lexus",120.0,"LX 570",70.0);
    C1.displayFuelDetails();
    C1.reFuel(30.0);
    C1.displayFuelDetails();
    C1.checkFuel();
    C1.driveCar(145.0,17.5);
    cout<<endl;
    C1.displayFuelDetails();

    return 0;
}
