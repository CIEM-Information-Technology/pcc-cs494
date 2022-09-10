#include<stdio.h>

/**
 * @brief function to sort an array
 * 
 * @param a array to be sorted
 * @param n number of elements in the array
 */
void sort_array(int a[], int n)
{
    int i, j, temp;
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

/**
 * @brief function to print an array
 * 
 * @param a array to be printed
 * @param n number of elements in the array
 */
void print_array(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/**
 * @brief Binary search algorithm using recursion
 * 
 * @param arr array to be searched
 * @param l left index of the array
 * @param r right index of the array
 * @param x elemtn to be searched
 * @return int index of the element if found, -1 otherwise
 */
int binary_search(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  return mid;
        if (arr[mid] > x) return binary_search(arr, l, mid-1, x);
        return binary_search(arr, mid+1, r, x);
    }
    return -1;
}

int main(void)
{
    int n;
    printf("Enter the size of n: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    sort_array(arr, n);
    print_array(arr, n);

    int x;
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    
    int result = binary_search(arr, 0, n-1, x);
    if (result == -1)
    {
        printf("Element is not present in array\n");
    }
    else 
    {
        printf("Element is present at index %d\n", result);
    }

    return 0;
}
