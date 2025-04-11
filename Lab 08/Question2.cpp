#include<iostream>
using namespace std;

class Account {
    string accNO;
    double accBalance;
public:
    Account(string accNO,double accBalance) : accNO(accNO),accBalance(accBalance) {}

    friend void transferFunds(Account& aa,Account& bb,double money);
    friend class Manager;
};

void transferFunds(Account& aa,Account& bb,double money) {
    if(money>0 && money <= aa.accBalance) {
        aa.accBalance -= money;
        bb.accBalance += money;
        cout<<"Transfered money ("<<money<<") from account "<<aa.accNO<<" to "<<bb.accNO<<endl;
    }
    else {
        cout<<"Invalid data!!Please enter correct data"<<endl;
    }
}

class Manager {
public:
    void display(Account& A) {
        cout<<"Account number: "<<A.accNO<<endl;
        cout<<"Account Balance: "<<A.accBalance<<endl;
    }
    void withdraw(Account& A,double amount) {
        if(amount<0 && amount >= A.accBalance) {
            cout<<"Invalid Amount!!,Try again..."<<endl;
        }
        else {
            A.accBalance -= amount;
            cout<<"After withdrawl the balance is: "<<A.accBalance<<endl;
        }
    }
    void deposit(Account& A,double amount) {
        if(amount<0 && amount > A.accBalance) {
            cout<<"Invalid Amount!!,Try again..."<<endl;
        }
        else {
            A.accBalance += amount;
            cout<<"After withdrawl the balance is: "<<A.accBalance<<endl;
        }
    }
    
};

int main() {
    Account Acc1("104-7A",54050.55);
    Account Acc2("105-8B",65700.35);

    Manager M1;
    M1.display(Acc1);
    cout<<"<<----------------------------->>"<<endl;
    M1.display(Acc2);
    cout<<"<<----------------------------->>"<<endl;
    M1.withdraw(Acc1,34200.4);
    M1.deposit(Acc1,23400.4);
    M1.withdraw(Acc2,20300.50);
    cout<<"<<----------------------------->>"<<endl;
    transferFunds(Acc1,Acc2,500.40);
    cout<<"<<----------------------------->>"<<endl;
    cout<<"Details After withdraw/deposit/transferFunds..."<<endl;
    M1.display(Acc1);
    cout<<"<<----------------------------->>"<<endl;
    M1.display(Acc1);
    cout<<"<<----------------------------->>"<<endl;
    M1.display(Acc2);
}
