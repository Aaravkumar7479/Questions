

//It specifically works best when the data is sorted and uniformly distributed.
//If the element repeats, interpolation search will also return one occurrence.
#include <stdio.h>
#include <stdlib.h>

int interpolationSearch(float arr[], int low,int high, float target)
{
int pos=0;
if (low<=high && target>=arr[low] && target<=arr[high]){


    pos=low+((target-arr[low])*(high-low)/(arr[high]-arr[low]));


            if(target==arr[pos])
                return pos;

            else if(target<arr[pos]) 
            return interpolationSearch(arr,low,pos-1,target);


            else 
            return interpolationSearch(arr,pos+1,high,target);
}
    
    return -1; //element not found
}

int main()
{
    int n;
    float target;
    printf("Enter the size of array : ");
    scanf("%d", &n);

    float arr[n];
    int low = 0, high = n - 1;

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the arr[%d] element : ", i);
        scanf("%f", &arr[i]);
    }
    printf("\nEnter the element which you want to find  : ");
    scanf("%f", &target);

    int result = interpolationSearch(arr, low,high, target);
    if (result != -1)
        printf("\nElement found at index %d\n", result);
    else
        printf("\nElement not found.\n");

    return 0;
}