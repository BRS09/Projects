#include <iostream>
#include <iomanip>

using namespace std;

/* Program name: main.cpp
*  Author: Brayden Scott
*  Date last updated: 2/5/2021
* Purpose: To calculate and split the costs and slices per person depending on how many people and pizzas that are ordered.
*/

int main() 
{
    cout << setprecision(2) << fixed << showpoint;
    // Integers and floating point numbers used in this program.
    int totalSlices, slicesPerPerson, smallPizza, mediumPizza, largePizza;
    float largePrice, mediumPrice, smallPrice, totalPrice, totalPerPerson;
    float grandTotal, numberOfPeople;
    
    cout << "How many people are getting pizza? "; // Asks user for number of people that are getting pizza.
    cin >> numberOfPeople; // Stores the user input into the numberOfPeople variable.
    cout << endl;
    
    cout << "A large pizza ($15) has 8 slices, how many large pizzas do you want? "; //Output that asks the user how many large pizzas they want.
    cin >> largePizza; //Input stored in largePizza variable.
    cout << endl;
    
    cout << "A medium pizza ($12) has 6 slices, how many medium pizzas do you want? "; //Output that asks the user how many medium pizzas they want.
    cin >> mediumPizza; //Input stored in mediumPizza variable.
    cout << endl;
    
    cout << "A small pizza ($9) has 4 slices, how many small pizzas do you want? "; //Output that asks the user how many small pizzas they want.
    cin >> smallPizza; //Input stored in smallPizza variable.
    cout << endl;
    
    cout << "You ordered " << largePizza << " large, " <<
            mediumPizza << " medium, and " << smallPizza << " small pizzas." << endl; //Output that repeats the customers order back to them.

    largePrice = 15.00 * largePizza; //Multiplies the price of a large pizza by how many the user entered and stores it.
    mediumPrice = 12.00 * mediumPizza; //Multiplies the price of a medium pizza by how many the user entered and stores it.
    smallPrice = 9.00 * smallPizza; //Multiplies the price of a small pizza by how many the user entered and stores it.
    totalSlices = largePizza * 8 + mediumPizza * 6 + smallPizza * 4; //Calculates how many slices of pizza the customers order contains.

    slicesPerPerson = totalSlices / numberOfPeople; //Calculates the number of slices per person.
    
    cout << "That is " << totalSlices << " total slices, and " << slicesPerPerson << " per person." << endl; //Outputs the total slices and slices per person
    
    totalPrice = largePrice + mediumPrice + smallPrice; //Calculates the total price of the order excluding tax, tip, and delivery fee and stores it.
    const double TAX = 0.08 * totalPrice; //Stores the calculation of the tax rate times the total price.
    const double DELIVFEE = 3.50; //Pizza delivery fee.
    const double TIP = 0.20 * (totalPrice + DELIVFEE + TAX); //Calculates the tip according to the total price, delivery fee, and tax rate.
    grandTotal = totalPrice + TAX + TIP + DELIVFEE; //Stores the grand total of the order.
    totalPerPerson = static_cast<float>(grandTotal / numberOfPeople); //Splits the grand total between how many people are getting pizza.
    
    
    cout << "The total for the pizzas is $" << totalPrice << "." << endl; //Outputs the total of just the pizzas.
    cout << "The delivery fee is $" << DELIVFEE << "." << endl; //Outputs the price of the delivery fee.
    cout << "The tax amount is $" << TAX << "." << endl; //Outputs the amount of tax on the order.
    cout << "The 20% tip (after adding the tax and delivery fee to the pizza cost) is $"  << TIP << "." << endl; //Outputs the calculated tip to the user.
    cout << "The total cost is $" << grandTotal << " which is $" << totalPerPerson << " per person." << endl; //Outputs the final price of the order.
    
	return 0;
}
