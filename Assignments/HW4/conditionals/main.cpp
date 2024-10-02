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

    // option
    cout << "Choose an option:\n";
    cout << "1. Sum\n";
    cout << "2. Product\n";
    cout << "3. Maximum\n";
    cout << "4. Minimum\n";
    cout << "5. Average\n";
    cout << "6. Check if sum is even, odd, or zero\n";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Sum: " << sum(numbers, size) << endl;
            break;
        case 2:
            cout << "Product: " << product(numbers, size) << endl;
            break;
        case 3:
            cout << "Maximum: " << findMax(numbers, size) << endl;
            break;
        case 4:
            cout << "Minimum: " << findMin(numbers, size) << endl;
            break;
        case 5:
            cout << "Average: " << average(numbers, size) << endl;
            break;
        case 6:
            cout << "Sum is: " << evenOddZero(numbers, size) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}