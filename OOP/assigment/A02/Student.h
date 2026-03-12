#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    int grades[5];
    int subjectCount;

public:
    Student(string fName, string lName, int g[], int count);

    double getAverage();
    bool hasWorseThanTwo();
    bool hasScholarship();
    void printName();
};

#endif