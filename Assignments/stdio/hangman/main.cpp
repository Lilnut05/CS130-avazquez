/*
Homework 1 - Hangman
Author: Adriel Vazquez
Date: 9/8/24
This program is an outline of hangman game to be finished in the future.
Using inputs and outputs to recieve and display characters.

*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
string name;
cout <<"Welcome to my hangman program, please enter your name:\n";
cin >> name;
cout << "Hello " << name << "! Nice to meet you!";
cout << "This hangman game is in the works, maybe you\'ll get to see this finished one day. \n Here is a demo of what it will look like!\n";

cout << "stage 0\n";
string stage0 = "    |----------\n    |/    |\n    |\n    |\n    |\n    |\n    |\n----------\n";
cout << stage0;
cout << "Press enter to see next stage";
cin.ignore(1,'\n');
cin.get();

cout << "stage 1\n";
string stage1 = "    |----------\n    |/    |\n    |     O\n    |\n    |\n    |\n    |\n----------\n";
cout << stage1;
cout << "Press enter to see next stage";
cin.ignore(0,'\n');
cin.get();

cout << "stage 2\n";
string stage2 = "    |----------\n    |/    |\n    |     O\n    |     |\n    |\n    |\n    |\n----------\n";
cout << stage2;
cout << "Press enter to see next stage";
cin.ignore(0,'\n');
cin.get();

cout << "stage 3\n";
string stage3 = "    |----------\n    |/    |\n    |     O\n    |    /|\n    |\n    |\n    |\n----------\n";
cout << stage3;
cout << "Press enter to see next stage";
cin.ignore(0,'\n');
cin.get();

cout << "stage 4\n";
string stage4 = "    |----------\n    |/    |\n    |     O\n    |    /|\\\n    |\n    |\n    |\n----------\n";
cout << stage4;
cout << "Press enter to see next stage";
cin.ignore(0,'\n');
cin.get();

cout << "stage 5\n";
string stage5 = "    |----------\n    |/    |\n    |     O\n    |    /|\\\n    |    /\n    |\n    |\n----------\n";
cout << stage5;
cout << "Press enter to see next stage";
cin.ignore(0,'\n');
cin.get();

cout << "stage 6\n";
string stage6 = "    |----------\n    |/    |\n    |     O\n    |    /|\\\n    |    / \\\n    |\n    |\n----------\n";
cout << stage6;

cout << "You lose, press enter to exit program:";
cin.ignore(0,'\n');
cin.get();
return 0;
}