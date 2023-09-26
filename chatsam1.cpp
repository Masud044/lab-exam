#include <bits/stdc++.h>


// Function to be integrated
double f(double x) {
    // Replace this with your own function
    return x * x;
}

// Simpson's 3/8 Rule function
double simpsons_3_8(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b); // Sum of the first and last points

    // Sum of the remaining points
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * f(x); // Weighted factor for multiples of 3
        } else {
            sum += 3 * f(x); // Weighted factor for others
        }
    }

    return (3 * h / 8) * sum;
}

int main() {
    double a, b;
    int n;

    // Input the interval [a, b] and the number of subintervals (must be a multiple of 3)
    std::cout << "Enter the lower limit (a): ";
    std::cin >> a;
    std::cout << "Enter the upper limit (b): ";
    std::cin >> b;
    std::cout << "Enter the number of subintervals (must be a multiple of 3): ";
    std::cin >> n;

    if (n % 3 != 0) {
        std::cout << "Number of subintervals must be a multiple of 3." << std::endl;
        return 1;
    }

    // Calculate the integral using Simpson's 3/8 Rule
    double result = simpsons_3_8(a, b, n);

    // Output the result
    std::cout << "Approximate integral: " << result << std::endl;

    return 0;
}

