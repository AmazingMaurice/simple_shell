#include <stdio.h>

/**
 * absoluteValue - Calculates the absolute value of a number.
 * @num: The number to calculate the absolute value of.
 *
 * Return: The absolute value of num.
 */
int absoluteValue(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int main(void)
{
	int number;

	printf("Enter a number: ");
	scanf("%d", &number);
	if (number < 0)
		printf("Negative numbers are not allowed.\n");
	else
		printf("The absolute value of %d is %d.\n", number, absoluteValue(number));
	return (0);
}
