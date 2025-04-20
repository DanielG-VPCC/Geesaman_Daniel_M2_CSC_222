// Geesaman_Daniel_M1_CSC_222.cpp : This file contains the 'main' function.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string studentNames[99];
int studentGrades[99][99];
double gradeAvg[99];
char gradeLetter[99];
string processingString;

struct student {
	string studentName;
	int studentId;
	int studentGrades[99];
	char gradeLetter;
};

struct student students[99];

//int fhandle(string studentNames[], int studentGrades[][99]);
void calcAvg(int studentGrades[][99], int totalNames, double gradeAvg[]);
void calcLtrGrade(double gradeAvg[], char gradeLetter[], int totalNames);
void printReport(string studentNames[], char gradeLetter[], int totalNames);

student* getData(fstream& file, int& studentCnt, int& testsCnt);

int main()
{
	int numberOfStudents = 0;
	int testsTaken = 0;

	int names = 0;
	fstream file;
	file.open("StudentTestData.txt");
	if (file.is_open())
	{
		getData(file, numberOfStudents, testsTaken);
		cout << numberOfStudents << " " << testsTaken;
	}
	else {
		cout << "file failed to open";
	}

	//calcAvg(studentGrades, totalNames, gradeAvg);
	//calcLtrGrade(gradeAvg, gradeLetter, totalNames);
	//printReport(studentNames, gradeLetter, totalNames);
	return 0;
}

student* getData(fstream& file, int& studentCnt, int& testsCnt)
{
	getline(file, processingString);
	int pos = processingString.find(' ');
	cout << "here1";
	studentCnt = stoi(processingString.substr(0, pos));
	processingString.erase(0, pos + 1);
	pos = processingString.find(' ');
	testsCnt = stoi(processingString.substr(0, pos));
	cout << studentCnt << " " << testsCnt;
	while (not file.eof())
	{
		getline(file, processingString);
		int pos = processingString.find(' ');

		while (pos != string::npos)
		{
			for (int i = 0; i < studentCnt; i++)
			{
				students[i].studentName = stoi(processingString.substr(0, pos));
				processingString.erase(0, pos + 1);
				pos = processingString.find(' ');
				students[i].studentId = stoi(processingString.substr(0, pos));
				processingString.erase(0, pos + 1);
				pos = processingString.find(' ');
				for (int j = 0; j < testsCnt; j++)
				{
					students[i].studentGrades[j] = stoi(processingString.substr(0, pos));
					processingString.erase(0, pos + 1);
					pos = processingString.find(' ');
				}
				/*if (pos == -1) {
					studentGrades[0][grades] = stoi(processingString);
				}*/
			}
		}
	}
	return students;
}

/*int fhandle(string studentNames[], int studentGrades[][99])
{
	int names = 0;
	fstream file;
	file.open("StudentGrades.txt");
	if (file.is_open())
	{
		while (not file.eof())
		{
			getline(file, processingString);
			int pos = processingString.find(' ');
			while (pos != string::npos)
			{
				int grades = 1;
				studentNames[names] = processingString.substr(0, pos);
				processingString.erase(0, pos + 1);
				pos = processingString.find(' ');
				while (pos != string::npos)
				{
					studentGrades[names][grades] = stoi(processingString.substr(0, pos));
					processingString.erase(0, pos + 1);
					pos = processingString.find(' ');
					//cout << studentGrades[names][grades];
					grades++;
					if (pos == -1) {
						studentGrades[names][grades] = stoi(processingString);
						//cout << studentGrades[names][grades];
					}
				}
				//cout << studentNames[names];
				studentGrades[names][0] = grades;
				names++;
			}
		}
	}
	else
		cout << "file failed to open";

	return names;
}*/

void calcAvg(int studentGrades[][99], int totalNames, double gradeAvg[])
{
	double total = 0;
	for (int i = 0; i < totalNames; i++) {
		total = 0;
		for (int j = 1; j < 99; j++) {
			total = total + studentGrades[i][j];
		}
		gradeAvg[i] = total / (studentGrades[i][0]);
	}
}

/*
when calculating letter grades, I was a little unsure as to where to break the values because
the chart we were given in the instructions does not use inclusive values.

I broke it up so that the letter grades are bounded by intervals of 10, I just wasn't sure if it should be
bounded on 59 69 79 89 as opposed to 60 70 80 90.
*/

void calcLtrGrade(double gradeAvg[], char gradeLetter[], int totalNames)
{
	for (int i = 0; i < totalNames; i++) {
		if (90.0 <= gradeAvg[i])
		{
			gradeLetter[i] = 'A';
		}
		else if (80.0 <= gradeAvg[i])
		{
			gradeLetter[i] = 'B';
		}
		else if (70.0 <= gradeAvg[i])
		{
			gradeLetter[i] = 'C';
		}
		else if (60.0 <= gradeAvg[i])
		{
			gradeLetter[i] = 'D';
		}
		else
			gradeLetter[i] = 'F';
	}
}

void printReport(string studentNames[], char gradeLetter[], int totalNames)
{
	cout << "Student Letter Grades for your class:" << endl << endl;
	for (int i = 0; i < totalNames; i++)
	{
		cout << studentNames[i] << ": " << gradeLetter[i] << endl;
	}
}
