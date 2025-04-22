#include"Course.h"

class LabCourse : public Course {
    double labTaskMarks,MidTerm,FinalMarks,ProjectMarks;
public:
    LabCourse(string courseCode, int credits,double labTaskMarks,double MidTerm,double FinalMarks,double ProjectMarks);

    void calculateGrade();
    void displayInfo();
};
