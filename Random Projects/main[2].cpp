#include <iostream>
#include <string>
#include <fstream>
#include <climits>

/* Program name: main.cpp
*  Author: Brayden Scott
*  Date last updated: 4/25/2021
* Purpose: This program uses structs and an array to gather the students' information, find a student by providing their id, find the highest gpa, and print the students that achieved that gpa.
*/

using namespace std;

const int ARRAY_SIZE = 20;

//struct that is used to gather students' first, middle, and last name.
struct nameType
{
	string first_name;
	char middle_initial = 'A';
	string last_name;
};

//struct used to gather the students name, id, email, gpa, and which program they are in.
struct studentType
{
	nameType name;
	int id = 0;
	string email;
	double GPA = 0.0;
	enum programType {CSCI, DBMS, INFM, SDEV};
};

//function prototypes.
void readClassRoster(ifstream& in, studentType list[], int& students);
void readProgramGPA(ifstream& in, studentType list[], int students);
int findStudentByID(int studentId, const studentType list[], int students);
double findHighestGPA(const studentType list[], int students);
void printHighestGPA(double highest, const studentType list[], int students);

int main()
{
	//assigns file input to in, number of students to 20, id to 0, bestGPA to 0, and declares the array.
	ifstream in;
	int numStudents = 20;
	int id = 0;
	studentType studentArr[ARRAY_SIZE];

	//function calls.
	readClassRoster(in, studentArr, numStudents);
	readProgramGPA(in, studentArr, numStudents);
	findStudentByID(id, studentArr, numStudents);
	double bestGPA = findHighestGPA(studentArr, numStudents);
	printHighestGPA(bestGPA, studentArr, numStudents);

	return 0;
}

//this function gathers the student data from the file.
void readClassRoster(ifstream& in, studentType list[], int& students)
{
	//declares classSize, name, id, and email.
	int classSize = 0;
	studentType name;
	studentType id;
	studentType email;

	//opens the file.
	in.open("classroster.txt");

	//takes in the class size written in the file.
	in >> classSize;

	//for loop that gathers the data in the file and stores it in the array accordingly.
	for (int i = 0; i < classSize; i++)
	{
		in >> list[i].name.first_name;
		in >> list[i].name.middle_initial;
		in >> list[i].name.last_name;
		in >> list[i].id;
		in >> list[i].email;
	}

	//closes the file.
	in.close();
}

//this function gathers the students' gpa's and which program's they are in.
void readProgramGPA(ifstream& in, studentType list[], int students)
{
	//declare id and program.
	int id = 0;
	char course;

	//outer for loop that increments through the array.
	for (int i = 0; i < students; i++)
	{
		//opens the file.
		in.open("studentlist.txt");

		//for loop that tries to match the id from the file to the id in the list.
		for (int j = 0; !in.eof(); j++)
		{
			//stores the id in the file in id variable.
			in >> id;

			//if the id in the file == the id from the array, break.
			if (id == list[i].id)
			{
				break;
			}

			//ignores the program and gpa so it only reads the student id's.
			in.ignore(INT_MAX, '\n');
		}

		//once the loop has found a matching id it stores the program that corresponds to the student id.
		in >> course;

		//then the program matches the character in the file to the program stored in the struct above.
		switch(course)
		{
		    case 'C': course = studentType::CSCI; break;
		    case 'S': course = studentType::SDEV; break;
		    case 'D': course = studentType::DBMS; break;
		    case 'I': course = studentType::INFM; break;
		}

		//after finding the program the students in, the program moves on and stores the students gpa.
		in >> list[i].GPA;

		//closes the file.
		in.close();
	}
}

//this function finds a student according to the id provided.
int findStudentByID(int studentId, const studentType list[], int students)
{
	//for loop that is used to increment through the array.
	for (int i = 0; i < students; i++)
	{
		//if the id in the array equals the id provided, return the position of the id in the array.
		if (list[i].id == studentId)
		{
			return i;
		}
	}

	//returns -1 if the student id is not found.
	return -1;
}

//function that finds the highest gpa of the students in the array.
double findHighestGPA(const studentType list[], int students)
{
	//declares variable that will be returned.
	double highest = 0.0;

	//for loop used to increment through the array.
	for (int i = 0; i < students; i++)
	{
		//if the gpa in element i of the array is greater than highest, store that gpa in highest.
		if (list[i].GPA > highest)
		{
			highest = list[i].GPA;
		}
	}

	//returns the highest gpa.
	return highest;
}

//this function prints the highest gpa and the students that achieved it.
void printHighestGPA(double highest, const studentType list[], int students)
{
	//beginning of the output
	cout << "The students with the highest GPA of " << highest << " are:" << endl;

	//for loop that increments through the array.
	for (int i = 0; i < students; i++)
	{
		//if the students gpa in the i element of the array equals highest, print their id, and name.
		if (list[i].GPA == highest)
		{
			cout << list[i].id << " - " << list[i].name.last_name << ", " << list[i].name.first_name << endl;
		}
	}
}
