#include <iostream>
#include <string>
#include "degree.h"


using namespace std;

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree) {			// Constructor

	SetStudentId(studentID);
	SetFName(firstName);
	SetLName(lastName);
	SetEmail(email);
	SetAge(age);
	SetCourseDays(daysInCourse1, daysInCourse2, daysInCourse3);
	SetDegree(degree);

}


void Student::Print(string studentInfo) {		// Print function requiring specific string input for proper attribute printing.
	if (studentInfo == "FName") {
		cout << fstName;
	}
	else if (studentInfo == "Age") {			// Using these variables instead of the function call is the exact same thing >:( 
		cout << stuAge;			
	}
	else if (studentInfo == "LName") {
		cout << lstName;
	}
	else if (studentInfo == "ID") {
		cout << studentId;
	}
	else if (studentInfo == "Email") {
		cout << emailAdr;
	}
	else if (studentInfo == "Degree") {
		if (degProgram == 0)
			cout << "Security";
		else if (degProgram == 1)
			cout << "Network";
		else if (degProgram == 2)
			cout << "Software";
		else
			cout << "Degree program is not specified.";
	}
	else if (studentInfo == "CourseLen") {
		temp = "{";
		for (i = 0; i < 3; ++i) {
			
			if (i == 2) {
				temp += to_string( classLength[i] );			
			}
			else {
				temp += ( to_string( classLength[i] ) + ", " );
			}
		}
		temp += "}";
		cout << temp;
	}
	else {
		cout << "Error: Invalid attribute specified\n";
	}
}

void Student::SetStudentId(string studentIdentifier) {		// Hopefully the Setters and Getters are self-explanatory.
	studentId = studentIdentifier;
}

void Student::SetFName(string firstName) {
	fstName = firstName;
}

void Student::SetLName(string lastName) {
	lstName = lastName;
}

void Student::SetEmail(string email) {
	emailAdr = email;
}

void Student::SetAge(int age) {
	stuAge = age;
}

void Student::SetCourseDays(int course1, int course2, int course3) {
	classLength[0] = course1;
	classLength[1] = course2;
	classLength[2] = course3;
}

void Student::SetDegree(DegreeProgram degree) {
	degProgram = degree;
}

string Student::GetStudentId() {
	return studentId;
}

string Student::GetFName() {
	return fstName;
}

string Student::GetLName() {
	return lstName;
}

string Student::GetEmail() {
	return emailAdr;
}

DegreeProgram Student::GetDegree() {
	return degProgram;
}

int Student::GetAge() {
	return stuAge;
}

int* Student::GetCourseDays() {		
	return classLength;

}
