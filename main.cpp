#include "roster.cpp"
#include "student.cpp"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;


int main() {

	
	const string studentData[] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Tanner,Mills,tmil760@wgu.edu,21,31,18,27,SOFTWARE"
	};

	

	int comma = 0;						// Index for the setting temporary values
	int courseCounter = 0;				// Index for setting the course lengths
	string temp;						// Unspecified temp value
	string idTemp;						// Rest of variables with 'temp' suffix are for setting the values for each student temporarily
	string fNameTemp;
	string lNameTemp;
	string emailTemp;
	int ageTemp = 0;
	int courseDaysTemp[3] = { 0, 0, 0 };
	DegreeProgram degreeTemp = SECURITY;
	const int studentDataLength = sizeof(studentData) / 40;			// Constant variable for setting the number of iterations for the parse and add loop.
	char studentTemp[100] = "";										// Temporarily holds the data for each student for adding students to the roster


	// Beginning of instructions in section F

	std::cout << "Course: C867\nLanguage Used: C++\nStudent: 009020370\nName: Tanner Mills\n\n\n";	// F1

	Roster classRoster;																				// F2



	// Start of F3
	for (int i = 0; i < studentDataLength; i++) {					// This for loop parses the information in the studentData array and creates student objects in the classRosterArray array of object pointers.
																	// (I suppose I could have added this into the roster.cpp file to try and keep main() short, but I started this way and see no reason to change now.)

		strcpy(studentTemp, studentData[i].c_str());				// Copies the string from the current studentData[currentInterval] to the studentTemp char array
		temp = "";
		comma = 0;

		for (int n = 0; studentTemp[n] != '\0'; n++) {				// Checks each character in the char array until the escape character is reached.

			if (studentTemp[n] == ',') {							// Checks if the character is at studentTemp[n] is comma.  If it is, check against 
																	// number of commas already found in the studentTemp array and determine what the 
				if (comma == 0) {									// type of information is based on comma count. This only works because the format
					idTemp = temp;									// of the info is the same in each index of the studentData array.
				}

				else if (comma == 1) {
					fNameTemp = temp;
				}

				else if (comma == 2) {
					lNameTemp = temp;
				}

				else if (comma == 3) {
					emailTemp = temp;
				}

				else if (comma == 4) {
					ageTemp = stoi(temp);
				}

				else if (comma == 5 || comma == 6 || comma == 7) {

					courseDaysTemp[courseCounter] = stoi(temp);						// Converts the temp variable to an int type.
					courseCounter++;

					if (courseCounter == 3) {
						courseCounter = 0;
					}
				}

				comma++;
				temp = "";															// Clears the temp variable for the next set of info.
			}																		// end of if (studentTemp[n] == ',')			

			else {																	// Else statement because there is no comma at the end of the student's information string.

				temp += studentTemp[n];

				if (temp == "SECURITY") {
					degreeTemp = SECURITY;
				}

				else if (temp == "NETWORK") {
					degreeTemp = NETWORK;
				}

				else if (temp == "SOFTWARE") {
					degreeTemp = SOFTWARE;
				}
			}
		}

		classRoster.add(idTemp, fNameTemp, lNameTemp, emailTemp, ageTemp, courseDaysTemp[0], courseDaysTemp[1], courseDaysTemp[2], degreeTemp);		// Add each student to the classRoster object using the temp variables set earlier.
		

		for (int n = 0; n < sizeof(courseDaysTemp) / 4; n++) {					// This clears the information in courseDaysTemp for the next student to be added to the roster.
			courseDaysTemp[n] = 0;
		}
	}	   


	
	// F4 start

	classRoster.printAll();																								

	classRoster.printInvalidEmails();

	for (int i = 0; i < studentDataLength; i++) {  
		classRoster.printAverageDaysInCourse(classRosterArray[i]->GetStudentId());
	}

	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");	//Demonstration of error when student is unavailable for deletion.

	// F4 end

	classRoster.~Roster();		// F5

	return 0;
}