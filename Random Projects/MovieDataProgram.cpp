#include <iostream>
#include <climits>
#include <string>

/* Program name: main.cpp
*  Author: Brayden Scott
*  Date last updated: 4/23/2021
* Purpose: Asks the user for information on two movies, the program then outputs formatted information back to the user.
*/

using namespace std;

//struct with type movieData that contains the information needed for the movies.
struct MovieData
{
    string title;
    string genre;
    string director;
    int yearReleased = 0;
    int runningTime = 0;
};

//function prototype.
void displayMovie(MovieData movie);

int main()
{
    //movieDataOne = 1st movie, movieDataTwo = 2nd movie.
    MovieData movieDataOne;
    MovieData movieDataTwo;

    //broadcasts that the program is entering data for movie 1.
    cout << "Entering data for movie #1" << endl;

    //asks the user for the title of the movie.
    cout << "Enter the title of the movie: ";
    //stores the title.
    getline(cin, movieDataOne.title);

    //asks the user for the genre of the movie.
    cout << "Enter the genre of the movie: ";
    //stores the genre.
    getline(cin, movieDataOne.genre);

    //asks the user for the director's name.
    cout << "Enter the director's name: ";
    //stores the director's name.
    getline(cin, movieDataOne.director);

    //asks the user to enter the year the movie was released.
    cout << "Enter the year the movie was released: ";
    //stores the year the movie was released.
    cin >> movieDataOne.yearReleased;
    
    //input validation while loop that checks for input failure or if the entered year is less than or equal to 1887.
    while (!cin || movieDataOne.yearReleased <= 1887)
    {
        //if !cin clear cin and ignore characters until a new line is reached.
        if (!cin)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

        //alert the user that the year should be after 1887.
        cout << "The year should be a number after 1887." << endl;

        //re-prompts the user for the year.
        cout << "Enter the year the movie was released: ";
        cin >> movieDataOne.yearReleased;
    }

    //asks the user for the runtime in minutes.
    cout << "Enter the runtime in minutes: ";
    //stores the runtime.
    cin >> movieDataOne.runningTime;

    //input validation while loop that checks for input failure and that the runetime is greater than 0.
    while (!cin || movieDataOne.runningTime <= 0)
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

        //alerst the user that the runtime should be greater than 0.
        cout << "The runtime should be a number greater than 0." << endl;

        //re-prompts the user for the runtime.
        cout << "Enter the runtime in minutes: ";
        cin >> movieDataOne.runningTime;
    }
    
    cout << endl << endl;

    //clear and ignore for the next strings the user will input.
    cin.clear();
    cin.ignore();

    cout << "Entering data for movie #2" << endl;

    //asks the user for the title.
    cout << "Enter the title of the movie: ";
    //stores the title.
    getline(cin, movieDataTwo.title);

    //asks the user for the genre.
    cout << "Enter the genre of the movie: ";
    //stores the genre.
    getline(cin, movieDataTwo.genre);

    //asks the user for the director's name.
    cout << "Enter the director's name: ";
    //stores the director's name.
    getline(cin, movieDataTwo.director);

    //asks the user for the year the movie was released.
    cout << "Enter the year the movie was released: ";
    //stores the year.
    cin >> movieDataTwo.yearReleased;

    //input validation while loop. the same as above.
    while (!cin || movieDataTwo.yearReleased <= 1887)
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

        cout << "The year should be a number after 1887." << endl;

        cout << "Enter the year the movie was released: ";
        cin >> movieDataTwo.yearReleased;
    }

    cout << "Enter the runtime in minutes: ";
    cin >> movieDataTwo.runningTime;

    //input validation while loop. the same as above.
    while (!cin || movieDataTwo.runningTime <= 0)
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

        cout << "The runtime should be a number greater than 0." << endl;

        cout << "Enter the runtime in minutes: ";
        cin >> movieDataTwo.runningTime;
    }
    
    cout << endl << endl;

    //outputs the information for movie 1 by calling the displayMovie() function.
    cout << "Here is the information for movie #1" << endl;
    displayMovie(movieDataOne);

    cout << endl;

    //outputs the information for movie 2 by calling the displayMovie() function.
    cout << "Here is the information for movie #2" << endl;
    displayMovie(movieDataTwo);

    return 0;
}

//function used to format and output the information the user entered.
void displayMovie(MovieData movie)
{
    //outputs the title, genre, director, year released, and runtime.
    cout << "Title: " << movie.title << endl;
    cout << "Genre: " << movie.genre << endl;
    cout << "Director: " << movie.director << endl;
    cout << "Year Released: " << movie.yearReleased << endl;
    cout << "Running time (in minutes): " << movie.runningTime << endl;

}
