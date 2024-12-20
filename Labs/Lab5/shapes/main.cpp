/*
    Loops Lab
    Updated By: Adriel Vazquez
    CSCI 130
    Date: 10/9/24

    Program prints geometric shapes of given height with * using loops
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void printTriangle(int height) {
    //Function takes height as an argument to print the triangle
    //of that height with *
    int row = 1;
    // row
    while (row <= height) {
        // column
        for(int col = 1; col<=row; col++)
            cout << "* ";
        row += 1;
        cout << endl;
    }
}


void printFlippedTriangle(int height) {
    /* 
    Implement the function that takes height as an argument
    and prints a triangle with * of given height.
    Triangle of height 5, e.g., should look like the following.
    * * * * *
    * * * *
    * * *
    * *
    *
    
    */
    // FIXED ...
 for (int row = height; row >= 1; --row) {
    for (int col = 1; col <= row; ++col) {
        cout << "* ";
    }
    cout << endl;
    }
}


/*  
FIXED
Design and implement a function that takes an integer as height and
prints square of the given height with *.
Square of height 5, e.g., would look like the following.

*  *  *  *  *  
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   

*/
void printSquare(int height) {
    for (int row = 1; row <= height; ++row) {
        for (int col = 1; col <= height; ++col) {
            cout << "* ";
        }
        cout << endl;
    }
}

// function clears the screen system call
// NOTE: system call is not a security best pracice!
void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

int main(int argc, char* argv[]) {
    // FIXME5 add a loop to make the program to continue to run until the user wants to quit
    char continueProgram;
    do {

    // FIXED call clearScreen function to clear the screen for each round of the loop
         clearScreen();

        int height;
        cout << "Program prints geometric shapes of given height with *\n";
        cout << "Please enter the height of the shape: ";
        cin >> height;
    // call printTriangle function passing user entered height
        cout << "\nTriangle:\n";
        printTriangle(height);

    // FIXED
    // Call printFlippedTriangle passing proper argument
    // Manually test the function
        cout << "\nFlipped Triangle:\n";
        printFlippedTriangle(height);

    // FIXED
    // Call the function defined in FIXME4 passing proper argument
    // Manually test the function
        cout << "\nSquare:\n";
        printSquare(height);

    // FIXED
    // prompt user to enter y/Y to continue anything else to quit
    cout << "\nDo you want to print another shape? (y/Y to continue, anything else to quit): ";
    cin >> continueProgram;
    }
    // FIEXED
    // Use conditional statements to break the loop or continue the loop
     while (continueProgram == 'y' || continueProgram == 'Y');

    return 0;
}
