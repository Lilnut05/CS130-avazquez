/*
Name: Adriel Vazquez
Date: 1/3/24
Kattis Hissing Microphone
*/
#include <iostream>
#include <string>
#include <cassert>

using namespace std;
int main() {
    string input;
    cin >> input;

    bool hasHiss = false;
    for (size_t i = 0; i < input.size() - 1; ++i) {
        if (input[i] == 's' && input[i + 1] == 's') {
            hasHiss = true;
            break;
        }
    }

    if (hasHiss) {
        cout << "hiss" << endl;
    } else {
        cout << "no hiss" << endl;
    }

    return 0;
}