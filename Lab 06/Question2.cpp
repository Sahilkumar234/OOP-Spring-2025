#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string brand;
    int speed;

public:
    Vehicle(string brand, int speed) : brand(brand), speed(speed) {}

    void display()
    {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle
{
protected:
    int seats;

public:
    Car(string brand, int speed, int seats) : Vehicle(brand, speed), seats(seats) {}

    void displayCar()
    {
        display();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car
{
protected:
    int batteryLife;

public:
    ElectricCar(string brand, int speed, int seats, int batteryLife) : Car(brand, speed, seats), batteryLife(batteryLife) {}

    void displayECar()
    {
        displayCar();
        cout << "BatteryLife: " << batteryLife << " Hours" << endl;
    }
};

int main()
{
    ElectricCar E1("Toyota Prius", 240, 5, 7);
    E1.displayECar();
}
