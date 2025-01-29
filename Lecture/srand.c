/*
* Tomorrow i will remember to be at BT5 at 8 am
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>		  //generate random numbers
#include<time.h>		  //use the current time for seed as a randomness

#define HISTO_SIZE 11
#define NUMBERS_GENERATED 11000

double histogramAverage(const int[], int);

int main() {

	int histo[HISTO_SIZE] = { 0 };		//initializing the array with 0
	double average;

	srand((unsigned)time(NULL));

	for (int i = 0; i < NUMBERS_GENERATED; i++)
	{
		histo[rand() % HISTO_SIZE]++;
		average = histogramAverage(histo, HISTO_SIZE);
	}

	printf("Histogram of random numbers: \n");
	for (int i = 0; i < HISTO_SIZE; i++)
	{
		printf("%2d: %5d\n", i, histo[i]);
		printf("Average value: %.1f\n", average);
	}


	return 0;
}

double histogramAverage(const int a[], int n)
{
	int sum = 0, count = 0;

	for (int i = 0; i < n; i++)
	{
		sum += i * a[i];
		count += a[i];
	}

	return (double)sum / (double)count;
}
