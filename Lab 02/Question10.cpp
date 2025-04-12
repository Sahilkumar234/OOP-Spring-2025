#include<iostream>
using namespace std;
 
int main() {
    int x,y,z;
    cout<<"Enter value of x: ";
    cin>>x;
    cout<<"Enter value of y: ";
    cin>>y;
    cout<<"Enter value of z: ";
    cin>>z;

    int*** matrix = new int**[x];
    for(int i=0;i<x;++i) {
        matrix[i] = new int*[y];
        for(int j=0;j<y;j++) {
            matrix[i][j] = new int[z];
        }
    }

    cout<<endl;
    cout<<"Enter the elements of 3D array..."<<endl;
    cout<<endl;
    for(int i=0;i<x;i++) {
        for(int j=0;j<y;j++) {
            for(int k=0;k<z;k++) {
                cout<<"Enter element["<<i<<"]["<<j<<"]["<<k<<"]: ";
                cin>>matrix[i][j][k];
            }
        }
    }
    cout<<endl;
    cout<<"The elements of 3D array..."<<endl;
    cout<<endl;
    for(int i=0;i<x;i++) {
        for(int j=0;j<y;j++) {
            for(int k=0;k<z;k++) {
                cout<<matrix[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    for(int i=0;i<x;++i) {
        for(int j=0;j<y;++j) {
            delete[] matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
}
