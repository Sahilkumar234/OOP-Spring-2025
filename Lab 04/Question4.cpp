#include<iostream>
using namespace std;
class Car{
string brand;
string model;
double price;
bool availabilty;
double *reveune;

public:
Car(){
brand = "unknown";
model = "genric";
price = 0.0;
availabilty = true;
reveune = new double();
}

Car(string brand,string model,double price,bool availabilty){
this->brand = brand;
this->model = model;
this->price = price;
this->availabilty = availabilty;	
}


void setrentalprice(double price){
this->price=price;	
}

void setavailabilty(bool availabilty){
this->availabilty=availabilty;	
}

double getrentalprice(){
return price;	
}

bool getavailabilty(){
return availabilty;	
}

Car(const Car &C1){
reveune = new double();	
brand = C1.brand;
model = C1.model;
price = C1.price;
availabilty = C1.availabilty;

}

void display(){
cout<<"Car Brand: "<<brand<<endl;
cout<<"Car Model: "	<<model<<endl;
cout<<"Rental price: "<<price<<endl;
cout<<"Availabilty: "<<availabilty<<endl;
}

void setReveune(int days){
*reveune=price*days;	
}

 double getReveune(){
return *reveune;	
}


~Car(){
cout<<"Destructor is Called! "<<endl;	
}

};
int main(){
Car c1("Fortuner","SUV",59200.25,true);

if(c1.getavailabilty()==true){

int days;
cout<<"Enter the days for renting the car: "<<endl;
cin>>days;
c1.setReveune(days);

cout<<"Revune of renting a car: "<<c1.getReveune()<<endl;
c1.setavailabilty(false);
}
else{
	cout<<"Car is not available: "<<endl;
}



	
	
return 0;	
}
