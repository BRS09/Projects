#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

/* Program name: main.cpp
*  Author: Brayden Scott
*  Date last updated: 3/4/2021
* Purpose: Calculates the orders from a file using a while loop and summarizes it into a table.
*/

using namespace std;

int main(){
	
	char productLetter;	//Letter of the product in the file variable.
	int productQuantity;	//Quantity of the product in the file variable.
	double productTotal, subTotal, grandTotal;	//productTotal - used to store the price of the item * the quantity. subTotal - stores the sum of every products total. grandTotal - stores subTotal and adds tax + shipping to the order.
	const double TAX = 0.17;	//17% tax that is added to the order.
	const double SHIPPING = 14.95;	//Cost of shipping that is added to the order.
	
	ifstream in;	//Declares the text file input.
	in.open("order.txt");	//Opens the text file.
	
	cout << "Thank You! Your order is summarized below:" << endl;	//Thanks the company and reminds them that the order summary is below.
	
	cout << setprecision(2) << fixed << showpoint;	//Sets the decimal value to two places, fixes it, and shows the point.
	
	cout << setw(52) << setfill('-') << '-' << endl;	//Creates a row for the beginning of the table.
	cout << "| " << "Product" << setw(10) << setfill(' ') << " | " << "Quantity" << setw(9) << setfill(' ') << " | " << "Line Total" << setw(6) << setfill(' ') << " |" << endl;	//Outputs the product, quantity, and  line total columns.
	cout << setw(52) << setfill('-') << '-' << endl;	//Ends this row of the table.
	
	while(!in.eof()){	//While loop that runs until the end of the file.
		
		in >> productLetter;	//Stores the first character from the file in the productLetter variable.
		in >> productQuantity;	//Stores the first number value from the file in the productQuantity variable.
		
		switch(productLetter){	//Case switch that takes the product letter as the expression to validate.
			case 'E':	//If the product letter is 'E' execute the following statements/calculations.
				productTotal = productQuantity * 74.56;	//Stores the product total by multiplying the quantity by the price of the product.
				subTotal += productTotal;	//Stores the sub total by adding the product total to sub total.
				cout << "| " << productLetter << setw(16) << setfill(' ') << " | " << productQuantity << setw(15) << setfill(' ') << " | " << productTotal << setw(9) << setfill(' ') << " |" << endl;	//Creates and outputs this products row on the table.
				cout << setw(52) << setfill('-') << "-" << endl;	//Ends this products row on the table.
				break;	//Breaks out of case E after the statements are executed.
				/*************************************************************************************************************
				The following statements below do the same thing as the case above, just different calculations! 
				Refer back to case E for an explanation of certain statements or calculations. Trying to increase readability! 
				*************************************************************************************************************/
			case 'H':
				productTotal = productQuantity * 3.45;
				subTotal += productTotal;
				cout << "| " << productLetter << setw(16) << setfill(' ') << "| " << productQuantity << setw(15) << setfill(' ') << "| " << productTotal << setw(10) << setfill(' ') << "|" << endl;
				cout << setw(52) << setfill('-') << "-" << endl;
				break;
			case 'D':
				productTotal = productQuantity * 23.13;
				subTotal += productTotal;
				cout << "| " << productLetter << setw(16) << setfill(' ') << "| " << productQuantity << setw(16) << setfill(' ') << "| " << productTotal << setw(11) << setfill(' ') << "|" << endl;
				cout << setw(52) << setfill('-') << "-" << endl;
				break;
			case 'G':
				productTotal = productQuantity * 9.34;
				subTotal += productTotal;
				cout << "| " << productLetter << setw(16) << setfill(' ') << "| " << productQuantity << setw(16) << setfill(' ') << "| " << productTotal << setw(11) << setfill(' ') << "|" << endl;
				cout << setw(52) << setfill('-') << "-" << endl;
				break;
			default:	//Default case that is entered if none of the letters match the cases above.
				break;	//Breaks out of the default case.
		
		}
	}
	
	grandTotal = subTotal + (subTotal * TAX) + SHIPPING;	//Stores the grand total of the order by adding the subtotal to the amount taxed and shipping cost.
	
	/*****************************************************************************************************************
	The statements below output the following rows of the table: Subtotal, Tax amount, Shipping cost, and Grand total.
	setw()= Amount of space to fill with a symbol or whitespace.
	setfill()= Fills the space with desired symbol/whitespace.
	right= Aligns the whitespace or symbol to the right.
	******************************************************************************************************************/
	cout << "| " << "Subtotal" << setw(16) << setfill(' ') << "| "  << setw(16) << setfill(' ') << "| " << subTotal << setw(16) << setfill(' ') << "|" << endl;
	cout << setw(52) << setfill('-') << "-" << endl;
	cout << "| " << "Tax" << setw(16) << setfill(' ') << "| "  << setw(16) << setfill(' ') << "| " << subTotal * TAX << setw(16) << setfill(' ') << "|" << endl;
	cout << setw(52) << setfill('-') << "-" << endl;
	cout << "| " << "Shipping" << setw(16) << setfill(' ') << "| "  << setw(16) << setfill(' ') << "| " << SHIPPING << setw(16) << setfill(' ') << "|" << endl;
	cout << setw(52) << setfill('-') << "-" << endl;
	cout << "| " << "Grand Total" << setw(16) << setfill(' ') << "| "  << setw(16) << setfill(' ') << "| " << grandTotal << setw(16) << setfill(' ') << "|" << endl;
	cout << setw(52) << setfill('-') << "-" << endl;
	
	return 0;
}
