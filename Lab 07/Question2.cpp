#include <iostream>
using namespace std;


class Product {
    protected:
    int productID;
    string productName;
    int price;
    int stockQuantity;

    public:
    Product() {}
    Product(int productID,string productName,int price,int stockQuantity) : productID(productID),productName(productName),price(price),stockQuantity(stockQuantity) {}

    int operator+(Product &Obj) {
        return this->price + Obj.price;
    }

    friend ostream& operator<<(ostream& O,Product& P);

    virtual void applyDiscount(double discount) {
        double newPrice;
        newPrice = price - price*discount;
        cout<<"Price after discount is: "<<newPrice<<endl;
    }

    virtual void calculateTotalPrice(int quantity) {
        int totalPrice = quantity*price;
        cout<<"Total price is: "<<totalPrice<<endl;
    }

    virtual void displayInfo() {
        cout<<"Product Name: "<<productName<<endl;
        cout<<"Product ID: "<<productID<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"stock Quantity: "<<stockQuantity<<endl;
    }
};

ostream& operator<<(ostream &O,Product &P) {
    P.displayInfo();
    return O;
}

class Electronics : public Product {
    int warrantyPeriod;
    string brand;

    public:
    Electronics(int productID,string productName,int price,int stockQuantity,int warrantyPeriod,string brand) :
    Product(productID,productName,price,stockQuantity),warrantyPeriod(warrantyPeriod),brand(brand) {}
    
    void displayInfo() {
        Product::displayInfo();
        cout<<"Warranty Period: "<<warrantyPeriod<<" hours"<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"<---------------------------------------->"<<endl;
    }
};

class Clothing : public Product {
    double size;
    string color;
    string fabricMaterial;

    public:
    Clothing(int productID,string productName,int price,int stockQuantity,double size,string color,string fabricMaterial) :
    Product(productID,productName,price,stockQuantity),size(size),color(color),fabricMaterial(fabricMaterial) {}

    void displayInfo() {
        Product::displayInfo();
        cout<<"Fabric Material: "<<fabricMaterial<<" hours"<<endl;
        cout<<"Size: "<<size<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"<---------------------------------------->"<<endl;
    }
    
    void applyDiscount(double discount) {
        double newPrice;
        newPrice = price - price*discount;
        cout<<"Price after discount is: "<<newPrice<<endl;
        cout<<"<---------------------------------------->"<<endl;
    }
};

class FoodItem : public Product {
    string expirationalDate;
    int calories;

    public: 
    FoodItem(int productID,string productName,int price,int stockQuantity,string expirationalDate,int calories) :
    Product(productID,productName,price,stockQuantity),expirationalDate(expirationalDate),calories(calories) {}

    void displayInfo() {
        Product::displayInfo();
        cout<<"Expirational Date: "<<expirationalDate<<" hours"<<endl;
        cout<<"Calories: "<<calories<<endl;
        cout<<"<---------------------------------------->"<<endl;
    }

    void calculateTotalPrice(int quantity) {
        double price_after_discount = price*quantity*0.10;
        cout<<"Total Price after discount is: "<<price_after_discount<<endl;
        cout<<"<---------------------------------------->"<<endl;
    }
};

class Book : public Product {
    string genre;
    string author;
    public:
    Book(int productID,string productName,int price,int stockQuantity,string genre,string author) :
    Product(productID,productName,price,stockQuantity),genre(genre),author(author) {}

    void displayInfo() {
        Product::displayInfo();
        cout<<"Genre: "<<genre<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"<---------------------------------------->"<<endl;
    }
};

int main() {
    Electronics E(1212,"Computer",18000,40,32,"hp");
    Product* P1 = &E;
    Clothing C1(1212,"Gul Ahmed Suit",8000,83,5.7,"Red","Imported");
    Product* P2 = &C1;
    FoodItem F1(2244,"Burger",580,50,"07-04-2025",24);
    Product* P3 = &F1;
    Book B1(4455,"Atomic habits",450,200,"Self-Help Book","James Clear");
    Product* P4 = &B1;

    cout<<*P1<<endl;
    cout<<*P2<<endl;
    cout<<*P3<<endl;
    cout<<*P4<<endl;

    P2->applyDiscount(0.7);
    P3->calculateTotalPrice(50);

    int bulkPrice = E + C1;
    cout << "Bulk purchase price: " << bulkPrice << endl;

}

