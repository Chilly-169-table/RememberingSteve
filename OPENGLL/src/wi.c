#include<stdio.h>

int main()
{
	int n, arr[10], hea1, hea2, i, clear;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);

	}

	scanf("%d", &hea1);
	scanf("%d", &hea2);

	clear = check(arr, n, hea1, hea2);
	printf("%d", clear);
	return 0;
}

int check(int arr[], int n, int hea1, int hea2)
{
	int i, j, sum = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < 9; j++)
			if (hea1 % j == 0)
			{
				if (hea2 % j == 0)
				{
					sum = sum + 1;
				}
			}
	}
	return sum;
}