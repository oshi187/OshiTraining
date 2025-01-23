#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define pi 3.141592

double circumference(double radius);
double getArea(double radius);

int main(void)
{
	double circum;
	double area;
	double radius= 0;

	printf("Please enter radius: ");
	scanf("%lf", &radius);
	//getchar();
	circum = circumference(radius);
	area = getArea(radius);
	
	printf("Circumference = %.2lf\n", circum);
	printf("Area = %.2lf\n", area);
	getchar();
	return 0;
	
}

double circumference(double radius) 
{
	double circum = 2 * pi * radius;
	return circum;
}

double getArea(double radius) 
{
	return pi * radius * radius;
}