#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
//Bowling Score assignment by Matthew Kalinin
using namespace std;
//string for the input file, integers for rows and columns, and for how many items in the text file
const string inputFile = "BowlingScores.txt";
const int NamesAndScores = 60;
const int numRows = 5;
const int numCols = 10;
ifstream inputStream;

//function takes in data from file and prints it out
void GetBowlingData(string Names[NamesAndScores], int Scores[numCols][numRows]) {
	//if file isnt found it will display so
	if (!inputStream) {
		cout << "File not found";
	}
	//for loop for taking in data
	for (int index = 0; index < 50; index++) {
		inputStream >> Names[index];

	}
	for (int index = 0; index < 50; index++) {
		cout << Names[index] << " \n";
	}
	//for loop for taking in and displaying integers from parallel array
	for (int row = 0; row < numRows; row++)
	{
		cout << endl;
		for (int col = 0; col < numCols; col++)
			cout << Scores[col][row] << " ";
		cout << endl;
	}

}

//function takes in scores from a parallel array and averages the scores
void GetAverageScore(int Scores[numCols][numRows]) {
	//for loop initializes the columns and rows and averages it
	for (int col = 0; col < numCols; col++)
	{
		int sum = 0;
		int average = 0;
		for (int row = 0; row < numRows; row++)
			sum = sum + Scores[col][row];
		average = sum / 5;
		cout << "Average of bowler #" << col + 1 << " = " << average << endl;
	}
}

//prints names, scores, and averages out
void PrettyPrintResults(string Names[NamesAndScores], int Scores[numCols][numRows]) {
	for (int index = 0; index < 50; index++) {
		inputStream >> Names[index];

	}
	for (int index = 0; index < 50; index++) {
		cout << Names[index] << " \n";
	}

	for (int row = 0; row < numRows; row++)
	{
		cout << endl;
		for (int col = 0; col < numCols; col++)
			cout << Scores[col][row] << " ";
		cout << endl;
	}

	for (int col = 0; col < numCols; col++)
	{
		int sum = 0;
		int average = 0;
		for (int row = 0; row < numRows; row++)
			sum = sum + Scores[col][row];
		average = sum / 5;
		cout << "Average of bowler #" << col + 1 << " = " << average << endl;
	}
}

int main()
{
	//struct for bowler names, their scores, and average score
	struct bowling {
		string bowlerName;
		int bowlerScore[5];
		int averageBowlScore;
	};
	//array that uses struct variables to list bowler information
	bowling bowlArray[10] = {
		{"JoJo", 185, 203, 177, 45, 65, 135},
		{"BBilly", 180, 90, 195, 293, 45, 160},
		{"ACooper", 178, 281, 111, 90, 343, 200},
		{"LGupta", 192, 283, 30, 169, 2, 135},
		{"RBlake", 23, 45, 96, 38, 76, 55},
		{"McClark", 160, 185, 145, 139, 456, 217},
		{"Sunny", 77, 31, 52, 74, 23, 51},
		{"Sammy", 93, 94, 289, 277, 89, 168},
		{"AliceB", 279, 185, 128, 93, 11, 139},
		{"MikeSmith", 85, 72, 49, 75, 25, 61},

	};

	inputStream.open(inputFile);
	cout << setw(60) << setfill('.') << '\n' << setw(45) << "Welcome to my Bowling Score Program" << setw(15) << '\n' << setw(60) << '\n' << endl;

	string bowlerNames[NamesAndScores];
	//parallel array with scores, could not get input and delimiters to seperate data in text file
	int bowlerScores[numCols][numRows] = {
	{185, 203, 177, 45, 65},
	{180, 90, 195, 293, 45},
	{178, 281, 111, 90, 343},
	{192, 283, 30, 169, 2},
	{23, 45, 96, 38, 76},
	{160, 185, 145, 139, 456},
	{77, 31, 52, 74, 23},
	{93, 94, 289, 277, 89},
	{279, 185, 128, 93, 11},
	{85, 72, 49, 75, 25}
	};

	//calling the functions
	GetBowlingData(bowlerNames, bowlerScores);
	GetAverageScore(bowlerScores);
	PrettyPrintResults(bowlerNames, bowlerScores);

	inputStream.close();
	return 0;
}