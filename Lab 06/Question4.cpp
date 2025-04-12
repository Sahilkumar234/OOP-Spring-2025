#include <iostream>
using namespace std;

class Accounts
{
protected:
    int accNO;
    float balance;

public:
    Accounts(int accNO, float balance) : accNO(accNO), balance(balance) {}

    void display()
    {
        cout << "Account NO: " << accNO << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingAccount : public Accounts
{
protected:
    float interestRate;

public:
    SavingAccount(int accNO, float balance, float interestRate) : Accounts(accNO, balance), interestRate(interestRate) {}

    void displaySavingAccount()
    {
        display();
        cout << "Interest Rate: " << interestRate << endl;
        cout << "<--------------------------->" << endl;
    }
};

class CheckingAccount : public Accounts
{
protected:
    float overDraftLimit;

public:
    CheckingAccount(int accNO, float balance, float overDraftLimit) : Accounts(accNO, balance), overDraftLimit(overDraftLimit) {}

    void displayCheckingAccount()
    {
        display();
        cout << "overDraftLimit: " << overDraftLimit << endl;
    }
};

int main()
{
    SavingAccount S1(1234, 2500.4, 2.7);
    S1.displaySavingAccount();

    CheckingAccount S2(4432, 3450.4, 3.8);
    S2.displayCheckingAccount();
}
