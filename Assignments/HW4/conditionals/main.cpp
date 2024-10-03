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
// Function to calculate the sum of the numbers
int sum(int numbers[], int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += numbers[i];  // Add each number to total
    }
    return total;
}

// Function to calculate the product of the numbers
int product(int numbers[], int size) {
    int total = 1;
    for (int i = 0; i < size; ++i) {
        total *= numbers[i];  // Multiply each number to total
    }
    return total;
}

// Function to find the largest number
int findMax(int numbers[], int size) {
    int maxValue = numbers[0];  // Start by assuming the first number is the largest
    for (int i = 1; i < size; ++i) {
        if (numbers[i] > maxValue) {
            maxValue = numbers[i];  // Update maxValue if we find a bigger number
        }
    }
    return maxValue;
}

// Function to find the smallest number
int findMin(int numbers[], int size) {
    int minValue = numbers[0];  // Start by assuming the first number is the smallest
    for (int i = 1; i < size; ++i) {
        if (numbers[i] < minValue) {
            minValue = numbers[i];  // Update minValue if we find a smaller number
        }
    }
    return minValue;
}

// Function to calculate the average
double average(int numbers[], int size) {
    return static_cast<double>(sum(numbers, size)) / size;  // Average = sum / number of items
}

// Function to check if the sum of the numbers is even, odd, or zero
string evenOddZero(int numbers[], int size) {
    int totalSum = sum(numbers, size);
    if (totalSum == 0) {
        return "Zero";
    } else if (totalSum % 2 == 0) {
        return "Even";
    } else {
        return "Odd";
    }
}

// A simple test function to manually check if the program works correctly
void test() {
    const int size = 5;

    // Test Case 1
    int nums1[size] = {1, 2, 3, 4, 5};
    if (sum(nums1, size) != 15) {
        cout << "Test 1 failed: Sum\n";
    }
    if (product(nums1, size) != 120) {
        cout << "Test 1 failed: Product\n";
    }
    if (findMax(nums1, size) != 5) {
        cout << "Test 1 failed: Max\n";
    }
    if (findMin(nums1, size) != 1) {
        cout << "Test 1 failed: Min\n";
    }
    if (average(nums1, size) != 3.0) {
        cout << "Test 1 failed: Average\n";
    }
    if (evenOddZero(nums1, size) != "Odd") {
        cout << "Test 1 failed: EvenOddZero\n";
    }

    // Test Case 2
    int nums2[size] = {0, 0, 0, 0, 0};
    if (sum(nums2, size) != 0) {
        cout << "Test 2 failed: Sum\n";
    }
    if (product(nums2, size) != 0) {
        cout << "Test 2 failed: Product\n";
    }
    if (findMax(nums2, size) != 0) {
        cout << "Test 2 failed: Max\n";
    }
    if (findMin(nums2, size) != 0) {
        cout << "Test 2 failed: Min\n";
    }
    if (average(nums2, size) != 0.0) {
        cout << "Test 2 failed: Average\n";
    }
    if (evenOddZero(nums2, size) != "Zero") {
        cout << "Test 2 failed: EvenOddZero\n";
    }

    cout << "All tests completed." << endl;
}
