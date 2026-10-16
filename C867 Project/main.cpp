// C867 Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main()
{
	//G1 Course info
	cout << "Course Title: Scripting and Programming - Applications C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "WGU student ID: 011616852" << endl;
	cout << "Name: Edward Hill" << endl << endl;


	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",

	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",

	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",

	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",

	"A5,Edward,Hill,ehil204@wgu.edu,30,2,15,9,SOFTWARE" };

	
	//G2 Roster class instance
	Roster classRoster;

	//G3 add each student
	int numStudents = sizeof(studentData) / sizeof(studentData[0]);
	for (int i = 0; i < numStudents; i++) {
		classRoster.parse(studentData[i]);
	}

	//G4 pseudocode
	classRoster.printAll();
	cout << endl;
	cout << "Average days in course" << endl;
	for (Student* s : classRoster.classRosterArray) {
			classRoster.printAverageDaysInCourse(s->getStudentID());
		}
	cout << endl;

	classRoster.printInvalidEmails();
	cout << endl;
	
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;
	
	classRoster.remove("A3");
	cout << "Removing A3" << endl << endl;
	
	classRoster.printAll();
	cout << endl;

	cout << "Removing A3" << endl;
	classRoster.remove("A3");
	
	
	

	classRoster.~Roster();
	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
