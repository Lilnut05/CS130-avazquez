#include <iostream>
#include <cmath>  

using namespace std;

int main() {
    // Constants
    double g = 9.81; 
    double feetToMeters = 0.3048;
    double metersToFeet = 3.28084;

    // Variables
    double velocity, angle, targetDistance;
    string unit;

    // Get user input for units
    cout << "Choose units (feet or meters): ";
    cin >> unit;


    // Get velocity, angle, and target distance
    cout << "Enter the velocity of projectile " << (unit == "feet" ? "feet/second" : "meters/second") << ": ";
    cin >> velocity;
    cout << "Enter the angle in degrees: ";
    cin >> angle;
    cout << "Enter the targets distance " << (unit == "feet" ? "feet" : "meters") << ": ";
    cin >> targetDistance;


    // Convert to meters from feet
    if (unit == "feet") {
        velocity = velocity * feetToMeters;
        targetDistance = targetDistance * feetToMeters;
    }


    // Calculate the angle in radians
    double angleRad = angle * (M_PI / 180.0);


    // Calculate Max height, flight, and distance
    double maxHeight = (velocity * velocity * sin(angleRad) * sin(angleRad)) / (2 * g);
    double flightTime = (2 * velocity * sin(angleRad)) / g;
    double distance = (velocity * velocity * sin(2 * angleRad)) / g;


    // results
    double roundedHeight = int(maxHeight * 100 + 0.5) / 100.0;
    double roundedFlightTime = int(flightTime * 100 + 0.5) / 100.0;
    double roundedDistance = int(distance * 10 + 0.5) / 10.0;


    // Max height
    if (unit == "feet") {
        cout << "Max height: " << roundedHeight * metersToFeet << " feet" << endl;
    } else {
        cout << "Max hieght: " << roundedHeight << " meters" << endl;
    }

    // Flight time
    cout << "Flight time: " << roundedFlightTime << " seconds" << endl;

    // Distance
    if (unit == "feet") {
        cout << "Distance: " << roundedDistance * metersToFeet << " feet" << endl;
    } else {
        cout << "Distance: " << roundedDistance << " meters" << endl;
    }

    // Check if the target is in range
    if (distance >= targetDistance) {
        cout << "The target is in range!" << endl;
    } else {
        cout << "The target is not in range." << endl;
    }

    return 0;
}
