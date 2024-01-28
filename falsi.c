#include <stdio.h>

#define ERROR .0001

double func(double x)
{
    // Define your function here
    return (x * x * x - 6 * x - 5);
}

double falsePosition(double a, double b)
{
    double c;

    while (1)
    {
        // Calculate the value of the function at points a and b
        double fa = func(a);
        double fb = func(b);

        if (fa * fb > 0)
        {
            return 1;
        }

        // Calculate the new point c using false position formula
        c = (a * fb - b * fa) / (fb - fa);

        // Check if the absolute difference between b and a is less than ERROR
        if (fabs(b - a) < ERROR)
        {
            break;
        }

        // Calculate the value of the function at point c
        double fc = func(c);

        // Update the values of a and b based on the sign of fc
        if (fc * fa < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    return c;
}

int main()
{
    double a, b;

    // Get the input values from the user
    printf("Enter the initial value a and b: ");
    scanf("%lf %lf", &a, &b);

    // Call the falsePosition function to find the root
    double root = falsePosition(a, b);

    // Print the root
    printf("Root: %lf\n", root);

    return 0;
}
