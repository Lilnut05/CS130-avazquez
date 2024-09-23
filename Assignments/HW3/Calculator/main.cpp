#include <iostream>
#include <cmath>
using namespace std;

// Simple functions to perform arithmetic operations
template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
T multiply(T a, T b) {
    return a * b;
}

template <typename T>
T divide(T a, T b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0; // return 0 to avoid crash
    }
    return a / b;
}

template <typename T>
T subtract(T a, T b) {
    return a - b;
}

template <typename T>
T remainder(T a, T b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return fmod(a, b);
}

template <typename T>
T power(T a, T b) {
    return pow(a, b);
}

template <typename T>
T squareRoot(T a) {
    if (a < 0) {
        cout << "Error: Negative input!" << endl;
        return 0;
    }
    return sqrt(a);
}

template <typename T>
T maximum(T a, T b) {
    if (a > b)
        return a;
    else
        return b;
}

void testFunctions() {
    cout << "Testing Functions:" << endl;
    cout << "Add (10 + 2): " << add(10, 2) << endl;
    cout << "Multiply (10 * 2): " << multiply(10, 2) << endl;
    cout << "Divide (10 / 2): " << divide(10, 2) << endl;
    cout << "Subtract (10 - 2): " << subtract(10, 2) << endl;
    cout << "Remainder (10 % 2): " << remainder(10, 2) << endl;
    cout << "Power (10 ^ 2): " << power(10, 2) << endl;
    cout << "Square Root (10): " << squareRoot(10) << endl;
    cout << "Maximum (10, 2): " << maximum(10, 2) << endl;
}

int main() {
    double num1, num2;

    // Ask the user to enter two numbers
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Perform calculations and show results
    cout << "Addition: " << add(num1, num2) << endl;
    cout << "Multiplication: " << multiply(num1, num2) << endl;
    cout << "Division: " << divide(num1, num2) << endl;
    cout << "Subtraction: " << subtract(num1, num2) << endl;
    cout << "Remainder: " << remainder(num1, num2) << endl;
    cout << "Power: " << power(num1, num2) << endl;
    cout << "Square Root of first number: " << squareRoot(num1) << endl;
    cout << "Maximum: " << maximum(num1, num2) << endl;

    // Run basic tests
    testFunctions();

    return 0;
}
