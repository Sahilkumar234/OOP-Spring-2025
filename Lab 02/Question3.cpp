#include<iostream>
#include<string>
using namespace std;

struct employees {
    string name;
    int hoursWorked;
    float hourlyRate;
};

int main() {

    int empNum;
    cout<<"Enter number of emplyees: ";
    cin>>empNum;
    employees* emp = new employees[empNum];
    float* salary = new float[empNum];

    for(int i=0;i<empNum;i++) {
        cout<<"Enter Employee "<<i+1<<" details..."<<endl;
        cout<<"Name: ";
        cin.ignore();
        getline(cin,emp[i].name);
        cout<<"Working Hours: ";
        cin>>emp[i].hoursWorked;
        cout<<"Hourly Rate: ";
        cin>>emp[i].hourlyRate;
        cout<<endl;
    }
    
    for(int i=0;i<empNum;i++) {
        salary[i] = emp[i].hoursWorked * emp[i].hourlyRate;
    }

    for(int i=0;i<empNum;i++) {
        cout<<"Salary of Employee "<<i+1<<": ";
        cout<<salary[i];
        cout<<endl;
    }

    delete[] emp;
    delete[] salary;
}
