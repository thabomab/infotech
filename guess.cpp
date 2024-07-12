#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 10 + 1;
    int guess;
    int attempts = 0;

    cout << "Guess the number (between 1 and 10): ";

    // Loop until the user guesses the correct number
    do {
        cin >> guess;
        attempts++;

        if (guess > randomNumber) {
            cout << "Too high! Try again: ";
        } else if (guess < randomNumber) {
            cout << "Too low! Try again: ";
        } else {
            cout << "Congratulations! You've guessed the number in " << attempts << " attempts." << endl;
        }
    } while (guess != randomNumber);

    return 0;
}
