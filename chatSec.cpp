#include <bits/stdc++.h>

using namespace std;

// Define the function whose root we want to find
double f(double x) {
    return pow(x, 3) + x - 1; // Change this function to your desired one
}

// Secant method to find the root of a function
double secant(double x0, double x1, double tol, int maxIterations) {
    int n = 0;

    while (n < maxIterations) {
        double f0 = f(x0);
        double f1 = f(x1);

        if (fabs(f1) < tol) {
            cout << "Root of the given equation = " << setprecision(10) << x1 << endl;
            cout << "No. of iterations = " << n << endl;
            return x1;
        }

        double x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);

        x0 = x1;
        x1 = x2;

        n++;
    }

    cout << "Secant method did not converge within the given number of iterations." << endl;
    return NAN; // Not-a-Number to indicate failure
}

int main() {
    double x0 = 0;   // First initial guess
    double x1 = 1;   // Second initial guess
    double tol = 0.0001; // Tolerance
    int maxIterations = 100; // Maximum number of iterations

    double root = secant(x0, x1, tol, maxIterations);

    return 0;
}

