/*
Adriel Vazquez
10/28/24
HW 6 Kattis Line them Up
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string checkOrder(const vector<string>& names) {
    bool isAscending = true;
    bool isDescending = true;

    for (size_t i = 1; i < names.size(); i++) {
        if (names[i] < names[i - 1]) {
            isAscending = false;
        }
        if (names[i] > names[i - 1]) {
            isDescending = false;
        }
    }

    if (isAscending) return "INCREASING";
    if (isDescending) return "DECREASING";
    return "NEITHER";
}

// Main function
int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test") {
        // Run unit tests
        vector<string> testCases[4] = {
            {"Alice", "Bob", "Charlie"},
            {"Charlie", "Bob", "Alice"},
            {"Alice", "Charlie", "Bob"},
            {"Bob"}
        };
        string expectedResults[4] = {"INCREASING", "DECREASING", "NEITHER", "INCREASING"};
        bool allTestsPassed = true;

        for (int i = 0; i < 4; i++) {
            string result = checkOrder(testCases[i]);
            if (result == expectedResults[i]) {
                cout << "Test " << i + 1 << " passed." << endl;
            } else {
                cout << "Test " << i + 1 << " failed. Expected: " 
                     << expectedResults[i] << ", Got: " << result << endl;
                allTestsPassed = false;
            }
        }

        if (allTestsPassed) {
            cout << "All unit tests passed!" << endl;
        } else {
            cout << "Some tests failed." << endl;
        }
    } else {
        // Regular program execution
        int n;
        cin >> n;
        vector<string> names(n);

        for (int i = 0; i < n; i++) {
            cin >> names[i];
        }

        cout << checkOrder(names) << endl;
    }

    return 0;
}