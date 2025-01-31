#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <math.h>
#include <stdio.h>


void clearInputBuffer(void);
double sine(double, int);
double principalvalue(double);

int main()
{
	double x = 0.0;
	int k = 0;
	double alpha = 0.0;
	char keypressed;
	
	while (1)
	{
		printf("Series expansion for sin(x * PI) with k > 0 terms.\n");
		printf("Please enter <x>,<k>: ");
		while ((scanf("%lf, %d", &x, &k) != 2) || (k <= 0) || (x < 0))
		{
			printf("Invalid input. Retry: ");
			clearInputBuffer();
		}
			
		

		alpha = x * M_PI;
		printf("Approximations of sin(%.2f * pi): \n", x);

		for (int i = 1; i <= k; i++)
		{
			printf(" k = %2d: sin(x * PI) = %lf\n", i, sine(alpha, i));
		}

		printf("Principal value: %.2f * pi\n", principalvalue(alpha) / M_PI);

		printf("Enter <q> to quit, any other key to continue.");
		scanf("%c", &keypressed);
		clearInputBuffer();
		if(keypressed == 'q' || keypressed == 'Q')
			break;
		putchar('\n');
	}
	return 0;
}

void clearInputBuffer(void)
{
	while (getchar() != '\n')
		continue;
}

double sine(double alpha, int k)
{
	double sine = 1.0;
	
	for (int i = 1; i <= k; i++)
		{
			sine *=  (1 - ((pow(alpha, 2)) / (pow((double)i, 2) * pow(M_PI, 2))));
		}
	sine *= alpha;
	return sine;
}

double principalvalue(double alpha)
{
	
	if (alpha < 0)
		alpha += 2 * M_PI;
	else if (alpha > 2 * M_PI)
		alpha -= 2 * M_PI;
	
	return alpha;
}
