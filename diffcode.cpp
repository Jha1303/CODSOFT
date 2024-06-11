#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Initialize random seed
    srand(time(0));  // simplified this line

    // Generate a random number between 1 and 100
    int number_to_guess = rand() % 100 + 1;
    int user_guess = 0;

    cout << "Guess the number (between 1 and 100): ";

    // This is a loop until the user guesses the correct number
    do {
        // Get user's guess
        cin >> user_guess;

        // Provide feedback to the user 
        if (user_guess < number_to_guess) {
            cout << "Too low, try again: ";
        } else if (user_guess > number_to_guess) {
            cout << "Too high, try again: ";
        } else {
            cout << "You've guessed the correct number." << endl;
        }
    } while (user_guess != number_to_guess);

    return 0;
}
