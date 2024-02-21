#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student
{
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;
public:
	Student(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	string getStudentID();
	void setStudentID(string studentID);
	string getFirstName();
	void setFirstName(string firstName);
	string getLastName();
	void setLastName(string lastName);
	string getEmailAddress();
	void setEmailAddress(string emailAddress);
	int getAge();
	void setAge(int age);
	int* getDaysInCourse();
	void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	DegreeProgram getDegreeProgram();
	void setDegreeProgram(DegreeProgram degreeProgram);
	void print();
};

