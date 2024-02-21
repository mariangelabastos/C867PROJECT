#include "roster.h"
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

Roster::Roster() : classRosterArray(new Student* [MAX_STUDENTS]) {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        classRosterArray[i] = NULL;
    }
}

void Roster::add(string studentID, string firstName, string
	lastName, string emailAddress, int age, int daysInCourse1, int
	daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int index = 0;
    while (index < MAX_STUDENTS && this->classRosterArray[index] != NULL) {
        index++;
    }
    if (index < MAX_STUDENTS) {
        this->classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress,
            age, daysInCourse1, daysInCourse2, daysInCourse3,
            degreeProgram);
        cout << "Student with ID " << studentID << " has been added to the roster." << endl;
    }
    else {
        cout << "Cannot add student. Roster is full." << endl;
    }
}

void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (classRosterArray[i] != NULL && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = NULL;
            cout << "Student with ID " << studentID << " has been removed from the roster." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Error: Student with ID " << studentID << " not found in the roster." << endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (classRosterArray[i] != NULL) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    bool found = false;
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (classRosterArray[i] != NULL && classRosterArray[i]->getStudentID() == studentID) {
            int sum = classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1]
                + classRosterArray[i]->getDaysInCourse()[2];
            double average = sum / 3.0;
            cout << "Student with ID " << studentID << " has an average of " << average << " days in the three courses." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Error: Student with ID " << studentID << " not found in the roster." << endl;
    }
}

void Roster::printInvalidEmails() {
    bool foundInvalid = false;
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (classRosterArray[i] != NULL) {
            string email = classRosterArray[i]->getEmailAddress();
            bool isValid = true;
            if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
                cout << "Invalid email found for student with ID " << classRosterArray[i]->getStudentID() << ": " << email << endl;
                foundInvalid = true;
            }
        }
    }
    if (!foundInvalid) {
        cout << "All student email addresses are valid." << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    bool foundStudents = false;
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (classRosterArray[i] != NULL && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
            foundStudents = true;
        }
    }
    if (!foundStudents) {
        cout << "No students found for the specified degree program." << endl;
    }
}

Roster::~Roster() {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        delete classRosterArray[i];
    }
    delete[] classRosterArray;
}
