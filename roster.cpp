#include <string>
#include <iostream>
#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;

Student* classRosterArray[] = { nullptr };	// E1

void Roster::add(string StudentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {	// E3a

	classRosterArray[studentCount] = new Student(StudentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);	// Initializes a student object in the pointer array 
	studentCount++;																																					// for each student with the info passed from main()

}

void Roster::remove(string studentID) {			//E3b

	foundStudent = false;

	for (i = 0; i < studentCount; i++) {
		if (classRosterArray[i] != nullptr) {										// Makes sure the student exists in classRosterArray[].

			if (classRosterArray[i]->GetStudentId() == studentID) {					// Match student at classRosterArray[i] with the student ID passed to the function

				classRosterArray[i]->~Student();									// Call the destructor
				foundStudent = true;												// I may not even need this assignment here, but probably good to have.
				classRosterArray[i] = nullptr;										// Sets the pointer in the array to nullptr so that it will be easy to skip over this when checking student information from the array.
				break;																// Break out of the for loop.

			}
		}	
		if (i == studentCount - 1 && foundStudent == false) {						// This runs if the student with student ID passed to function exists.

			cout << "Student with ID \"" << studentID << "\" is not found \n";

		}
	}
}

void Roster::printAll() {						// E3c

	cout << "Students currently on the class roster:\n";

	for (i = 0; i < studentCount; i++) {

		if (classRosterArray[i] != nullptr) {		// Seems self-explanatory, but calls the print function for each type of information for the student except for their email addresses
													// as listed in E3c. The if statement checks to see if the student exists. Student doesn't exist if classRosterArray[i] is a nullptr.
			classRosterArray[i]->Print("ID");
			cout << tab << "First Name: ";
			classRosterArray[i]->Print("FName");
			cout << tab << "Last Name: ";
			classRosterArray[i]->Print("LName");
			cout << tab << "Age: ";
			classRosterArray[i]->Print("Age");
			cout << tab << "daysInCourse: ";
			classRosterArray[i]->Print("CourseLen");
			cout << tab << "Degree Program: ";
			classRosterArray[i]->Print("Degree");
			cout << endl;
			
		}
	}
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {	//E3d

	for (i = 0; i < studentCount; i++) {

		if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->GetStudentId() == studentID)) {		// Checks to make sure that the student exists in classRosterArray and that the student ID of classRosterArray[i] matches
			cout << "Average days for student with ID \'" << studentID << "\' to complete course: ";		// the student ID passed to the function.

			studentAvg = (*classRosterArray[i]->GetCourseDays() + *(classRosterArray[i]->GetCourseDays() + 1) + *(classRosterArray[i]->GetCourseDays() + 2)) / 3;	// Grabs the length of each of the three classes for the student
			cout << studentAvg << " days" << endl;																													// using the pointer and averages them out.

		}
	}
}

void Roster::printInvalidEmails() {			// E3e
	cout << "Students with invalid email addresses are shown below.\n";
	for (i = 0; i < studentCount; i++) {

		foundStudent = false;		
		foundAt = false;
		foundPeriod = false;
		foundSpace = false;

		if (classRosterArray[i] != nullptr) {									// If student exists, then copy the email of that student to the temporary variable.
			strcpy(studentTemp, (classRosterArray[i]->GetEmail()).c_str());
		}
		else {
			continue;															// If the student doesn't exist, then the for loop continues to the next iteration.
		}

		for (int n = 0; studentTemp[n] != '\0'; n++) {							// Loop until escape character is found
			if (studentTemp[n] == '@') {										// Found @ sign?
				foundAt = true;
			}

			if (studentTemp[n] == '.') {										// Found period?
				foundPeriod = true;
			}

			if (studentTemp[n] == ' ') {										// Found whitespace? 
				foundSpace= true;
				break;															
			}

		}

		if ((foundAt == false || foundPeriod == false) || foundSpace == true) {	// If email has been found to be problematic, then continue to print statement in next if statement.
			foundStudent = true;
		}

		if (foundStudent == true) {												// Print bad email

			classRosterArray[i]->Print("ID");
			cout << tab;
			classRosterArray[i]->Print("Email");
			cout << endl;

		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {				// E3f
	cout << endl << "Students currently associated with DegreeProgram: ";

	if (degreeProgram == 0)								// Standard if else. Enumerated data type makes for easy if else statement.
		cout << "\'Security\'\n";
	else if (degreeProgram == 1)
		cout << "\'Network\'\n";
	else if (degreeProgram == 2)
		cout << "\'Software\'\n";


	for (i = 0; i < studentCount; i++) {										// Loop to print the students under the specified degree program.

		if (classRosterArray[i]->GetDegree() == degreeProgram) {
			classRosterArray[i]->Print("ID");
			cout << tab;
			classRosterArray[i]->Print("FName");
			cout << tab;
			classRosterArray[i]->Print("LName");
			cout << endl;
		}
	}
	cout << endl;
}