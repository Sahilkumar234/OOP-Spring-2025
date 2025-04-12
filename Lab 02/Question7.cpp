#include<iostream>
using namespace std;

int main() {
    int r,r1;
    int c,c1;
    cout<<"Enter rows matrix1: ";
    cin>>r;
    cout<<"Enter columns matrix1: ";
    cin>>c;
    cout<<"Enter rows of matrix2: ";
    cin>>r1;
    cout<<"Enter columns of matrix2: ";
    cin>>c1;

    if(c!=r1) {
        cout<<"Matrix multiplication is not possible..."<<endl;
        return 1;
    }

    int** matrix1 = new int*[r];
    int** matrix2 = new int*[r1];
    int** result = new int*[r];

    for(int i=0;i<r;i++) {
        matrix1[i] = new int[c];
    }
    for(int i=0;i<r1;i++) {
        matrix2[i] = new int[c1];
    }
    for(int i=0;i<r;i++) {
        result[i] = new int[c1];
    }

    cout<<"Enter matrix1 elements..."<<endl;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout<<"Enter element ["<<i<<"]["<<j<<"]: ";
            cin>>matrix1[i][j];
        }
    }
    cout<<endl;
    cout<<"Enter matrix2 elements..."<<endl;
    for(int i=0;i<r1;i++) {
        for(int j=0;j<c1;j++) {
            cout<<"Enter element ["<<i<<"]["<<j<<"]: ";
            cin>>matrix2[i][j];
        }
    }
    cout<<endl;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            result[i][j] = 0;
                for(int k=0;k<c;k++) {
                    result[i][j] += matrix1[i][k]*matrix2[k][j];
                }
        }
    }
    cout<<"Matrix Multiplication is below..."<<endl;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c1;j++) {
            cout<<result[i][j]<<" | ";
        }
        cout<<endl;
    }

    for(int i = 0; i < r; i++) {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for(int i = 0; i < r1; i++) {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    for(int i = 0; i < r; i++) {
        delete[] result[i];
    }
    delete[] result;
return 0;
}
