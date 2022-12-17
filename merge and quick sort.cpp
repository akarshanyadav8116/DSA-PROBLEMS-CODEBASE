#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,arr_size;
    printf("Enter the size of the array");
    scanf("%d",&arr_size);
    int arr[arr_size];
    for(int i=0;i<arr_size;i++){
    	scanf("%d",&arr[i]);
	}
}
