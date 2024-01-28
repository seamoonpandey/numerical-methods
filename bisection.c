/*
Program : Bisection Method, find real roots of a function
 */

#include <stdio.h>

#define function(x) (x * x * x - 6 * x + 2)
#define ERROR .0001

// Function to find the root using the bisection method
double bisectionMethod(double a, double b)
{
    double c;

    // Check if the function values at the endpoints have opposite signs
    if (function(a) * function(b) >= 0)
    {
        // Display an error message and exit the function
        printf("Error: The function values at the endpoints do not have opposite signs\n");
        return 1;
    }

    // Iterate until the desired accuracy is achieved
    while ((b - a) >= ERROR)
    {
        // Find the midpoint
        c = (a + b) / 2;

        // Check if the midpoint is the root
        if (function(c) == 0.0)
        {
            return c;
        }
        // Update the interval based on the sign of the function value at the midpoint
        else if (function(c) * function(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    // Return the approximate root
    return (a + b) / 2;
}

int main()
{
    double a, b, root;

    // Input the endpoints of the interval
    printf("Enter the endpoints of the interval: ");
    scanf("%lf %lf", &a, &b);

    // Find the root using the bisection method
    root = bisectionMethod(a, b);

    // Display the root
    printf("The root is: %lf\n", root);

    return 0;
}