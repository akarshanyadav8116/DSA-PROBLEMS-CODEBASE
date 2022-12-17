#include<stdio.h>
#include<stdlib.h>
int bubblesort(int a[],int size){
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
int main(){
	int i,n,*arr;
	printf("Name : Akarshan Yadav\n");
	printf("Roll No. :2101640100022\n");
	printf("Section : CS II A\n");
	printf("Program : Selection Sort Algorithm\n\n");
	printf("Enter the size of the array :");
	scanf("%d",&n);
	arr=(int*)calloc(n,sizeof(int));
	printf("Enter the elements :");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	bubblesort(arr,n);
	printf("\nThe sorted array is :\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
