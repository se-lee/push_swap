#include <stdio.h>
#include <stddef.h>

void    swap(int *a, int *b)
{
    int    temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

size_t    partition(int array[], size_t length)
{
    int        pivot;
    size_t    index;
    size_t    pivot_index;

    index = 1;
    pivot_index = 0;
    pivot = array[0];
    while (index < length)
    {
        if (array[index] < pivot)
        {
            pivot_index += 1; // The pivot index is now one more on the right
            swap(&array[index], &array[pivot_index]); // Put this value at pivot place
        }
        index += 1;
    }
    swap(&array[0], &array[pivot_index]);
    return (pivot_index);
}

void    quick_sort(int array[], size_t length)
{
    int    pivot_index;

    if (length <= 1)
        return ; // No need to sort
    pivot_index = partition(array, length);
    quick_sort(&array[0], pivot_index);
    quick_sort(&array[pivot_index + 1], length - (pivot_index + 1));
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
}
*/
