#include<stdio.h>

/**
 * @brief function to find the maximum and minimum element in an array
 * using divide and conquer.
 * 
 * @param a array to be searched
 * @param n number of elements in the array
 * @param max pointer to the maximum element
 * @param min pointer to the minimum element
 */
void max_min(int a[], int n, int *max, int *min)
{
    int max1, min1, mid;
    if (n == 1)
    {
        *max = *min = a[0];
    }
    else if (n == 2)
    {
        if (a[0] > a[1])
        {
            *max = a[0];
            *min = a[1];
        }
        else
        {
            *max = a[1];
            *min = a[0];
        }
    }
    else
    {
        mid = n / 2;
        max_min(a, mid, max, min);
        max_min(a + mid, n - mid, &max1, &min1);
        if (*max < max1)
            *max = max1;
        if (*min > min1)
            *min = min1;
    }
}

int main()
{
    int a[100], n, i, max, min;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    max_min(a, n, &max, &min);
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}