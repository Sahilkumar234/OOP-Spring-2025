#include<iostream>
using namespace std;
class Car{
string brand;
string model;
double price;
bool availabilty;
double *reveune;
int registrationNO;

public:
Car(){
brand = "unknown";
model = "genric";
price = 0.0;
availabilty = true;
registrationNO = 0;
reveune = new double(0.0);
}

Car(string brand,string model,double price,bool availabilty,int registrationNO ){
this->brand = brand;
this->model = model;
this->price = price;
this->availabilty = availabilty;
this->registrationNO = registrationNO;	
reveune = new double(0.0);
}


void setrentalprice(double price){
this->price = price;	
}

void setavailabilty(bool availabilty){
this->availabilty = availabilty;	
}

double getrentalprice(){
return price;	
}

bool getavailabilty(){
return availabilty;	
}


void display(){
cout<<"Car Brand: "<<brand<<endl;
cout<<"Car Model: "	<<model<<endl;
cout<<"Rental price: "<<price<<endl;
cout<<"Availabilty: "<<availabilty<<endl;
cout<<"Revune: "<<*reveune<<endl;
cout<<"Regirstration Number: "<<registrationNO<<endl;

}

void setreveune(int days){
*reveune=price*days;
	
}

 double getreveune(){
return *reveune;	
}


void applydiscount(int days){

if(days>5 && days<10){
    price=price-((price*0.02));	
}
else if(days>10){
    price=price-((price*0.1));	
}
}


~Car(){
cout<<"Destructor is Called! "<<endl;
delete reveune;	
}

};
int main(){
Car c1("Fortuner","SUV",59200.25,true,9912);
Car c2("Honda","Civic",34500.24,true,9917);
cout<<"Car 1: "<<endl;
if(c1.getavailabilty()==true){

int days;
cout<<"Enter the days for renting the car: "<<endl;
cin>>days;
c1.applydiscount(days);
c1.setreveune(days);
c1.setavailabilty(false);
}
else{
	cout<<"Car is not available: "<<endl;
}

cout<<"Car 2: "<<endl;
if(c2.getavailabilty()==true){

int days;
cout<<"Enter the days for renting the car: "<<endl;
cin>>days;
c2.applydiscount(days);
c2.setreveune(days);
c2.setavailabilty(false);
}
else{
	cout<<"Car is not available: "<<endl;
}
cout<<"Car 1 Details: "<<endl;
c1.display();
cout<<endl;
cout<<"Car 2 Details: "<<endl;
c2.display();




	
	
return 0;	
}
