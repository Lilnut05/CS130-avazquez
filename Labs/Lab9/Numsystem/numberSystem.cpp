/*
    CS1 - Vector Lab

    Updated by: Adriel Vazquez
    Date: 11/11/24

    Program: Number system converter  

    The program converts decimal (unsigned int) number to binary and octol representations.
    Lab demonstrates the vector application. 
*/

#include <iostream> 
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <cctype>

using namespace std;

using llu = unsigned long long int;

// System specific macro function sysclear that 
// clears console text
// NOTE: system call is not security best practice!
#ifdef _WIN32
#define clearScreen() system ("cls") // not secure!
#else
#define clearScreen() system ("clear") // not secure!
#endif

// converts decimal number to binary representation
string decToBin(llu);

// converts binary number to decimal representation
llu binToDec(string binaryNum);

// converts decimal number to octal representation
string decToOct(llu);

// converts octal number to decimal number
llu octToDec(string octalNum);

// function to display and capture menu options
int menuOption();

int main()
{
    llu decimalNum;
    int choice;
    string octalNum, binary;
    do {
        clearScreen();
        cout << "Decimal, Binary, and Octal Number System Converter.\n";
        choice = menuOption();
        switch(choice) {
            case 1:
                // FIXED
                cout << "Enter a decimal to convert into binary \n";
                cin >> decimalNum;
                binary = decToBin(decimalNum);
                cout << decimalNum << " in binary is " << binary << endl;
                break;
            case 2:
                // FIXed
                cout << "Enter binary to convert into decimal\n";
                cin >> binary;
                decimalNum = binToDec(binary);
                cout << binary << " in decimal is " << decimalNum << endl;
                break;
            case 3:
                cout << "Enter a positive whole decimal number: ";
                cin >> decimalNum;
                octalNum = decToOct(decimalNum);
                printf("(%llu) base 10 = (%s) base 8\n", decimalNum, octalNum.c_str());
                break;
            case 4:
                cout << "Enter a positive octal number: ";
                cin >> octalNum;
                decimalNum = octToDec(octalNum);
                printf("(%s) base 8 = (%llu) base 10\n", octalNum.c_str(), decimalNum);
                break;
            case 5:
                break;
        }
        if (choice != 5) {
            cin.ignore();
            cout << "Enter to continue...";
            cin.get();
        }
    } while (choice != 5);
    cin.ignore();
    cout << "Good bye! Enter to quit...";
    cin.get();
    return 0;
}

string decToBin(llu num) {
    // FIXED - implement algorithm step in Ch03-StdInputOutput chapter
    // or use hint from decToOct function
    string binary = "";
    if (num == 0) return "0";
    while (num > 0) {
        binary = to_string(num % 2) + binary;
        num /= 2;
    }
    return binary;
}

llu binToDec(string binaryNumber)
{
    // FIXED - implement algorithm described in Ch03-StdInputOutput chapter
    // or use hints from binToOct function
    llu decimal = 0;
    llu power = 1;
    for (int i = binaryNumber.size() - 1; i >= 0; i--) {
        if (binaryNumber[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}

string decToOct(llu num)
{
    /*
    Algorithm steps:
    1. repeteadly divide the decimal number by base 8 until the quotient becomes 0
    2. collect the remainder for each division
    3. reverse the order of the remainders 
        - the first remainder is the last digit in octal
    */
    vector<int> octal;
    int divisor = 8; // base 8
    llu quotient = num;
    int remainder;
    // step 1 and 2
    cout << "quotient = " << quotient << endl;
    while (quotient != 0) {
        remainder = quotient%divisor;
        quotient = quotient/divisor;
        octal.push_back(remainder);
        // debug log
        cerr << "quotient = " << quotient << " " << remainder << endl;
    }

    // step 3. convert octal vector into string for easy printing the result
    // collect remainders in reverse order
    string ans = "";
    while(not octal.empty()) {
        // collect from the last element
        ans += to_string(octal.back());
        // remove the last element
        octal.pop_back();
    }
    return ans;
}


llu octToDec(string octalNumber)
{
    /* Algorithm steps:
    1. multiply each octal digit by its place value in octal
    2. sum all place values
    e.g. (173) base 8 = 1x8^2 + 7x8^1 + 3x8^0 = 64+56+3 = (123) base 10
    */
    llu ans = 0;
    int exp;
    // traverse from last digit to the first digit of octal number
    for(int i = octalNumber.size()-1; i>=0; i--) {
        exp = octalNumber.size()-1 - i;
        int digit = int(octalNumber[i]) - int('0');
        // step 1 and 2
        ans += digit*pow(8, exp);
    }
    return ans;
}

int menuOption() {
    int choice;
    cout << "Menu options: \n"
        << "1. Convert Decimal to Binary Number System\n"
        << "2. Convert Binary to Decimal Number System\n"
        << "3. Convert Decimal to Octal Number System\n"
        << "4. Convert Octal to Decimal Number System\n"
        << "5. Exit the program\n";
    cout << "Enter your choice: [1-5]: ";
    cin >> choice;
    return choice;
}