#include"Course.h"
#pragma once 

class LectureCourse : public Course {
    double quizMarks;
    double assignmentMarks;
    double midTerms,finalMarks;
public:
    LectureCourse(string courseCode, int credits,double quizMarks,double assignmentMarks,double midTerms,double finalMarks);

    void calculateGrade();
    void displayInfo();
};
