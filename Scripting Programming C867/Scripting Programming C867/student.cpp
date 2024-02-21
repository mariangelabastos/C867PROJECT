#include "student.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) : studentID(studentID),
	firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), degreeProgram(degreeProgram)

{
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
}

string Student::getStudentID() {
	return this->studentID;
}

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

string Student::getLastName() {
	return this->lastName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

string Student::getEmailAddress() {
	return this->emailAddress;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

int Student::getAge() {
	return this->age;
}

void Student::setAge(int age) {
	this->age = age;
}

int* Student::getDaysInCourse() {
	return this->daysInCourse;
}

void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

string convertEnumToString(DegreeProgram degreeProgram) {
	switch (degreeProgram)
	{
	case SECURITY:
		return "Securtiy";
	case NETWORK:
		return "Network";
	case SOFTWARE:
		return "Software";
	default:
		return "Not Valid.";
	}
}

void Student::print() {
	cout << "Student ID: " << this->studentID << "\tFirst Name: " << this->firstName <<
		"\tLast Name:" << this->lastName << "\nEmail Address: " << this->emailAddress <<
		"\tAge: " << this->age << "\tDays In Course: " << this->daysInCourse[0] << "," <<
		this->daysInCourse[1] << "," << this->daysInCourse[2] << "\tDegree Program: " <<
		convertEnumToString(this->degreeProgram) << endl;
}


