/*
Author: Adriel Vazquez
Date: 12/4/24
A program that allows the user to play tic tac toe against a CPU, or another player.
*/

#include <iostream>
#include "Final.h"

using namespace std;
//Menu
int main() {
    int choice;
    char symbol;

    displayWelcome();

    cout << "Choose:\n1. Single Player\n2. Two Player\n";
    cin >> choice;

    symbol = choosePSymbol();

    if (choice == 1) {
        SinglePlayer(symbol);
    } else if (choice == 2) {
        TwoPlayer();
    } else {
        cout << "Wrong choice, exiting..." << endl;
    }

    saveStats();

    return 0;
}
