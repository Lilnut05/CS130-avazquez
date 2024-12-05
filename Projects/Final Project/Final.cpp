/*
Author: Adriel Vazquez
Date: 12/4/24
A program that allows the user to play tic tac toe against a CPU, or another player.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

// Functions
void displayWelcome();
char choosePSymbol();
void initializeBoard();
void displayBoard();
void PMove(char PSymbol);
void CMove(char CSymbol);
bool checkWin(char symbol);
bool checkTie();
void SinglePlayerGame(char PSymbol);
void TwoPlayerGame();
void saveStats();


int main() {

}

// Function Definitions
void displayWelcome() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
}

char choosePSymbol() {
    char symbol;
    do {
        cout << "Choose your symbol (X or O): ";
        cin >> symbol;
    } while (symbol != 'X' && symbol != 'O');
    return symbol;
}

void initializeBoard() {

}