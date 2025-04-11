#include <iostream>
using namespace std;

class Ticket
{
protected:
    int ticketID;
    string passengerName;
    int price;
    bool isreserved;
    string date;
    string destination;

public:
    Ticket(int ticketID, string passengerName, int price, string date, string destination) : ticketID(ticketID), passengerName(passengerName), price(price), date(date), destination(destination), isreserved(false) {}

    void displayInfo()
    {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Price: " << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
        cout << "Ticket availablity " <<isreserved<< endl;
    }

    void reserve()
    {
        if (isreserved)
        {
            isreserved = true;
            cout << "Ticket ID: " << ticketID << " Reserved successfully" << endl;
        }
        else
        {
            cout << "Ticket ID: " << ticketID << " Reserved successfully" << endl;
        }
    }

    void cancel()
    {
        if (isreserved)
        {
            isreserved = true;
            cout << "Ticket " << ticketID << " cancelled not succefull" << endl;
        }
        else
        {
            cout << "Ticket " << ticketID << " Cancelled successfully" << endl;
        }
    }
};

class FlightTicket : public Ticket
{
    string airLineName;
    int flightNumber;
    string flightClass;

public:
    FlightTicket(int ticketID, string passengerName, int price, string date, string destination, string airLineName, int flightNumber, string flightClass) : Ticket(ticketID, passengerName, price, date, destination), airLineName(airLineName), flightNumber(flightNumber), flightClass(flightClass) {}

    void displayInfo()
    {
        Ticket::displayInfo();
        cout << "Air Line Name: " << airLineName << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "FlightClass: " << flightClass << endl;
    }
};

class TrainTicket : public Ticket
{
    string coachType;
    int trainNumber;
    int departureTime;
    static int seatNUmber;

public:
    TrainTicket(int ticketID, string passengerName, int price, string date, string destination, string coachType, int trainNumber, int departureTime) : Ticket(ticketID, passengerName, price, date, destination), coachType(coachType), trainNumber(trainNumber), departureTime(departureTime) {}

    void displayInfo()
    {
        Ticket::displayInfo();
        cout << "coach Type: " << coachType << endl;
        cout << "train Number: " << trainNumber << endl;
        cout << "departureTime: " << departureTime << endl;
    }

    void reserve()
    {
        seatNUmber++;
        cout << "New seat " << seatNUmber << " Assigned successfully" << endl;
    }
};
static int ::seatNUmber = 1122;

class BusTicket : public Ticket
{
    string busCompany;
    int seatNO;

public:
    BusTicket(int ticketID,string passengerName, int price, string date, string destination, string busCompany, int seatNO) : Ticket(ticketID, passengerName, price, date, destination), busCompany(busCompany), seatNO(seatNO) {}

    void displayInfo()
    {
        Ticket::displayInfo();
        cout << "Passenger Name: " << passengerName << endl;
        cout << "seat Number: " << seatNO << endl;
    }

    void cancel()
    {
        if (isreserved)
        {
            isreserved = false;
            cout << "Bus Ticket Cancelled..." << endl;
        }
        else
        {
            cout << "Bus Ticket Not Cancelled" << endl;
        }
    }
};

class ConcertTicket : public Ticket
{
    string artistName;
    string venue;
    string seattype;

public:
    ConcertTicket(int ticketID, string passengerName, int price, string date, string destination, string artistName, string venue, string seattype) : Ticket(ticketID, passengerName, price, date, destination), artistName(artistName), venue(venue), seattype(seattype) {}

    void displayInfo()
    {
        Ticket::displayInfo();
        cout << "Artist Name: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat type: " << seattype << endl;
    }
};

int main()
{
    FlightTicket F1(112, "AL--", 500, "23-4-2022", "IslamAbad", "PIA", 433, "Economic");
    Ticket *T = &F1;
    T->displayInfo();

    TrainTicket TT2(112, "AL--", 500, "23-4-2022", "IslamAbad", "Faisal Mover", 404, 12);
    Ticket *T2 = &TT2;
    T2->reserve();

    BusTicket BB(4444,"Sahil", 500, "24-05-2024", "Muree", "Faisal Mover", 32);
    Ticket *T3 = &BB;
    T3->cancel();

    ConcertTicket CC(2323, "Sahil", 4200, "17-04-2025", "Toronto", "Atif Aslam", "Coca Cola Arena", "VIP");
    Ticket *T4 = &CC;
    T4->displayInfo(); 
}
