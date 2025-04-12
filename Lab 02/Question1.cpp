#include<iostream>
#include<string>
using namespace std;

struct Books {
    string title;
    string author;
    int year;
};

int main() {
    int n;
    cout<<"Enter books number: ";
    cin>>n;
    Books* b1 = new Books[n];

    for(int i=0;i<n;i++) {
        cout<<"Enter Book "<<i+1<<" details:"<<endl;
        cout<<"Book title: ";
        cin.ignore();
        getline(cin,b1[i].title);
        cout<<"Book Author: ";
        getline(cin,b1[i].author);
        cout<<"Enter year: ";
        cin>>b1[i].year;
        cout<<endl;
    }
    
    cout<<endl;
    int specificYear;
    cout<<"Enter specific year: ";
    cin>>specificYear;

    cout<<endl;
    cout<<"Book Published after "<<specificYear<<endl;
    int found = 0;
    for(int i=0;i<n;i++) {
        if(b1[i].year>specificYear) {
            cout<<"Book Title: "<<b1[i].title<<endl;
            cout<<"Book Author: "<<b1[i].author<<endl;
            cout<<"Book year: "<<b1[i].year<<endl;
            found = 1;
            cout<<endl;
        }
    }

    if(found==0) {
        cout<<"No Books printed after "<<specificYear;
    }
    delete[] b1;
}
