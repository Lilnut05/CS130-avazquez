/*
Adriel Vazquez
TitctacHEADER
*/
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

//Functions
void displayWelcome();
char choosePSymbol();
void initializeGrid();
void displayGrid();
void PMove(char PSymbol);
void CMove(char CSymbol);
bool checkWin(char symbol);
bool checkTie();
void SinglePlayer(char PSymbol);
void TwoPlayer();
void saveStats();
void checkSecretWin();

//Global Variables
extern int winStreak;
extern int gamesWon;

#endif
