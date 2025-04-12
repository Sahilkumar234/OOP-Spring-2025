#include<iostream>
using namespace std;

int main() {
    int rows,cols;
    cout<<"Enter number of rows: ";
    cin>>rows;
    cout<<"Enter number of columns: ";
    cin>>cols;

    int** matrix1 = new int*[rows];
    int** matrix2 = new int*[rows];
    int** sum = new int*[rows];
    int** difference = new int*[rows];

    for(int i=0;i<rows;++i) {
        matrix1[i] = new int[cols];
    }
    for(int i=0;i<rows;++i) {
        matrix2[i] = new int[cols];
    }
    for(int i=0;i<rows;++i) {
        sum[i] = new int[cols];
    }
    for(int i=0;i<rows;++i) {
        difference[i] = new int[cols];
    }

    cout<<"Enter elements of Matrix 1...."<<endl;
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            cout<<"Enter element["<<i<<"]["<<j<<"]: ";
            cin>>matrix1[i][j];
        }
    }
    cout<<"Enter elements of Matrix 1...."<<endl;
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            cout<<"Enter element["<<i<<"]["<<j<<"]: ";
            cin>>matrix2[i][j];
        }
    }
    cout<<endl;
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
                sum[i][j] = matrix1[i][j]+matrix2[i][j];
        }
    }
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
                difference[i][j] = matrix1[i][j]-matrix2[i][j];
        }
    }
    cout<<endl;
    cout<<"Matrix sum is: "<<endl;
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
         if(rows==cols) {
           cout<<sum[i][j]<<" ";
           }
        else {
            cout<<"Invalid entered data..";
            break;
            }
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Matrix subtraction is: "<<endl;
     for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
        if(rows==cols) {
           cout<<difference[i][j]<<" ";
           }
        else {
            cout<<"Invalid entered data..";
            break;
            }
        }
        cout<<endl;
    }
    for(int i=0;i<rows;++i) {
        delete[] matrix1[i];
    }
    for(int i=0;i<rows;++i) {
        delete[] matrix2[i];
    }
    for(int i=0;i<rows;++i) {
        delete[] sum[i];
    }
    for(int i=0;i<rows;++i) {
        delete[] difference[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] sum;
    delete[] difference;

}
