#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

const int MAX_STUDENTS = 25;// constant maximum number of students that can be read.
const int AMOUNT_OF_HW = 10;// constant maximum nnumber of homework grades that can be read per students.
const int AMOUNT_OF_TESTS = 3;// constant maximum number of exams grade that can be read per students.

struct studentType
{
	string first;// contains the first name of the student
	string last;// contains the last name of the student
	char grade;// contains the letter grade of the student
	int hw[AMOUNT_OF_HW];// list of assignment grades
	int exams[AMOUNT_OF_TESTS];//list of exam grades
};



int readFile(studentType[]);// declared function that returns the amount of students read from the file.

void outputStudentInfo(string, string, char, int[], int[]); // a declared function that  outputs the students in format.

string format(string);// a declared function that takes in a string and returns that string formatted. Capitalizes first letter and changes the rest to a lower case.

char computeGrade(int[], int[]);// a declared function that returns a letter grade.

int findStudent(studentType[], int, string);// a declared function that compares the last string parameter with all the last names in the list of students.



int main()
{
	// declared 2d arrays, variables, and strings.
	studentType student[MAX_STUDENTS];
	int numStudents;
	int counter=0;
	string search;


	// number of students read.

	
	numStudents = readFile(student);
	format(student[counter].first);
	// computing every students homeworks and exams grade. 
	for ( int i=0; i < numStudents; i++)
	{
		student[counter].grade;

		student[counter].grade=computeGrade(student[counter].hw,student[counter].exams);

		counter++;

	}


	// declared string search.



	/* prompting user to input a last name to search for a students in the file or input 'Quit' to terminate the program.
	if the last name that the user entered was found in the file, the program outputs the students information. */


	cout << "Enter a student's last name or enter quit: ";
	cin >> search;
	search= format(search);

	while (search!= "Quit")
	{
		int index;

		index= findStudent(student, numStudents, search);

		if (index==-1)
		{
			cout << "Student not found!" << endl;
		}

		else
		{
			outputStudentInfo(student[index].first, student[index].last, student[index].grade, student[index].hw, student[index].exams);
		}

		cout << "Enter a student's last name or enter quit: ";
		cin >> search;
		search= format(search);



	}




	return 0;

}

/* the following function contains a loop that keeps prompting the user to input a valid file and then another loop that reads whats in the file
 and assign it to the proper declared array and counts how many students it read in.*/

int  readFile( studentType student[])
{
	int counter=0;


	ifstream inFile;
	string filename;
	
	do
	{

		cout<< "Enter a filename: ";
		cin>> filename;

 		//filename.c_str() returns a C style string version
		inFile.open(filename.c_str());
		
	}
	while(!inFile.is_open());

	inFile>>student[counter].first;

	while(!inFile.eof())
	{
		
		inFile>> student[counter].last;
		

		student[counter].first= format(student[counter].first);
		student[counter].last= format(student[counter].last);

		for( int i=0; i< AMOUNT_OF_HW; i++)
		{
			inFile>> student[counter].hw[i];

		}

		for (int i=0; i < AMOUNT_OF_TESTS; i++)
		{
			inFile>> student[counter].exams[i];
		}

		counter++;

		inFile>> student[counter].first;
	}

	return counter;
}

/*the following function outputs students information after the user inputs a lastname of student that exists in the file.
It outputs the student's name, homework grade, exam grade, and overall letter grade.*/

void outputStudentInfo(string firstname, string lastname, char grade, int hw[], int exams[])
{
	cout << format(lastname)<< ", " << format(firstname)<< endl;
	cout <<"Assignment Grades"<< endl;

	for (int i=0; i < AMOUNT_OF_HW; i++)
	{
		cout << hw[i] <<" ";
	}

	cout << endl;

	cout << "Exam grades" << endl;

	for (int i=0; i < AMOUNT_OF_TESTS; i++)
	{
		cout << exams[i] << " ";
	}

	cout << endl;

	cout << "Letter Grade"<< endl;

	cout << grade << endl;
	
}

// the following function formats students first and last name when ever its called.

string format(string student)
{

	student[0]=toupper(student[0]);

	if(student.length()!=0)
	{
		for (int i= 1; i < student.length(); i++)
		{

			student[i]= tolower(student[i]);
		}

	}

	return student;

}

/* the following function calculates student grade by preforming a calculation of the avarage homework grade and exam grade and it calculates 
 the overall grade of each student and assign a proper letter grade.*/
char computeGrade(int hw[], int exams[])
{

	double hw_avarage=0;
	double exam_avarage=0;
	double avarage=0;
	double exam_total=0;
	double hw_total=0;
	int i=0;

	for (int i=0; i< AMOUNT_OF_TESTS; i++)
	{
		exam_total += exams[i];
	}

	exam_avarage= exam_total/AMOUNT_OF_TESTS;

	for (int i=0; i < AMOUNT_OF_HW; i++)
	{
		hw_total += hw[i];
	}

	hw_avarage= hw_total/AMOUNT_OF_HW;

	avarage= (exam_avarage + hw_avarage)/2;

	if( avarage >= 90)
	{
		return 'A';
	}

	else if (avarage >= 80 and avarage < 90)
	{
		return 'B';
	}

	else if (avarage >= 70 and avarage < 80)
	{
		return 'C';
	}

	else if (avarage >= 60 and avarage < 70)
	{
		return 'D';
	}

	else
	{
		return 'F';
	}

}

/* the following function searches and compare the last name of the student entered by the user. If the search was found it returns student info
 if not it returns -1, (student not found).*/

int findStudent(studentType student[], int numStudents, string lastname)
{

	bool found= false;
	int i = 0;


	for ( i=0; i < numStudents; i++)
	{

		if (student[i].last.compare(lastname)==0)
		{
			found= true;

			break;
		}

	}


	if(found)
	{
		return i;
	}

	else
	{
		return -1;
	}

	


}
