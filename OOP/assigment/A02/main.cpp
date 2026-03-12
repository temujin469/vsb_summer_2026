#include "Classroom.h"
#include <iostream>
using namespace std;

int main() {

    int g1[5] = {1,1,2,1,1};
    int g2[5] = {2,2,2,2,2};
    int g3[5] = {1,1,1,1,1};

    Student s1("Jan", "Novak", g1, 5);
    Student s2("Petr", "Svoboda", g2, 5);
    Student s3("Anna", "Kralova", g3, 5);

    Student students[] = {s1, s2, s3};

    Classroom classroom(students, 3);

    classroom.printStudentsWithScholarship();

    return 0;
}