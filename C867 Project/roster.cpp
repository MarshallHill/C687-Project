#include <iostream>
#include <sstream>
#include "roster.h"
using namespace std;


void Roster::parse(std::string row) {
	std::stringstream ss(row);
	std::string f[9];
	for (int i = 0; i < 9; i++) {
		std::getline(ss, f[i], ',');
	}

	DegreeProgram dp = SECURITY;
	if (f[8] == "NETWORK") {
		dp = NETWORK;
	}
	else if (f[8] == "SOFTWARE") {
		dp = SOFTWARE;
	}

	add(f[0], f[1], f[2], f[3], std::stoi(f[4]), 
		std::stoi(f[5]), std::stoi(f[6]), std::stoi(f[7]), dp);
}

void Roster::add(std::string StudentID, std::string firstName,
	std::string lastName, std::string emailAddress,
	int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* student = new Student(StudentID, firstName, lastName, 
	emailAddress, age, daysInCourse, degreeProgram);
	classRosterArray.push_back(student);
}


void Roster::remove(std::string studentID) {
	for (size_t i = 0; i < classRosterArray.size(); ++i) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			delete classRosterArray[i];
			classRosterArray.erase(classRosterArray.begin() + i);
			return;
		}
	}
	std::cout << "Student ID " << studentID << " not found." << std::endl;
}

void Roster::printAll() {
	for (Student* s : classRosterArray) {
		s->print();
	}
}

void Roster::printAverageDaysInCourse(std::string studentID) {
	for (Student* s : classRosterArray) {
		if (s->getStudentID() == studentID) {
			const int* days = s->getDaysInCourse();
			double average = (days[0] + days[1] + days[2]) / 3.0;
			std::cout << studentID << ": " << average << std::endl;
			return;
		}
	}
	std::cout << "Student ID " << studentID << " not found." << std::endl;
}

void Roster::printInvalidEmails() {
	for (Student* s : classRosterArray) {
		std::string email = s->getEmailAddress();
		bool hasAt = email.find('@') != std::string::npos;
		bool hasDot = email.find('.') != std::string::npos;
		bool hasSpace = email.find(' ') == std::string::npos;
		if (!hasAt || !hasDot || !hasSpace) {
			std::cout << "Invalid email: " << email << std::endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Degree Program: " << endl;
	for (Student* s : classRosterArray) {
		if (s->getDegreeProgram() == degreeProgram) {
			s->print();
		}
	}
}

Roster::~Roster() {
	for (Student* s : classRosterArray) {
		delete s;
	}
	classRosterArray.clear();
}