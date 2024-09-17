/*
Homework 2 - Math
Author: Adriel Vazquez
Date: 9/15/24
This program takes sides of a traingle and outputs
information like area and perimeter from them.
*/
#include <iostream>
#include <cstdio>
#include <cassert>
#include <cmath>

int main()
{
//take a numbers and store them for use later.
double a, b ,c ,sum, semiPerimeter, result, finalResult;
std::cout << "Hello, please enter three sides of a triangle.\n";
std::cout << "Side 1: ";
std::cin >> a;
std::cout << "Side 2: ";
std::cin >> b;
std::cout << "Side 3: ";
std::cin >> c;
//Use a formula
sum = a+b+c;
semiPerimeter = sum/2;

result = semiPerimeter*(semiPerimeter-a)*(semiPerimeter-b)*(semiPerimeter-c);
finalResult = sqrt(result);
std::cout << "Area: " << finalResult << '\n';
std::cout << "Perimeter: " << sum << '\n';
//Test if triangle can exist

if (a + b > c && a + c > b && b + c > a) {
        std::cout << "Tringle is real \n";
    } else {
        std::cout << "Traingle doesnt exist \n";
    }
}