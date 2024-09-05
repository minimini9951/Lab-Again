#include <stdio.h>

int main()
{
	int price1 = 0;
	int price2 = 0;
	int fuel1 = 0;
	int fuel2 = 0;
	int value1 = 0;
	int value2 = 0;

	printf("Enter the value of Car 1(price, fuel effficiency) : ");
	scanf_s("%d, %d", &price1, &fuel1);
	printf("Enter the value of Car 2(price, fuel effficiency) : ");
	scanf_s("%d, %d", &price2, &fuel2);

	value1 = price1 + fuel1 * 15000 * 50 * 4;
	value2 = price2 + fuel2 * 15000 * 50 * 4;

	if (value1 < value2)
	{
		printf("Car 1: %d, Car 2: %d\n", value1, value2);
		printf("Car 1 is better than Car 2");
	}
	else if (value2 < value1)
	{
		printf("Car 1: %d, Car 2: %d\n", value1, value2);
		printf("Car 2 is better than Car 1");
	}
	else
	{
		printf("Car 1: %d, Car 2: %d\n", value1, value2);
		printf("both are same");
	}
}