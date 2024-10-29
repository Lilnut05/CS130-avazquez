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
        };
        