/*
Adriel Vazquez
10/16/24
Kattis Fizzbuzz

*/

#include <iostream>
#include <string>

using namespace std;

string fizzBuzz(int num, int x, int y) {
    if (num % x == 0 && num % y == 0) {
        return "FizzBuzz";
    } else if (num % x == 0) {
        return "Fizz";
    } else if (num % y == 0) {
        return "Buzz";
    } else {
        return to_string(num);
    }
}

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test") {
        int testsPassed = 0;
        int totalTests = 4;

        if (fizzBuzz(3, 3, 5) == "Fizz") testsPassed++;
        if (fizzBuzz(5, 3, 5) == "Buzz") testsPassed++;
        if (fizzBuzz(15, 3, 5) == "FizzBuzz") testsPassed++;
        if (fizzBuzz(2, 3, 5) == "2") testsPassed++;

        if (testsPassed == totalTests) {
            cout << "All tests passed!" << endl;
        } else {
            cout << testsPassed << " out of " << totalTests << " tests passed." << endl;
        }
        return 0;
    }

    int x, y, n;
    cin >> x >> y >> n;

    for (int i = 1; i <= n; i++) {
        cout << fizzBuzz(i, x, y) << endl;
    }

    return 0;
}
