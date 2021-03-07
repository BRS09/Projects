#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main(){

  int lowerInput, upperInput;
  double userIncrement;
  double fahreinFormula =
  double newtFormula = lowerInput * (33/100);

  ofstream out;
  out.open("conversion_table.txt");

  cout << setprecision(2) << fixed << showpoint;

  cout << "Enter the lower value for the conversion table: ";
  cin >> lowerInput;
  cout << endl;

  while(!cin){
    cout << "You have not entered a number. Try again." << endl;
    cout << "Enter the lower value for the conversion table: ";
    cin >> lowerInput;
    cout << endl;
  }

  cout << "Enter the upper value for the conversion table";
  cin >> upperInput;
  cout << endl;

  while(upperInput < lowerInput){
    cout << "Your upper value is less than your lower value. Try again." << endl;
    cout << "Enter the upper value for the conversion table: ";
    cin >> upperInput;
    cout << endl;
  }

  cout << "What do you want to use for your increment: ";
  cin >> userIncrement;
  cout << endl;

  while(userIncrement < 0){
    cout << "The increment must be greater than 0." << endl;
    cout << "What do you want to use for your increment: ";
    cin >> userIncrement;
    cout << endl;
  }

  out << 'C' << setw(10) << setfill(" ") << " " << 'F' << setw(10) << setfill(" ") << " " << 'N' << setw(10) << setfill(" ") << " " << endl;
  out << setw(30) << setfill("-") << "-" << endl;

  return 0;

}
