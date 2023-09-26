#include <iostream>
#include <cmath>

using namespace std;

// Define the function to be integrated
double f(double x) {
    return log(x); // Change this function to the one you want to integrate
}

// Simpson's 1/3 Rule for numerical integration
double simpsonsRule(double a, double b, int n) {
    if (n % 2 != 0) {
        cerr << "Number of subintervals (n) must be even for Simpson's 1/3 Rule." << endl;
        return NAN; // Not-a-Number to indicate failure
    }

    double h = (b - a) / n;
    double integral = f(a) + f(b); // Initialize with endpoints

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            integral += 2 * f(x); // For even subintervals
        } else {
            integral += 4 * f(x); // For odd subintervals
        }
    }

    integral *= h / 3.0;

    return integral;
}

int main() {
    double a = 4;   // Lower limit of integration
    double b = 5.2;   // Upper limit of integration
    int n = 6;        // Number of subintervals (must be even)

    double result = simpsonsRule(a, b, n);

    cout << "Approximate integral: " << result << endl;

    return 0;
}

