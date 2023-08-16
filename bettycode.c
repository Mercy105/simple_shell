#include <stdio.h>
/**
 * main - main program
 * description - returns the sum of two digits
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int a;

	int b;

	int add;

	printf("Enter the value of a and b\n");
	scanf("%d%d", &a, &b);
	add = a + b;
	printf("Sum of a and b is %d", add);
	return (0);
}
