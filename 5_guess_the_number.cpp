/*
* guess number between user's input range
* user has limited amount of guesses
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <time.h>
using namespace std;

int main()
{
    //set variables
    int rng, range1, range2, answer, attempt;
    string cont;

    //make user enter the range of the game
    cout << "Enter the range of the game: ";
    cin >> range1;
    cin >> range2;

    //start the rng
    srand(time(NULL));

    //user input rng
    rng = rand() % range2 + range1;             //range2 goes first for custom rng

    //choose the number of guesses
    cout << "How many attempts do you want:" << setw(5) << "3"
         << setw(5) << "4" << setw(5) << "5" << endl;
    cin >> attempt;

    //anything that is 3, 4, 5 attempts
    if (attempt == 3 ||  attempt == 4 || attempt == 5) {
        do {
            //start of the game
            cout << "Enter a number between: " << range1 << " - " << range2 << " \n";
            cin >> answer;;
            //counting down
            attempt--;
        
            //when number is lower
            if (answer > rng) {
                cout << "You have " << attempt << " attempts left.\n";
                cout << "The Number is lower.\n\n";
            }
            //when number is higher
            else if (answer < rng) {
                cout << "You have " << attempt << " attempts left.\n";
                cout << "The Number is higher.\n\n";
            }
            //got the correct number
            else if (answer == rng) { 
                cout << "You've guessed the number with " << attempt << " attempts left!\n\n";
                break;
            }
        } while (attempt > 0);

        //runs out of attempt
        if (attempt == 0 && answer != rng) {
            cout << "You have run out of guesses.\n";
            cout << "The Number is " << rng << ".\n\n";
        }

        //asking user to continue
        cout << "Do you wish to start over?\n"
             << "'yes' or 'no'\n";
        cin >> cont;

        if (cont == "yes") {
            return main();
        }
        else if (cont == "no") {
            return 0;
        }
    }
    
    //anything else tthats not 3, 4, 5 attempt
    else {
        cout << "Not in the parameter.\n";
        cout << "Starting over.\n\n";
        return main();
    }
}
