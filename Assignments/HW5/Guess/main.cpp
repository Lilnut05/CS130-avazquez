/*
Adriel Vazquez
10/16/24
HW5 - Loops
This program is a guess the number game
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int randomNumber() {
    return rand() % 20 + 1;
}

int readNumber() {
    int guess;
cout << "Guess a number between 1-20 \n";
cin >> guess;

//Check if input is valid
while (guess < 1 || guess > 20) {
        cout << "Invalid number. Please enter a number between 1 and 20: ";
        cin >> guess;
    }
    return guess;
}

//Check if guess is right
int checkGuess(int guess, int secretNumber) {
    if (guess == secretNumber) {
        return 0;
    } else if (guess < secretNumber) {
        return -1;
    } else {
        return 1;
    }
}

int main(){
 srand(static_cast<unsigned int>(time(0)));

    cout << "Welcome to Guess the Number!!!!!!!" << endl;
    string Name;
    cout << "Please enter your name: ";
    cin >> Name;

    char playAgain = 'y';
    int gamesPlayed = 0;
    int gamesWon = 0;

    // Loop for playing the game
    while (playAgain == 'y' || playAgain == 'Y') {
        int secretNumber = randomNumber();
        int attempts = 0;
        bool hasWon = false;

        cout << "Hello, " << Name << "! Guess a number between 1-20" << endl;
        cout << "You have 6 tries to guess it!" << endl;

        while (attempts < 6) {
            int guess = readNumber();
            attempts++;

            int result = checkGuess(guess, secretNumber);
            if (result == 0) {
                cout << "Congratulations! You guessed it in " << attempts << " attempts!" << endl;
                hasWon = true;
                gamesWon++;
                break; //Exits the loop
            } else if (result == -1) {
                cout << "Too low! Try again." << endl;
            } else {
                cout << "Too high! Try again." << endl;
            }
        }

        //Guess incorrect
        if (!hasWon) {
            cout << "Sorry, you didn't guess the number. It was " << secretNumber << "." << endl;
        }

        gamesPlayed++;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        //Loop Command
        if (playAgain != 'y' && playAgain != 'Y') {
            playAgain = 'n';
        }
    }

    //Game Sum {Bonus}
    cout << "\nGame Over. Goodbye " << Name << endl;
    cout << "Games Played: " << gamesPlayed << endl;
    cout << "Games Won: " << gamesWon << endl;
    if (gamesPlayed > 0) {
        double winPercentage = (static_cast<double>(gamesWon) / gamesPlayed) * 100.0;
        cout << "Winning Percentage: " << winPercentage << "%" << endl;
        if (gamesPlayed > gamesWon)
        {
            cout << "Haha bad ratio L";
        }
        
    }

    return 0;
};

