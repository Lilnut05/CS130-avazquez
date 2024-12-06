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
//Choose player symbol X or O
char choosePSymbol() {
    char symbol;
    cout << "Choose your symbol (X/O): ";
    cin >> symbol;
    while (symbol != 'X' && symbol != 'O') {
        cout << "Invalid choice! Please choose either 'X' or 'O': ";
        cin >> symbol;
    }
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
//Play again
bool playAgain() {
    char choice;
    cout << "Do you want to play again? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

//Players move and check
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
//Random decision for cpu placement
void CMove(char CSymbol) {
    srand(time(0));  // Seed for rng

    int row, col;
    do {
        row = rand() % 3;  // Random row: 0, 1, or 2
        col = rand() % 3;  // Random column: 0, 1, or 2
    } while (grid[row][col] != ' '); //Check for empty
    grid[row][col] = CSymbol;
}
//Checks for wins
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
//Checks if game is tied
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
//Single player
void SinglePlayer(char PSymbol) {
    char CSymbol = (PSymbol == 'X') ? 'O' : 'X';  // Assign the opposite symbol to the computer
    bool continuePlaying = true;

    while (continuePlaying) {
        initializeGrid();

        while (true) {
            displayGrid();
            PMove(PSymbol);  // Player moves

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

            CMove(CSymbol);  // Computer moves

            if (checkWin(CSymbol)) {
                cout << "Computer wins!" << endl;
                winStreak = 0;
                break;
            }
        }

        continuePlaying = playAgain();  // Ask if the player wants to play again
    }
}

// Two-player
void TwoPlayer() {
    bool continuePlaying = true;
    
    while (continuePlaying) {
        char player1 = 'X', player2 = 'O';
        initializeGrid();

        while (true) {
            displayGrid();
            PMove(player1);  // Player 1 makes a move
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
            PMove(player2);  // Player 2 makes a move
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

        continuePlaying = playAgain();  // Ask if the players want to play again
    }
}
//saves stats
void saveStats() {
    ofstream outFile("gameStats.txt");
    outFile << "Games won: " << gamesWon << endl;
    outFile << "Win streak: " << winStreak << endl;
    outFile.close();
}

//secret win screen
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
        cout << " Congratulations, you are the TOP G!!!!";
    }
    else if (winStreak == 3) {
        cout << "Congrats you found the sEECret winscreen!!";
    }
}