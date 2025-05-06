// Geesaman_Daniel_M1_CSC_222.cpp : This file contains the 'main' function.

/*
This program reads a file that has names, student IDs, and grades and outputs a list of how well each student did in the class.
This program uses structs to accomplish this.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct student {
	string studentName;
	int studentId;
	int* studentGrades = new int[99];
	double gradeAvg;
	char gradeLetter;
};

void calcAvg(student students[], int& studentCnt, int& testsCnt);
void calcLtrGrade(student students[], int& studentCnt, int& testsCnt);
void printReport(student students[], int& studentCnt, int& testsCnt);
student *getData(fstream& file, int& studentCnt, int& testsCnt);

int main()
{
	int numberOfStudents = 0;
	int testsTaken = 0;
	
	int names = 0;
	fstream file;
	file.open("StudentTestData.txt");
	if (file.is_open())
	{
		student *stud = getData(file, numberOfStudents, testsTaken);
		calcAvg(stud, numberOfStudents, testsTaken);
		calcLtrGrade(stud, numberOfStudents, testsTaken);
		printReport(stud, numberOfStudents, testsTaken);
		delete[] stud;
	}
	else {
		cout << "file failed to open";
	}
	return 0;
}

/*
This function requires a file and studentCnt and testsCnt pointers. The preconditions are that the file must be opened,
studentCnt and testCnt must be initialized. The postcondition is that the function will return the students struct to the main function.
*/
student *getData(fstream& file, int& studentCnt, int& testsCnt)
{
	string pString;
	student* students = new student[99];
	
	getline(file, pString);
	int pos = pString.find(' ');
	studentCnt = stoi(pString.substr(0, pos));
	pString.erase(0, pos + 1);
	pos = pString.find(' ');
	testsCnt = stoi(pString.substr(0, pos));
	int i = 0;
	while (not file.eof())
	{
		getline(file, pString);
		int pos = pString.find(' ');
		students[i].studentName = pString.substr(0, pos);
		pString.erase(0, pos + 1);
		pos = pString.find(' ');
		students[i].studentId = stoi(pString.substr(0, pos));
		pString.erase(0, pos + 1);
		pos = pString.find(' ');
		for (int j = 0; j < testsCnt; j++)
		{
			students[i].studentGrades[j] = stoi(pString.substr(0, pos));
			pString.erase(0, pos + 1);
			pos = pString.find(' ');
		}
		i++;
	}
	return students;
}

/*
This function accepts the studentCnt and testsCnt pointers. The preconditions are that the studentCnt and testsCnt variables
must be initialized and populated with the data found on the first line of the file, the students struct must also be global and
populated with data found in the file. The postcondition is that the grade average of each of the students will be placed within their
respective students[].gradeAvg slot.
*/
void calcAvg(student students[], int& studentCnt, int& testsCnt)
{
	double total = 0;
	for (int i = 0; i < studentCnt; i++) {
		total = 0;
		for (int j = 0; j < testsCnt; j++) {
			total = total + students[i].studentGrades[j];
		}
		students[i].gradeAvg = total / testsCnt;
	}
}

/*
The calcLtrGrade function accepts the studentCnt and testsCnt pointers.
The preconditions are that the studentCnt and testsCnt variables must be initialized and populated with the data found on the first line of the file,
and the students[].gradeAvg struct must have been filled with a value.
The postcondition is that the students[].gradeLetter struct will be filled with a letter grade representing the input students[].gradeAvg value
for each student.


when calculating letter grades, I was a little unsure as to where to break the values because
the chart we were given in the instructions does not use inclusive values.

I broke it up so that the letter grades are bounded by intervals of 10, I just wasn't sure if it should be
bounded on 59 69 79 89 as opposed to 60 70 80 90.
*/

void calcLtrGrade(student students[], int& studentCnt, int& testsCnt)
{
	for (int i = 0; i < studentCnt; i++) {
		if (90.0 <= students[i].gradeAvg)
		{
			students[i].gradeLetter = 'A';
		}
		else if (80.0 <= students[i].gradeAvg)
		{
			students[i].gradeLetter = 'B';
		}
		else if (70.0 <= students[i].gradeAvg)
		{
			students[i].gradeLetter = 'C';
		}
		else if (60.0 <= students[i].gradeAvg)
		{
			students[i].gradeLetter = 'D';
		}
		else
			students[i].gradeLetter = 'F';
	}
}

/*
The printReport function accepts the studentCnt and testsCnt variables.
The preconditions are that the studentCnt and testsCnt variables must be initialized and populated with the data found on the first line of the file,
and the students struct must have all its slots filled with a value.
The postcondition of this function is that it will use the studentName, studentId, gradeAvg, and gradeLetter slots of the students struct to output
a report showing the name, id, avg score, and grade for each student found in the file.
*/

void printReport(student students[], int& studentCnt, int& testsCnt)
{
	cout << endl;
	cout << "Student Letter Grades for your class:" << endl << endl;
	cout << "Student" << setw(10) << "ID" << setw(10) << "Score" << setw(10) << "Grade" << endl;
	for (int i = 0; i < studentCnt; i++)
	{
		cout << students[i].studentName << setw(10) << students[i].studentId << setw(10) << students[i].gradeAvg << setw(10) << students[i].gradeLetter << endl;
	}
}
