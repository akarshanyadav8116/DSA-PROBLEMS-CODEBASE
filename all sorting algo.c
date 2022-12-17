#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int getMax(int arr[], int n)
{
    int i,max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
int getMin(int arr[], int n)
{
    int i,min = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}
void bubblesort(int a[],int size){
	int i,j,z;
	for(i=0;i<size;i++){
		for(j=0;j<size-i-1;j++){
			if(a[j]>a[j+1]){
				z=a[j];
				a[j]=a[j+1];
				a[j+1]=z;
			}
		}
	}
}
void insertionsort(int a[],int size){
	int i,j,key;
	for(i=1;i<size;i++){
		key=a[i];
		for(j=i-1;j>=0;j--){
			if(key<a[j]){
				a[j+1]=a[j];
			}
			else{
				break;
			}
		}
		a[j+1]=key;
	}
}
void selectionsort(int a[],int size){
	int i,j,z;
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(a[i]>a[j]){
				z=a[j];
				a[j]=a[i];
				a[i]=z;
			}
		}
	}
}
void countsort(int *arr,int size){
    int *count,*ans,i,range,max,min;
    max=getMax(arr,size);
    min=getMin(arr,size);
    range=max-min+1;
    ans=(int*)calloc(size,sizeof(int));
  	count=(int*)calloc(range,sizeof(int));
    for (i=0;i<size;i++)
        count[arr[i] - min]++;
  
    for (i=1;i<range;i++)
        count[i]+=count[i-1];
  
    for (i=size-1;i>=0;i--){
        ans[count[arr[i]-min]-1]=arr[i];
        count[arr[i]-min]--;
    }
    for (i=0;i<size;i++)
        arr[i]=ans[i];
}
void RadixcountSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n)
{
    int exp,m = getMax(arr, n);
    for (exp = 1; m / exp > 0; exp *= 10)
        RadixcountSort(arr, n, exp);
}
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main(){
	int op,n,i,*arr;
	while(1){
	printf("Name : Akarshan Yadav\n");
	printf("Roll No. :2101640100022\n");
	printf("Section : CS II A\n\n");
	printf("\t\t\t\t\tMAIN MENU");
	printf("\n1) Sort using bubble sort");
	printf("\n2) Sort using insertion sort");
	printf("\n3) Sort using selection sort");
	printf("\n4) Sort using counting sort");
	printf("\n5) Sort using radix sort");
	printf("\n6) Exit");
	printf("\nEnter your choice :");
	scanf("%d",&op);
	if(op<=5){
		printf("\nEnter the size of the array :");
		scanf("%d",&n);
		arr=(int*)malloc(n*sizeof(int));
		printf("Enter the elements :");
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		printf("\nGiven array is\n");
		printArray(arr,n);
	}
	switch(op){
		case 1: bubblesort(arr,n);
				printf("\nSorted array is \n");
    			printArray(arr,n);
				break;
		case 2: insertionsort(arr,n);
				printf("\nSorted array is \n");
    			printArray(arr,n);
    			getch();
    			system("cls");   
				break;
		case 3: selectionsort(arr,n);
				printf("\nSorted array is \n");
    			printArray(arr,n);
    			getch();
    			system("cls");   
				break;
		case 4: countsort(arr,n);
				printf("\nSorted array is \n");
    			printArray(arr,n);
    			getch();
    			system("cls");   
				break;
		case 5: radixsort(arr,n);
				printf("\nSorted array is \n");
    			printArray(arr,n);
    			getch();
    			system("cls");  
				break;
		case 6: printf("Exiting the program.......Press any key to exit");
				getch();
				exit(0);
				break;
		default:printf("\nYou entered a wrong choice....Enter again....");
				getch();
				system("cls");  
	}
	if(op>6){
		continue;
	}
}
return 0;
}
