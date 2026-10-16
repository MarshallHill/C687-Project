#pragma once
#ifndef roster_H
#define roster_H
#include "student.h"
#include <vector>

class Roster {
private: 
	std::vector<Student*> classRosterArray;

public:
	~Roster();
	void parse(std::string row);
	void add(std::string StudentID, std::string firstName, 
		std::string lastName, std::string emailAddress, 
		int age, int daysInCourse1, int daysInCourse2, 
		int daysInCourse3, DegreeProgram degreeProgram);
	void remove(std::string studentID);
	void printAll() const;
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);


};


#endif