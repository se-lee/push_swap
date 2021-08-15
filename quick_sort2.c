#include <stdio.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		partition(int array[], int size)
{
	int	pivot;
	int	i;
	int partition_index;

	pivot = array[0];
	i = 1;
	partition_index = 0;
	while (i < size)
	{
		if (array[i] < pivot)
		{
			partition_index++;
			swap(&array[i], &array[partition_index]);
		}
		i++;
	}
	swap(&array[0], &array[partition_index]);
	return (partition_index);
}

void	quick_sort(int	array[], int size)
{
	int	partition_index;

	if (size <= 1)
		return ;
	partition_index = partition(array, size);
	quick_sort(&array[0], partition_index);
	quick_sort(&array[partition_index + 1], size - (partition_index + 1));
}

/*
int main()
{
    size_t            i;
    const size_t    length = 10;
    int                array[length] = {3, 7, 1, 5, 6, 4, 8, 2, 0, 9};

    printf("before sort: ");
    i = 0;
    while (i < 10)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");
    quick_sort(array, length);
    printf("after sort: ");
    i = 0;
    while (i < 10)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");
    return (0);
}*/