#include <stdio.h>

/*
* Power function
* It will take 2 integers  (base and power).
* power will always be >= 0 and returns the operation base ^ power.
* For this function, you CAN NOT use the ' * ' operator.
*/
int power(int number, int time)
{
	int base = number;
	int temp = number;

	if (time == 0 && number != 0)
		return 1;
	else if (number == 0)
		return 0;
	else if (time < 0)
		return -1;

	for (int i = 1; i < time; i++)
	{
		number = temp;
		for (int j = 1; j < base; j++)
		{
			temp += number;
		}
	}
	return temp;
}

/*
* AreaSubstractor.
* It will take an int array of n size as parameter.
* It will search for the MAX and MIN numbers in it,
* and returns the result of Max^2 - Min^2.
*/
int areaSubstractor(int* arrptr, int size)
{
	if (arrptr == NULL || size <= 0)
		return 0;

	int max = *arrptr;
	int min = *arrptr;
	
	for (int i = 1; i < size; i++)
	{
		if (max < *(arrptr + i))
			max = *(arrptr + i);

		if (min > *(arrptr + i))
		{
			min = *(arrptr + i);
		}
	}
	return max * max - min * min;
}

int determinant2x2(int* arrptr)
{
	return *arrptr * *(arrptr + 3) - *(arrptr + 1) * *(arrptr + 2);
}
/*
* Determinant2dSquareArrays.
* It will take a 2D int Array of size [3][3] and return its determinant
*/
int determinant2dSquareArrays(int* arrptr)
{
	int result = 0;
	int result_p = 0;

	int arr[2][2] = {0};

	int* p = &arr[0][0];


	int col0 = 0;
	int col1 = 1;
	int col2 = 2;

	int n = 3;
	int cnt = 0;

	for (int i = 0; i < 3; i++)
	{
		////Option 2. Works for nxn
		//for (int x = 0; x < n; x++)
		//{
		//	if (i == x)
		//		continue;

		//	for (int y = 1; y < n; y++)
		//	{
		//		p[cnt] = arrptr[n * y + x];/// x , y, i, n
		//		cnt++;
		//	}
		//}

		//Option 1. Works for 3x3
		switch(i)
		{
		case 0:
			arr[0][0] = arrptr[3 * 1 + 1]; // i = 1
			arr[0][1] = arrptr[3 * 1 + 2]; // i = 1
			arr[1][0] = arrptr[3 * 2 + 1]; // i = 1
			arr[1][1] = arrptr[3 * 2 + 2]; // i = 1
			break;
		case 1:
			arr[0][0] = arrptr[3 * 1 + 0]; // i = 1
			arr[0][1] = arrptr[3 * 1 + 2]; // i = 1
			arr[1][0] = arrptr[3 * 2 + 0]; // i = 1
			arr[1][1] = arrptr[3 * 2 + 2]; // i = 1

			break;

		case 2:
			arr[0][0] = arrptr[3 * 1 + 0]; // i = 1
			arr[0][1] = arrptr[3 * 1 + 1]; // i = 1
			arr[1][0] = arrptr[3 * 2 + 0]; // i = 1
			arr[1][1] = arrptr[3 * 2 + 1]; // i = 1
			break;
		default:
		}

		result_p = *(arrptr + i) * determinant2x2(&arr[0][0]);

		if (i % 2 == 1)
			result_p *= -1;

		result += result_p;
	}

	return result;
}

int main()
{
	int num = 0;
	int number = 0;
	int pow = 0;
	int result = 0;
	int arr[5] = { -3, -2, -5, -1, -9 };
	int arr2[3][3] = { {-1, 0, 1}, {2, 3, 4}, {5, 6, -7} };
	printf("1: Calculate power\n");
	printf("2: AreaSubstractor\n");
	printf("3: Determinant2dSquareArrays\n");
	printf("Enter the number: ");
	scanf_s("%d", &num);
	switch (num)
	{
	case 1:
		printf("Power Fuction: \n");
		printf("Enter the number and power: ");
		scanf_s("%d %d", &number, &pow);

		result = power(number, pow);

		printf("%d power %d is %d", number, pow, result);

	case 2:
		printf("AreaSubstractor Fuction: \n");
		result = areaSubstractor(arr, 5);
		printf("%d", result);

	case 3:

	default:
		break;
	}
}