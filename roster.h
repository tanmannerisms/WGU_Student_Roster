#pragma once
#include "degree.h"
#include <cstring>

using namespace std;


class Roster {
public:

							

	void add(string StudentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram); 
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);


private:

	int i;									// Standard index variable for counting.
	int studentAvg;							// Variable for holding the average number of days a student spends in a course.
	int studentCount = 0;					// Counter to hold number of students added to the roster.
	bool foundStudent;						// Boolean values for determining problematic email adresses.
	bool foundPeriod;
	bool foundAt;
	bool foundSpace;
	string tab = "\t";						// Better than typing in \t every time I need a tab when printing.
	char studentTemp[20] = "";				// Char array for temporarily holding the email of a student.

};

