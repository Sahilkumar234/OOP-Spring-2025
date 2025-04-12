#include<iostream>
using namespace std;

int main() {
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    int** array = new int*[size];

    for(int i=0;i<size;++i) {
        array[i] = new int;
        cout<<"Enter element ["<<i<<"]: ";
        cin>>*array[i];
    }
    cout<<endl;
    cout<<"Array elements are...."<<endl;
    for(int i=0;i<size;i++) {
        cout<<"Element ["<<i<<"]: "<<*array[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<size;++i) {
        delete[] array[i];
    }

    delete[] array;
}
