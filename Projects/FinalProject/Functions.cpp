/*
Adriel Vazquez
Functions For Tic Tack toe game
*/
#include "Final.h"

int winStreak = 0;
int gamesWon = 0;
char grid[3][3];

void displayWelcome() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
}

char choosePSymbol() {
    char symbol;
    cout << "Choose your symbol (X/O): ";
    cin >> symbol;
    return symbol;
}

void initializeGrid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }
}

void displayGrid() {
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j] << " | ";
        }
        cout << endl;
    }
}

void PMove(char PSymbol) {
    int move;
    cout << "Enter your move (1-9): ";
    cin >> move;

    if (move < 1 || move > 9 || grid[(move - 1) / 3][(move - 1) % 3] != ' ') {
        cout << "Invalid move! Try again.\n";
        PMove(PSymbol);
        return;
    }

    grid[(move - 1) / 3][(move - 1) % 3] = PSymbol;
}

void CMove(char CSymbol) {
    for (int i = 0; i < 9; i++) {
        int row = i / 3;
        int col = i % 3;
        if (grid[row][col] == ' ') {
            grid[row][col] = CSymbol;
            break;
        }
    }
}

bool checkWin(char symbol) {
    for (int i = 0; i < 3; i++) {
        if ((grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) ||
            (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)) {
            return true;
        }
    }
    if ((grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) ||
        (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol)) {
        return true;
    }
    return false;
}

bool checkTie() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void SinglePlayer(char PSymbol) {
    char CSymbol = (PSymbol == 'X') ? 'O' : 'X';
    initializeGrid();

    while (true) {
        displayGrid();
        PMove(PSymbol);

        if (checkWin(PSymbol)) {
            cout << "You win!" << endl;
            gamesWon++;
            winStreak++;
            checkSecretWin();
            break;
        }

        if (checkTie()) {
            cout << "It's a tie!" << endl;
            break;
        }

        CMove(CSymbol);

        if (checkWin(CSymbol)) {
            cout << "Computer wins!" << endl;
            winStreak = 0;
            break;
        }
    }
}

void TwoPlayer() {
    char player1 = 'X', player2 = 'O';
    initializeGrid();

    while (true) {
        displayGrid();
        PMove(player1);
        if (checkWin(player1)) {
            cout << "Player X wins!" << endl;
            gamesWon++;
            winStreak++;
            checkSecretWin();
            break;
        }

        if (checkTie()) {
            cout << "It's a tie!" << endl;
            break;
        }

        displayGrid();
        PMove(player2);
        if (checkWin(player2)) {
            cout << "Player O wins!" << endl;
            winStreak = 0;
            break;
        }

        if (checkTie()) {
            cout << "It's a tie!" << endl;
            break;
        }
    }
}

void saveStats() {
    ofstream outFile("gameStats.txt");
    outFile << "Games won: " << gamesWon << endl;
    outFile << "Win streak: " << winStreak << endl;
    outFile.close();
}

void checkSecretWin() {
    if (winStreak == 5) {
        cout << "            __________\n";
        cout << "          |           |\n";
        cout << "         |_____________|\n";
        cout << "          \\           /\n";
        cout << "           \\         /\n";
        cout << "            |_______|\n";
        cout << "               | |\n";
        cout << "               | |\n";
        cout << "               | |\n";
        cout << "              /   \\\n";
        cout << "             /     \\\n";
        cout << "            '-------'\n";
        cout << " Congratulations, you are the TOP G!!!!"
    }
}