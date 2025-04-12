#include<iostream>
using namespace std;

class Car {
    string* brand;
    string* model;
    long int* price;

    public:
        Car(string brand,string model,long int price) {
            this->brand = new string(brand);
            this->model = new string (model);
            this->price = new long int(price);
        }

        Car(Car &obj) {
            brand = new string(*obj.brand);
            model = new string(*obj.model);
            price = new long int(*obj.price);
        }

        ~Car() {
            cout<<"Car "<<*brand<<" "<<*model<<" is removed..."<<endl;
        }
    
        void displayDetails() {
            cout<<"Car model: "<<*model<<endl;
            cout<<"Car brand: "<<*brand<<endl;
            cout<<"Car price: "<<*price<<endl;
        }

        void modifyDetails(string b,string m,long int p) {
            this->brand = new string(b);
            this->model = new string (m);
            this->price = new long int(p);

        }

};
int main() {

    int days;
    
    Car C1("Toyota","Corolla",4400000);
    Car C2(C1);

    C1.displayDetails();
    cout<<endl;
    C2.displayDetails();

    C1.modifyDetails("Honda","Civic",4980000);
    cout<<endl;
    cout<<"Modified Car details..."<<endl;
    C1.displayDetails();

    cout<<endl;
    cout<<"Copied Car Details..."<<endl;
    C2.displayDetails();
    cout<<endl;
}
