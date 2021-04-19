#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <climits>
#include <string>

/* Program name: main.cpp
*  Author: Brayden Scott
*  Date last updated: 4/18/2021
* Purpose: Asks the user for the number of votes received during a ballot, totals the votes, and then finds the percentage each candidate had of the ballot.
*/

using namespace std;

//function prototypes and array size constant.
void inputBallot(int list[], int listSize, int& voteSum, string& temp);
void calculateBallot(int listNums[], int listSizeN, double listAvg[], int listSizeA, int& voteSum);
void outputBallot(int listNums[], int listSizeN, double listAvg[], int listSizeA, int& voteSum, string winner);
const int ARRAY_SIZE = 10;

int main() {
	
	//declares the arrays that hold the votes and percentages, as well as the sum of the votes and winner of the ballot.
	int ballotNum[ARRAY_SIZE];
	double ballotAvg[ARRAY_SIZE];
	int sum;
	string winner;
    
    //function calls.
	inputBallot(ballotNum, ARRAY_SIZE, sum, winner);
	calculateBallot(ballotNum, ARRAY_SIZE, ballotAvg, ARRAY_SIZE, sum);
	outputBallot(ballotNum, ARRAY_SIZE, ballotAvg, ARRAY_SIZE, sum, winner);

	return 0;
}

//void function that gathers input from the user and stores it in the ballotNum array. Also finds the winner and totals the votes in the array.
void inputBallot(int list[], int listSize, int& voteSum, string& temp)
{
    //name stores the winner, tempTwo stores the vote count of the winner, voteCount stores the number of votes for a candidate, and voteSum is used to find the total number of votes.
	string name;
	int tempTwo = 0;
	int voteCount;
	voteSum = 0;
    
    //declares and opens the file to read.
	ifstream in;
	in.open("ballot.txt");
    
    //for loop runs until the end of the file.
	for (int i = 0; !in.eof(); i++)
	{
	    //collects the first name from the file and asks how many votes were received by the candidate.
		in >> name;
		cout << "Enter the number of votes received by " << name << ": ";
		cin >> voteCount;
		cout << endl;
        
        //input validation loop that checks if the input was a number and if it is greater than -1.
		while (!cin || voteCount < 0)
		{
		    //checks if the input is not a number.
			if (!cin)
			{
			    //clears and ignores the next characters until a new line is reached and asks for additional input.
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "That is not a number! Please try again." << endl;
				cout << "Enter the number of votes received by " << name << ": ";
				cin >> voteCount;
				cout << endl;
			}
			//else statement that reminds the user that the votes cannot be less than 0.
			else
			{
				cout << "The number of votes cannot be less than 0. Please try again." << endl;
				cout << "Enter the number of votes received by " << name << ": ";
				cin >> voteCount;
				cout << endl;
			}
		}
        
        //while voteCount is greater than tempTwo, stores voteCount in tempTwo and store the winners name in temp.
		while (voteCount > tempTwo)
		{
			tempTwo = voteCount;
			temp = name;
		}
		
		//stores the sum by adding voteCount to voteSum.
		voteSum = voteSum + voteCount;
		//stores the voteCount in the i element of the array.
		list[i] = voteCount;
	}
    //closes the file.
	in.close();

}


//void function that calculates the percentage the candidate has of the total votes.
void calculateBallot(int listNums[], int listSizeN, double listAvg[], int listSizeA, int& voteSum)
{
    //used as a holder until temp is assigned to the array listAvg.
	double temp = 0;

    //for loop used to calculate and store the percentages.
	for (int i = 0; i < listSizeN; i++)
	{
	    //if the element in listNums is greater than or equal to 0, calculate and store the value.
		if (listNums[i] >= 0) 
		{
			temp = ((listNums[i] * 1.0)/ voteSum) * 100.0;
			listAvg[i] = temp;
		}
		//exit the loop if there are extra unused elements.
		else
		{
			break;
		}
	}

}

//void function that outputs the results to the user.
void outputBallot(int listNums[], int listSizeN, double listAvg[], int listSizeA, int& voteSum, string winner)
{
    //variable used to output the names in the file.
	string name;

	cout << showpoint << setprecision(2) << fixed;
    
    //header of the table.
	cout << left << setw(10) << "Candidate" << right << "   " << setw(10) << "Votes Received" << "   " << setw(15) << "% of Total Votes" << endl;
    
    //opens the file ballot.txt for output.
	ifstream in;
	in.open("ballot.txt");
	
    //for loop used to output the name, amount of votes, and percentage of votes of the candidates.
	for (int i = 0; !in.eof(); i++)
	{
		in >> name;
		cout << left << setw(10) << name << right << "   " << setw(10) << listNums[i] << "   " << setw(15) << listAvg[i] << endl;
	}
    //closes the file.
	in.close();
    
    //outputs the total number of votes and the winner of the election.
	cout << left;
	cout << setw(19) << "Total" << voteSum << endl;
	cout << "The Winner of the Election is " << winner << "." << endl;
}
