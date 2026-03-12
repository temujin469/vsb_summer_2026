#include "Classroom.h"
#include <iostream>
using namespace std;

Classroom::Classroom(Student s[], int count) {
    students = s;
    studentCount = count;
}

void Classroom::printStudentsWithScholarship() {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].hasScholarship()) {
            students[i].printName();
        }
    }
}