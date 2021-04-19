#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <climits>
#include <string>

/* Program name: jbtictac.cpp
*  Author: John Doe
*  Date last updated: 5/1/2017
* Purpose: Play the game of Tic-Tac-Toe
*/

using namespace std;

void inputBallot(int list[], int listSize, int& voteSum, string& temp);
void calculateBallot(int listNums[], int listSizeN, double listAvg[], int listSizeA, int& voteSum);
void outputBallot(int listNums[], int listSizeN, double listAvg[], int listSizeA, int& voteSum, string winner);
const int ARRAY_SIZE = 10;

int main() {
	
	int ballotNum[ARRAY_SIZE];
	double ballotAvg[ARRAY_SIZE];
	int sum;
	string winner;

	inputBallot(ballotNum, ARRAY_SIZE, sum, winner);
	calculateBallot(ballotNum, ARRAY_SIZE, ballotAvg, ARRAY_SIZE, sum);
	outputBallot(ballotNum, ARRAY_SIZE, ballotAvg, ARRAY_SIZE, sum, winner);

	return 0;
}

void inputBallot(int list[], int listSize, int& voteSum, string& temp)
{
	string name;
	int tempTwo = 0;
	int voteCount;
	voteSum = 0;

	ifstream in;
	in.open("ballot.txt");

	for (int i = 0; !in.eof(); i++)
	{
		in >> name;
		cout << "Enter the number of votes received by " << name << ": ";
		cin >> voteCount;
		cout << endl;

		while (!cin || voteCount < 0)
		{
			if (!cin)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "That is not a number! Please try again." << endl;
				cout << "Enter the number of votes received by " << name << ": ";
				cin >> voteCount;
				cout << endl;
			}
			else
			{
				cout << "The number of votes cannot be less than 0. Please try again." << endl;
				cout << "Enter the number of votes received by " << name << ": ";
				cin >> voteCount;
				cout << endl;
			}
		}

		while (voteCount > tempTwo)
		{
			tempTwo = voteCount;
			temp = name;
		}
		
		voteSum = voteSum + voteCount;
		list[i] = voteCount;
	}

	in.close();

}


void calculateBallot(int listNums[], int listSizeN, double listAvg[], int listSizeA, int& voteSum)
{
	double temp = 0;

	for (int i = 0; i < listSizeN; i++)
	{
		if (listNums[i] >= 0) 
		{
			temp = ((listNums[i] * 1.0)/ voteSum) * 100.0;
			listAvg[i] = temp;
		}
		else
		{
			break;
		}
	}

}

void outputBallot(int listNums[], int listSizeN, double listAvg[], int listSizeA, int& voteSum, string winner)
{
	string name;

	cout << showpoint << setprecision(2) << fixed;

	cout << left << setw(10) << "Candidate" << right << "   " << setw(10) << "Votes Received" << "   " << setw(15) << "% of Total Votes" << endl;

	ifstream in;
	in.open("ballot.txt");

	for (int i = 0; !in.eof(); i++)
	{
		in >> name;
		cout << left << setw(10) << name << right << "   " << setw(10) << listNums[i] << "   " << setw(15) << listAvg[i] << endl;
	}

	in.close();

	cout << left;
	cout << setw(19) << "Total" << voteSum << endl;
	cout << "The Winner of the Election is " << winner << "." << endl;
}