#include<iostream>
using namespace std;

class Car {
    string brand;
    string model;
    long int price;
    bool availablity;

    public:
        Car(string brand,string model,long int price,bool availablity) {
            this->brand = brand;
            this->model = model;
            this->price = price;
            this->availablity = true;
        }
        void Discount(int days) {
            if(days > 5 && days < 10) {
                double discount = price*0.05;
                price -= discount;
                cout<<"Discount is "<<discount<<" and Car price is: "<<price<<endl;
            }
            else if(days > 10) {
                double discount = price * 0.1;
                price -= discount;
                cout<<"Discount is "<<discount<<" and Car price is: "<<price<<endl;
            }
            else {
                cout<<"No discount available..."<<endl;
            }
        }
        void checkAvailablity() {
            if(availablity) {
                availablity = true;
                cout<<"Car is available for rent..."<<endl;
            }
            else {
                cout<<"Car is not available for rent..."<<endl;
            }
        }

        void displayDetails() {
            cout<<"Car model: "<<model<<endl;
            cout<<"Car brand: "<<brand<<endl;
            cout<<"Car price: "<<price<<endl;
            cout<<"Car availablity: "<<availablity<<endl;
        }

};
int main() {

    int days;
    
    Car C1("Toyota","Corolla",4400000,true);
    C1.displayDetails();

    cout<<endl;
    C1.checkAvailablity();
    cout<<endl;
    
    cout<<"Enter days: ";
    cin>>days;
    C1.Discount(days);

}
