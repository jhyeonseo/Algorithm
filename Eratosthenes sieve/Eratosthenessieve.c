#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("탐색할 자연수 범위를 입력하세요\n1 ~ ");
	scanf("%d", &n);

	short* arr = (short*)calloc(n, sizeof(short));
	if (arr == NULL)   // 메모리 할당 실패
	{
		printf("calloc error");
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (arr[i - 1] == 0)
			{
				for (int j = i * 2; j <= n; j += i)
				{
					if (arr[j - 1] == 0)
					{
						arr[j - 1] = 1;
					}
				}
			}
		}

		int count = 0;
		for (int i = 1; i < n; i++)
		{
			if (arr[i] == 0)
			{
				printf("%d ", i + 1);
				count++;
			}

		}

		printf("\n\n1부터%d 까지의 소수의 개수 = %d", n, count);


		free(arr);
	}
	return 0;
}