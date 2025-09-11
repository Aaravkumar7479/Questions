#include <stdio.h>

#include <stdlib.h>

int binarySearch(float arr[], int n, float target)
{

    int l = 0, r = n - 1;
    while (l <= r) // use while (l<=r) for  single size array.
    {
        int mid =  l + (r - l)/2; // use l + (r - l)/2 instead of (l+r)/2 ;To avoids integer overflow in large arrays

        if (target == arr[mid])
            return mid;

        else if (target < arr[mid])
            r = mid - 1;

        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
    int n;
    float target;
    printf("Enter the size of array : ");
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arr[%d] element : ", i);
        scanf("%f", &arr[i]);
    }
    printf("Enter the element which you want to find  : ");
    scanf("%f", &target);

    int result = binarySearch(arr, n, target);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found.\n");

    return 0;
}