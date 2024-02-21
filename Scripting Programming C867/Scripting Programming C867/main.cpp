#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"
#include "degree.h"
#include <vector>
#include <sstream>

using namespace std;

const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Mariangela,Bronder,mbronde@wgu.edu,26,45,30,36,SOFTWARE" };

void parseStudentData(Roster& roster) {
    int dataSize = sizeof(studentData) / sizeof(studentData[0]);
    for (int i = 0; i < dataSize; ++i) {
        string data = studentData[i];
        stringstream ss(data);
        vector<string> tokens;
        string token;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        if (tokens.size() != 9) {
            cerr << "Error: Invalid student data format." << endl;
            continue;
        }
        string studentID = tokens[0];
        string firstName = tokens[1];
        string lastName = tokens[2];
        string emailAddress = tokens[3];
        int age = stoi(tokens[4]);
        int daysInCourse1 = stoi(tokens[5]);
        int daysInCourse2 = stoi(tokens[6]);
        int daysInCourse3 = stoi(tokens[7]);
        DegreeProgram degreeProgram;
        string degreeStr = tokens[8];
        if (degreeStr == "SECURITY") {
            degreeProgram = SECURITY;
        }
        else if (degreeStr == "NETWORK") {
            degreeProgram = NETWORK;
        }
        else if (degreeStr == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        }
        else {
            cerr << "Error: Invalid degree program." << endl;
            continue;
        }
        roster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }
}

void printYourInfo() {
	cout << "Course Title: C867\tProgramming Language: C++\tWGU Student ID: 001400279\tName: Mariangela Bronder" << endl;
}

int main(int argc, char* argv[]) {
    printYourInfo();
	Roster classRoster;
    parseStudentData(classRoster);
	classRoster.printAll();
	classRoster.printInvalidEmails();
	for (int i = 0; i < MAX_STUDENTS; i++) {
        if (classRoster.classRosterArray[i] != NULL) {
            classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
        }
	}
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	return 0;
}
