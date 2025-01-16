#define _CRT_SECURE_NO_DEPRECATE	
#include <stdio.h>
#include <math.h>

double f(double x); // Function
double bisection(double x1, double x2, double m); // Bisection method

int main()
{
	double xl = 0.0;
	double xr = 4.0;
	double tolerance = 1e-6;

	if (bisection(xl, xr, tolerance) != -1)
	{
		printf("The approximation of the root is: %lf\n", bisection(xl, xr, tolerance));
	}

	return 0;
}

// Function
double f(double x)
{
	return pow(x, 2) - (2 * x) - 1;
}

// Bisection method
double bisection(double x1, double x2, double m)
{
	double xm;
	if (f(x1) * f(x2) >= 0)
	{
		printf("No root in this interval\n");
		return -1;
	}

	while (fabs(x1 - x2) > m)
	{
		xm = (x1 + x2) / 2;

		if (f(xm) == 0)
		{
			return xm; // Exact root
		}
		else if(f(xm) * f(x1) < 0.0)
		{
			x2 = xm; //root in left half
		}
		else
		{
			x1 = xm; // root in right half
		}
	}
	return (x1 + x2) / 2;
}

