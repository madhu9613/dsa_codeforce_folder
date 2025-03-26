#include <iostream>
#include <cmath> // for cos() and sin()
#define PI 3.14159265358979323846
using namespace std;

int main() {
    double angle_in_degrees, angle_in_radians;

    cout << "Enter the angle in degrees: ";
    cin >> angle_in_degrees;

    // Convert degrees to radians
    angle_in_radians = angle_in_degrees * (PI / 180.0);

    cout << "cos(" << angle_in_degrees << " degrees) = " << cos(angle_in_radians) << endl;
    cout << "sin(" << angle_in_degrees << " degrees) = " << sin(angle_in_radians) << endl;

    return 0;
}
