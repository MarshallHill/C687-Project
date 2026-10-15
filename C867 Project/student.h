#pragma once
#ifndef student_H
#define student_H
#include "degree.h"
#include <string>
using namespace std;

class Student {

private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;


public:
	Student(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse[3],
		DegreeProgram degreeProgram);

	//Accessors
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	const int* getDaysInCourse() const;
	DegreeProgram getDegreeProgram() const;

	//Mutators
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[3]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print() const;

};
#endif