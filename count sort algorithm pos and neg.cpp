#include<stdio.h>
#include<stdlib.h>
void countsort(int *arr,int max,int size,int min){
    int *count,*ans,i,range;
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
int main(){
	int i,n,*a,max=0,min=214;
	printf("Name : Akarshan Yadav\n");
	printf("Roll No. :2101640100022\n");
	printf("Section : CS II A\n");
	printf("Program : Count Sort Algorithm\n\n");
	printf("Enter the size of the array :");
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int));
	printf("Enter the elements of the array :");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		/*if(max<a[i]){
			max=a[i];
		}
		if(min>a[i]){
			min=a[i];
		}*/
	}
	printf("%d ",min);
	//countsort(a,max,n,min);
	printf("\nThe sorted array is :\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
