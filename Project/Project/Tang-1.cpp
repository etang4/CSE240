
#include <iostream>
// Include fstream to import file reading functions.
#include <fstream>
// Include string to do string operations.
#include <string>

using namespace std;

// Forward Declarations

void ReadScore();

int main()
{
	cout << "ReadScore...\n " << endl;
	ReadScore();
	cout << "Done\n " << endl;
	return 0;
}

// This function uses multiple get lines to read from the file
void ReadScore()
{
	// Declare object to read file. Enter the name of the file.csv you want to read from.
	ifstream file("score.csv");
	// These strings are declared to store the parsed data. There should be one variable per column of data
	string Name, Graphic, Gameplay, Storyline;
	int GraphicRating, GameplayRating, StorylineRating;

	// If the file is readable
	if (file.is_open())
	{
		//Consume line describing data
		getline(file, Name);
		// Keep reading until the delimeter. In this case, it is '/'
		while (getline(file, Name, ','))
		{
			getline(file, Graphic, ',');
			getline(file, Gameplay, ',');
			getline(file, Storyline, '\n');


			// Convert string to an integer
			GraphicRating = stoi(Graphic);
			GameplayRating = stoi(Gameplay);
			StorylineRating = stoi(Storyline);

			cout << "Name: " << Name << endl;
			cout << "Graphic: " << GraphicRating << endl;
			cout << "Gameplay: " << GameplayRating << endl;
			cout << "Storyline: " << StorylineRating << "\n" << endl;

		}
		// Always close a file when done reading.
		file.close();
	}
	else
		cout << "Unable to open file" << endl;
	// Consumes extra newline at the end
	getline(file, Name);
};