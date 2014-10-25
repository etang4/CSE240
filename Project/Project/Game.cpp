/*	Group Binary
	Matt Kim, Kyle Steffa & Eric Tang
	CSE 240
	1st Project Deliverable
*/

#include <iostream>
// Include fstream to import file reading functions.
#include <fstream>
// Include string to do string operations.
#include <string>


using namespace std;

// Forward Declarations
void ReadGameInfo();
void ReadScore();

//Game class
class Game{
	int gameplay, graphics, storyline;
	//Returns overall score of game.
	float results()
	{
		float result = (gameplay + graphics + storyline) / 3.0f;
		return result;
	}
	Game *next;
};


/*Main Method*/

void main()
{
	cout << "ReadGameInfo";
	ReadGameInfo();
	cout << "readScore";
	ReadScore();
}

//Read game information
void ReadGameInfo()
{
	string gName, gGenre, gConsole; //assign string variables
	ifstream file("game.csv");//opens game.csv and assigns it to Rgame

	if (file.is_open()) //Checks to see if file is open, if it isn't than it will say unable to open
	{
		//Consume extra line describing data in .csv file
		getline(file, gName);
		while (getline(file, gName, ','))// keeps going while there is a value to get
		{
			getline(file, gGenre, ',');
			getline(file, gConsole, '\n');

			//Prints out name, genre and console of the game.
			cout << "Name: " << gName << endl;
			cout << "Genre: " << gGenre << endl;
			cout << "Console: " << gConsole << "\n" << endl;
		}
		file.close(); //close file
	}
	else cout << "Was unable to open file" << endl;
}

// Prints out the name and scores for each game.
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
		//Consume extra line describing data in .csv file
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

			//Print out name and scores of each game
			cout << "Name: " << Name << endl;
			cout << "Graphic: " << GraphicRating << endl;
			cout << "Gameplay: " << GameplayRating << endl;
			cout << "Storyline: " << StorylineRating << "\n" << endl;

		}
		//Close a file when done reading.
		file.close();
	}
	else
		cout << "Unable to open file" << endl;
	// Consumes extra newline at the end
	getline(file, Name);
};