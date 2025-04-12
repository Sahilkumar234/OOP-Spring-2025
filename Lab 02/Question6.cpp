#include<iostream>
#include<string>
using namespace std;

struct Student {
    string name;
    string subject;
    int rollN0;
    float marks;
};

int main() {
    int StudNum;
    int subjectNum = 3;
    cout<<"Enter Student number: ";
    cin>>StudNum;

    float avg;
    Student** stud = new Student*[StudNum];
    for(int i=0;i<StudNum;i++) {
        stud[i] = new Student[subjectNum];
    }

    for(int i=0;i<StudNum;i++) {
        cout<<endl;
        cout<<"Enter Student "<<i+1<<" Name: ";
        cin.ignore();
        getline(cin,stud[i][0].name);
        cout<<"Enter Student "<<i+1<<" Roll No: ";
        cin>>stud[i][0].rollN0;
            for(int j=0;j<subjectNum;j++) {
                cout<<"Enter Subject "<<j+1<<": ";
                cin.ignore();
                getline(cin,stud[i][j].subject);
                cout<<"Enter marks of Subject "<<j+1<<": ";
                cin>>stud[i][j].marks;
            }
    }
    cout<<endl;
    for(int i=0;i<StudNum;i++) {
        cout<<"Student "<<i+1<<"Details "<<endl;
        float totalMarks=0;
        for(int j=0;j<subjectNum;j++) {
            totalMarks += stud[i][j].marks;
        }
        float avg = totalMarks / subjectNum;
        cout<<"Student name: "<<stud[i][0].name<<endl;
        cout<<"Student Roll No: "<<stud[i][0].rollN0<<endl;
        cout<<"Average marks of Student "<<i+1<<": "<<avg<<endl;
        cout<<endl;
    }
   

    for (int i = 0; i < StudNum; i++) {
        delete[] stud[i];
    }
    delete[] stud;

    return 0;
}
