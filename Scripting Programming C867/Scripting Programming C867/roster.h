#pragma once
#include "student.h"
#include "degree.h"
#include <string>

constexpr auto MAX_STUDENTS = 70;

using namespace std;

class Roster
{
public:
	Student** classRosterArray;
	Roster();
	void add(string studentID, string firstName, string
		lastName, string emailAddress, int age, int daysInCourse1, int
		daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};

