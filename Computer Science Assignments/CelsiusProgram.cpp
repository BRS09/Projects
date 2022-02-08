#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <climits>

/* Program name: main.cpp
*  Author: Brayden Scott
*  Date last updated: 3/5/2021
* Purpose: Converts the celsius range to fahrenheit and newton, the range increases by a set increment. Both the range and increment are determined by the user. The program outputs this data in a table to a file.
*/

using namespace std;

int main(){

  double userIncrement, i, lowerInput, upperInput;    //userIncrement - stores the increment chosen. i - used to stop for loop. lowerInput - lower value for conversion. upperInput - upper value for conversion.
  double fahreinFormula, newtFormula;   //fahreinFormula - formula used to convert celsius to fahrenheit. newtFormula - formula used to convert celsius to newton.

  ofstream out;   //Declares the output to file statement.
  out.open("conversion_table.txt");   //Opens the file to be written to.

  cout << "Enter the lower value for the conversion table: ";   //Asks the user to input a lower value for conversion.
  cin >> lowerInput;    //Collects the input and stores it in the lowerInput variable.
  cout << endl;   //Ends the line.

  while(!cin){    //While loop that is entered if lowerInput has put cin into a failstate.
    cin.clear();    //Restores the input stream to a correct state.
    cin.ignore(INT_MAX, '\n');  //Ignores the max amount of characters until it reaches a new line.
    cout << "You have not entered a number. Try again." << endl;    //Alerts the user that they have not entered a number and to try again.
    cout << "Enter the lower value for the conversion table: ";   //Asks the user for a lower value for conversion.
    cin >> lowerInput;    //Collects the input and stores it in the lowerInput variable.
    cout << endl;   //Ends the line.
  }

  cout << "Enter the upper value for the conversion table: ";   //Asks the user for a upper value for conversion.
  cin >> upperInput;    //Collects the input and stores it in the upperInput variable.
  cout << endl;   //Ends the line.

  while(upperInput < lowerInput){   //While loop that is entered if the upperInput is less than the lowerInput.
    cin.clear();    //Restores the input stream to a correct state.
    cin.ignore(INT_MAX, '\n');    //Ignores the max amount of characters until it reaches a new line.
    cout << "Your upper value is less than your lower value. Try again." << endl;   //Alerts the user that their upperInput is less than their lowerInput.
    cout << "Enter the upper value for the conversion table: ";   //Asks the user to input a upper value again.
    cin >> upperInput;    //Collects the input and stores it in the upperInput variable.
    cout << endl;   //Ends the line.
  }

  cout << "What do you want to use for your increment: ";   //Output that asks the user an increment for the conversion.
  cin >> userIncrement;   //Collects the input and stores the userIncrement.
  cout << endl;   //Ends the line.

  while(userIncrement < 0){   //While loop that is entered if the userIncrement is less than 0.
    cin.clear();    ////Restores the input stream to a correct state.
    cin.ignore(INT_MAX, '\n');    //Ignores the max amount of characters until it reaches a new line.
    cout << "The increment must be greater than 0." << endl;    //Output tells the user that their increment needs to be greater than 0.
    cout << "What do you want to use for your increment: ";   //Asks the user for an increment again.
    cin >> userIncrement;   //Collects the input and stores the userIncrement.
    cout << endl;   //Ends the line.
  }
  /**********************************************************************************************
  The code below creates the header for the table in the text file. !Notice! out instead of cout.
  **********************************************************************************************/
  out << setprecision(2) << fixed << showpoint << left;   //Sets the decimal place of output to 2, fixes it, and shows the point.
  out << setw(10) << "C" << setw(10) << "F" << setw(10) << "N" << endl;
  out << setw(30) << setfill('_') << '_' << endl;
  out << setfill(' ');

  for(i += lowerInput; i <= upperInput && i >= lowerInput; i += userIncrement){   //For loop that is entered if i is less than or equal to upperInput and i is greater than or equal to lowerInput. i is set to i = i + lowerInput so that the loop begins at the specified lower value. And is incremented by i = i + userIncrement to increment through the conversion limit set by the user.
    fahreinFormula = (9 * i / 5) + 32;    //fahreinFormula - converts celsius to fahreinheit.
    newtFormula = i * 0.3300;   //newtFormula - converts celsius to newton.
    out << setw(10) << i << setw(10) << fahreinFormula << setw(10) << newtFormula << endl;    //Creates the rows of the table by outputting the conversions using setw() before each output.
  }

  return 0;   //Program ends.

}
