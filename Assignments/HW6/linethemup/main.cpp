/*
Adriel Vazquez
10/28/24
HW 6 Kattis Line them Up
*/
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

        for (int i = 0; i < 4; i++) {}
