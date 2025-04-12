#include<iostream>
using namespace std;

int main() {
    int AQI[4][7];

    for(int i=0;i<4;i++) {
        cout<<endl;
        for(int j=0;j<7;j++) {
            cout<<"AQI value of city "<<i+1<<" on day "<<j+1<<": ";
            cin>>AQI[i][j];
        }
    }
    int star;
    for(int i=0;i<4;i++) {
        cout<<"City "<<i+1<<": "<<endl;
        for(int j=0;j<7;j++) {
            star = AQI[i][j]/50;
            cout<<"day "<<j+1<<": ";
            for(int k=star;k>0;k--) {
                cout<<"* ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}
