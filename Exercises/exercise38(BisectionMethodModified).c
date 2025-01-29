/*
Name - Oshini Vidhara Jayaweera
Module - Software Construction 1 (C programming)

Description - This program approximates the roots of the function f(x) using the bisection method
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

double function(double);
double bisection(double, double, double, double);

int main() 
{
	double varXl = 0.0;
	double varXr = 4.0;
	double varXm = 0.0;
	double tolerance = 1e-6;

	if ((function(varXl) * function(varXr)) < 0)
	{
		printf("There exist a zero-crossing in the interval %.2lf and %.2lf", varXl, varXr);	
		printf("\nApproximation of zero-crossing: x = %.6lf", bisection(varXl, varXr, varXm, tolerance));
		printf("\nThe function value at x: f(x) = %.6lf is ", function(varXm));
	}
	else
	{
		printf("There exist NO zero-crossing in the interval  %.2lf and %.2lf", varXl, varXr);
	}	
	return 0;
}

double function(double x) 
{
	double function = pow(x, 2) - (2 * x) - 1;
	return function;
}

double bisection(double xl, double xr, double xm, double tolerance)
{
	while (fabs(xl - xr) > tolerance)
	{
		xm = (xl + xr) / 2.0;
		if ((function(xm) * function(xl)) < 0.0)
		{
			xr = xm;		
		}
		else
		{
			xl = xm;
		}
	}
	xm = (xl + xr) / 2;
	return xm;
}
