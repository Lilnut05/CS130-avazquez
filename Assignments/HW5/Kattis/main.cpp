/*
Adriel Vazquez
10/16/24
Kattis Fizzbuzz

*/

// main.cpp
#include <iostream>
#include <string>

using namespace std;

string fizzBuzz(int num) {
    if (num % 3 == 0 && num % 5 == 0) {
        return "FizzBuzz";
    } else if (num % 3 == 0) {
        return "Fizz";
    } else if (num % 5 == 0) {
        return "Buzz";
    } else {
        return to_string(num);
    }
}

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test") {
        int testsPassed = 0;

        if (fizzBuzz(3) == "Fizz") testsPassed++;
        if (fizzBuzz(5) == "Buzz") testsPassed++;
        if (fizzBuzz(15) == "FizzBuzz") testsPassed++;
        if (fizzBuzz(2) == "2") testsPassed++;

        if (testsPassed == 4) {
            cout << "All tests passed!" << endl;
        } else {
            cout << "Some tests failed." << endl;
        }
        return 0;
    }

    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; ++i) {
        cout << fizzBuzz(i) << endl;
    }

    return 0;
}
