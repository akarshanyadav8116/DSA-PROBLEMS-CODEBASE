#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
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
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main(){
	int op;
	int i,arr_size,*arr;
	printf("Name : Akarshan Yadav\n");
	printf("Roll No. :2101640100022\n");
	printf("Section : CS II A\n");
	printf("Program : Bubble Sort Algorithm\n\n");
	printf("\t\t\t\tMAIN MENU\n");
	printf("1)Sort using merge sort\n");
	printf("2)Sort using quick sort\n");
	printf("Enter your choice :");
	scanf("%d",&op);
	if(op==1||op==2){
    		printf("Enter the size of the array");
    		scanf("%d",&arr_size);
    		arr=(int*)malloc(arr_size*sizeof(int));
    		printf("\nEnter the elements of the array :");
    		for(i=0;i<arr_size;i++){
    				scanf("%d",&arr[i]);
			}
			printf("Given array is \n");
    		printArray(arr,arr_size);
	}
	switch(op){
		case 1:
    		mergeSort(arr,0,arr_size - 1);
    		printf("\nSorted array is \n");
    		printArray(arr, arr_size);
			break;
		case 2:
    		quickSort(arr,0,arr_size-1);
    		printf("\nSorted array is \n");
    		printArray(arr, arr_size);
			break;
		default:
		printf("You entered a wrong choice. Enter again....\n");		
	}
	return 0;
}
