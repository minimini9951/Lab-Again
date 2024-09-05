#include <stdio.h>

#define bias 127

int pow(int num, int time)
{
	int i = 1;
	int temp = num;
	for (; i < time; i++)
	{
		temp *= num;
	}
	return temp;
}

int main()
{
	//initialize
	int arr[32];
	float num = 0;
	int exp = 0;
	int temp_exp = 0;
	int man = 0;
	float temp_man = 0;
	int cnt = 0;

	//get value and enter
	printf("Enter the number: ");
	scanf_s("%f", &num);

	//initialize array
	for (int i = 0; i < 32; i++)
	{
		arr[i] = 0;
	}

	if (num == 0)
	{
		for (int i = 0; i < 1; i++)
			printf("%d", arr[i]);
		printf(" ");

		for (int i = 0; i < 8; i++)
			printf("%d", arr[i + 1]);
		printf(" ");

		for (int i = 0; i < 23; i++)
			printf("%d", arr[i + 9]);
	}

	//Calculate the sign part and enter value
	if (num < 0)
	{
		arr[0] = 1;
		num *= -1;
	}

	//devide exponent part and fraction part
	//Calculate exponent
	if (num > 1)
	{
		//Calculate exponent value
		while (num > 2)
		{
			num /= 2;
			cnt++;
		}
		exp = bias + cnt;
		
	}
	else if (num < 1)
	{
		while (num < 1)
		{
			num *= 2;
			cnt--;
		}
		exp = bias + cnt;

	}
	
	//Change to binary
	for (int i = 0; i < 8; i++)
	{
		if (exp % 2 == 0)
		{
			arr[8 - i] = 0;
		}
		else
			arr[8 - i] = 1;
		exp /= 2;
	}

	//Calculate mantissa value
	int i = 1;
	num -= 1;
	while (i <= 23)
	{
		float t = 1.f / pow(2, i);
		if (num >= t)
		{
			num -= t;
			arr[8 + i] = 1;
		}
		else
		{
			arr[8 + i] = 0;
		}
		i++;
	}

	for (int i = 0; i < 1; i++)
		printf("%d", arr[i]);
	printf(" ");

	for (int i = 0; i < 8; i++)
		printf("%d", arr[i + 1]);
	printf(" ");
	
	for (int i = 0; i < 23; i++)
		printf("%d", arr[i + 9]);

	return 0;
}