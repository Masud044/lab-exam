#include<bits/stdc++.h>

using namespace std;

// Define the function whose root we want to find
double f(double x) {
    return x * x - 4; // Change this function to your desired one
}

// Modified Secant method to find the root of a function
double modifiedSecant(double x0, double tol, int maxIterations) {
    int n = 0;
    double x = x0;
    double delta = 0.01; // Initial perturbation

    while (n < maxIterations) {
        double f0 = f(x);
        double f1 = f(x + delta);

        if (fabs(f0) < tol) {
            cout << "Root of the given equation = " << setprecision(10) << x << endl;
            cout << "No. of iterations = " << n << endl;
            return x;
        }

        double dfdx = (f1 - f0) / delta;
        x = x - f0 / dfdx;

        n++;
    }

    cout << "Modified Secant method did not converge within the given number of iterations." << endl;
    return NAN; // Not-a-Number to indicate failure
}

int main() {
    double x0 = 1.0;      // Initial guess
    double tol = 0.0001;  // Tolerance
    int maxIterations = 100; // Maximum number of iterations

    double root = modifiedSecant(x0, tol, maxIterations);

    return 0;
}

