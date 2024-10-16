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
        std::cout << "Invalid number. Please enter a number between 1 and 20: ";
        std::cin >> guess;
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

};

