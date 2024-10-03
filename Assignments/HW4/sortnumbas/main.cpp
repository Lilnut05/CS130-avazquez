#include <iostream>

using namespace std;

// Function to sort and print two numbers in ascending order
void sortAndPrint(int a, int b) {
    if (a < b) {
        cout << a << " " << b << endl;
    } else {
        cout << b << " " << a << endl;
    }
}

void test() {
    int x = 3, y = 1;
    cout << "Test 1: "; 
    sortAndPrint(x, y);

    x = -30; y = -10;
    cout << "Test 2: "; 
    sortAndPrint(x, y);

    x = 20; y = 2;
    cout << "Test 3: "; 
    sortAndPrint(x, y); 
}

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test") {
        test();
        return 0;
    }

    int a, b;

    // Input two integers
    cin >> a >> b;

    // Sort and print them
    sortAndPrint(a, b);

    return 0;
}