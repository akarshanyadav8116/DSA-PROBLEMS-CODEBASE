#include<stdio.h>
#include<stdlib.h>
int lsearch(int a[],int n,int ele){
	int i;
	for(i=0;i<n;i++){
		if(a[i]==ele){
			return i+1;
		}
	}
	return -1;
}
int Bsearch(int a[],int n,int ele){
	int beg,mid,last;
	beg=0;
	last=n-1;
	while(beg<=last){
		mid=(beg+last)/2;
		if(a[mid]==ele){
			return mid+1;
		}
		else if(ele<a[mid]){
			last=mid-1;
		}
		else{
			beg=mid+1;
		}
	}
	return -1;
}
int main(){
int op,n,i,*arr,pos=-1,ele;
	while(1){
	system("cls");
	printf("Name : Akarshan Yadav\n");
	printf("Roll No. :2101640100022\n");
	printf("Section : CS II A\n\n");
	printf("\t\t\t\t\tMAIN MENU");
	printf("\n1) Search using linear search");
	printf("\n2) Search using binary search");
	printf("\n3) Exit");
	printf("\nEnter your choice :");
	scanf("%d",&op);
	if(op<=2){
		printf("\nEnter the size of the array :");
		scanf("%d",&n);
		arr=(int*)malloc(n*sizeof(int));
		if(op==1){
			printf("Enter the elements :");
		}
		else{
			printf("Enter the elements (in ascending order):");
		}
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		printf("Enter the element to be searched");
		scanf("%d",&ele);
	}
	switch(op){
		case 1: pos=lsearch(arr,n,ele);
				if(pos!=-1){
					printf("\nThe element is at position %d\n",pos);
				}
				else{
					printf("\nElement not found\n");
				}
				getch();
				break;
		case 2: pos=Bsearch(arr,n,ele);
				if(pos!=-1){
					printf("\nThe element is at position %d\n",pos);
				}
				else{
					printf("\nElement not found\n");
				}
				getch();
				break;
		case 3: printf("Exiting the program.......Press any key to exit");
				getch();
				exit(0);
				break;
		default:printf("\nYou entered a wrong choice....Enter again....");
				getch();  
	}
}
return 0;
}
