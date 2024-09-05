//#include <stdio.h>
//
//float pow(float num, float time)
//{
//	if (time == 0)
//		return 1;
//	float temp = num;
//	for (int i = 0; i < time; i++)
//	{
//		temp *= num;
//	}
//	return temp;
//}
//
//int main()
//{
//	int money = 0;
//	float rate = 0.0f;
//	float year = 0.0f;
//
//	printf("Enter amount of money: ");
//	scanf_s("%d", &money);
//
//	printf("Enter the annual interest rate: ");
//	scanf_s("%f", &rate);
//
//	while (pow((1 + rate), year) <= 2)
//	{
//		year++;
//	}
//	printf("When money is %d and rate is %.1f, year required is %.1f", money, rate, year);
//}