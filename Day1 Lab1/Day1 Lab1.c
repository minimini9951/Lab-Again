#include <stdio.h>
#include <math.h>

int pow2(int num, int times)
{
	if (times == 0)
	{
		return 1;
	}
	int i = 1;
	int temp = num;
	for (; i < times; i++)
	{
		temp *= num;
	}
	return temp;
}

//calculates the factorial of a number and prints the output.
static void factorial()
{
	//�ʱⰪ ����
	int n = 0;
	int temp = 1;
	int i = 1;
	printf("Enter the number: ");
	//�Է¹��� �� ������ �ֱ�
	scanf_s("%d", &n);
	//i�� 1���� n���� �ݺ��ϸ� temp�� i�� ������
	for (; i <= n; i++) 
	{
		temp *= i;
	}

	//���
	printf("%d factorial is %d\n\n", n, temp);
}

//calculates the sum of digits of a number.
static void sum_digits()
{
	//�ʱⰪ ����
	float n = 0;
	float m = 0;
	float sum = 0;
	//�Է¹��� �� ������ �ֱ�
	printf("Enter the number(ex: 5, 7): ");
	scanf_s("%f, %f", &n, &m);
	//���
	sum = n + m;
	//���
	printf("The sum of two number is %.1f\n\n", sum);
}

//checks if a number is prime.
static void is_prime()
{
	//�ʱⰪ ����
	int p = 0;
	int i = 1;
	int is_p = 1;
	//�Է¹��� �� ������ �ֱ�
	printf("Enter the number: ");
	scanf_s("%d", &p);
	//�Ҽ����� �ƴ��� ���
	for (; i <= p; i++)
	{
		if (p % i == 0 && i != 1 && i != p)
		{
			is_p = 0;
		}
	}
	//���
	if (is_p == 0)
		printf("%d is not prime number\n\n", p);
	else
		printf("%d is prime number\n\n", p);
}

//solves a linear equation: ax + b = 0
static void linear_equation_solver()
{
	//�ʱⰪ ����
	float a = 0;
	float b = 0;
	float x = 0;
	//�Է¹��� �� ������ �ֱ�
	printf("Enter the number(ex: 5, 7): ");
	scanf_s("%f, %f", &a, &b);
	//���
	if (a == 0)
	{
		printf("a�� 0�� �ɼ� �����ϴ�.\n\n");
		return;
	}
	x = -1 * b / a;
	//���
	printf("x is %.1f\n\n", x);
}

//solves a quadratic equation: ax^2 + bx + c = 0
static void quadratic_equation_solver()
{
	//�ʱⰪ ����
	float a = 0;
	float b = 0;
	float c = 0;
	float x = 0;
	float x1 = 0;
	float x2 = 0;
	//�Է¹��� �� ������ �ֱ�
	printf("Enter the number(ex: 5, 0, 9): ");
	scanf_s("%f, %f, %f", &a, &b, &c);
	if (a == 0)
	{
		printf("a�� 0�� �ɼ� �����ϴ�.\n\n");
		return;
	}
	//��� �� ���
	if (b * b - 4 * a * c < 0)
	{
		printf("x�� ����� ���� �ΰ� �����ֽ��ϴ�.\n\n");
	}
	else if (b * b - 4 * a * c == 0)
	{
		printf("x�� %.1f�Դϴ�.\n\n", -1 * b / 2 * a);
	}
	else if (b * b - 4 * a * c > 0)
	{
		x1 = (-b + sqrtf(b * b - 4 * a * c)) / 2 * a;
		x2 = (-b - sqrtf(b * b - 4 * a * c)) / 2 * a;
		printf("x�� %.1f, %.1f�Դϴ�.\n\n", x1, x2);
	}
}

//checks if a number is a palindrome. Same number left to right and right to left.
static void palindrome_number()
{
	//initialize
	int n = 0;
	int i = 0;
	int temp = 0;
	int cnt = 0;
	int left_num = 0;
	int right_num = 0;
	int is_palindrome = 0;
	//Put the value in variable
	printf("Enter the number: ");
	scanf_s("%d", &n);
	temp = n;
	//Calculation part
	//Get "n" length
	while (temp)
	{
		temp /= 10;
		cnt++;
	}
	if (cnt == 1)
		is_palindrome = 1;
	else
	{
		if (cnt % 2 == 0)
		{
			if (n % 11 == 0)
				is_palindrome = 1;
		}
		else
		{
			for (; i < cnt / 2; i++)
			{
				//Isolate left most digit
				left_num = n / pow2(10, (cnt - 1 - i));
				if (i != 0)
				{
					left_num %= 10;
				}
				//Isolate Right most digit
				right_num = (n / pow2(10, i)) % 10;

				//compare
				if (left_num == right_num)
					is_palindrome = 1;
				else
				{
					is_palindrome = 0;
					break;
				}
				//printf("%d, %d\n", left_num, right_num); //debug
			}
		}
	}
	
	//print
	if (is_palindrome)
		printf("%d is palindrome\n\n", n);
	else
		printf("%d is not palindrome\n\n", n);
}

int main()
{
	int Flag = 1;
	int n = 0;
	while (Flag)
	{
		printf("1: Factorial\n");
		printf("2: Sum digits\n");
		printf("3: Check prime\n");
		printf("4: Linear_equation\n");
		printf("5: Quadratic_equation\n");
		printf("6: Check palindrome\n");
		printf("Enter the number: ");

		scanf_s("%d", &n);
		switch (n)
		{
			case 1:
				factorial();
				break;
			case 2:
				sum_digits();
				break;
			case 3:
				is_prime();
				break;
			case 4:
				linear_equation_solver();
				break;
			case 5:
				quadratic_equation_solver();
				break;
			case 6:
				palindrome_number();
				break;
		default:
			Flag = 0;
		}
	}
}