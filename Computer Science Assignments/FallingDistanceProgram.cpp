#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>

/* Program name: main.cpp
*  Author: Brayden
*  Date last updated: 3/28/2021
* Purpose: Calculates the distance of a falling object based on the time the user entered and outputs the results in a table.
*/

using namespace std;

double fallingDistance(double);        //function prototype

int main()
{
	double fallingTime;     //variable that stores the falling time entered by the user.
	double valueHolder;     //holds the value calculated from the function.

	cout << "Please enter the total falling time: ";        //Asks the user to input the total falling time of the object.
	cin >> fallingTime;     //stores the input in the fallingTime variable.
	cout << endl;       //ends the current line.

	while (!cin || fallingTime < 0)     //while loop that is entered if !cin or fallingTime is less than 0.
	{
		if (!cin)       //selection structure executes when !cin.
		{
			cin.clear();        //clears cin.
			cin.ignore(INT_MAX, '\n');      //ignores the next value until the next new line.

			cout << "That is not a number! Please try again." << endl;      //Alerts the user that they did not enter a number.
			cout << "Please enter the total falling time: ";        //Asks the user for additional input.
			cin >> fallingTime;     //Stores the new fallingTime.
			cout << endl;       //Ends this line.
		}
		else
		{
			cout << "Your time should be greater than 0." << endl;      //Alerts the user that their fallingTime should be greater than 0.
			cout << "Please enter the total falling time: ";        //Asks the user for additional input.
			cin >> fallingTime;     //Stores the new fallingTime.
			cout << endl;       //Ends this line.
		}
	}

	cout << setprecision(2) << showpoint << fixed << left;      //sets the decimal place to 2, shows the point, fixes it, and aligns it left.
	cout << setw(15) << "Time" << setw(15) << "Distance" << endl;       //Outputs the header of the table.
	cout << setw(30) << setfill('*') << "*" << endl;        //separates the header from the data values.
	cout << setfill(' ');       //fills the space between time and distance in the header with whitespace.

	for (double t = 0; t <= fallingTime; t += 5)     //for loop that is executed when t is less than fallingTime.
	{
		if (t > 0 && fallingTime - t < 5 && fallingTime - t > 0)       //if statement that executes when fallingTime is not incrementable by 5 because the user entered say 23 or 49.
		{
			valueHolder = fallingDistance(t);       //calls fallingDistance to calculate the falling distance of t's current value.

			cout << setw(15) << t << setw(15) << valueHolder << endl;   //Outputs the values in the table.

			int lastIncrement = fallingTime - t;        //variable lastIncrement is calculated by subtracting t from fallingTime. 23 - 20 = 3 for example.
			t += lastIncrement;     //adds lastIncrement to the current value of t. 20 + 3 = 23 for example.

			valueHolder = fallingDistance(t);       //calls the function again to pass 23 into the calculation.

			cout << setw(15) << t << setw(15) << valueHolder << endl;       //outputs the last values of time and distance.
		}
		else        //statements executed when t is 0 or fallingTime - t is not less than 5 but greater than 0.
		{
			valueHolder = fallingDistance(t);       //calls the function for calculations and stores it in valueHolder.

			cout << setw(15) << t << setw(15) << valueHolder << endl;       //outputs the values, time and distance.
		}


	}

	return 0;
}

double fallingDistance(double fallingTime)     //function that calculates the falling distance with fallingTime as its parameter.
{
	double totalDistanceFallen = 1.0 / 2.0 * 9.8 * pow(fallingTime, 2);     //variable that stores the calculations of the distance fallen.

	return totalDistanceFallen;     //returns the totalDistanceFallen
}
