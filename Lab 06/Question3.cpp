#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : public Person
{
protected:
    string subject;

public:
    Teacher(string name, int age, string subject) : Person(name, age), subject(subject) {}

    void displayTeacher()
    {
        display();
        cout << "Subject: " << subject << endl;
    }
};

class Researcher : public Teacher
{
protected:
    string researchArea;

public:
    Researcher(string name, int age, string subject, string researchArea) : Teacher(name, age, subject), researchArea(researchArea) {}

    void displayResearcher()
    {
        displayTeacher();
        cout << "Reasearch Area: " << researchArea << endl;
    }
};

class Professor : public Researcher
{
protected:
    int publication;

public:
    Professor(string name, int age, string subject, string researchArea, int publication) : Researcher(name, age, subject, researchArea), publication(publication) {}

    void displayProfessor()
    {
        displayResearcher();
        cout << "Publication: " << publication << endl;
    }
};

int main()
{
    Professor P1("Sir Talha", 24, "OOP LAB", "Artificial Intelligence", 5);
    P1.displayProfessor();
}
