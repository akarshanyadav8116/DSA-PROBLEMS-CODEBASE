#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int j,i = (low- 1);
  
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main()
{
    int i,n;
    printf("Enter the size of the array :");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array :");
    for(i=0;i<n;i++){
    	scanf("%d",&a[i]);
	}
    quickSort(a,0,n-1);
    printf("\nSorted array: \n");
    printArray(a,n);
    return 0;
}
