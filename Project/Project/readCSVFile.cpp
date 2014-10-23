/*
// Written by Garrett Gutierrez
// For use in CSE240

#include <iostream>
// Include fstream to import file reading functions.
#include <fstream>
// Include string to do string operations.
#include <string>

using namespace std;

// Forward Declarations

void parseMethod1();
void parseMethod2();

int main()
{
	char choice;
	do{
		cout << "Select parsing method" << endl;
		cout << "(1) For using getline with delimeters" << endl;
		cout << "(2) For using line parser" << endl;
		cout << "(0) To quit" << endl;

		choice = getc(stdin);
		cout << "\n";
		if (choice == '1')
			parseMethod1();
		else if (choice == '2')
			parseMethod2();
		else
		{
			cout << "Incorrect input\n" << endl;
			cin.ignore();
		}
			
	} while (choice != '0');
	return 0;
}

// This function uses multiple get lines to read from the file
void parseMethod1()
{
	// Declare object to read file. Enter the name of the file.csv you want to read from.
	ifstream file("parsing.csv");
	// These strings are declared to store the parsed data. There should be one variable per column of data
	string firstName, lastName, eyeColor, height, weight, DOB;
	int heightValue;
	float weightValue;

	// If the file is readable
	if (file.is_open())
	{
		// Keep reading until the delimeter. In this case, it is '/'
		while (getline(file, firstName, ','))
		{
			getline(file, lastName, ',');
			getline(file, eyeColor, ',');
			getline(file, height, ',');
			getline(file, weight, ',');
			getline(file, DOB, ',');

			// Convert string to an integer
			heightValue = stoi(height);
			// Convert string to a float
			weightValue = stof(weight);

			cout << firstName << ' ' << lastName << endl;
			cout << "Eye color: " << eyeColor << endl;
			cout << "Height in inches: " << heightValue << endl;
			cout << "Weight in lbs: " << weightValue << endl;
			cout << "Date of Birth (DD/MM/YYYY): " << DOB << "\n" << endl;

		}
		// Always close a file when done reading.
		file.close();
	}
	else
		cout << "Unable to open file" << endl;
	// Consumes extra newline at the end
	cin.ignore();
};

// This method gets an entire row from the file, then parses it for the desired information.
void parseMethod2()
{
	// Declare object to read file. Enter the name of the file.csv you want to read from.
	ifstream file("parsing.csv");
	// These strings are declared to store the parsed data. There should be one variable per column of data
	string input,firstName, lastName, eyeColor, height, weight, DOB;
	// Specify the delimeter for parsing
	string delimeter = ",";
	int heightValue;
	float weightValue;

	// If the file is readable
	if (file.is_open())
	{
		// Keep reading until the end of line.
		while (getline(file, input, '\n'))
		{
			// Read the input string until the delimeter is found.
			firstName = input.substr(0, input.find(delimeter));
			input.erase(0, input.find(delimeter) + delimeter.length());
			// Erase the parsed input so that it is not read again

			lastName = input.substr(0, input.find(delimeter));
			input.erase(0, input.find(delimeter) + delimeter.length());

			eyeColor = input.substr(0, input.find(delimeter));
			input.erase(0, input.find(delimeter) + delimeter.length());

			height = input.substr(0, input.find(delimeter));
			input.erase(0, input.find(delimeter) + delimeter.length());

			weight= input.substr(0, input.find(delimeter));
			input.erase(0, input.find(delimeter) + delimeter.length());

			DOB = input.substr(0, input.find(delimeter));
			input.erase(0, input.find(delimeter) + delimeter.length());

			// Convert string to an integer
			heightValue = stoi(height);
			// Convert string to a float
			weightValue = stof(weight);

			cout << firstName << ' ' << lastName << endl;
			cout << "Eye color: " << eyeColor << endl;
			cout << "Height in inches: " << heightValue << endl;
			cout << "Weight in lbs: " << weightValue << endl;
			cout << "Date of Birth (DD/MM/YYYY): " << DOB << "\n" << endl;

		}
		// Always close a file when done reading.
		file.close();
	}
	else
		cout << "Unable to open file" << endl;
	// Consumes extra newline character at end
	cin.ignore();
};
*/