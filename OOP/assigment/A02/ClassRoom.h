#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "Student.h"

class Classroom {
private:
    Student* students;
    int studentCount;

public:
    Classroom(Student s[], int count);
    void printStudentsWithScholarship();
};

#endif