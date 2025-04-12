#include<iostream>
#include<string>
using namespace std;

class Wallet {
    private:
        string ownerName;
        float totalBalance;
        string transactionHistory[50];
        int transCount;

    public:
    void setValue(string ownerName,float totalBalance) {
        this->ownerName = ownerName;
        this->totalBalance = totalBalance;
        transactionHistory[0] = "Initial amount: " + to_string(totalBalance);
        transCount = 1;
    }

    void addMoney (float money) {
        if(money > 0) {
            totalBalance += money;
            transactionHistory[transCount++] = "Added: " + to_string(money);
            cout<<money<<": Successfully added in your wallet.."<<endl;
        } else {
            cout<<"Invalid Amount to add"<<endl;
        }
    }
    void spendMoney (float money) {
        if(money > 0 && money <= totalBalance) {
            totalBalance -= money;
            transactionHistory[transCount++] = "Spended: " + to_string(money);
            cout<<money<<": Successfully spended from your wallet.."<<endl;
            if(totalBalance < 100) {
                cout<<"your Balance is Low!! your current balance is: "<<totalBalance<<endl;
            } 
        }
        else {
            cout<<"Insufficient balance..."<<endl;
        }
    }
    
    void displayHistory() {
        cout<<endl;
        cout<<"Transaction history of "<<ownerName<<": "<<endl;
        cout<<endl;
        for(int i=0;i<transCount;i++) {
            cout<<transactionHistory[i]<<endl;
        }
        cout<<"Your current balace is: "<<totalBalance<<endl;
    }

};
  
int main() {
    Wallet W1;
    W1.setValue("Sahil",430.00);
    W1.addMoney(170.00);
    W1.spendMoney(200);
    W1.spendMoney(130);
    W1.displayHistory();

    return 0;
}
