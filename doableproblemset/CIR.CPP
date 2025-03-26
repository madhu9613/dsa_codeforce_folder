#include <iostream>
#include <cmath> // For sin() and cos()
using namespace std;

void draw_circle(int radius) {
    double aspect_ratio = 2.0; // Adjust to match the console's character aspect ratio

    for (int i = 0; i <= 2 * radius; i++) {
        for (int j = 0; j <= 2 * radius; j++) {
            // Calculate the distance from the center (radius, radius)
            double dx = (i - radius) / aspect_ratio;
            double dy = j - radius;
            double distance = sqrt(dx * dx + dy * dy);

            // Print '*' if the distance is approximately equal to the radius
            if (distance > radius - 0.5 && distance < radius + 0.5) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;

        // Add an extra blank line for vertical stretching to make it more circular
        if (i % 2 == 0) {
            cout << endl;
        }
    }
}

int main() {
    int radius;

    cout << "Enter the radius of the circle: ";
    cin >> radius;

    draw_circle(radius);

    return 0;
}
