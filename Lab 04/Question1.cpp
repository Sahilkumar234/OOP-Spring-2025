#include<iostream>
#include<string>
using namespace std;

class Car {
    string brand;
    string model;
    long int price;
    bool availablity;

    public:
        Car() {
            brand = "Unknown";
            model = "Genre";
            price = 0.0;
            availablity = true;
        }

        void updateDetails(string brand,string model,long int price,bool availablity) {
                this->brand = brand;
                this->model = model;
                this->price = price;
                availablity = true;
        }

        bool checkAvailablity() const {
            return availablity;
        }

        void rentRequest()  {
            if(availablity) {
                availablity = true;
                cout<<"Car is  rented"<<endl;
            }
            else {
                cout<<"Car is available for rent"<<endl;
            }
        }

        void displayDetails() {
            cout<<"CAr model: "<<model<<endl;
            cout<<"CAr brand: "<<brand<<endl;
            cout<<"Car price: "<<price<<endl;
            cout<<"Car Availablity: "<<(availablity ? "available" : "Not available")<<endl;
        }
}; 

int main() {
    Car C2;
    cout<<"Initial Car Details..."<<endl;
    C2.displayDetails();
    cout<<endl;

    C2.updateDetails("Changan","Alsvin",2300000,true);
    cout<<"Updated Car Details..."<<endl;
    C2.displayDetails();
    cout<<endl;

    cout << "Giving to rent the car..." << endl;
    C2.rentRequest();
    cout << endl;

    cout<<"Check Availablity after renting the car..."<<endl;
    if(C2.checkAvailablity()) {
        cout<<"Car is available for rent"<<endl;
    }
    else {
        cout<<"Car is not available for rent.."<<endl;
    }

}
