#include <stdio.h>

void	bubble_sort(int arr[], int size)
{
	int temp;
	int i;
	int	j;

	temp = 0;
	i = 0;
	while(i < size - 1)
	{
		j = 0;
		while(j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;	
	}
}

// int main()
// {
// 	int arr[10] = {5, 1, 3, 2, 7, 6, 4, 8, 9, 0};
// 	int	i;

// 	printf("before sort: ");
// 	while (i < 10)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	bubble_sort(arr, 10);
// 	printf("after sort : ");
// 	i = 0;
// 	while (i < 10)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	return (0);
// }
