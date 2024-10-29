/*
Adriel Vazquez
10/28/24
HW 6 Kattis Falling Apart
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


pair<int, int> splitSum(vector<int> pieces) {
    sort(pieces.rbegin(), pieces.rend()); // Sort in descending order
    int player1 = 0, player2 = 0;
    for (size_t i = 0; i < pieces.size(); i++) {
        if (i % 2 == 0) player1 += pieces[i];
        else player2 += pieces[i];
    }
    return {player1, player2};
}

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test") {
        // Unit tests
        vector<pair<vector<int>, pair<int, int>>> testCases = {
            {{8, 6, 4, 2}, {10, 10}},
            {{5, 3, 7, 1}, {8, 8}},
            {{1, 1, 1, 1}, {2, 2}},
            {{9}, {9, 0}},
        };
        bool allTestsPassed = true;

        for (size_t i = 0; i < testCases.size(); i++) {
            auto result = splitSum(testCases[i].first);
            if (result == testCases[i].second) {
                cout << "Test " << i + 1 << " passed." << endl;
            } else {
                cout << "Test " << i + 1 << " failed. Expected: (" 
                     << testCases[i].second.first << ", " 
                     << testCases[i].second.second << "), Got: (" 
                     << result.first << ", " << result.second << ")" << endl;
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
        vector<int> pieces(n);

        for (int i = 0; i < n; i++) {
            cin >> pieces[i];
        }

        auto result = splitSum(pieces);
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}