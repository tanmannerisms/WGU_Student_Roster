#pragma once
#include "degree.h"
using namespace std;

class Student {
public:
	Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);			// Constructor	

	void Print(string studentInfo);														// Print student info
	void SetStudentId(string studentIdentifier);										// Sets student ID
	void SetFName(string firstName);													// Sets first name
	void SetLName(string lastName);														// Sets last name
	void SetEmail(string email);														// Sets student email
	void SetAge(int age);																// Sets student age
	void SetCourseDays(int course1, int course2, int course3);							// Sets the time to complete different courses
	void SetDegree(DegreeProgram degree);												// Sets student degree path. Corresponds to variable: degProgram


	string GetStudentId();																// Gets the student ID
	string GetFName();																	// Getter for student's first name
	string GetLName();																	// Getter for student last name
	string GetEmail();																	// Getter for student email
	DegreeProgram GetDegree();															// Getter for student degree program
	int GetAge();																		// Getter for student age
	int* GetCourseDays();																// Getter for days to complete course(s). Should return the data using pointers to classLength[]


private:
	int stuAge, i;																		// Student Age and interval counter
	int classLength[3];																	// Array to hold the average days in each class
	string studentId, fstName, lstName, emailAdr, temp, allInfo;						// All the variables for the student attributes, along with the temporary and all info variable
	DegreeProgram degProgram;															// Degree Program variable
};