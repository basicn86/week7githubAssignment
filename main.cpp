//Nedim Basic
//12th of December, 2021
//Week 7 programming assignment

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//declare constants
const int max_bowlers = 10;
const int max_scores = 5;


//bowler struct
//Contains the name, scores, and average score of the bowler
struct Bowler {
	string name;
	int scores[max_scores];
	int avgScore;
};

//This function reads the bowler scores and bowlers names from a file and stores them in a struct
//The function will return FALSE if the file fails to open
//The function will return TRUE if the function successfully reachs the end of its operation
bool GetBowlingData(const char* fileName, Bowler* bowlers) {
	ifstream myFile;
	myFile.open(fileName); //open the file
	if (!myFile) return false; //returns false if the file fails to open

	//The outer for loop traverses through each bowler
	for (int i = 0; i < max_bowlers; i++) {
		myFile >> bowlers[i].name; //read the name from the file and store it into the bowler name array
		//This inner for loop traverses through each bowler's score in the file, and stores it into the score array of that bowler
		for (int j = 0; j < max_scores; j++) {
			myFile >> bowlers[i].scores[j]; //read the score from the file and store it into the bowler score array
		}
	}

	//Return true if the operation is a success
	return true;
}

void GetAverageScore(Bowler* bowlers) {
	int total = 0;
	//The outer for loop traverses through each bowler
	for (int i = 0; i < max_bowlers; i++) {
		//This inner for loop traverses through each bowler's scores, and add each score into an accumulative
		//total variable. This total variable will then be divided by the maximum amount of scores available.
		for (int j = 0; j < max_scores; j++) {
			total += bowlers[i].scores[j];
		}
		//Get the average score by dividing the total score by the maximum amount of scores,
		//then store the result of the calculation in the bowler's average score variable.
		bowlers[i].avgScore = total / max_scores;
		total = 0; //Reset the total to 0, so that the variable is ready to use for the next bowler;
	}
}

void PrettyPrintResults(Bowler* bowlers) {
	//For loop that traverses each bowler
	for (int i = 0; i < max_bowlers; i++) {
		cout << "BOWLER NAME: " << bowlers[i].name << endl; //display the bowler name
		cout << "SCORES: "; //display the scores by the bowler
		//This inner for loop traverses through all the scores the bowler has made,
		//then it prints out each score in the console, separated by a space.
		for (int j = 0; j < max_scores; j++) {
			cout << bowlers[i].scores[j] << " ";
		}
		cout << endl;
		cout << "AVERAGE: " << bowlers[i].avgScore << endl << endl; //display the average count of scores
	}
};

int main() {
	//declare variables
	Bowler bowlers[max_bowlers];

	//Try to open the file, if the file does not open, end the program and display that the file failed to open
	if (!GetBowlingData("BowlingScores.txt", bowlers)) {
		cout << "The file failed to open" << endl;
		return 1;
	}

	GetAverageScore(bowlers); //call the GetAverageScore function

	PrettyPrintResults(bowlers); //call the PrettyPrintResults function
}