#include <iostream>
#include <string>
#include "student.h"

using namespace std;

Student::Student(string studentID, 
	string firstName, string lastName, 
	string emailAddress, int age, int daysInCourse[3], 
	DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	setDaysInCourse(daysInCourse);
	this->degreeProgram = degreeProgram;
}


// Accessors
string Student::getStudentID() const {
	return studentID;
}
string Student::getFirstName() const {
	return firstName;
}
string Student::getLastName() const {
	return lastName;
}
string Student::getEmailAddress() const {
	return emailAddress;
}
int Student::getAge() const {
	return age;
}
const int* Student::getDaysInCourse() const {
	return daysInCourse;
}
DegreeProgram Student::getDegreeProgram() const {
	return degreeProgram;
}


// Mutators
void Student::setStudentID(std::string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(std::string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(std::string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(std::string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDaysInCourse(int daysInCourse[3]) {
	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}


void Student::print() const {
	cout << "Student ID: " << studentID << "\t";
	cout << "First Name: " << firstName << "\t";
	cout << "Last Name: " << lastName << "\t";
	cout << "Email Address: " << emailAddress << "\t";
	cout << "Age: " << age << "\t";
	cout << "Days in Course: {" << daysInCourse[0] << ", "
		<< daysInCourse[1] << ", "
		<< daysInCourse[2] << "} \t";
	cout << "Degree Program: ";
	switch (degreeProgram) {
	case SECURITY:
		cout << "SECURITY" << endl;
		break;
	case NETWORK:
		cout << "NETWORK" << endl;
		break;
	case SOFTWARE:
		cout << "SOFTWARE" << endl;
		break;
	default:
		cout << "UNKNOWN" << endl;
		break;
	}
}
