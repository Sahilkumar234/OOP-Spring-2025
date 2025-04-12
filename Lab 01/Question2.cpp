#include<iostream>
using namespace std;

void IdtDays(int AQI[4][7]) {
    for(int i=0;i<4;i++) {
        cout<<endl;
        for(int j=0;j<7;j++) {
            if(AQI[i][j]>150)
                cout<<"On The day "<<j+1<<" AQI of city "<<i+1<<" is "<<AQI[i][j]<<" exceeds 150 by ( "<<AQI[i][j]-150<<" )"<<endl;
        }
    }
}

int main() {
    int AQI[4][7];

    for(int i=0;i<4;i++) {
        cout<<endl;
        for(int j=0;j<7;j++) {
            cout<<"Enter the AQI on day "<<j+1<<" of city "<<i+1<<": ";
            cin>>AQI[i][j];
        }
    }
    IdtDays(AQI);
}
   

