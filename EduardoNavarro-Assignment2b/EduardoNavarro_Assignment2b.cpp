// Assignment 2B
// Written by Eduardo Navarro
// Program to read file named Grades.txt and show that it is reading the file, display the contents of such file and display the student and class statistics.


#include <iostream>
#include <fstream>
#include<string>
#include<iomanip>
#include<math.h>



using namespace std;

int main()
{
	ifstream infile; // Stream class to read from files
	infile.open("Grades.txt"); // Open file

	string Name;
	string lines;
	float Test1;
	float Test2;
	float Total_Points = 0;
	float Numeric_Grade = 0;
	char Letter_Grade = 'A';
	int Number = 0;
	int Average; // = (Total_Test1 + Total_Test2) / 2;
	int number_of_students = 0;
	float Total_Test1 = 0;
	float Total_Test2 = 0;
	float sum1 = 0;
	float sum2 = 0;
	
	setprecision(2);

	
	if (infile.is_open()) // check to see if file was able to open and be read.
	{
		cout << "infile is open" << endl;
	}
	else 
	{
		cout << "infile is NOT found" << endl;
	}

	
	cout << "\n";
	cout << "\n";

	while (infile >> Name >> Test1 >> Test2) // Reading from file the name, the test 1 score and the test 2 score
	{

		cout << setw(15) << left << Name + " " << setw(15) << left << Test1 << setw(15) << left << Test2 << endl; // Formating a table
		number_of_students++; // Calculates the number of students is reading from the file line by line
		sum1 += Test1; // adds the test1 for every entry
		//cout << Total_Test1 << sum1 << endl;
		sum2 += Test2; // adds the test2 for every entry
		//cout << Total_Test2 << sum2 << endl;
	}
	{
		infile.clear(); // Trying to clear the file so I can read the information again
		infile.seekg(0, infile.beg); // Setting the coursor back at the beggining of the file
		cout << "\n";
		cout << "STUDENT STATISTICS" << endl; //About to display the student stats
		cout << "\n";
		cout << setw(15) << left << "Name" << setw(15) << left << "Total Points" << setw(15) << left << "Numeric Grade" << setw(15) << left << "Letter Grade" << endl; // Formating a table
		
		
		while (infile >> Name >> Test1 >> Test2)

		{
			Total_Points = Test1 + Test2;
			Numeric_Grade = Total_Points / 2;
						

				if (Numeric_Grade >= 90)
				{
					Letter_Grade = 'A';
				}
				else if (Numeric_Grade >= 80 && Numeric_Grade <= 89.99)
				{
					Letter_Grade = 'B';
				}
				else if (Numeric_Grade >= 70 && Numeric_Grade <= 79.99)
				{
					Letter_Grade = 'C';
				}
				else if (Numeric_Grade >= 60 && Numeric_Grade <= 69.99)
				{
					Letter_Grade = 'D';
				}
				else if (Numeric_Grade <= 59.99)
				{
					Letter_Grade = 'F';
				}
			cout << setw(15) << left << Name + " " << setw(15) << left << Test1 + Test2 << setw(15) << left << Numeric_Grade << setw(15) << left << Letter_Grade << endl; // Formating a table
				
		}
		{
			cout << "\n";
			cout << "\n";
			cout << "CLASS STATISTICS" << endl;
			cout << " Num of students: " << number_of_students << endl; 	// Count how many students in file.
			cout << " Average is " << setw(15) << right << (sum1 + sum2) / number_of_students / 2 << endl; // average of both test for all students in file
			cout << " Maximum is " << setw(15) << right << "Maximum" << endl; // Maximum absolute value for all tests in file
			cout << " Minimum is " << setw(15) << right << "Minumum" << endl; // Minimum absolute value for all tests in file

		}
	}

	system("pause");

	return 0;

	infile.close();
}