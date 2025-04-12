#include <iostream>
#include <cstring>
using namespace std;

class Student
{
    int ID;
    string name;
    int *ExamScore;
    int scoreNo;

public:
    Student(const string &name, int ID, int *ExamScore, int scoreNo) : name(name), ID(ID), scoreNo(scoreNo)
    {
        this->ExamScore = new int[scoreNo];
        for (int i = 0; i < scoreNo; i++)
        {
            this->ExamScore[i] = ExamScore[i];
        }
    }

    Student(const Student &Stud)
    {
        ID = Stud.ID;
        name = Stud.name;
        scoreNo = Stud.scoreNo;
        ExamScore = new int[scoreNo];

        for (int i = 0; i < scoreNo; i++)
        {
            ExamScore[i] = Stud.ExamScore[i];
        }
    }

    ~Student()
    {
        delete[] ExamScore;
    }

    void displayStudent()
    {
        cout << "Student name: " << name << endl;
        cout << "Student's ID: " << ID << endl;
        for (int i = 0; i < scoreNo; i++)
        {
            cout << "Score " << i + 1 << ": " << ExamScore[i] << endl;
        }
        cout << "---------------------------" << endl;
    }
};

int main()
{
    int EScore1[] = {80, 89, 82, 76};
    Student S1("Sahil Kumar", 223, EScore1, 4);
    S1.displayStudent();

    Student S2 = S1;
    cout << "Copy constructor of student ID(223): " << endl;
    S2.displayStudent();

    int EScore2[] = {74, 79, 85, 86};
    Student S3("Dev Kumar", 443, EScore2, 4);
    S3.displayStudent();

    Student S4 = S3;
    cout << "Copy constructor of student ID(223): " << endl;
    S4.displayStudent();
}
