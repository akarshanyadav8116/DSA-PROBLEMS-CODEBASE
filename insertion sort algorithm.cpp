#include<stdio.h>
#include<stdlib.h>
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
int main(){
	int i,n,*arr;
	printf("Name : Akarshan Yadav\n");
	printf("Roll No. :2101640100022\n");
	printf("Section : CS II A\n");
	printf("Program : Insertion Sort Algorithm\n\n");
	printf("Enter the size of the array :");
	scanf("%d",&n);
	arr=(int*)calloc(n,sizeof(int));
	printf("Enter the elements of the array :");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	insertionsort(arr,n);
	printf("\nThe sorted array is:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
