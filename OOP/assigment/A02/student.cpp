#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string fName, string lName, int g[], int count) {
    firstName = fName;
    lastName = lName;
    subjectCount = count;

    for (int i = 0; i < count; i++) {
        grades[i] = g[i];
    }
}

double Student::getAverage() {
    int sum = 0;

    for (int i = 0; i < subjectCount; i++) {
        sum += grades[i];
    }

    return (double)sum / subjectCount;
}

bool Student::hasWorseThanTwo() {
    for (int i = 0; i < subjectCount; i++) {
        if (grades[i] > 2) {
            return true;
        }
    }
    return false;
}

bool Student::hasScholarship() {
    return getAverage() < 1.7 && !hasWorseThanTwo();
}

void Student::printName() {
    cout << firstName << " " << lastName << endl;
}