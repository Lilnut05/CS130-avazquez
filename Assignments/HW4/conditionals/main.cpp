#include <iostream>  

using namespace std;

// Function prototypes
int sum(int numbers[], int size);
int product(int numbers[], int size);
int findMax(int numbers[], int size);
int findMin(int numbers[], int size);
double average(int numbers[], int size);
string evenOddZero(int numbers[], int size);
void test();  

int main(int argc, char* argv[]) {
    // If the user enters "test" when running the program run test
    if (argc > 1 && string(argv[1]) == "test") {
        test();
        return 0;
    }

    const int size = 5; 
    int numbers[size];

    // input 5 numbers
    cout << "Enter 5 numbers: ";
    for (int i = 0; i < size; ++i) {
        cin >> numbers[i];  
    }