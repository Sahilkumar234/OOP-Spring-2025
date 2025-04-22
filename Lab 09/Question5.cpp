#include <iostream>
using namespace std;

class Shipment
{
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string trackingNumber, double weight) : trackingNumber(trackingNumber), weight(weight) {}

    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
    virtual ~Shipment() {};
};

class AirFreight : public Shipment
{
    int time;

public:
    AirFreight(string trackingNumber, double weight) : Shipment(trackingNumber, weight) {}

    void estimateDeliveryTime()
    {
        time = 13;
    }
    void showDetails()
    {
        cout << "Tracking number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Estimated time by AirFreight: " << time << " hours" << endl;
    }
};

class GroundShipment : public Shipment
{
    int time;

public:
    GroundShipment(string trackingNumber, double weight) : Shipment(trackingNumber, weight) {}

    void estimateDeliveryTime()
    {
        time = 29;
    }
    void showDetails()
    {
        cout << "Tracking number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Estimated time by Ground Shipment: " << time << " hours" << endl;
    }
};

int main()
{
    Shipment *shipments[2];
    AirFreight A1("107L3JJ", 567.66);
    GroundShipment G1("12UY83K", 977.45);
    shipments[0] = &A1;
    shipments[1] = &G1;

    for (int i = 0; i < 2; i++)
    {
        shipments[i]->estimateDeliveryTime();
        shipments[i]->showDetails();
        cout << "<-------------------------------------->" << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete shipments[i];
    }
}
