/*****************************************************************************************************
 * Provided file for lab exam.
 *****************************************************************************************************
 * Author: Oshini Jayaweera
 * Project: 2D points
 * Copyright: 2023, Marc Hensel
 * Version: 2023.09.19
 * License: CC BY-NC-SA 4.0, see https://creativecommons.org/licenses/by-nc-sa/4.0/deed.en
 *****************************************************************************************************/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaring the structure with x and y as members
typedef struct{
	int x;
	int y;
}point2D;

int keyboardInputNumberPoints(void);//get number of points as user input
point2D* generateRandomPoints(int numberPoints); //generate random values for x and y 
void printPoints(point2D* points, int numberPoints);// print the randomly generated points
point2D getCenterOfGravity(point2D* points, int numberPoints);//get mean of x and y values and get cog

int main(void)
{
	int numPoints = keyboardInputNumberPoints();
	point2D* points = generateRandomPoints(numPoints);
	printPoints(points, numPoints);
	printf("\n");
	point2D finalPoints = getCenterOfGravity(points, numPoints);
	printf("Center of gravity: cog = (%d, %d)", finalPoints.x, finalPoints.y);

	free(points); //freeing memory allocated
	return 0;
}

//get number of points as user input
int keyboardInputNumberPoints(void)
{
	int input = 0;
	int n;

	while (1)
	{
		printf("Enter number of 2D points to generate: ");
		input = scanf("%d", &n);
		while (getchar() != '\n'); //clear input buffer

		if (input != 1)
			printf("Invalid input. Try again.\n\n");
		else if (n < 0)
			printf("Number of points must be positive. Try again.\n\n");
		else if (input == 1)
		{
			printf("Number entered: %d\n\n", n);
			break;
		}
	}
	return n;
}

//generate random values for x and y 
point2D* generateRandomPoints(int numberPoints)
{
	point2D* points;

	//allocating memory for an array of structure variables
	if ((points = (point2D*)malloc(numberPoints * sizeof(point2D))) == NULL) 
		exit(EXIT_FAILURE);

	srand((unsigned)time(NULL));
	for (int i = 0; i < numberPoints; i++)
	{
		points[i].x = rand() % 10;
		points[i].y = rand() % 10;
	}
	return points;
}

// print the randomly generated points
void printPoints(point2D* points, int numberPoints)
{
	for (int i = 0; i < numberPoints; i++)
	{
		printf("P%d = (%d, %d)\n", i+1, points[i].x, points[i].y);
	}
}

//get mean of x and y values and get cog
point2D getCenterOfGravity(point2D* points, int numberPoints)
{
	int sumX = 0;
	int sumY = 0;
	int meanX = 0;
	int meanY = 0;

	for (int i = 0; i < numberPoints; i++)
	{
		sumX += (points[i].x);
		sumY += (points[i].y);
	}
	meanX = (sumX + (int)0.5 ) / numberPoints; //Calculating means of x and y values
	meanY =(sumY+(int)0.5) / numberPoints;
    
	point2D finalPoints = { meanX, meanY };

	return finalPoints;
}
