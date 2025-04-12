#include <iostream>
#include <string>
using namespace std;

void swapNames(string &x,string &y) {
    string temp = x;
    x = y;
    y = temp;
}

void sortNames(string* name,int limit) {
    for(int i=0;i<limit-1;i++) {
        for(int j=0;j<limit-i-1;j++) {
            if(name[j]>name[j+1]) {
                swapNames(name[j],name[j+1]);
            }
        }
    }
}

int main() {
    int limit;
    cout << "Enter the limit of strings: ";
    cin >> limit;
    cout << endl;

    string* name = new string[limit];
     cin.ignore(); 

    for (int i = 0; i < limit; i++) {
        cout << "Enter name " << i + 1 << ": ";
        getline(cin, name[i]);
    }

    cout << "\nEntered names:\n";
    for (int i = 0; i < limit; i++) {
        cout << "Name " << i + 1 << ": " << name[i] << endl;
    }
    cout<<endl;
    sortNames(name,limit);
    cout<<"Sorted array is...."<<endl;

    for(int i=0;i<limit;i++) {
        cout<<"Name "<<i+1<<": "<<name[i]<<endl;
    }



    delete[] name;
    return 0;
}
