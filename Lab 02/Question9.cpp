#include<iostream>
#include<string>
using namespace std;

struct Product {
    string name;
    string productID;
    int quantity;
    float price;
};

int main() {
    int num;
    cout<<"Enter the number of products: ";
    cin>>num;

    Product* prod = new Product[num];

    cout<<endl;
    for(int i=0;i<num;i++) {
        cout<<"Enter the details of product "<<i+1<<endl;
        cout<<"Enter Product ID: ";
        cin>>prod[i].productID;
        cout<<"Enter Product name: ";
        cin.ignore();
        getline(cin,prod[i].name);
        cout<<"Enter Produact Quantity: ";
        cin>>prod[i].quantity;
        cout<<"Enter the product price: ";
        cin>>prod[i].price;
        cout<<endl;
    }

    float total = 0;
    for(int i=0;i<num;i++) {
        total += prod[i].quantity * prod[i].price;
    }
    cout<<endl;
    cout<<"Inventory Details..."<<endl;
        cout<<"Total inventory: "<<total<<endl;
    delete[] prod;
}

