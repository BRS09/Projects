#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <climits>

/* Program name: main.cpp
*  Author: Brayden Scott
*  Date last updated: 3/28/2021
* Purpose: Asks the user for the center point of a circle and another point on the circle. With this information, the program then calculates the radius, area, and perimeter of the circle and returns the values to the user.
*/

using namespace std;

/***********************
* function prototypes. *
***********************/
double calculateRadius(int, int, int, int);
double calculateArea(double);
double calculatePerimeter(double);
void formatOutput();

int main()
{
    int x1, y1, x2, y2;    //used in calculateRadius.

    cout << "Please enter the center point in the form x y: ";      //Asks the user for the center point of the circle.
    cin >> x1 >> y1;        //Stores the value in x1 and y1.
    cout << endl;       //Ends the current line.

    while (!cin)        //Input validation checks if user input is correct.
    {
        cin.clear();        //Clears cin.
        cin.ignore(INT_MAX, '\n');      //Ignores the following input until a new line is reached.

        cout << "You entered something that is not a number. Please try again." << endl;        //Alerts the user that their input was invalid.

        cout << "Please enter the center point in the form x y: ";      //Asks the user for the center point again.
        cin >> x1 >> y1;        //Stores the values.
        cout << endl;       //Ends the current line.
    }

    cout << "Please enter the point on the circle in the form x y: ";       //Asks the user for another point on the circle.
    cin >> x2 >> y2;        //Stores the values in x2 and y2.
    cout << endl;       //Ends the current line.

    while (!cin)        //While loop that checks for valid input.
    {
        cin.clear();        //Clears cin.
        cin.ignore(INT_MAX, '\n');      //Ignores the following input until a new line is reached.

        cout << "You entered something that is not a number. Please try again." << endl;        //Alerts the user that their input was invalid.

        cout << "Please enter the point on the circle in the form x y: ";       //Asks the user for a point on the circle again.
        cin >> x2 >> y2;        //Stores the values.
        cout << endl;       //Ends the current line.
    }

    formatOutput();     //function that formats the output.

    double radiusOutput = calculateRadius(x1, y1, x2, y2);      //calls the calculateRadius function and stores its return value into radiusOutput.
    double areaOutput = calculateArea(radiusOutput);        //calls the calculateArea function with a parameter of the results of calculateRadius and stores it in areaOutput.
    double perimeterOutput = calculatePerimeter(radiusOutput);      //calls the calculatePerimeter function with a parameter of the results of calculateRadius and stores it in perimeterOutput.

    /*********************************************************************
    Outputs the points the user selected, the radius, area, and perimeter.
    *********************************************************************/
    cout << "Here is the information for the circle formed from (" << x1 << "," << y1
        << ") and (" << x2 << "," << y2 << ")" << endl;
    cout << "Radius: " << radiusOutput << endl;
    cout << "Area: " << areaOutput << endl;
    cout << "Perimeter: " << perimeterOutput << endl;

    return 0;

}

double calculateRadius(int x1, int y1, int x2, int y2)      //This function takes in the x1, y1, x2, and y2 values entered by the user.
{
    double circleRadius = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));      //Declares circleRadius, this variable stores the results of the point chosen by the user as the radius of the circle.

    return circleRadius;       //returns the radius of the circle.

}

double calculateArea(double circleRadius)       //Function used to calculate the area of the circle, takes the radius as its parameter.
{
    double circleArea = 3.14 * pow(circleRadius, 2);        //circleArea stores the calculation results that find the area of the circle.

    return circleArea;      //returns the area of the circle.

}

double calculatePerimeter(double circleRadius)      //Function used to calculate the perimeter of the circle, takes the circles radius as its parameter.
{
    double circlePerimeter = 2 * 3.14 * circleRadius;       //Stores the calculation results that find the perimeter of the circle.

    return circlePerimeter;     //returns the perimeter of the circle.

}

void formatOutput()     //Function used to format the output of the program.
{
    cout << setprecision(4) << showpoint << fixed;      //sets the decimal to 4 decimal places, shows the point, and fixes it.
}
