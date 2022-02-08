#include <iostream>
#include <climits>
#include <cmath>
#include <string>

/* Program name: main.cpp
*  Author: Brayden Scott
*  Date last updated: 4/19/2021
* Purpose: Takes temperature value for the months of the year from the user and calculates the average high and low temperatures. It also finds the highest temperature and lowest temperature of the year, and outputs all of this back to the user.
*/

using namespace std;

//constants, ROW is the number of rows for the 2D array, NUM_MONTHS is the number of rows for the months array, and months holds the months of the year.
const int ROW = 12;
const int NUM_MONTHS = 12;
const string months[NUM_MONTHS] = { "January","February","March","April","May","June","July","August","September","October","November","December" };

//function prototypes.
void getData(double list[ROW][2], int rows);
double averageHigh(double list[ROW][2], int rows);
double averageLow(double list[ROW][2], int rows);
double indexHighTemp(double list[ROW][2], int rows);
double indexLowTemp(double list[ROW][2], int rows);

int main()
{
    //declares the 2D array being used in the program.
    double monthTemps[ROW][2];

    //calls the get data functions with the parameters set to the 2D array and the number of rows.
    getData(monthTemps, ROW);

    //outputs the average high and low temperatures by calling the functions.
    cout << "The average high is: " << averageHigh(monthTemps, ROW) << endl;
    cout << "The average low is: " << averageLow(monthTemps, ROW) << endl;

    //stores the indexes of the highest and lowest temperatures in the variables below.
    int indexHigh = indexHighTemp(monthTemps, ROW);
    int indexLow = indexLowTemp(monthTemps, ROW);

    //outputs the highest and lowest temperatures.
    cout << "The highest temperature was " << monthTemps[indexHigh][0] << " in the month of " << months[indexHigh] << endl;
    cout << "The lowest temperature was " << monthTemps[indexLow][1] << " in the month of " << months[indexLow] << endl;

    return 0;
}

//this function reads and stores the temperatures the user inputs into the array.
void getData(double list[ROW][2], int rows)
{
    //for loop that increments through the array for input.
    for (int i = 0; i < rows; i++)
    {
        //asks the user to input the highest temperature of the month and stores it in the array.
        cout << "Enter the highest temperature for the month of " << months[i] << ": ";
        cin >> list[i][0];

        //asks the user to input the lowest temperature of the month and stores it in the array.
        cout << "Enter the lowest temperature for the month of " << months[i] << ": ";
        cin >> list[i][1];
        cout << endl;

        //input validation loop that checks cin and makes sure the low temperature is not higher than the high temperature.
        while (!cin || list[i][0] < list[i][1])
        {
            //if !cin, clear cin and ignore until a new line. then asks the user for the temps again.
            if (!cin)
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                cout << "Error: You entered something that is not a number." << endl;
                
                cout << endl;

                cout << "Enter the highest temperature for the month of " << months[i] << ": ";
                cin >> list[i][0];

                cout << "Enter the lowest temperature for the month of " << months[i] << ": ";
                cin >> list[i][1];
                cout << endl;
            }
            //asks the user for the temps again if the low temp is higher than the high temp.
            else
            {
                cout << "Error: The first temp must be higher than the second" << endl;

                cout << "Enter the highest temperature for the month of " << months[i] << ": ";
                cin >> list[i][0];

                cout << "Enter the lowest temperature for the month of " << months[i] << ": ";
                cin >> list[i][1];
                cout << endl;
            }
        }
    }
}

//this function averages the high temps received from the user.
double averageHigh(double list[ROW][2], int rows)
{
    //sum is used to total the values, avgHigh is used to store the average of temperatures.
    double sum = 0;
    double avgHigh;

    //for loop that increments through the array and adds the values to the sum variable.
    for (int i = 0; i < ROW; i++)
    {
        sum += list[i][0];
    }

    //calculates and stores the average by dividing sum by the number of months.
    avgHigh = sum / NUM_MONTHS;

    //returns the value of avgHigh.
    return avgHigh;
}

//this function calculates the average of the low temperatures.
double averageLow(double list[ROW][2], int rows)
{
    //sum stores the total of the low temps, avgLow stores the average of the temps.
    double sum = 0;
    double avgLow;

    //for loop that increments through the array and adds the values to sum.
    for (int i = 0; i < rows; i++)
    {
        sum += list[i][1];
    }

    //calculates the average by dividing sum by the number of months.
    avgLow = sum / NUM_MONTHS;

    //returns the average value of the low temps.
    return avgLow;
}

//this function finds the index of the highest temp entered by the user throughout the year.
double indexHighTemp(double list[ROW][2], int rows)
{
    //indexOne stores the high temp value to be compared, indexTwo stores the index location of the highest temp.
    double indexOne = 0;
    int indexTwo = 0;

    //for loop increments through the array and finds the highest temperature of the year.
    for (int i = 0; i < rows; i++)
    {
        //if temperature in array is higher than indexOne, store that temp in indexOne and store i in indexTwo.
        if (list[i][0] > indexOne)
        {
            indexOne = list[i][0];
            indexTwo = i;
        }
    }

    //returns the index location to be used in main.
    return indexTwo;
}

//this function finds the index location of the lowest temp throughout the year.
double indexLowTemp(double list[ROW][2], int rows)
{
    //indexOne is used to compare the temp in the array to the lowest temp found so far, indexTwo stores the location of the lowest temp in the array.
    double indexOne = 1000;
    int indexTwo = 0;

    //for loop increments through the array to find the lowest temperature of the year.
    for (int i = 0; i < rows; i++)
    {
        if (list[i][1] < indexOne)
        {
            indexOne = list[i][1];
            indexTwo = i;
        }
    }

    //returns the index of the lowest temp of the year.
    return indexTwo;
}
