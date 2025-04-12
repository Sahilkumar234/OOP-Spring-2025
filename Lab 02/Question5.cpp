#include<iostream>
using namespace std;

int main() {
    int n;
    int sum = 0;

    cout<<"Enter the size of array: ";
    cin>>n;
    int* array = new int[n];
    
    for(int i=0;i<n;i++) {
        cout<<"Element ["<<i<<"]: ";
        cin>>array[i];
    }
    cout<<endl;
    int *array1 = array;
    cout<<"Traversed Elements are...."<<endl;
    for(int i=0;i<n;i++) {
        cout<<"Element ["<<i<<"]: "<<*(array1+i)<<endl;
    }
    cout<<endl;
    array1 = array;
    for(int i=0;i<n;i++) {
        sum = sum + *(array1+i);
    }
    cout<<"Sum of array elements is: "<<sum<<endl;
    delete[] array; 
}
