#include<iostream>
using namespace std;

int main() {
    float AQI[4][28];
    float TotalAQI[4] = {0}; 
    float weeklyAvg[4][4] = {0}; 

    for(int i=0; i<4; i++) {
        cout << endl;
        cout << "Enter the AQI values for city " << i+1 << ":" << endl;
        for(int j=0; j<28; j++) {
            cout << "AQI value on day " << j+1 << ": ";
            cin >> AQI[i][j];
            TotalAQI[i] += AQI[i][j];
            weeklyAvg[i][j/7] += AQI[i][j];
        }
    }

    cout << endl;
    for(int i=0; i<4; i++) {
        cout << "The Monthly average AQI of city " << i+1 << " is: " << TotalAQI[i]/28 << endl;
    }

    cout<<endl;
    cout << "Weekly Average AQI for each city: " << endl;
    for(int i=0; i<4; i++) {
        cout << "Weekly Averages for City " << i+1 << ": " << endl;
        for(int j=0; j<4; j++) {
            weeklyAvg[i][j] /= 7;
            cout << "Week " << j+1 << ": " << weeklyAvg[i][j] << " ";
            cout<<endl;
        }
    }
    int AirImprovedCity = -1; 
    float HighestAirQuality = 0; 

    for (int i = 0; i < 4; i++) { 
    float improved = weeklyAvg[i][0] - weeklyAvg[i][3]; 

    if (improved > HighestAirQuality) { 
        HighestAirQuality = improved; 
        AirImprovedCity = i; 
      } 
    } 
    if (AirImprovedCity != -1) { 
    cout << endl << "City" << AirImprovedCity + 1 << " showed the most improvement with a drop of "<< HighestAirQuality << " in AQI over the month." << endl;   
    } 
    else { 
    cout << endl << "No significant improvement detected." << endl; 
    } 

    return 0;
    }

    
