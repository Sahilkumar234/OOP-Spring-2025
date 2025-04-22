#include "LabCourse.h"
#include "LectureCourse.h"

int main()
{
    Course *courses[2];
    courses[0] = new LectureCourse("JL1023", 3, 8.33, 9.42, 23.45, 46.5);
    courses[1] = new LabCourse("SLB9023", 1, 20, 15.5, 46.75, 9.5);

    for (int i = 0; i < 2; i++)
    {
        courses[i]->displayInfo();
        courses[i]->calculateGrade();
        cout << "<<----------------------------------->>" << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete courses[i];
    }
}
