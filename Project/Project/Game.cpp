/*	Group Binary
	Kyle Steffa & Eric Tang
	CSE 240
	2nd Project Deliverable
*/

#include <iostream>
// Include fstream to import file reading functions.
#include <fstream>
// Include string to do string operations.
#include <string>

using namespace std;

class GameScore{
public:
	float gameplay, graphics, storyline;

	//display scores
	float results()
	{
		float result = (gameplay + graphics + storyline) / 3.0f;
		return result;
	}
	GameScore *next;
};
//Game class
class Game{
	public:
	string title, genre, console;
	float avgGameplay, avgGraphics, avgStoryline;
	GameScore* scores;
	Game *next;
} *head = NULL;

class ActionGame : public Game{

};

class RolePlayingGame : public Game{

};

class StrategyGame : public Game{

};

class SportGame : public Game{

};

// Forward Declarations
void ReadGameInfo();
void Display();
void ReadScore();
void Insert(string, string, string);
Game* Search(char*);

/*Main Method*/

void main()
{
	cout << "ReadGameInfo";
	ReadGameInfo();
	cout << "readScore";
	ReadScore();
	Display();
}

void Display(){
	Game* temp = head;
	while (temp != NULL){
		cout << temp->title << endl;
		cout << "Console: " << temp->console << endl;
		cout << "Genre: " << temp->genre << endl;
		cout << "Graphic: " << temp->scores->graphics << "\t";
		cout << "Gameplay: " << temp->scores->gameplay << "\t";
		cout << "Storyline: " << temp->scores->storyline << endl;
		cout << "Overall Score: " << temp->scores->results() << endl;
		temp = temp->next;
	}
}

void ReadGameInfo()
{
	string gName, gGenre, gConsole; //assign string variables
	ifstream Rgame; //assings a file input variable
	Rgame.open("game.csv"); //opens game.csv and assigns it to Rgame

	if (Rgame.is_open()) //Checks to see if file is open, if it isn't than it will say unable to open
	{
		getline(Rgame, gName, '\n'); //removes first line

		while (getline(Rgame, gName, ','))// keeps going while there is a value to get
		{
			getline(Rgame, gGenre, ',');
			getline(Rgame, gConsole, '\n');

			Insert(gName, gGenre, gConsole); //sends individual game info to Insert() to be placed in linklist
		}
		Rgame.close(); //close file
	}
	else cout << "Was unable to open file" << endl;
}

void Insert(string inName, string inGenre, string inConsole)
{
	Game *n = head, *prevn = NULL; //creates n (node pointer) looking at the head, and prevn  looking at the previous node before
	int namecomp;

	//Creates a new node
	Game* gm = new Game;
	gm->title = inName;
	gm->genre = inGenre;
	gm->console = inConsole;
	gm->next = NULL;

	if (head == NULL) //if list is empty
	{
		head = gm;
	}
	else //if list is not empty
	{
		while (n != NULL) //while there is a node
		{
			namecomp = inName.compare(n->title); //compares inputed game name with link list name (a < b = -1, b>a = 1)
			//already exsists, will not insert
			if (namecomp == 0)
			{
				cout << inName << " already exsists" << endl;
				return;
			}

			else if (namecomp < 0) //reached its insert point between pn and n
			{
				//goes at the head
				if ((n == head))
				{
					gm->next = head;
					head = gm;
					return;

				}
				else
				{
					//goes some where in the middle
					gm->next = n;
					prevn->next = gm;
					return;
				}
			}
			else //next node
			{
				prevn = n; //assigns previous node
				n = n->next; //moves current node to next node
			}

		}
		//went through while and did not find a place to go, so place at end
		prevn->next = gm;
	}
}

// Prints out the name and scores for each game.
void ReadScore()
{
	// Declare object to read file. Enter the name of the file.csv you want to read from.
	ifstream file("score.csv");
	// These strings are declared to store the parsed data. There should be one variable per column of data
	string Name, Graphic, Gameplay, Storyline;
	float GraphicRating, GameplayRating, StorylineRating,totalGraphic, totalGameplay, totalStoryline;

	// If the file is readable
	if (file.is_open())
	{
		// Keep reading until the delimeter. In this case, it is '/'
		while (getline(file, Name, ','))
		{
			getline(file, Graphic, ',');
			getline(file, Gameplay, ',');
			getline(file, Storyline, '\n');


			// Convert string to an integer
			GraphicRating = stof(Graphic);
			totalGraphic = GraphicRating;
			GameplayRating = stof(Gameplay);
			totalGameplay = GameplayRating;
			StorylineRating = stof(Storyline);
			totalStoryline = StorylineRating;

			char * Namep = new char[Name.length() + 1];
			Namep[Name.length() + 1] = '\0';
			strcpy(Namep, Name.c_str());

			Game* currentGame = Search(Namep);
			//Game must exist in the list in order for there to be scores.
			if (currentGame != NULL){
				int counter = 1;
				while (currentGame->scores != NULL){
					counter++;
					totalGraphic += currentGame->scores->graphics;
					totalGameplay += currentGame->scores->gameplay;
					totalStoryline += currentGame->scores->storyline;
					currentGame->scores = currentGame->scores->next;
				}
				currentGame->scores = new GameScore();
				currentGame->scores->gameplay = GameplayRating;
				currentGame->scores->graphics = GraphicRating;
				currentGame->scores->storyline = StorylineRating;

				//compute average using counter
				currentGame->avgGameplay = totalGameplay / counter;
				currentGame->avgGraphics = totalGraphic / counter;
				currentGame->avgStoryline = totalStoryline / counter;

				//Print out name and scores of each game
				cout << "Name: " << Name << endl;
				cout << "Graphic: " << GraphicRating << endl;
				cout << "Gameplay: " << GameplayRating << endl;
				cout << "Storyline: " << StorylineRating << "\n" << endl;
			}
		}
		//Close a file when done reading.
		file.close();
	}
	else
		cout << "Unable to open file" << endl;
	// Consumes extra newline at the end
	getline(file, Name);
};

Game* Search(char* name){
	Game* temp = head;
	while (temp != NULL){
		if (temp->title == name){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}