#include<stdio.h>
int main()
{
	int year1;
	int year2 = year1 - 543;
	printf("Enter initial year you doubt in Buddhist Era\n");
	scanf("%d", &year1);
	if(year2>0 && year2<10000)
	{
		if (year2 % 400 == 0)
		{
			printf("Leap Year");
		}
		else if (year2 % 100 == 0)
		{
			printf("NOT a Leap a Leep Year");
		}
		else if (year2 % 4 == 0)
		{
			printf("Leap Year");
		}
		else
		{
			printf("NOT a Leap a Leep Year");
		}

		for (int i = year;i <= year + 1000;i++)
		{
			if (i % 400 == 0)
			{
				printf("%d ",i);
			}
			else if (i % 100 == 0)
			{
				printf("");
			}
			else if (year % 4 == 0)
			{
				printf(" yes ");
			}
		}
	}
}