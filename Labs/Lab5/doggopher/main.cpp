/*
Kattis - Dog & Gopher
Loop Lab
Updated By: Adriel Vazquez
CSCI 111
Date: 10/10/24

Read and solve the Kattis problem: https://open.kattis.com/problems/doggopher 

Algorithm Steps:
		1. Read gopher and dog's coordinates
		2. Define a function to find and return the Euclidean distance between the two points
    3. For each gopher hole coordinate:
      3.a find the distance between the gopher position and the hole
      3.b find the distance between the dog position and the hole
      4.c if the dog's distance is larger or equal to twice the distance of gopher, 
          gopher can get away through that hole. 
          4.c.1 Stop testing other holes.
    4. If no safe hole is found, the gopher cannot escape.
*/

#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

// Function prototypes
// Function finds the the Euclidean distance given two points (x1, y1) and (x2, y2)
float distance(const float x1, const float y1, const float x2, const float y2);
// function to test distance function
void testDistance();

#define TOLERANCE 1e-6 // 10^-6 or 0.000001

int main(int argc, char* argv[]) {
  if (argc == 2 and string(argv[1]) == string("test")) {
    // FIXED: call testDistance function
    testDistance();
  }
  else {
    float gopherX, gopherY;
    float x, y; // varibles to read gopher hole coordinates
    string answer = "The gopher cannot escape.";
    float gopher_dist, dog_dist=0;
    // read gopher's coordinates
    cin >> gopherX >> gopherY;
    // FIXED: read dog's coordinates
    float dogX, dogY;
    cin >> dogX >> dogY;
    while (cin >> x >> y) { // while there's hole coordinates to read
      //find gopher's distance from (x, y)
      gopher_dist = distance(gopherX, gopherY, x, y);
      // store the returned result into answer variable
      // FIXED: find dog's distance from (x, y)
      dog_dist = distance(dogX, dogY, x, y);
      if (dog_dist >= 2*gopher_dist) {
        ostringstream oss;
        oss << fixed << showpoint << setprecision(3);
        oss << "The gopher can escape through the hole at (" << x << "," << y << ").";
        answer = oss.str();
        break; // no need to test more holes; the first one will do!
      }
    }
    cout << answer << endl;
  }
	return 0;
}

// Function implementation
float distance(const float x1, const float y1, const float x2, const float y2) {
  float d = 0;
  // FIXED: Find the Eucledian distance between two points on 2-d coordiantes.
  // store the distance into the `d` variable
  d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return d;
}

// function to test area function
void testDistance() {
  float x1, y1, x2, y2, answer, expected;
  x1 = 1.000f;
  y1 = 1.000f;
  x2 = 2.000f;
  y2 = 2.000f;
  answer = distance(x1, y1, x2, y2);
  expected = 1.4142135623731;
  cout << fixed << showpoint << setprecision(3) << endl;
  cout << answer << " " << expected << endl;
  assert(abs(answer-expected) < TOLERANCE);
  // FIXED: Write 2nd test case for distance function
  x1 = 0.000f;
  y1 = 1.000f;
  x2 = 0.000f;
  y2 = 1.000f;
  answer = distance(x1, y1, x2, y2);
  expected = 1.4142135623731;
  cout << fixed << showpoint << setprecision(3) << endl;
  cout << answer << " " << expected << endl;
  assert(abs(answer-expected) < TOLERANCE);
  // FIXED: Write 3rd test case for distance function
  x1 = 0.000f;
  y1 = 12.000f;
  x2 = 9.000f;
  y2 = 19.000f;
  answer = distance(x1, y1, x2, y2);
  expected = 11.401754251;
  cout << fixed << showpoint << setprecision(3) << endl;
  cout << answer << " " << expected << endl;
  assert(abs(answer-expected) < TOLERANCE);
  // FIXED: Write 4th test case for distance function
  x1 = 0.000f;
  y1 = 2.000f;
  x2 = 4.000f;
  y2 = 2.000f;
  answer = distance(x1, y1, x2, y2);
  expected = 4;
  cout << fixed << showpoint << setprecision(3) << endl;
  cout << answer << " " << expected << endl;
  assert(abs(answer-expected) < TOLERANCE);
  cerr << "All test cases passed!\n";
}
